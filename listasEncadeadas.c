#include <stdio.h>

// NODO
typedef struct n{
    int info;
    Nodo* prox;
} Nodo;

void NodoConstrutor(int val, Nodo* n){
    n->info = val;
    n->prox = NULL;
}

// LISTA
typedef struct l{
    int tamanho;
    Nodo* cabeca;
} Lista;

void ListaConstrutor(Lista* l){
    l->cabeca = NULL;
    l->tamanho = 0;
}

// MAIN
int main(){
    
}