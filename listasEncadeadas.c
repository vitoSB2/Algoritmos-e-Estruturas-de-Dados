#include <stdio.h>

// NODO
typedef struct n{
    int info;
    struct n* prox;
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

//ADICIONAR ELEMENTO
int Add(Lista* l, int index, int val){
    if(index>l->tamanho || index<0 ) return 0;

    Nodo* novo = (Nodo*) malloc (sizeof(Nodo));
    NodoConstrutor(val, novo);
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
int Get(Lista* l, int val){
    Nodo* buscado = l->cabeca;
    for(int i=0; i!=l->tamanho; i++){
        if(buscado->info == val){
            return i;
        }
        buscado = buscado->prox;
    }
    return -1;
}

//REMOVER ELEMENTO POR INDICE
int RemoveIndex(Lista* l, int index){
    if(index>l->tamanho || index<0 ) return 0;

    Nodo* removido = l->cabeca;
    if(index == 0){
        l->cabeca = removido->prox;
        free(removido);
    } else {
        Nodo* anterior = l->cabeca;
        for(int i = 0; i!=index-1; i++)
            anterior = anterior->prox;
        
        removido = anterior->prox;
        anterior->prox = removido->prox;
        free(removido);
    }

    l->tamanho--;
    return 1;
}

//REMOVER ELEMENTO POR NUMERO
int RemoveValue(Lista* l, int val){
    Nodo* removido = l->cabeca;
    int index = -1;

    for(int i=0; i!=l->tamanho; i++){
        if(removido->info == val){
            index = i;
            break;
        }
        removido = removido->prox;
    }

    if(index == -1) return 0;
    
    if(index == 0){
        l->cabeca = removido->prox;
        free(removido);
    } else {
        Nodo* anterior = l->cabeca;
        for(int i = 0; i!=index-1; i++)
            anterior = anterior->prox;
        
        removido = anterior->prox;
        anterior->prox = removido->prox;
        free(removido);
    }

    l->tamanho--;
    return 1;
}

// MAIN
int main(){
    Lista* lista = (Lista*) malloc (sizeof(Lista));
    ListaConstrutor(lista);
    int opcao = 0, valor, index;
    Nodo* representacao;

    while(opcao != 5){

        representacao = lista->cabeca;
        printf("MATRIZ:\n---------------------------\n");
        for(int i = 0; i < lista->tamanho; i++){
            printf("%d - ", representacao->info);
            representacao = representacao->prox;
        }
        printf("\n---------------------------\n\n");

        printf("---------------------------\nSelecione a opcao desejada: \n1 - Adicionar elemento\n2 - Buscar elemento\n3 - Remover por indice\n4 - Remover por valor\n5 - Sair\n---------------------------\n\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);
            printf("Digite o indice onde o valor sera adicionado: ");
            scanf("%d", &index);

            if(Add(lista, index, valor) == 0)
                printf("\nIndice fora dos limites\n\n");
            else 
                printf("\nValor adicionado com sucesso\n\n");
            
        } else if(opcao == 2){
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);

            if(Get(lista, valor) == -1)
                printf("\nValor nao encontrado\n\n");
            else 
                printf("\n{O valor esta na posicao %d}\n\n", Get(lista, valor));
            
        } else if(opcao == 3){
            printf("Digite o indice do numero a ser excluido: ");
            scanf("%d", &index);

            if(RemoveIndex(lista, index) == 0)
                printf("\nIndice fora dos limites\n\n");
            else 
                printf("\nO valor no indice %d foi excluido com sucesso\n\n", index);

        } else if (opcao == 4){
            printf("Digite o numero a ser excluido: ");
            scanf("%d", &valor);

            if(RemoveValue(lista, valor) == 0){
                printf("Valor nao encontrado\n\n");
            } else {
                printf("O valor %d foi excluido com sucesso\n\n", valor);
            }
        }
    }
}