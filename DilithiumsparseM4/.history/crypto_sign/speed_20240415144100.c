#include "api.h"
#include "hal.h"
#include "sendfn.h"
#include "poly.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>

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
  poly_uniform_eta(&s1, rho, 0);
  poly cp;

}
void test_smallpoly_old()
{

}
int main(void)
{
  test_scheme();

}
