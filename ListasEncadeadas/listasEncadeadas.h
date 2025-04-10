#include <stdio.h>


// NODO
typedef struct n{
    int info;
    struct n* prox;
} Nodo;

void nodoConstrutor(int val, Nodo* n){
    n->info = val;
    n->prox = NULL;
}

// LISTA
typedef struct l{
    int tamanho;
    Nodo* cabeca;
} Lista;

void listaConstrutor(Lista* l){
    l->cabeca = NULL;
    l->tamanho = 0;
}

//ADICIONAR ELEMENTO
int add(Lista* l, int index, int val){
    if(index>l->tamanho || index<0 ) return 0;
    Nodo* novo = (Nodo*) malloc (sizeof(Nodo));
    nodoConstrutor(val, novo);
    if(index == 0){
        novo->prox = l->cabeca;
        l->cabeca = novo;
    } else {
        Nodo* temp = l->cabeca;
        for(int i = 0; i!=index-1; i++)
            temp = temp->prox;
        novo->prox = temp->prox;
        temp->prox = novo;
    }
    l->tamanho++;
    return 1;
}

//BUSCAR ELEMENTO
int get(Lista* l, int val){
    Nodo* buscado = l->cabeca;
    for(int i=0; i!=l->tamanho; i++){
        if(buscado->info == val)
            return i;
        buscado = buscado->prox;
    }
    return -1;
}

//REMOVER ELEMENTO POR INDICE
int removeIndex(Lista* l, int index){
    if(index>=l->tamanho || index<0 ) return 0;

    Nodo* removido = l->cabeca;
    if(index == 0)
        l->cabeca = removido->prox;
    else {
        Nodo* anterior = l->cabeca;
        for(int i = 0; i!=index-1; i++)
            anterior = anterior->prox;
        removido = anterior->prox;
        anterior->prox = anterior->prox->prox;
    }
    free(removido);
    l->tamanho--;
    return 1;
}

//REMOVER ELEMENTO POR NUMERO
int removeValue(Lista* l, int val){
    return removeIndex(l, get(l, val));
}

//INSERIR ELEMENTO NA FRENTE
int insertFront(Lista* l, int val){
    return add(l, 0, val);
}

//INSERIR ELEMENTO NO FUNDO
int insertBack(Lista* l, int val){
    return add(l, l->tamanho, val);
}

//MOSTRAR A LISTA
void showList(Lista* l){
    Nodo* representacao;
    representacao = l->cabeca;
    printf("LISTA:\n---------------------------\n");
    for(int i = 0; i < l->tamanho; i++){ 
        printf("%d - ", representacao->info);
        representacao = representacao->prox;
    }
    printf("\n---------------------------\n---------------------------\n");
    printf("Selecione a opcao desejada: \n\n");
    printf("1 - Adicionar elemento\n2 - Buscar elemento\n3 - Remover por indice\n");
    printf("4 - Remover por valor\n5 - Inserir valor na frente\n6 - Inserir valor no fundo\n");
    printf("7 - Sair\n---------------------------\n\n");
}