#!/bash
make
./parser < text.c > asm.txt
cd ../interpretor
make
./interpretor < ../parser/asm.txt
cd ../parser
python asm2hex.py > code.hex
