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
    while(l != NULL){
        printf("%d \n", l-> valor);
        l = l-> prox;
    }
}

LInt reverseL (LInt l){
    LInt ant = NULL;
    LInt atual = l;
    while (atual != NULL){
        LInt prox = atual->prox;
        atual -> prox = ant;
        ant = atual;
        atual = prox;
    }
    return ant;
}

void insertOrd(LInt *l, int a) {
    LInt novo = malloc(sizeof(struct lligada));  
    novo->valor = a;
    novo->prox = NULL;
    if (*l == NULL || (*l)->valor >= a) {
        novo->prox = *l;  
        *l = novo;        
    } else {
        LInt temp = *l;
        while (temp->prox != NULL && temp->prox->valor < a) {
            temp = temp->prox;  
        }
        novo->prox = temp->prox;  
        temp->prox = novo;        
    }
}

int removeOneOrd(LInt *l, int a) {
    if (*l == NULL) return 1;
    LInt temp = *l;
    if (temp->valor == a) {
        *l = temp->prox;
        free(temp);
        return 0;
    }
    while (temp->prox != NULL && temp->prox->valor != a) {
        temp = temp->prox;
    }
    if (temp->prox != NULL) {
        LInt proxi = temp->prox;
        temp->prox = proxi->prox;
        free(proxi);
        return 0;
    }
    return 1;
}

void merge (LInt *l, LInt a, LInt b){
    while(a !=NULL || b!=NULL){
        if (a->valor < b-> valor || b == NULL){ //a!=NULL && b !=NULL -> se n colocarmos da segmenation fault 
            *l = a;
            a = a->prox;
        }
        else{
            *l = b;
            b = b->prox;
        }
        l = &((*l)->prox);
    }
    *l = NULL; // ultimo no, sempre null
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l != NULL){
        if(l->valor < x){
            *mx = l;
            mx = &((*mx)->prox);
        }
        else{
            *Mx = l;
            Mx = &((*Mx)->prox);
        }
        l = l->prox;
    }
    *Mx = NULL;
    *mx = NULL;
}