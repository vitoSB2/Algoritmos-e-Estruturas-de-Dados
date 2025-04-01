#include<stdio.h>
#include<stdlib.h>
#define cap 2

struct List{
    int size;
    int capacity;
    int *lista;
};

void duplicarTam (struct List *l){
    int *nova = (int*)malloc(sizeof(int) * (l->capacity * 2));

    for(int i = 0; i < l->size; i++){
        nova[i] = l->lista[i];
    }

    free(l->lista);

    l->lista = nova;
    l->capacity = l->capacity*2;
}

int add(int v, int index, struct List *l){
    if(index > l->size || index < 0 ) return -1;
    if(l->size == l->capacity) duplicarTam(l);

    if(l->lista[index] != -1){
        for(int i = l->size; i > index; i--){
            l->lista[i] = l->lista[i-1];
        }
    }
    
    l->lista[index] = v;
    l->size++;
    return 0;
}

int get(int v, struct List *l){

    for(int i = 0; i < l->size; i++){
        if(l->lista[i] == v){
            return i;
        }
    }
    return -1;
}

int removeIndex(int index, struct List *l){
    if(index < 0 || index >= l->size-1) return -1;

    for(int i = index; i < (l->size - 1); i++){
        l->lista[i] = l->lista[i+1];
    }

    l->size--;
    return 0;
}

int removeValue(int v, struct List *l){
    int index = get(v, l);
    if(index == -1) return -1;

    for(int i = index; i < (l->size - 1); i++){
        l->lista[i] = l->lista[i+1];
    }

    l->size--;
    return 0;
}

int inverter(struct List *l){

    for(int i=0; i < (l->size)/2; i++){
        int temp = l->lista[i];
        l->lista[i] = l->lista[l->size - i - 1];
        l->lista[l->size - i - 1] = temp;
    }
}

void main(){
    struct List l;
    l.lista = (int*)malloc(sizeof(int) * (cap));
    l.size = 0;
    l.capacity = cap;
    int opcao = 0, valor, index;

    while(opcao != 6){

        for(int i = 0; i < l.size; i++){
            printf("%d ", l.lista[i]);
        }
        printf("\n\n");

        printf("Selecione a opcao desejada: \n1 - Adicionar elemento\n2 - Buscar elemento\n3 - Remover por indice\n4 - Remover por valor\n5 - Inverter\n6 - Sair\n\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            printf("Digite o valor a ser adicionado: ");
            scanf("%d", &valor);
            printf("Digite o indice onde o valor sera adicionado: ");
            scanf("%d", &index);

            if(add(valor, index, &l) == -1){
                printf("Erro ao adicionar valor\n\n");
            } else {
                printf("Valor adicionado com sucesso\n\n");
            }

        } else if(opcao == 2){
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);

            if(get(valor, &l) == -1){
                printf("Valor nao encontrado\n\n");
            } else {
                printf("O valor esta na posicao %d\n\n", get(valor, &l));
            }
        } else if(opcao == 3){
            printf("Digite o indice do numero a ser excluido: ");
            scanf("%d", &valor);

            if(removeIndex(valor, &l) == -1){
                printf("Erro ao excluir valor\n\n");
            } else {
                printf("O valor no indice %d foi excluido com sucesso\n\n", valor);
            }

        } else if (opcao == 4){
            printf("Digite o numero a ser excluido: ");
            scanf("%d", &valor);

            if(removeValue(valor, &l) == -1){
                printf("Erro ao excluir valor\n\n");
            } else {
                printf("O valor %d foi excluido com sucesso\n\n", valor);
            }
        } else if (opcao == 5){
            inverter(&l);
            printf("Lista invertida com sucesso\n\n");
        }
    }

}