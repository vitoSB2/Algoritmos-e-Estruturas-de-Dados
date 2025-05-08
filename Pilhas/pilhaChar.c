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
    if(p->topo == -1) return 1;

    Pilha pilhaAux;
    initPilha(&pilhaAux);
    char letra; 
    int tam = p->topo+1;

    for(int i=0; i<tam/2; i++){
        top(p, &letra);
        push(&pilhaAux, letra);
        pop(p);
    }

    if((tam)%2 == 1){
        top(p, &letra);
        push(&pilhaAux, letra);
    }

    for(int i=0; i<tam/2; i++)
        if(p->elementos[i] != pilhaAux.elementos[i])
            return 2;

    return 0;
}

int main(){
    Pilha pilha;
    initPilha(&pilha);
    char palavra[MAX];

    printf("PILHA (LIFO)\n\n");

    printf("Escreva a palavra: ");
    scanf("%s", &palavra);

    for(int i=0; palavra[i] != '\0'; i++){
        push(&pilha, palavra[i]);
    }

    printf("MATRIZ:\n---------------------------\n");
    for(int i = 0; i <= pilha.topo; i++)
        printf("%c - ", pilha.elementos[i]);
    printf("\n---------------------------\n\n");

    if(palindromo(&pilha) == 0)
        printf("E um Palindromo!");
    else
        printf("Nao e um Palindromo :(");

}