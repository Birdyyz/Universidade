#include <stdio.h>

typedef struct lligada {
    int valor;
    struct lligada *prox;
    } *LInt;

int length (LInt l){
    int count = 0;
    while(l != NULL){
        count++;
        l=l->prox;
    }
    return count;
}

void freeL (LInt l){
    while ( l != NULL){
        LInt temp = l-> prox;
        free(l);
        l = temp;
    }
}

void imprimeL (LInt l){
    while(l!=NULL){
        printf("%d \n", l-> valor);
        l = l-> prox;
    }
}