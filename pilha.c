#include<stdio.h>

#define MAX 5

struct Pilha{
    int topo;
    int elementos[MAX];
}; typedef struct Pilha Pilha;

// CONSTRUTOR DA PILHA
void initPilha(Pilha *p){
    p->topo = -1;
}

// INSERÇÃO RESTRITA
int push(Pilha *p, int val){
    if(p->topo == MAX-1) return 1;
    p->topo++;
    p->elementos[p->topo] = val;
    return 0;
}

// REMOÇÃO RESTRITA
int pop(Pilha *p){
    if(p->topo == -1) return 1;
    p->topo--;
    return 0;
}

// BUSCA RESTRITA
int top(Pilha *p, int *resultado){
    if(p->topo == -1) return 1;
    resultado = p->elementos[p->topo];
    return 0;
}

void main(){
    Pilha pilha;
    initPilha(&pilha);
    int opcao, val;

    printf("PILHA (FIFO)\n\n");
    while(opcao != 4){
        printf("MATRIZ:\n---------------------------\n");
        for(int i = 0; i <= pilha.topo; i++){
            printf("%d - ", pilha.elementos[i]);
        }
        printf("\n---------------------------\n\n");

        printf("---------------------------\nSelecione a opcao desejada: \n1 - (PUSH) Adicionar elemento no topo\n2 - (POP) Remover elemento do topo\n3 - (TOP) Buscar elemento do topo\n4 - Sair\n---------------------------\n\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &val);

            if(push(&pilha, val) == 0)
                printf("O valor foi adicionado com sucesso!\n\n");
            else 
                printf("A Pilha atingiu o seu limite!\n\n");

        }else if(opcao == 2){
            if(pop(&pilha) == 0)
                printf("O topo foi removido com sucesso!\n\n");
            else 
                printf("A Pilha esta vazia!\n\n");

        }else if(opcao == 3){
            if(top(&pilha, &val) == 0)
                printf("<<<<< O topo e %d! >>>>>\n\n", val);
            else 
                printf("A Pilha está vazia!\n\n");

        }else
            printf("Finalizando as operacoes...");
    }
}