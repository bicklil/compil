#include "afnd.h"
#include <string.h>

int alpha(int n)
{
    if (n == 0)
	return '-';
    n--;
    return 'a' + n;
}

int num(char c)
{
  if (c=='-')
    return 0;
  else
    return ((int) (c-'a'+1));
}

void initafnd(afnd * A)
{
    int s, l;
    A->init  = 0ULL;
    A->final = 0ULL;
    for (s = 0; s < 64; s++)
	for (l = 0; l < ALPHA; l++)
	    A->trans[s][l] = 0;
}

void addinit(afnd * A, int s)
{
  A->init  = INT_ETAT(s);
}

void addfinal(afnd * A, int s)
{
  A->final ^= INT_ETAT(s);
}

void addtrans(afnd * A, int s1, int s2, char c)
{
  A->trans[s1][num(c)] ^= INT_ETAT(s2);
}

void printafnd(afnd * A)
{
  int s,l,q;
  for (s=0; s<ETAT; s++){
    printf("\nEtat %d: ",s);
    if (A->init == INT_ETAT(s))
      printf(" init");
    if (IN(s,A->final))
      printf(" final");
    for (l = 0; l < ALPHA; l++){
      for (q=0; q<ETAT; q++){
	if (IN(q, A->trans[s][l]))
	  printf("\n%d -- %c --> %d", s, alpha(l), q);
      }
    }
  }
}

void finitafn(afnd *A, char * f)
{
    FILE* file = fopen(f, "r");
	int dep,arr,test=1;
	char b;
	char etat;
	
	fscanf(file,"%d\n",&dep);
	addinit(A, dep);
	
	while(test)	
	{
		fscanf(file, "%d%c" ,&arr,&b);
		addfinal(A, arr);
		if( b == '\n')
			test = 0;
	}
	
	
	while(fscanf(file,"%d %c %d\n",&dep,&etat,&arr) == 3){
		addtrans(A,dep,arr,etat);
	}
	fclose(file);
}

ullong epsilon(int s,afnd* A)
{
	ullong retour;
	retour = A->trans[s][0];
	return retour;
}

int utile(int s,afnd* A)
{
	int l,q;
	for (l=0;l<ALPHA; l++)
	{	
		if (A->trans[s][l] != 0)
			return 1;
	}
	for (q=0;q<ETAT;q++)
	{
		for (l=0;l<ALPHA;l++)
		{
			if ( q == s)
				{
				break;
				}
			else
				{
				if ( A->trans[q][l] & (1ULL << s))
					return 1;
				}
		}
	}
	return 0;
}

afd* determinisation(afnd *A)
{
	int i,j;
	afd D;
	File** p_file = NULL;
	ullong etat_actu;
	D = calloc(1<<25, sizeof(*afd));
	for(i=0; i<2^25; i++)
		D[i] = calloc(1,sizeof(D[i]);

	for (i=0; i<25; i++)
	{
		if(A->final == INT_ETAT(i))
			for(j=0; j<2^25;j++)
			{
				if((2^i & j) == 2^i):
					D[j].final = 1;
			}
		if(A->initial == INT_ETAT(i))
			file_enqueue(p_file, epsilon(i,A));
	}

	etat_actu = file_dequeue(p_file);
	while(etat_actu != -1)
	{
		if (test_afd(D, etat_actu))
		{
			marque_afd(D, etat_actu);
			ajout_file(p_file, etat_actu, A);
		}
		etat_actu = file_dequeue(p_file);
	}
}

void file_enqueue(File **p_file, ullong donnee)
{
	File *p_nouveau = malloc(sizeof *p_nouveau);
	if (p_nouveau != NULL)
    {
        p_nouveau->suivant = NULL;
        p_nouveau->donnee = donnee;
        if (*p_file == NULL)
        {
            *p_file = p_nouveau;
        }
        else
        {
            File *p_tmp = *p_file;
            while (p_tmp->suivant != NULL)
            {
                p_tmp = p_tmp->suivant;
            }
            p_tmp->suivant = p_nouveau;
        }
    }
}

ullong file_dequeue(File **p_file)
{

    ullong ret = -1;

    /* On teste si la file n'est pas vide. */

    if (*p_file != NULL)

    {

        /* Création d'un élément temporaire pointant vers le deuxième élément de la file. */

        File *p_tmp = (*p_file)->suivant;

        /* Valeur à retourner */

        ret = (*p_file)->donnee;

        /* Effacement du premier élément. */

        free(*p_file), *p_file = NULL;

        /* On fait pointer la file vers le deuxième élément. */

        *p_file = p_tmp;

    }

    return ret;

}

int test_afd(afd D, ullong etat)
{
	
}
