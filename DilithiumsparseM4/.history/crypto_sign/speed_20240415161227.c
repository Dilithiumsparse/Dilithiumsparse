#include "api.h"
#include "hal.h"
#include "sendfn.h"
#include "poly.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "smallpoly.h"
#include "smallntt.h"
#define MLEN 59

#define printcycles(S, U) send_unsignedll((S), (U))
void test_scheme()
{
  unsigned char sk[CRYPTO_SECRETKEYBYTES];
  unsigned char pk[CRYPTO_PUBLICKEYBYTES];
  unsigned char sm[MLEN+CRYPTO_BYTES];
  size_t smlen;
  unsigned long long t0, t1;
  int i;
  unsigned long long kpt = 0, signt = 0, verifyt = 0;

  hal_setup(CLOCK_BENCHMARK);
  for(i = 0; i < 2; i++){
        hal_send_str("==========================");
    }

    for (i = 0; i < CRYPTO_ITERATIONS; i++)
    {
      // Key-pair generation
      t0 = hal_get_time();
      crypto_sign_keypair(pk, sk);
      t1 = hal_get_time();
      // printcycles("keypair cycles:", t1 - t0);
      kpt += (t1-t0);
      // Signing
      t0 = hal_get_time();
      crypto_sign(sm, &smlen, sm, MLEN, sk);
      t1 = hal_get_time();
      // printcycles("sign cycles:", t1 - t0);
      signt += (t1-t0);
      // Verification
      t0 = hal_get_time();
      crypto_sign_open(sm, &smlen, sm, smlen, pk);
      t1 = hal_get_time();
      // printcycles("verify cycles:", t1 - t0);
      verifyt += (t1-t0);
      // hal_send_str("#");
  }
  printcycles("keypair cycles:", (kpt)/CRYPTO_ITERATIONS);
  printcycles("sign cycles:", (signt)/CRYPTO_ITERATIONS);
  printcycles("verify cycles:", (verifyt)/CRYPTO_ITERATIONS);
  hal_send_str("#");
  while(1);
  while(1);
  return 0;
}
void test_sparse_new()
{
  poly s1;
  uint8_t rho[32];
  int8_t s1_sparse[2*N] = {0};
  smallpoly s1_prime;
  smallpoly cp_small;
  smallhalfpoly cp_small_prime;
  poly z;
  int i, j;
  int8_t cs[N] = {0};
  poly_uniform_eta(&s1, rho, 0);
  for(i = 0; i < N; i ++)
  {
    s1_sparse[i] = s1.coeffs[i];
    s1_prime.coeffs[i] = s1.coeffs[i];
  }
  poly cp;
  poly_challenge(&cp, rho);
   //encode cp
  uint8_t pos_neg_list[TAU+1];
  int pos_ptr = 1, neg_ptr = TAU;
  unsigned long long t0, t1;
  unsigned long long spt = 0, spt2 = 0;

  hal_setup(CLOCK_BENCHMARK);
  for(i = 0; i < 2; i++){
        hal_send_str("==========================");
  }
  for(j = 0; j < N; j ++)
  {
    if(cp.coeffs[j]==1)
    {
      pos_neg_list[pos_ptr++] = j;
    }
    if(cp.coeffs[j]==-1)
    {
      pos_neg_list[neg_ptr--] = j;
    }
  }
  for (i = 0; i < CRYPTO_ITERATIONS; i++)
  {
    t0 = hal_get_time();
    pos_neg_list[0] = pos_ptr-1;
    prepare_table_asm(s1_sparse);
    sparse_polymul(cs, pos_neg_list, s1_sparse);
    t1 = hal_get_time();
    spt += (t1-t0);

    t0 = hal_get_time();
    small_ntt(s1_prime.coeffs);
    poly_small_ntt_precomp(&cp_small, &cp_small_prime, &cp);
    poly_small_basemul_invntt(&z, &cp_small, &cp_small_prime, &s1_prime);
    t1 = hal_get_time();
    spt2 += (t1-t0);
    }
     
    printcycles("sparse mult cycles:", (spt)/CRYPTO_ITERATIONS);
    printcycles("small ntt cycles:", (spt2)/CRYPTO_ITERATIONS);
    hal_send_str("#");
    while(1);
    while(1);
}
// void test_smallpoly_old()
// {
//   poly s1;
//   uint8_t rho[32];
//   smallpoly s1_prime;
//   smallpoly cp_small;
//   smallpoly cp_small_prime;
//   poly z;
//   int i;
//   poly_uniform_eta(&s1, rho, 0);
//   for(i = 0; i < N; i ++)
//   {
//     s1_prime.coeffs[i] = s1.coeffs[i];
//   }
//   poly cp;
//   poly_challenge(&cp, rho);
//   unsigned long long t0, t1;
//   unsigned long long spt2 = 0;

//   hal_setup(CLOCK_BENCHMARK);
//   for(i = 0; i < 2; i++){
//         hal_send_str("==========================");
//   }
//   for (i = 0; i < CRYPTO_ITERATIONS; i++)
//   {
    
//     t0 = hal_get_time();
//     small_ntt(s1_prime.coeffs);
//     poly_small_ntt_precomp(&cp_small, &cp_small_prime, &cp);
//     poly_small_basemul_invntt(&z, &cp_small, &cp_small_prime, &s1_prime);
//     t1 = hal_get_time();
//     spt2 += (t1-t0);
//   }
//     printcycles("small ntt cycles:", (spt2)/CRYPTO_ITERATIONS);
//     hal_send_str("#");
//     while(1);
//     while(1);

// }
int main(void)
{
  test_scheme();
  // test_sparse_new();
  // test_smallpoly_old();

}
