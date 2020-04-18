#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


p_arvore criar_arvore(char *dado, p_arvore esq, p_arvore dir){
    p_arvore r = malloc(sizeof(arvore));
    if(r == NULL)
        exit(1);
    strcpy(r->dado, dado);
    r->esquerda = esq;
    r->direita = dir;
    return r;
}


void imprimirArvore(p_arvore raiz){
    if (raiz != NULL && raiz->esquerda != NULL && raiz->direita != NULL) {
        printf("( ");
        imprimirArvore(raiz->esquerda);
        printf(" %s ", raiz->dado);
        imprimirArvore(raiz->direita);
        printf(" )");
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL){
        printf("%s", raiz->dado);
    }
}

void destruir_arvore(p_arvore raiz){
    if (raiz != NULL){
        destruir_arvore(raiz->direita);
        destruir_arvore(raiz->esquerda);
        free(raiz);
    }
}
