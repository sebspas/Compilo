all: lex yacc
	gcc lex.yy.c y.tab.c error.c tabSymb.c tabFunc.c -ll -o parser

lex: parser.l
	flex parser.l

yacc: parser.y 
	yacc -dv parser.y

clean:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm parser
