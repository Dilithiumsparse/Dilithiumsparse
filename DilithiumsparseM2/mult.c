/*
Parallel version
Corresponding Algorithm 9
*/

#include <stdio.h>
#include <stdint.h>
#include "params.h"
#include "poly.h"
#include "mult.h"
#include <arm_neon.h>


int smallpolyvecl_mul_neon_earlycheck(polyvecl *z, polyvecl *y, const int8_t a[256], int8_t b[L][256], int32_t B)
{
    int8_t v[L][2*N];
    int8x16_t v_vec, b_vec;
    int8x16_t c_vec[L][16];
    int i, j, k;
    for(k = 0; k < L; k ++)
    {
        for(i = 0; i < N/16; i ++)
        {
            c_vec[k][i] =  vdupq_n_s8(0);
            b_vec = vld1q_s8(&b[k][i*16]);
            v_vec = vnegq_s8(b_vec);
            vst1q_s8(&v[k][16*i], v_vec);
        }
        for(i = N; i < 2*N; i +=16)
        {
            b_vec = vld1q_s8(&b[k][i-N]);
            vst1q_s8(&v[k][i], b_vec);
        }
    }
    
    for(i = 0; i < N; i ++)
    {
        if(a[i] == 1)
        {
            for(k = 0; k < L; k ++)
            {
                for(j = 0; j < N/16; j ++)
                {
                    v_vec = vld1q_s8(&v[k][j*16-i+N]);
                    c_vec[k][j] = vaddq_s8(v_vec, c_vec[k][j]);
                }
            }
        }
        if(a[i] == -1)
        {
            for(k = 0; k < L; k ++)
            {
                for(j = 0; j < N/16; j ++)
                {
                    v_vec = vld1q_s8(&v[k][j*16-i+N]);
                    c_vec[k][j] = vsubq_s8(c_vec[k][j], v_vec);
                }
            }
        }
    }
    int8x8_t l_vec;
    uint32x4_t mask_vec;
    uint32_t mask;
    int32x4_t z_vec, y_vec, z_vec_abs;
    int32x4_t bound_vec = vdupq_n_s32(B);
    for(k = 0; k < L; k ++)
    {
        for(i = 0; i < N/16; i ++)
        {
            //因为这里其实是每次计算16个数，16个cs1结果
            // 前8个中前4个
            l_vec = vget_low_s8(c_vec[k][i]);
            //扩展16bit
            int16x8_t v_vec_s16 = vmovl_s8(l_vec);
            //load y的系数
            y_vec = vld1q_s32(&y->vec[k].coeffs[16*i]);
            //扩展到32bit相加 y+cs1
            z_vec = vaddq_s32(y_vec, vmovl_s16(vget_low_s16(v_vec_s16)));
            //compute abs and check
            //计算y+cs1绝对值然后进行判断
            z_vec_abs = vabsq_s32(z_vec);
            //make comparison
            mask_vec = vcgeq_s32(z_vec_abs, bound_vec);
            //compute mask in every data lane
            mask =  vaddvq_u32(mask_vec);
            if(mask != 0)
            {
                return 1;
            }
            vst1q_s32(&z->vec[k].coeffs[16*i], z_vec);
            //前8个中后四个
            y_vec = vld1q_s32(&y->vec[k].coeffs[16*i+4]);
            //用high取后四个
            z_vec = vaddq_s32(y_vec, vmovl_s16(vget_high_s16(v_vec_s16)));
            //compute abs and check
            z_vec_abs = vabsq_s32(z_vec);
            //make comparison
            mask_vec = vcgeq_s32(z_vec_abs, bound_vec);
            //compute mask in every data lane
            mask =  vaddvq_u32(mask_vec);
            if(mask != 0)
            {
                return 1;
            }
            vst1q_s32(&z->vec[k].coeffs[16*i+4], z_vec);
            //重新load后8个
            //处理前四个
            l_vec = vget_high_s8(c_vec[k][i]);
            v_vec_s16 = vmovl_s8(l_vec);
            y_vec = vld1q_s32(&y->vec[k].coeffs[16*i+8]);
            z_vec = vaddq_s32(y_vec, vmovl_s16(vget_low_s16(v_vec_s16)));
            //compute abs and check
            z_vec_abs = vabsq_s32(z_vec);
            //make comparison
            mask_vec = vcgeq_s32(z_vec_abs, bound_vec);
            //compute mask in every data lane
            mask =  vaddvq_u32(mask_vec);
            if(mask != 0)
            {
                return 1;
            }
            vst1q_s32(&z->vec[k].coeffs[16*i+8], z_vec);

            y_vec = vld1q_s32(&y->vec[k].coeffs[16*i+12]);
            z_vec = vaddq_s32(y_vec, vmovl_s16(vget_high_s16(v_vec_s16)));
            //compute abs and check
            z_vec_abs = vabsq_s32(z_vec);
            //make comparison
            mask_vec = vcgeq_s32(z_vec_abs, bound_vec);
            //compute mask in every data lane
            mask =  vaddvq_u32(mask_vec);
            if(mask != 0)
            {
                return 1;
            }
            vst1q_s32(&z->vec[k].coeffs[16*i+12], z_vec);
        }
    }
    return 0;
}

