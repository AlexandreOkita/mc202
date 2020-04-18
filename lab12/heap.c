#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#define PAI(i) ((i-1)/2)
#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)

/*Funcao auxiliar que troca o conteudo de dois itens*/
/*Entrada: itens que serao trocados*/
void troca(p_item *a, p_item *b){
    p_item aux = *a;
    *a = *b;
    *b = aux;
}

p_item criar_item(char nome[], int peso){
    p_item item = malloc(sizeof(Item));
    strcpy(item->nome, nome);
    item->peso = peso;
    return item;
}

p_fp criar_fila_prior(int tam){
    p_fp fila_prior = malloc(sizeof(Fila_prior));
    fila_prior->vet = malloc(tam*sizeof(p_item));
    fila_prior->tamanho = tam;
    fila_prior->n = 0;
    return fila_prior;
}

void destroi_item(p_item item){
    free(item);
}

void destruir_fila_prior(p_fp fila){
    int i;
    for (i = 0; i < fila->n; i++){
        destroi_item(fila->vet[i]);
    }
    free(fila->vet);
    free(fila);
}

/*Funcao auxiliar que sobe um item na prioridade de um heap maximo mantendo a propriedade do heap*/
/*Entrada: heap e posicao do item*/
void sobe_no_heap_max(p_fp fprio, int i){
    if (i > 0 && fprio->vet[PAI(i)]->peso < fprio->vet[i]->peso){
        troca(&fprio->vet[i], &fprio->vet[PAI(i)]);
        sobe_no_heap_max(fprio, PAI(i));
    }
}

/*Funcao auxiliar que desce um item na prioridade de um heap maximo mantendo a propriedade do heap*/
/*Entrada: heap e posicao do item*/
void desce_no_heap_max(p_fp fprio, int i){
    int maior_filho;
    if (F_ESQ(i) < fprio->n){
        maior_filho = F_ESQ(i);
        if (F_DIR(i) < fprio->n && fprio->vet[F_ESQ(i)]->peso < fprio->vet[F_DIR(i)]->peso)
            maior_filho = F_DIR(i);
        if (fprio->vet[i]->peso < fprio->vet[maior_filho]->peso){
            troca(&fprio->vet[i], &fprio->vet[maior_filho]);
            desce_no_heap_max(fprio, maior_filho);
        }
    }
}

/*Funcao auxiliar que sobe um item na prioridade de um heap minimo mantendo a propriedade do heap*/
/*Entrada: heap e posicao do item*/
void sobe_no_heap_min(p_fp fprio, int i){
    if (i > 0 && fprio->vet[PAI(i)]->peso > fprio->vet[i]->peso){
        troca(&fprio->vet[i], &fprio->vet[PAI(i)]);
        sobe_no_heap_min(fprio, PAI(i));
    }
}

/*Funcao auxiliar que desce um item na prioridade de um heap minimo mantendo a propriedade do heap*/
/*Entrada: heap e posicao do item*/
void desce_no_heap_min(p_fp fprio, int i){
    int menor_filho;
    if (F_ESQ(i) < fprio->n){
        menor_filho = F_ESQ(i);
        if (F_DIR(i) < fprio->n && fprio->vet[F_ESQ(i)]->peso > fprio->vet[F_DIR(i)]->peso)
            menor_filho = F_DIR(i);
        if (fprio->vet[i]->peso > fprio->vet[menor_filho]->peso){
            troca(&fprio->vet[i], &fprio->vet[menor_filho]);
            desce_no_heap_min(fprio, menor_filho);
        }
    }
}

void insere_max(p_item item, p_fp fprio){
    fprio->vet[fprio->n] = item;
    fprio->n++;
    sobe_no_heap_max(fprio, fprio->n-1);
}
p_item extrai_maximo(p_fp fprio){
    p_item item = fprio->vet[0];
    troca(&fprio->vet[0], &fprio->vet[fprio->n-1]);
    fprio->n--;
    desce_no_heap_max(fprio, 0);
    return item;
}

void insere_min(p_item item, p_fp fprio){
    fprio->vet[fprio->n] = item;
    fprio->n++;
    sobe_no_heap_min(fprio, fprio->n-1);
}
p_item extrai_minimo(p_fp fprio){
    p_item item = fprio->vet[0];
    troca(&fprio->vet[0], &fprio->vet[fprio->n-1]);
    fprio->n--;
    desce_no_heap_min(fprio, 0);
    return item;
}
