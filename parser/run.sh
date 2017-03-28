#!/bash
make
./parser < test_error.c > asm.txt
cd ../interpretor
make
./interpretor < ../parser/asm.txt
