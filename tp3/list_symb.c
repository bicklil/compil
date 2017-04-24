#include"list_symb.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int inserer(char *nom, list_symb *ptr){
    if (ptr->count == -1){
        ptr->symb = malloc(strlen(nom)+1);
        strcpy(nom, ptr->symb);

        ptr->count = 1;
        ptr->suiv = NULL;
        return 1;
        }
    while (ptr->suiv != NULL){
        if (strcmp(nom, ptr->symb) == 0){
            ptr->count +=1;
            return 0;
            }
        else ptr = ptr->suiv;}
    ptr->suiv = malloc(sizeof(list_symb));
    ptr = ptr->suiv;
    ptr->symb = malloc(strlen(nom)+1);
    strcpy(nom, ptr->symb);
    ptr->count = 1;
    ptr->suiv = NULL;
    return 1;

}

void print_list(list_symb *ptr){
    while(ptr->suiv != NULL){
        printf("%s %d\n", ptr->symb, ptr->count);
        ptr = ptr->suiv;
    }
    printf("%s %d\n", ptr->symb, ptr->count);
}
