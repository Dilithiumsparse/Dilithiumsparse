make clean
# dilithium2 old
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium2/old bin/crypto_sign_dilithium2_old_test.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium2_old_test.bin 0x8000000
make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium2/old bin/crypto_sign_dilithium2_old_stack.bin
sudo st-flash --reset write bin/crypto_sign_dilithium2_old_stack.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium2/old bin/crypto_sign_dilithium2_old_speed.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium2_old_speed.bin 0x8000000
#dilithium2 new
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium2/new bin/crypto_sign_dilithium2_new_test.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium2_new_test.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium2/new bin/crypto_sign_dilithium2_new_speed.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium2_new_speed.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium2/new bin/crypto_sign_dilithium2_new_stack.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium2_new_stack.bin 0x8000000
#dilithium3 plant
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium3/m4plant bin/crypto_sign_dilithium3_m4plant_test.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium3_m4plant_test.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium3/m4plant bin/crypto_sign_dilithium3_m4plant_speed.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium3_m4plant_speed.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium3/m4plant bin/crypto_sign_dilithium3_m4plant_stack.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium3_m4plant_stack.bin 0x8000000
#dilithium3 new
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium3/new bin/crypto_sign_dilithium3_new_test.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium3_new_test.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium3/new bin/crypto_sign_dilithium3_new_speed.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium3_new_speed.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium3/new bin/crypto_sign_dilithium3_new_stack.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium3_new_stack.bin 0x8000000
#dilithium5 old 
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium5/old bin/crypto_sign_dilithium5_old_speed.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium5_old_speed.bin 0x8000000
#make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium5/old bin/crypto_sign_dilithium5_old_test.bin
#sudo st-flash --reset write bin/crypto_sign_dilithium5_old_test.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium5/old bin/crypto_sign_dilithium5_old_stack.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium5_old_stack.bin 0x8000000
#dilithium5 new
#  make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium5/new bin/crypto_sign_dilithium5_new_test.bin
#  sudo st-flash --reset write bin/crypto_sign_dilithium5_new_test.bin 0x8000000
#   make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium5/new bin/crypto_sign_dilithium5_new_speed.bin
#  sudo st-flash --reset write bin/crypto_sign_dilithium5_new_speed.bin 0x8000000
# make -j 12 IMPLEMENTATION_PATH=crypto_sign/dilithium5/new bin/crypto_sign_dilithium5_new_stack.bin
# sudo st-flash --reset write bin/crypto_sign_dilithium5_new_stack.bin 0x8000000