int smallpolyveck_mul_neon_earlycheck(polyveck *z, polyveck *w0, const int8_t a[256], int8_t b[K][256], int32_t B)
{
    int8_t v[K][2*N];
    int8x16_t v_vec, b_vec;
    int8x16_t c_vec[K][16];
    int32x4_t bound_vec = vdupq_n_s32(B);
    int i, j, k;
    for(k = 0; k < K; k ++)
    {
        for(i = 0; i < N/16; i ++)
        {
            c_vec[k][i] =  vdupq_n_s8(0);
            b_vec = vld1q_s8(&b[k][i*16]);
            v_vec = vnegq_s8(b_vec);
            vst1q_s8(&v[k][16*i], v_vec);
        }
        for(i = N; i < 2*N; i +=16)
        {
            b_vec = vld1q_s8(&b[k][i-N]);
            vst1q_s8(&v[k][i], b_vec);
        }
    }
    
    for(i = 0; i < N; i ++)
    {
        if(a[i] == 1)
        {
            for(k = 0; k < K; k ++)
            {
                for(j = 0; j < N/16; j ++)
                {
                    v_vec = vld1q_s8(&v[k][j*16-i+N]);
                    c_vec[k][j] = vaddq_s8(v_vec, c_vec[k][j]);
                }
            }
        }
        if(a[i] == -1)
        {
            for(k = 0; k < K; k ++)
            {
                for(j = 0; j < N/16; j ++)
                {
                    v_vec = vld1q_s8(&v[k][j*16-i+N]);
                    c_vec[k][j] = vsubq_s8(c_vec[k][j], v_vec);
                }
            }
        }
    }
    int8x8_t l_vec;
    uint32x4_t mask_vec;
    uint32_t mask;
    int32x4_t z_vec, w0_vec, z_vec_abs;
    for(k = 0; k < K; k ++)
    {
        for(i = 0; i < N/16; i ++)
        {
           // 前4个
            l_vec = vget_low_s8(c_vec[k][i]);
            int16x8_t v_vec_s16 = vmovl_s8(l_vec);
            w0_vec = vld1q_s32(&w0->vec[k].coeffs[16*i]);
            z_vec = vsubq_s32(w0_vec, vmovl_s16(vget_low_s16(v_vec_s16)));
            //compute abs and check
            z_vec_abs = vabsq_s32(z_vec);
            //make comparison
            mask_vec = vcgeq_s32(z_vec_abs, bound_vec);
            //compute mask in every data lane
            mask =  vaddvq_u32(mask_vec);
            if(mask != 0)
            {
                return 1;
            }
            vst1q_s32(&z->vec[k].coeffs[16*i], z_vec);
            //后4个
            w0_vec = vld1q_s32(&w0->vec[k].coeffs[16*i+4]);
            z_vec = vsubq_s32(w0_vec, vmovl_s16(vget_high_s16(v_vec_s16)));
            //compute abs and check
            z_vec_abs = vabsq_s32(z_vec);
            //make comparison
            mask_vec = vcgeq_s32(z_vec_abs, bound_vec);
            //compute mask in every data lane
            mask =  vaddvq_u32(mask_vec);
            if(mask != 0)
            {
                return 1;
            }
            vst1q_s32(&z->vec[k].coeffs[16*i+4], z_vec);
            
            l_vec = vget_high_s8(c_vec[k][i]);
            v_vec_s16 = vmovl_s8(l_vec);
            w0_vec = vld1q_s32(&w0->vec[k].coeffs[16*i+8]);
            z_vec = vsubq_s32(w0_vec, vmovl_s16(vget_low_s16(v_vec_s16)));
            //compute abs and check
            z_vec_abs = vabsq_s32(z_vec);
            //make comparison
            mask_vec = vcgeq_s32(z_vec_abs, bound_vec);
            //compute mask in every data lane
            mask =  vaddvq_u32(mask_vec);
            if(mask != 0)
            {
                return 1;
            }
            vst1q_s32(&z->vec[k].coeffs[16*i+8], z_vec);

            w0_vec = vld1q_s32(&w0->vec[k].coeffs[16*i+12]);
            z_vec = vsubq_s32(w0_vec, vmovl_s16(vget_high_s16(v_vec_s16)));
            //compute abs and check
            z_vec_abs = vabsq_s32(z_vec);
            //make comparison
            mask_vec = vcgeq_s32(z_vec_abs, bound_vec);
            //compute mask in every data lane
            mask =  vaddvq_u32(mask_vec);
            if(mask != 0)
            {
                return 1;
            }
            vst1q_s32(&z->vec[k].coeffs[16*i+12], z_vec);
        }
    }
    return 0;
}
