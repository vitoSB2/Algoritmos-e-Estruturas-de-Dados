#include<stdio.h>

#define MAX 10

struct Pilha{
    int topo;
    char elementos[MAX];
}; typedef struct Pilha Pilha;

// CONSTRUTOR DA PILHA
void initPilha(Pilha *p){
    p->topo = -1;
}

// INSERÇÃO RESTRITA
int push(Pilha *p, char letra){
    if(p->topo == MAX-1) return 1;
    p->topo++;
    p->elementos[p->topo] = letra;
    return 0;
}

// REMOÇÃO RESTRITA
int pop(Pilha *p){
    if(p->topo == -1) return 1;
    p->topo--;
    return 0;
}

// BUSCA RESTRITA
int top(Pilha *p, char *resultado){
    if(p->topo == -1) return 1;
    *resultado = p->elementos[p->topo];
    return 0;
}

int palindromo(Pilha *p){
    int i = 0, j = p->topo;
    while(i < j){
        if(p->elementos[i] != p->elementos[j]) return 1;
        i++;
        j--;
    }
    return 0;
}
int main(){
    Pilha pilha;
    initPilha(&pilha);
    int opcao;
    char letra;

    printf("PILHA (LIFO)\n\n");
    while(opcao != 5){
        printf("MATRIZ:\n---------------------------\n");
        for(int i = 0; i <= pilha.topo; i++){
            printf("%c - ", pilha.elementos[i]);
        }
        printf("\n---------------------------\n\n");

        printf("---------------------------\nSelecione a opcao desejada: \n1 - (PUSH) Adicionar elemento no topo\n2 - (POP) Remover elemento do topo\n3 - (TOP) Buscar elemento do topo\n4 - Descobrir de e um Palindromo\n5 - Sair\n---------------------------\n\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor a ser adicionado: ");
            scanf(" %c", &letra);

            if(push(&pilha, letra) == 0)
                printf("O valor foi adicionado com sucesso!\n\n");
            else 
                printf("A Pilha atingiu o seu limite!\n\n");

        }else if(opcao == 2){
            if(pop(&pilha) == 0)
                printf("O topo foi removido com sucesso!\n\n");
            else 
                printf("A Pilha esta vazia!\n\n");

        }else if(opcao == 3){
            if(top(&pilha, &letra) == 0)
                printf("<<<<< O topo e %c! >>>>>\n\n", letra);
            else 
                printf("A Pilha está vazia!\n\n");

        }else if(opcao == 4){
            if(palindromo(&pilha) == 0)
                printf("A Pilha e um Palindromo!\n\n");
            else 
                printf("A Pilha nao e um Palindromo!\n\n");

        }else
            printf("Finalizando as operacoes...");
    }
}