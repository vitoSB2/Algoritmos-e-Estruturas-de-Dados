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
        if(buscado->info == val){
            return i;
        }
        buscado = buscado->prox;
    }
    return -1;
}

//REMOVER ELEMENTO POR INDICE
int removeIndex(Lista* l, int index){
    if(index>=l->tamanho || index<0 ) return 0;

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

    printf("foi");

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

void showList(Lista* l){
    Nodo* representacao;
    representacao = l->cabeca;
        printf("LISTA:\n---------------------------\n");
        for(int i = 0; i < l->tamanho; i++){
            printf("%d - ", representacao->info);
            representacao = representacao->prox;
        }
        printf("\n---------------------------\n");
}

// MAIN
int main(){
    Lista* lista = (Lista*) malloc (sizeof(Lista));
    listaConstrutor(lista);
    int opcao = 0, valor, index;
    

    while(opcao != 7){

        showList(lista);

        printf("---------------------------\nSelecione a opcao desejada: \n1 - Adicionar elemento");
        printf("\n2 - Buscar elemento\n3 - Remover por indice\n4 - Remover por valor\n5 - Inserir valor na frente");
        printf("\n6 - Inserir valor no fundo\n7 - Sair\n---------------------------\n\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);
            printf("Digite o indice onde o valor sera adicionado: ");
            scanf("%d", &index);

            if(add(lista, index, valor) == 0)
                printf("\nIndice fora dos limites\n\n");
            else 
                printf("\nValor adicionado com sucesso\n\n");
            
        } else if(opcao == 2){
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);

            if(get(lista, valor) == -1)
                printf("\nValor nao encontrado\n\n");
            else 
                printf("\n{O valor esta na posicao %d}\n\n", get(lista, valor));
            
        } else if(opcao == 3){
            printf("Digite o indice do numero a ser excluido: ");
            scanf("%d", &index);

            if(removeIndex(lista, index) == 0)
                printf("\nIndice fora dos limites\n\n");
            else 
                printf("\nO valor no indice %d foi excluido com sucesso\n\n", index);

        } else if(opcao == 4){
            printf("Digite o numero a ser excluido: ");
            scanf("%d", &valor);

            if(removeValue(lista, valor) == 0){
                printf("Valor nao encontrado\n\n");
            } else {
                printf("O valor %d foi excluido com sucesso\n\n", valor);
            }
        } else if(opcao == 5){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);

            insertFront(lista, valor);
            printf("\nValor adicionado com sucesso\n\n");
        } else if(opcao == 6){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);

            insertBack(lista, valor);
            printf("\nValor adicionado com sucesso\n\n");
        }
    }
}