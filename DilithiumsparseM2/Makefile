CC ?= /usr/bin/cc
CFLAGS += -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wredundant-decls \
          -Wshadow -Wpointer-arith -fomit-frame-pointer -mtune=native -O3
NISTFLAGS += -Wno-unused-result -mpopcnt -maes \
             -mtune=native -fomit-frame-pointer -O3
RM = /bin/rm

ASM = __asm_NTT.S __asm_iNTT.S __asm_poly.S feat.S
SOURCES = sign.c ntt.c packing.c poly.c polyvec.c reduce.c rounding.c randombytes.c mult.c m1cycles.c 
SOURCESKECCAK = $(SOURCES) fips202.c fips202x2.c symmetric-shake.c 
HEADERS = params.h sign.h ntt.h packing.h poly.h polyvec.h reduce.h rounding.h randombytes.h mult.h m1cycles.h  
HEADERSKECCAK = $(HEADERS) fips202.h fips202x2.h symmetric.h macros.i macros_common.i

all: test speed

test: dilithium_test2 dilithium_test3 dilithium_test5 

speed: dilithium_speed2 dilithium_speed3 dilithium_speed5


dilithium_test2: $(ASM) $(SOURCESKECCAK) $(HEADERSKECCAK) dilithium_test.c
	$(CC) $(CFLAGS) -DDILITHIUM_MODE=2 $(ASM) $(SOURCESKECCAK) dilithium_test.c -o dilithium_test2
dilithium_test3: $(ASM) $(SOURCESKECCAK) $(HEADERSKECCAK) dilithium_test.c
	$(CC) $(CFLAGS) -DDILITHIUM_MODE=3 $(ASM) $(SOURCESKECCAK) dilithium_test.c -o dilithium_test3
dilithium_test5: $(ASM) $(SOURCESKECCAK) $(HEADERSKECCAK) dilithium_test.c
	$(CC) $(CFLAGS) -DDILITHIUM_MODE=5 $(ASM) $(SOURCESKECCAK) dilithium_test.c -o dilithium_test5


dilithium_speed2: $(ASM) $(SOURCESKECCAK) $(HEADERSKECCAK) dilithium_speed.c
	$(CC) $(CFLAGS) -DDILITHIUM_MODE=2 $(ASM) $(SOURCESKECCAK) dilithium_speed.c -o dilithium_speed2
dilithium_speed3: $(ASM) $(SOURCESKECCAK) $(HEADERSKECCAK) dilithium_speed.c
	$(CC) $(CFLAGS) -DDILITHIUM_MODE=3 $(ASM) $(SOURCESKECCAK) dilithium_speed.c -o dilithium_speed3
dilithium_speed5: $(ASM) $(SOURCESKECCAK) $(HEADERSKECCAK) dilithium_speed.c
	$(CC) $(CFLAGS) -DDILITHIUM_MODE=5 $(ASM) $(SOURCESKECCAK) dilithium_speed.c -o dilithium_speed5


.PHONY: clean

clean:
	-$(RM) -rf *.o
	-$(RM) -rf dilithium_test2
	-$(RM) -rf dilithium_speed2
	-$(RM) -rf dilithium_test3
	-$(RM) -rf dilithium_speed3
	-$(RM) -rf dilithium_test5
	-$(RM) -rf dilithium_speed5

