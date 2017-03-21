#!/bash
make
./parser < text.c > asm.txt
cd ../interpretor
make
./interpretor < ../parser/asm.txt
