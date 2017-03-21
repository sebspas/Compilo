all: lex yacc
	gcc lex.yy.c y.tab.c -ll -o interpretor

lex: interpretor.l
	flex interpretor.l

yacc: interpretor.y 
	yacc -dv interpretor.y

clean:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm interpretor
