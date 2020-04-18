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

p_no buscar(p_no lista, int elem){
    if (lista == NULL || lista -> dado == elem){
        return lista;
    }
    return buscar(lista -> prox, elem);
}

p_no remover(p_no lista, int elem){
    p_no atual, ant = NULL;
    while (atual != NULL){
        if (atual->dado == elem){
            if (ant != NULL){
                ant->prox = atual->prox;
            } else {
                lista = atual->prox;
            }
            free(atual);
            return lista;
        }
        ant = atual;
        atual = atual->prox;
    }
    return lista;
}
