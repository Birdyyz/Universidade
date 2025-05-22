#include <stdio.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

LInt reverseL (LInt l){
    if(l == NULL){ 
        return l;
    }
    LInt anterior = NULL;
    LInt atual = l;
    while(atual != NULL){
        LInt proximo = atual ->prox;
        atual -> prox = anterior;
        anterior = atual;
        atual = proximo;
    }    
    return anterior;
}

int removeOneOrd(LInt *l, int x) {
    while (*l != NULL && (*l)->valor != x) {
        l = &(*l)->prox;
    }

    if (*l == NULL) {
        return 1; 
    }

    LInt temp = *l;        
    *l = (*l)->prox;       
    free(temp);           

    return 0; 
}

int removeMaiorL (LInt *l){
    int remover = (*l) -> valor;
    LInt temp = *l;
    while(temp != NULL){
        if(temp->valor > remover){
            remover = temp->valor;
        }
        temp = temp -> prox;
    }
    while(*l != NULL && (*l)->valor != remover){
        l = &(*l)->prox;
    }
    if(*l != NULL){
        LInt apagar = *l;
        *l = (*l) -> prox;
        free(apagar);
    }
    return remover;
} 