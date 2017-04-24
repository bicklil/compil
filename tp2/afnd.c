#include "afnd.h"
#include<string.h>

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
    for (s = 0; s < 25; s++)
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
    if (utile(s, A)){
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
}

void finitafn(afnd *A, char *f){
    FILE * fic = fopen(f, "r");
    int state1, state2, test = 1;
    char a;
    //char line[256], *mot;

    fscanf(fic, "%d\n", &state1);
    addinit(A, state1);

    while(test){
        fscanf(fic, "%d%c", &state1, &a);
        addfinal(A, state1);
        if ( a == '\n') test = 0;
        }

    while ( fscanf(fic, "%d %c %d\n", &state1, &a, &state2) == 3 ){
        addtrans(A, state1, state2, a);
        }

    fclose(fic);
    }


ullong epsilon(int s, afnd *A){
    ullong e_ferm;
    e_ferm = A->trans[s][0];
    e_ferm |= 1<<s;
    return e_ferm;
    }


int utile(int s, afnd *A){
    int l, q;
    for(l=0; l<ALPHA; l++){
        if (A->trans[s][l] != 0){
            return 1;
            }
        }
    for (q=0; q<ETAT; q++){
        for (l=0; l<ALPHA; l++){
            if (q==s) break;
            else if (A->trans[q][l] & (1ULL << s)) return 1;
            }
        }
    return 0;
    }


afd determinisation(afnd *A){
    ullong x, X;
    int s, c;
    afd D;
    D = calloc(1<<19, sizeof(etat));

    File* f=NULL;
    //f = malloc(sizeof(File));
    ullong init;
    init = epsilon(0, A);
    file_enqueue(&f, init);
    //Code prof
    x = file_dequeue(&f);
    D[x].mark = 1;
    while(x != -1){
        for(c=1; c<ALPHA; c++){
            X = 0;
            for(s=0; s<19; s++){
                if (IN(s,x)) X |= epsilon(A->trans[s][c], A);
                D[x].trans[c] = X;
                if (D[X].mark == 0) file_enqueue(&f, X);
                else
                printf("%lld\n",X);
                }
            }
        x = file_dequeue(&f);
        D[x].mark = 1;
        }
    return D;
    }


void file_enqueue(File **p_file, ullong donnee){
    File *p_nouveau = malloc(sizeof *p_nouveau);
    if (p_nouveau != NULL){
        p_nouveau->suivant = NULL;
        p_nouveau->donnee = donnee;
        if (*p_file == NULL) *p_file = p_nouveau;
        else{
            File *p_tmp = *p_file;
            while (p_tmp->suivant != NULL){
                p_tmp = p_tmp->suivant;
                }
            p_tmp->suivant = p_nouveau;
            }
        }
    }



ullong file_dequeue(File **p_file){
    ullong ret = -1;
    if(*p_file != NULL){
        File *p_tmp = (*p_file)->suivant;
        ret = (*p_file)->donnee;
        free(*p_file), *p_file = NULL;
        *p_file = p_tmp;
        }
    return ret;
    }
