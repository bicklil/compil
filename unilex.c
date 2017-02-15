# include <regex.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct{
  regex_t regex;
  char nom[32];
}unilex_t;

unilex_t* creer_unilex_table()
{
  regex_t regex ;
  regmatch_t pmatch[1];
  int i;
  char line[256];
  char tempo[256];

  int cpt = 0,nb =0;
  FILE* file= fopen("spec.txt","r");
  while (fgets(line, sizeof(line), file))
  {
    cpt++;
  }
  rewind(file);
  unilex_t* tab = malloc(cpt*sizeof(unilex_t));
  while (fgets(line, sizeof(line), file))
  {
    i=1;
    strcat(tempo,"\"");
    while(strcmp("\"",&line[i]) != 0)
    {
      sprintf(tempo,"%s%s",tempo,&line[i]);
      i++;
    }
    i++;
    sprintf(tempo,"%s%s",tempo,&line[i]);
    if (regcomp(&(tab[nb].regex),tempo,REG_EXTENDED) !=0)
      exit(1);
    memset(tempo,0,sizeof(tempo));
    nb++;
  }
}

int main ( int argc , char * argv[])
{
  creer_unilex_table();
  return 0;
}
