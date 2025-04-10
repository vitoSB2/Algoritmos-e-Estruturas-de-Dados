#include <stdio.h>
#include "listasEncadeadas.h"

// MAIN
int main(){
    Lista* lista = (Lista*) malloc (sizeof(Lista));
    listaConstrutor(lista);
    int opcao = 0, valor, index;

    while(opcao != 7){
        
        showAll(lista);
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);
            printf("Digite o indice onde o valor sera adicionado: ");
            scanf("%d", &index);
            if(add(lista, index, valor) == 0)
                printf("\nIndice fora dos limites!!\n\n");
            else 
                printf("\nValor adicionado com sucesso\n\n");
            
        } else if(opcao == 2){
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            if(get(lista, valor) == -1)
                printf("\nValor nao encontrado!!\n\n");
            else 
                printf("\n<<O valor esta na posicao %d>>\n\n", get(lista, valor));

        } else if(opcao == 3){
            printf("Digite o indice do numero a ser excluido: ");
            scanf("%d", &index);
            if(removeIndex(lista, index) == 0)
                printf("\nIndice fora dos limites!!\n\n");
            else 
                printf("\nO valor no indice %d foi excluido com sucesso\n\n", index);

        } else if(opcao == 4){
            printf("Digite o numero a ser excluido: ");
            scanf("%d", &valor);
            if(removeValue(lista, valor) == 0)
                printf("Valor nao encontrado!!\n\n");
            else
                printf("O valor %d foi excluido com sucesso\n\n", valor);

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

        } else printf("Finalizando operacoes...\n");
    }
}