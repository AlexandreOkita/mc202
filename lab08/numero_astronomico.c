#include <stdio.h>
#include <stdlib.h>
#include "numero_astronomico.h"

p_no criar_lista(){
    return NULL;
}
void destruir_lista(p_no lista){
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}
p_no adicionar_elemento(p_no lista, int dado){
    p_no novo;
    novo = malloc(sizeof(No_duplo));
    if(novo!=NULL){
        novo->prox = lista;
        novo->ant = NULL;
        novo->dado = dado;
        if (lista != NULL){
            lista->ant = novo;
        }
    }
    return novo;
}
void imprimir_lista(p_no lista){
    if(lista != NULL){
        imprimir_lista(lista->prox);
        printf("%d", lista->dado);
    }
}
/*Funcao privada que adiciona um no contendo zero no final da lista*/
/*Entrada: lista que sera ampliada com o zero*/
/*Saida: lista ampliada*/
p_no ampliar_lista(p_no lista){
    p_no novo;
    novo = malloc(sizeof(No_duplo));
    novo->dado = 0;
    novo->prox = NULL;
    novo -> ant = lista;
    lista->prox = novo;
    return novo;
}
/*Soma os dados de dois nos*/
/*Entrada: nos que serao somados e variavel "vai um"*/
/*Saida: da o valor da soma por referencia e retorna se "vai um"*/
int somarNos(p_no no1, p_no no2, int overflow){
    int dado2 = 0;
    if(no2 != NULL) {
        dado2 = no2->dado;
    }
    no1->dado += dado2 + overflow;
    if (no1->dado>9){
        no1->dado -= 10;
        return 1;
    }
    return 0;
}
p_no somar_listas(p_no l1, p_no l2){
    int overflow = 0;
    p_no ultimo = l1;
    p_no resultado = l1;
    while (l1 != NULL || l2 != NULL){
        overflow = somarNos(l1, l2, overflow);
        if (l1->prox == NULL && l2 != NULL ){
            if (l2->prox != NULL) {
                ampliar_lista(l1);
            }
        }
        ultimo = l1;
        l1 = l1->prox;
        if (l2 != NULL)
            l2 = l2->prox;
    }
    if (overflow == 1){
        ultimo = ampliar_lista(ultimo);
        ultimo->dado += 1;
    }
    return resultado;
}
void limpar_lista(p_no lista){
    p_no atual = lista;
    p_no ultimo = atual;
    p_no aux;
    /*Identifica o último número diferente de zero */
    while (atual != NULL){
        if (atual->dado != 0){
            ultimo = atual;
        }
        atual = atual->prox;
    }
    /*Atualiza o ultimo nó*/
    if(ultimo->prox != NULL){
        atual = ultimo->prox;
        ultimo->prox = NULL;
    }
    /*Limpa os zeros à esquerda*/
    while(atual != NULL){
        aux = atual;
        free(atual);
        atual = aux->prox;
    }
}
