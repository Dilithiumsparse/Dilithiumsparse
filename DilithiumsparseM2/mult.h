#include <stdio.h>
#include <stdint.h>
#include "params.h"
#include "poly.h"
#include "polyvec.h"
int smallpolyveck_mul_neon_earlycheck(polyveck *z, polyveck *w0, const int8_t a[256], int8_t b[K][256], int32_t B);
int smallpolyvecl_mul_neon_earlycheck(polyvecl *z, polyvecl *y, const int8_t a[256], int8_t b[L][256], int32_t B);
