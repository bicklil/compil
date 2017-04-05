#include <stdio.h>
#include <stdlib.h>

typedef enum {PLUS, FOIS, PARO, PARF, CHIFFRE} TOKEN;

char *next;
int expr();
int expr1();
int terme();
int terme1();
int facteur();
int term(TOKEN);

int expr() {
  char* copie = next;
  if (terme() && expr1())
    return 1;
  next = copie;
  return 0;
}

int expr1(){
  char* copie = next;
  if (term(PLUS) && terme() && expr1())
    return 1;
  next = copie;
  return 1;
}

int terme() {
  char* copie = next;
  if (facteur() && terme1())
    return 1;
  next = copie;
  return 0;
}

int terme1() {
  char* copie = next;
  if (term(FOIS) && facteur() && terme1())
    return 1;
  next = copie;
  return 1;
}

int facteur(){
  char* copie = next;
  if (term(CHIFFRE) )
    return 1;
  next = copie;
  if ( term(PARO) && expr() && term(PARF))
    return 1;
  next = copie;
  return 0;
}

int term(TOKEN tok){
  printf("%c\n",next[0]);
  switch (*next)
  {
    case '+':
      if (tok == PLUS)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '*':
      if (tok == FOIS)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '(':
      if (tok == PARO)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case ')':
      if (tok == PARF)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '0':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '1':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '2':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '3':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '4':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '5':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '6':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '7':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '8':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    case '9':
      if (tok == CHIFFRE)
      {
        next ++;
        return 1;
      }
      return 0;
      break;
    default:
      return 0;
  }
}

int main(int argc, char** argv)
{
  next = argv[1];
  int status = expr();
  if (*next != '\0')
    status = 0;
  printf("%s\n",argv[1]);
  printf("%d\n",status);
  return 0;
}
