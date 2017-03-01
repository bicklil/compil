#ifndef AFND_H
#define AFND_H

#include <stdlib.h>
#include <stdio.h>

#define ALPHA 27
#define ETAT  64

#define INT_ETAT(s) (1ULL<< (s))
#define IN(s,X) ((INT_ETAT(s) & X ) > 0)


typedef unsigned long long int ullong;
typedef struct {
	ullong init, final;
        ullong trans[ETAT][ALPHA];  // q -l-> trans[q][l]
} afnd;

int alpha(int n);
void initafnd(afnd * A);
void addinit(afnd * A, int s);
void addfinal(afnd * A, int s);
void addtrans(afnd * A, int s1, int s2, char c);
void printafnd(afnd * A);
void finitafn(afnd *A, char * f);
ullong epsilon(int s, afnd* A);
int utile(int s, afnd *A);
#endif
