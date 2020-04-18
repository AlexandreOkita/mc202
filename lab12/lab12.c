#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/*Imprime e atualiza a mediana dos valores existentes nos dois heaps*/
/*Entrada: heap maximo e minimo que foram utilizados para encontrar a mediana*/
/*Saída: valor da nova mediana*/
int imprimir_atualizar_mediana(p_fp heap_max, p_fp heap_min);

int main(){
    int peso, med = 0, tam, i;
    char nome[20];
    p_item item;
    p_fp heap_max, heap_min;

    scanf("%d", &tam);
    heap_max = criar_fila_prior(tam);
    heap_min = criar_fila_prior(tam);

    for(i = 0; i<tam; i++){
        scanf("%s %d", nome, &peso);
        item = criar_item(nome, peso);
        if(peso > med){
            insere_min(item, heap_min);
        }
        else{
            insere_max(item, heap_max);
        }
        if(heap_min->n > heap_max->n+1){
            item = extrai_minimo(heap_min);
            insere_max(item, heap_max);
        }
        else if(heap_max->n > heap_min->n+1){
            item = extrai_maximo(heap_max);
            insere_min(item, heap_min);
        }
        med = imprimir_atualizar_mediana(heap_max, heap_min);
    }
    destruir_fila_prior(heap_max);
    destruir_fila_prior(heap_min);
    return 0;
}

int imprimir_atualizar_mediana(p_fp heap_max, p_fp heap_min){
    int med;
    if (heap_max->n > heap_min->n){
        printf("%s: %d\n", heap_max->vet[0]->nome, heap_max->vet[0]->peso);
        med = heap_max->vet[0]->peso;
    }
    else if (heap_max->n < heap_min->n){
        printf("%s: %d\n", heap_min->vet[0]->nome, heap_min->vet[0]->peso);
        med = heap_min->vet[0]->peso;
    }
    else{
        printf("%s: %d\n", heap_max->vet[0]->nome, heap_max->vet[0]->peso);
        printf("%s: %d\n", heap_min->vet[0]->nome, heap_min->vet[0]->peso);
        med = (heap_max->vet[0]->peso + heap_min->vet[0]->peso)/2;
    }
    return med;
}
