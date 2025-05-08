#include<stdio.h>

#define MAX 5

struct Fila{
    int ultimo;
    int elementos[MAX];
}; typedef struct Fila Fila;

// CONSTRUTOR DA PILHA
void initFila(Fila *f){
    f->ultimo = -1;
}

// INSERÇÃO RESTRITA
int enqueue(Fila *f, int val){
    if(f->ultimo == MAX-1) return 1;
    f->ultimo++;
    f->elementos[f->ultimo] = val;
    return 0;
}

// REMOÇÃO RESTRITA
int dequeue(Fila *f){
    if(f->ultimo == -1) return 1;
    for(int i = 0; i != f->ultimo; i++)
        f->elementos[i] = f->elementos[i+1];
    f->ultimo--;
    return 0;
}

int main(){
    Fila fila;
    initFila(&fila);
    int opcao, val;

    printf("FILA (FILO)\n\n");
    while(opcao != 3){
        printf("MATRIZ:\n---------------------------\n");
        for(int i = 0; i <= fila.ultimo; i++){
            printf("%d - ", fila.elementos[i]);
        }
        printf("\n---------------------------\n\n");

        printf("---------------------------\nSelecione a opcao desejada: \n1 - (ENQUEUE) Adicionar proximo elemento\n2 - (DEQUEUE) Remover elemento da frente\n3 - Sair\n---------------------------\n\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &val);

            if(enqueue(&fila, val) == 0)
                printf("O valor foi adicionado com sucesso!\n\n");
            else 
                printf("A Pilha atingiu o seu limite!\n\n");
        }else if(opcao == 2){
            if(dequeue(&fila) == 0)
                printf("O topo foi removido com sucesso!\n\n");
            else 
                printf("A Pilha esta vazia!\n\n");
        }else
            printf("Finalizando as operacoes...");
    }
}