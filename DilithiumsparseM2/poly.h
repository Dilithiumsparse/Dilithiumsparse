#ifndef POLY_H
#define POLY_H

/*
 * This file is dual licensed
 * under Apache 2.0 (https://www.apache.org/licenses/LICENSE-2.0.html)
 * or public domain at https://github.com/pq-crystals/dilithium
 */

#include "params.h"
#include <stdint.h>

typedef struct {
    int32_t coeffs[N];
} poly;
typedef struct {
    int16_t coeffs[N];
} smallpoly;
typedef struct {
    int8_t coeffs[N];
} smallpoly2;
void poly_reduce(poly *a);
void poly_caddq(poly *a);
void poly_freeze(poly *a);

void poly_add(poly *c, const poly *a, const poly *b);
void poly_sub(poly *c, const poly *a, const poly *b);
void poly_shiftl(poly *a);

void poly_ntt(poly *a);
void poly_invntt_tomont(poly *a);
void poly_pointwise_montgomery(poly *c, const poly *a, const poly *b);

void poly_power2round(poly *a1, poly *a0, const poly *a);
void poly_decompose(poly *a1, poly *a0, const poly *a);
unsigned int poly_make_hint(poly *h, const poly *a0, const poly *a1);
void poly_use_hint(poly *b, const poly *a, const poly *h);

int poly_chknorm(const poly *a, int32_t B);
void poly_uniform(poly *a,
                  const uint8_t seed[SEEDBYTES],
                  uint16_t nonce);
void poly_uniformx2(poly *a0, poly *a1,
                    const uint8_t seed[SEEDBYTES],
                    uint16_t nonce0, uint16_t nonce1);
void poly_uniform_eta(poly *a,
                      const uint8_t seed[CRHBYTES],
                      uint16_t nonce);
void poly_uniform_etax2(poly *a0, poly *a1,
                        const uint8_t seed[CRHBYTES],
                        uint16_t nonce0, uint16_t nonce1);
void poly_uniform_gamma1(poly *a,
                         const uint8_t seed[CRHBYTES],
                         uint16_t nonce);
void poly_uniform_gamma1x2(poly *a0, poly *a1,
                           const uint8_t seed[CRHBYTES],
                           uint16_t nonce0, uint16_t nonce1);
void poly_challenge(poly *c, const uint8_t seed[SEEDBYTES]);

void polyeta_pack(uint8_t *r, const poly *a);
void polyeta_unpack(poly *r, const uint8_t *a);

void polyt1_pack(uint8_t *r, const poly *a);
void polyt1_unpack(poly *r, const uint8_t *a);

void polyt0_pack(uint8_t *r, const poly *a);
void polyt0_unpack(poly *r, const uint8_t *a);

void polyz_pack(uint8_t *r, const poly *a);
void polyz_unpack(poly *r, const uint8_t *a);

void polyw1_pack(uint8_t *r, const poly *a);
void poly_encode(uint8_t index[TAU+1], const poly c);
void smallpolyeta_unpack(int16_t r[N], const uint8_t *a);
void smallpoly2eta_unpack(int8_t r[N], const uint8_t *a);
void smallpoly2_challenge(smallpoly2 *c, const uint8_t seed[SEEDBYTES]);
void smallpoly_challenge(smallpoly *c, const uint8_t seed[SEEDBYTES]);
void polysmallbig_add(poly *c, const int16_t a[N], const poly *b);
void polysmallbig_sub(poly *c, const poly *a, const int16_t b[N]);
void polysmallbig2_add(poly *c, const int8_t a[N], const poly *b);
void polysmallbig2_sub(poly *c, const poly *b, const int8_t a[N]);
#endif
