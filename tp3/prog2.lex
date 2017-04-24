%{
    /*Prologue*/
    #include <stdio.h>
    #include <string.h>
    #include "list_symb.h"
    list_symb *liste = NULL;
%}
%option nounput
%option noinput
/*Definitions*/
BLANC [ \t\n]
LETTRE [a-zA-Z]
MOT {LETTRE}+
CHIFFRE [0-9]
NOMBRE {CHIFFRE}+
%%
{MOT} { inserer(yytext, liste);printf("%s\n",yytext);}
{BLANC}
.
%%
int main(int argc, char**argv){
    liste = malloc(sizeof(list_symb));
    liste->count = -1;
    if(argc > 1) yyin = fopen(argv[1], "r");
    else yyin = stdin;
    yylex();
    print_list(liste);
    return 0;
    }
