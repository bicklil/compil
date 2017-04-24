#ifndef AFND_H
#define AFND_H

#include <stdlib.h>
#include <stdio.h>

#define ALPHA 27
#define ETAT  19

#define INT_ETAT(s) (1ULL<< (s))
#define IN(s,X) ((INT_ETAT(s) & X ) > 0)


typedef unsigned long long int ullong;
typedef struct {
    ullong init, final;
    ullong trans[ETAT][ALPHA];  // q -l-> trans[q][l]
} afnd;

typedef struct etat{
    int mark;
    int final;
    ullong *trans[27];
    } etat;

typedef struct etat * afd;

typedef struct file
{
    ullong donnee;
    struct file *suivant;
} File;

void file_enqueue(File **p_file, ullong donnee);
ullong file_dequeue(File **p_file);
int alpha(int n);
void initafnd(afnd * A);
void addinit(afnd * A, int s);
void addfinal(afnd * A, int s);
void addtrans(afnd * A, int s1, int s2, char c);
void printafnd(afnd * A);
void finitafn(afnd *A, char *f);
ullong epsilon(int s, afnd *A);
int utile(int s, afnd *A);
afd determinisation(afnd *A);

#endif
