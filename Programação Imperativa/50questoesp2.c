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
        if (a!=NULL && b !=NULL && a->valor < b-> valor || b == NULL){  
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

int calculalength(LInt l) {
    int count = 0;
    while (l != NULL) {
        count++;
        l = l->prox;
    }
    return count;
}


LInt parteAmeio (LInt *l){
    if (*l == NULL || (*l)->prox == NULL) return NULL;
    LInt ant = NULL;
    LInt agr = *l;
    int length = calculalength(*l);
    int atual = 0;
    int meio = length / 2;
    while (atual < meio && agr!=NULL){
        atual++;
        ant = agr;
        agr = agr -> prox;
    }
    ant -> prox = NULL;
    LInt res = *l;
    *l = agr;
    return res;
}

int removeAll (LInt *l, int x){
    if (*l == NULL) return 0;
    LInt ant = NULL;
    LInt atual = *l;
    int count = 0;
    while (atual != NULL){
        if (atual -> valor == x){
            if (ant == NULL){
                *l = atual -> prox;
            }
            else{
            ant->prox = atual ->prox;
        }
        count++;
        atual = atual -> prox;
    }
        else{
            ant = atual;
            atual = atual -> prox;
        }
    }
    
    return count;
}
// so funciona para 2 testes
int removeDups (LInt *l){
    int count = 0;
    LInt ant = NULL;
    LInt atual = *l;
    while(atual!=NULL){
        if(ant == NULL){
            ant = atual;
            atual = atual->prox;
        }
        else if(atual->valor == ant -> valor){
            ant -> prox = atual ->prox;
            atual = atual ->prox;
            count ++;
        }
        else{
            ant = atual;
            atual = atual ->prox;
        }
    }
    return count;
}

int removeDups(LInt *l) {
    int count = 0;
    LInt atual = *l;
    LInt ant = NULL;
    LInt seg = NULL;

    while (atual != NULL) {
        ant = atual;  
        seg = atual->prox;  

        while (seg != NULL) {
            if (seg->valor == atual->valor) {
                count++;  
                ant->prox = seg->prox;  
                seg = ant->prox;  
            } else {
                ant = seg;
                seg = seg->prox;
            }
        }

        atual = atual->prox;  
    }

    return count;
}

int removeMaiorL(LInt *l) {

    LInt atual = *l;
    LInt ant = NULL;
    LInt maior = *l;
    LInt antmaior = NULL;

    while (atual != NULL) {
        if (atual->valor > maior->valor) {
            maior = atual;
            antmaior = ant;
        }
        ant = atual;
        atual = atual->prox;
    }
    if (antmaior == NULL) {
        *l = maior->prox;
    } else {
        antmaior->prox = maior->prox;
    }
    int valorMaior = maior->valor;
    return valorMaior;
}


void init (LInt *l){
    LInt atual = *l;
    LInt ant = NULL;
    while(atual -> prox != NULL){
        ant = atual;
        atual = atual -> prox;
    }
    if(ant == NULL){
        free(atual);
        *l = NULL;
    }
    else{
        free(atual);
        ant ->prox = NULL;
    }
}

void appendL (LInt *l, int x){
    LInt add = malloc(sizeof(struct lligada));
    add -> valor = x;
    add -> prox = NULL;
    LInt atual = *l;
    if (*l == NULL){
        *l = add;
    }else{
    while(atual ->prox !=NULL){
        atual = atual -> prox;
    }
    atual -> prox = add;
}
}

void concatL (LInt *a, LInt b){
    if (*a == NULL) {
        *a = b;
    }
    else{
    LInt atual = *a;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = b;
    }
}

LInt cloneL (LInt l) {
    if (l == NULL){
         return NULL; 
    }
    LInt novo = malloc(sizeof(struct lligada));
    novo->valor = l->valor;
    LInt head = novo; 
    l = l->prox;

    while (l != NULL) {
        novo->prox = malloc(sizeof(struct lligada));
        novo = novo->prox;
        novo->valor = l->valor;
        l = l->prox;
    }
    novo->prox = NULL;

    return head;
}

LInt cloneRev (LInt l) {
    LInt head = NULL;
    while (l != NULL) {
        LInt novo = malloc(sizeof(struct lligada));
        novo->valor = l->valor;
        novo->prox = head; 
        head = novo;       
        l = l->prox;
    }
    return head;
}

int maximo (LInt l){
    int max = 0;
    while (l !=NULL){
        if (l -> valor > max){
            max = l-> valor;
        }
        l = l->prox;
    }
    return max;
}

int length (LInt l){
    int count = 0;
    while(l != NULL){
        count++;
        l=l->prox;
    }
    return count;
}

int take (int n, LInt *l){
    LInt atual = *l;
    int tamanho = length(*l);
    if (tamanho <= n){
        return tamanho;
    }
    int i;
    for(i = 0; i < n; i++){
        atual = atual -> prox;
    }
    while (atual != NULL) {
        LInt temp = atual->prox;
        free(atual);
        atual = temp;
}

    return n;
}