# include <regex.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct{
  regex_t regex;
  char nom[32];
}unilex_t;

unilex_t* creer_unliex_table()
{
  regex_t regex ;
  regmatch_t pmatch[1];
  int i;
  char* line;
  FILE* file= fopen("spec.txt","r");
  while (fgets(line, sizeof(line), file))
  {
    if (regcomp(&regex,"\"*\"",REG_EXTENDED) != 0)
		return 1;
	if (regexec(&regex, line, 1,pmatch,0) == 0)
		{
			for(i=pmatch[0].rm_so;i<pmatch[0].rm_eo;i++)

		}
  }
}

int main ( int argc , char * argv[])
{

}
