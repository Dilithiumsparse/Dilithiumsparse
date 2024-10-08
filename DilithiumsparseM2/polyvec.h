#ifndef POLYVEC_H
#define POLYVEC_H

/*
 * This file is dual licensed
 * under Apache 2.0 (https://www.apache.org/licenses/LICENSE-2.0.html)
 * or public domain at https://github.com/pq-crystals/dilithium
 */

#include "params.h"
#include "poly.h"
#include <stdint.h>

/* Vectors of polynomials of length L */
typedef struct {
    poly vec[L];
} polyvecl;
typedef struct {
    smallpoly vec[L];
}smallpolyvecl;
typedef struct {
    smallpoly2 vec[L];
}smallpoly2vecl;
void polyvecl_uniform_eta(polyvecl *v, const uint8_t seed[CRHBYTES], uint16_t nonce);

void polyvecl_uniform_gamma1(polyvecl *v, const uint8_t seed[CRHBYTES], uint16_t nonce);

void polyvecl_reduce(polyvecl *v);

void polyvecl_freeze(polyvecl *v);

void polyvecl_add(polyvecl *w, const polyvecl *u, const polyvecl *v);

void polyvecl_ntt(polyvecl *v);
void polyvecl_invntt_tomont(polyvecl *v);
void polyvecl_pointwise_poly_montgomery(polyvecl *r, const poly *a, const polyvecl *v);
void polyvecl_pointwise_acc_montgomery(poly *w,
                                       const polyvecl *u,
                                       const polyvecl *v);

int polyvecl_chknorm(const polyvecl *v, int32_t B);

/* Vectors of polynomials of length K */
typedef struct {
    poly vec[K];
} polyveck;
typedef struct {
    smallpoly vec[K];
}smallpolyveck;
typedef struct {
    smallpoly2 vec[K];
}smallpoly2veck;
void polyveck_uniform_eta(polyveck *v, const uint8_t seed[CRHBYTES], uint16_t nonce);

void polyveck_reduce(polyveck *v);
void polyveck_caddq(polyveck *v);
void polyveck_freeze(polyveck *v);

void polyveck_add(polyveck *w, const polyveck *u, const polyveck *v);
void polyveck_sub(polyveck *w, const polyveck *u, const polyveck *v);
void polyveck_shiftl(polyveck *v);

void polyveck_ntt(polyveck *v);
void polyveck_invntt_tomont(polyveck *v);
void polyveck_pointwise_poly_montgomery(polyveck *r, const poly *a, const polyveck *v);

int polyveck_chknorm(const polyveck *v, int32_t B);

void polyveck_power2round(polyveck *v1, polyveck *v0, const polyveck *v);
void polyveck_decompose(polyveck *v1, polyveck *v0, const polyveck *v);
unsigned int polyveck_make_hint(polyveck *h,
                                const polyveck *v0,
                                const polyveck *v1);
void polyveck_use_hint(polyveck *w, const polyveck *u, const polyveck *h);

void polyveck_pack_w1(uint8_t r[K * POLYW1_PACKEDBYTES], const polyveck *w1);

void polyvec_matrix_expand(polyvecl mat[K], const uint8_t rho[SEEDBYTES]);

void polyvec_matrix_pointwise_montgomery(polyveck *t, const polyvecl mat[K], const polyvecl *v);
void polyveclsmallbig_add(polyvecl *w, const int16_t u[L][N], const polyvecl *v);
void polyvecksmallbig_sub(polyveck *w, const polyveck *v, const int16_t u[K][N]);
void polyveclsmallbig2_add(polyvecl *w, const int8_t u[L][N], const polyvecl *v);
void polyvecksmallbig2_sub(polyveck *w, const polyveck *v, const int8_t u[K][N]);
#endif
