
#ifndef Liste
#define Liste

#include<stdlib.h>
#include<stdio.h>

typedef struct list_symb{
    char *symb;
    int count;
    struct list_symb * suiv;
    } list_symb;

int inserer(char *nom, list_symb *ptr);
void print_list(list_symb *ptr);

#endif
