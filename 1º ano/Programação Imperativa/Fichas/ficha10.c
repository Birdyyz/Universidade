#include <stdio.h>
// "Woohoo I found you, get ready to be deleted"
typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} * ABin;

// casos-> n ter arvore
// ter um filho (direito)
// ser uma folha
ABin removeMenor (ABin *a){
    if(*a == NULL){
        return *a;
    }
    // ir para o filho menor 
    while ((*a) -> esq != NULL){
        a = &(*a) -> esq;
    }
    // como agora encontramos o menor vamos apagá-lo da existencia
    // caso de nao ter filho direito
    if(&(*a)->dir == NULL){
        free(*a);
        a = NULL;
        } 
    else{
    // caso de ter filho direito
    struct nodo *temp = *a;
    *a = (*a)->dir;
    free(temp);
    }
    return *a;
}

void removeRaiz (ABin *a){
    if(*a == NULL){
        return;
    }
    // procurar o menor elemento da arvore direita
    ABin temp;
    if((*a)->esq == NULL){
        temp = *a;
        *a = (*a) -> dir;
        free(temp);
    }
    else if((*a)-> dir == NULL){
        temp = *a;
        *a = (*a) -> esq;
        free(temp);
    }
    else{
        ABin *min = &(*a)-> dir;
        while ((*a)-> esq != NULL){
            a = &(*a) -> esq;
        }
        (*a) -> valor = (*min) -> valor;
        ABin deletar = *min;
        if((*min)-> dir != NULL){
            *min = (*min)->dir;
        }
        else{
            *min = NULL;
        }
        free(deletar);
    }
}