# include <regex.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>



int main ( int argc , char * argv[])
{
  regex_t regex ;
  regmatch_t pmatch[1];
  const char* filename = argv[2];
  int i,test;
  FILE* file = fopen(filename, "r");
  char line[256],souligne[256],tempo[30];
  char* word;
  if ( regcomp (&regex, argv[1], REG_EXTENDED )!=0)
    return 1;

  while (fgets(line, sizeof(line), file)){
    test = 0;
    word = strtok(line, " ");
    strcat(tempo," ");
    while ( word != NULL)
    {
      if ( regexec (&regex, word, 1, pmatch, 0)==0)
      {
          test = 1;
          for(i=0;i<strlen(word);i++)
          {
            if( (i>=pmatch[0].rm_so) && (i<= pmatch[0].rm_eo - 1))
            {
              strcat(tempo,"^");
            }
            else
            {
              strcat(tempo," ");
            }
          }
          strcat(tempo," ");

      }

      else
      {
        for(i=0;i<strlen(word);i++)
          strcat(tempo," ");
      }
      strcat(souligne,tempo);
      memset(tempo, 0,sizeof(tempo));
      printf("%s ", word);
      word = strtok(NULL, " \n");
    }
    if (test)
      printf("\n%s\n",souligne );
    else
      printf("\n");
    memset(souligne, 0,sizeof(souligne));

  }
  regfree(&regex);

  return 0;
}
