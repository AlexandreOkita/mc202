#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

p_no criar_lista() {
    return NULL;
}

void destruir_lista(p_no lista){
    if (lista != NULL) {
        destruir_lista(lista->prox);
        free(lista);
    }
}

void destruir_listaI(p_no lista){
    p_no atual, prox;
    for (atual = lista; atual != NULL; atual = prox){
        prox = atual->prox;
        free(atual);
    }
}

p_no adicionar_elemento(p_no lista, int elem){
    p_no novoNo;
    novoNo = malloc(1*sizeof(No));
    if (novoNo != NULL){
        novoNo -> prox = lista;
        novoNo -> dado = elem;
    }
    return novoNo;
}

void imprimirI(p_no lista){
    p_no atual;
    for (atual = lista; atual != NULL; atual = lista->prox){
        printf("%d\n", atual->dado);
    }
}
void imprimirR(p_no lista){
    if (lista != NULL){
        imprimirR(lista->prox);
        printf("%d\n", lista->dado);
    }
}

p_no copiar_lista(p_no lista){
    p_no novo;
    if (lista==NULL){
        return NULL;
    }
    novo = malloc(sizeof(No));
    novo->dado = lista->dado;
    novo->prox = copiar_lista(lista->prox);
    return novo;
}

p_no inverter_lista(p_no lista){
    p_no ant, atual, invertida = NULL;
    atual = lista;
    while (atual != NULL){
        ant = atual;
        atual = ant->prox;
        ant->prox = invertida;
        invertida = ant;
    }
    return invertida;
}

p_no concatenar_lista(p_no primeira, p_no segunda){
    if (primeira == NULL){
        return segunda;
    }
    primeira->prox = concatenar_lista(primeira->prox, segunda);
    return primeira;
}

p_no inserir_circular(p_no lista, int x){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = x;
    if (lista==NULL){
        novo->prox = novo;
    }   else{
        novo->prox = lista->prox;
        lista->prox = novo;
    }
    return novo;
}
