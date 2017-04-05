hihi: lex.yy.c list_symb.o
	gcc lex.yy.c list_symb.o -lfl -o analex -g

lex.yy.c: prog2.lex
	flex prog2.lex

list_symb.o: list_symb.h list_symb.c
	gcc -c list_symb.c
