%{
/*Prologue*/
#include <stdio.h>
#include <string.h>
int longmax = 0, colonemax = 0, colone = 0, lignemax = 0, ligne = 1;
char motlepluslong[256];

%}
%option nounput
%option noinput
/*Definition*/
BLANC [ \t\n]
LETTRE [a-zA-Z]
MOT {LETTRE}+

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
. { colone = colone +1;}
%%
int main(void){
yylex();
printf("\nMot le plus long: %s, de longueur: %d, %d colonne, %d ligne\n", motlepluslong, longmax, colonemax, lignemax);
return 0;
}
