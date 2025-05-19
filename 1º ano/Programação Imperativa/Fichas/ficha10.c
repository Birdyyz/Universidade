#include <stdio.h>
// "Woohoo I found you, get ready to be deleted"
typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} * ABin;

// casos-> n ter arvore
// ter um filho (direito)
// ser uma folha
void removeMenor(ABin *a) {
    if (*a == NULL) return;

    while ((*a)->esq != NULL) {
        a = &(*a)->esq;
    }

    ABin temp = *a;
    *a = (*a)->dir; 
    free(temp);     
}


void removeRaiz(ABin *a) {
    if (*a == NULL) return;

    ABin temp;

    if ((*a)->esq == NULL) {
        temp = *a;
        *a = (*a)->dir;
        free(temp);
    }
    else if ((*a)->dir == NULL) {
        temp = *a;
        *a = (*a)->esq;
        free(temp);
    }
    else {
        ABin *min = &(*a)->dir;
        while ((*min)->esq != NULL) {
            min = &(*min)->esq;
        }

        (*a)->valor = (*min)->valor;

        temp = *min;
        *min = (*min)->dir;  
        free(temp);
    }
}

int removeElem (ABin *a, int x){
    if(*a == NULL){
        return 1;
    }

    if ((*a)->valor > x){
        return removeElem(&(*a)->esq,x);
    }
    if((*a)->valor < x){
        return removeElem(&(*a)->dir,x);
    }
    if((*a)->valor == x){
        // é uma folha
        if((*a)->dir == NULL && (*a)-> esq == NULL){
            free(*a);
            *a = NULL;
            return 0;
        }
        if((*a)->dir == NULL){
            ABin temp = ((*a)->esq);
            free(*a);
            *a = temp;
            return 0;
        }
        else if((*a)->esq == NULL){
            ABin temp = (*a)->dir;
            free(*a);
            *a = temp;
            return 0; 
        }else{
            ABin temp = (*a)->dir;
            while(temp->esq != NULL){
                temp = temp ->esq;
            }
            (*a) -> valor = temp->valor;
            removeElem(&(*a)->dir, temp->valor);
            return 0;
        }
    }
    return 1;
}