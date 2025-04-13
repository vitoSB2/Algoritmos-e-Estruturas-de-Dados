#include <stdio.h>
#include "listasEncadeadas.h"

int main(){
    Lista* lista1 = (Lista*) malloc (sizeof(Lista));
    listaConstrutor(lista1);
    Lista* lista2 = (Lista*) malloc (sizeof(Lista));
    listaConstrutor(lista2);
    int opcao = 0, valor, index;

    while(opcao != 7){
        
        
        showList(lista1, 1);
        printf("Lista tamanho: %d\n\n", countList(lista1 -> cabeca));
        showList(lista2, 2);
        printf("Lista tamanho: %d\n\n", countList(lista2 -> cabeca));
        
        printf("---------------------------\n");
        printf("Selecione a opcao desejada: \n\n");
        printf("1 - Adicionar na Lista1\n2 - Adicionar na Lista2\n3 - Remover na Lista1\n");
        printf("4 - Remover na Lista2\n5 - Concatenar Listas\n6 - Concatenar Listas 2\n");
        printf("7 - Sair\n---------------------------\n\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);
            printf("Digite o indice onde o valor sera adicionado: ");
            scanf("%d", &index);
            if(add(lista1, index, valor) == 0)
                printf("\nIndice fora dos limites!!\n\n");
            else 
                printf("\nValor adicionado com sucesso\n\n");
            
        } else if(opcao == 2){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);
            printf("Digite o indice onde o valor sera adicionado: ");
            scanf("%d", &index);
            if(add(lista2, index, valor) == 0)
                printf("\nIndice fora dos limites!!\n\n");
            else 
                printf("\nValor adicionado com sucesso\n\n");

        } else if(opcao == 3){
            printf("Digite o indice do numero a ser excluido: ");
            scanf("%d", &index);
            if(removeIndex(lista1, index) == 0)
                printf("\nIndice fora dos limites!!\n\n");
            else 
                printf("\nO valor no indice %d foi excluido com sucesso\n\n", index);

        } else if(opcao == 4){
            printf("Digite o indice do numero a ser excluido: ");
            scanf("%d", &index);
            if(removeIndex(lista2, index) == 0)
                printf("\nIndice fora dos limites!!\n\n");
            else 
                printf("\nO valor no indice %d foi excluido com sucesso\n\n", index);

        } else if(opcao == 5){
            printf("\nLISTA CONCATENADA: \n");
            showList(concatenar(lista1, lista2), 0);
            printf("\n\n\n");

            free(lista2);
            lista2 = (Lista*) malloc (sizeof(Lista));
            listaConstrutor(lista2);

        } else if(opcao == 6){
            printf("\nLISTA CONCATENADA: \n");
            Lista* listaConcatenada = concatenar2(lista1, lista2);
            showList(listaConcatenada, 0);
            printf("\n\n\n");

            free(lista1);
            free(lista2);

            lista1 = listaConcatenada;
            lista2 = (Lista*) malloc (sizeof(Lista));
            listaConstrutor(lista2);

        } else printf("Finalizando operacoes...\n");
    }
}