%{
/*Prologue*/
#include <stdio.h>
#include <string.h>
int total = 0,longmax = 0, colonemax = 0, colone = 0, lignemax = 0, ligne = 1;
char motlepluslong[256];

%}
%option nounput
%option noinput
/*Definition*/
BLANC [ \t\n]
LETTRE [a-zA-Z]
MOT {LETTRE}+
CHIFFRE [0-9]
NOMBRE {CHIFFRE}+

%%

{MOT} {
  if (yyleng > longmax){
    longmax = yyleng;
    strcpy(motlepluslong, yytext);
    lignemax = ligne;
    colonemax = colone;
    printf("\n%s",yytext);
    }
  else
    colone = colone + yyleng;
  }
{BLANC} {if( strcmp(yytext,"\n") == 0)
  {
    colone = 1;
    ligne = ligne +1;
  }
  else
  {
    colone = colone + yyleng;
  }
}
{NOMBRE} {total = total + atoi(yytext);}
. { colone = colone +1;}
%%
int main(int argc, char** argv){
  if(argc > 1)
    yyin = fopen(argv[1],"r");
  else
    yyin = stdin;
yylex();
printf("\nMot le plus long: %s, de longueur: %d, %d colonne, %d ligne\n", motlepluslong, longmax, colonemax, lignemax);
printf("\nSomme des entiers: %d\n",total );
return 0;
}
