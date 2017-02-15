# include <regex.h>
# include <stdio.h>
# include <stdlib.h>



int main ( int argc , char * argv[])
{
  regex_t regex ;
  regmatch_t pmatch[1];
  if ( regcomp (&regex, argv[1], REG_EXTENDED )!=0)
    return 1;
  if ( regexec (&regex, argv[2], 1, pmatch, 0)==0)
    {
      printf ( "motif trouve !\n" );
      printf("indice de depart: %d\n",pmatch[0].rm_so );
      printf("indice de fin: %d\n",pmatch[0].rm_eo-1 );
    }
  else
    printf ( "motif non trouve !\n" );
  regfree(&regex);
  return 0;
}
