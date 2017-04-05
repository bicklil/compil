%{
    #include<stdio.h>
    #include<ctype.h>
    int yylex();
    int yyerror(char *msg);
    int yylval;
    int myexp(int, int);
%}
%token NB PLUS FOIS FIN PARO PARF DIVISE SOUSTRACTION ESPACE TAB
%left PLUS
%left FOIS
%start PROG

%%

PROG: EXP FIN { printf("%d", $1 ); return 1;}
EXP   : NB { $$ = $1 ;}
      | EXP PLUS EXP { $$ = $1 + $3 ;}
      | EXP FOIS EXP { $$ = $1 * $3 ;}
      | EXP FOIS FOIS EXP { $$ = myexp($1,$4) ;}
      | EXP DIVISE EXP { $$ = $1 / $3;}
      | EXP SOUSTRACTION EXP { $$ = $1 - $3;}
      | EXP ESPACE {$$ = $1;}
      | ESPACE EXP{$$ = $2;}
      | TAB EXP{$$ = $2;}
      | EXP TAB{$$ = $1;}
      | PARO EXP PARF{$$ = $2;  }
      ;
%%
int main(void){
    yyparse();
    }

int yylex(){
    int car,tempo;
    car = getchar();
    if(car == EOF) return 0;
    if (isdigit(car)){
        tempo = car - '0';
        car = getchar();
        while (isdigit(car))
        {
          tempo = tempo * 10 +(car - '0');
          car = getchar();
        }
        yylval = tempo;
        return NB;
        }
    switch(car){
        case '+': return PLUS;
        case '*': return FOIS;
        case '=': return FIN;
        case '/': return DIVISE;
        case '-': return SOUSTRACTION;
        case ' ': return ESPACE;
        case '\t': return TAB;
        case '(': return PARO;
        case ')': return PARF;
        }
    }
int yyerror(char *msg){
    printf("\n%s\n", msg);
    }

int myexp(int x, int n){
  int i, res = 1;
  for(i=0;i<n;i++) res = res *x;
  return res;
}
