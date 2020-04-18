#include <stdio.h>
#include <stdlib.h>
#include "treap.h"

p_no procuraMaisEsq(p_no raiz);

p_no criar_conjunto(){
    return NULL;
}

p_no rot_dir(p_no raiz){
    p_no x = raiz->esq;
    x->pai = raiz->pai;
    if ( raiz->pai != NULL ) {
        if ( raiz->pai->esq == raiz) {
            raiz->pai->esq = x;
        } else {
            raiz->pai->dir = x;
        }
    }
    raiz->pai = x;
    raiz->esq = x->dir;
    if ( x->dir != NULL ) {
        x->dir->pai = raiz;
    }
    x->dir = raiz;
    return x;
}

p_no rot_esq(p_no raiz){
    p_no x = raiz->dir;
    x->pai = raiz->pai;
    if ( raiz->pai != NULL ) {
        if ( raiz->pai->esq == raiz) {
            raiz->pai->esq = x;
        } else {
            raiz->pai->dir = x;
        }
    }
    raiz->pai = x;
    raiz->dir = x->esq;
    if ( x->esq != NULL ) {
        x->esq->pai = raiz;
    }
    x->esq = raiz;
    return x;
}

p_no busca(p_no raiz, int chave){
    p_no ret;
    if(raiz == NULL || raiz->chave == chave) {
        ret = raiz;
    } else if(chave < raiz->chave) {
        ret = busca(raiz->esq, chave);
    } else {
        ret = busca(raiz->dir, chave);
    }
    return ret;
}
p_no inserir(p_no raiz, int chave){
    p_no novo;
    if (raiz == NULL){
        novo = malloc(sizeof(No));
        novo->esq = novo->dir = NULL;
        novo->chave = chave;
        novo->prior = rand()%1000;
        novo->pai = raiz;
        return novo;
    }
    if (chave < raiz->chave){
        raiz->esq = inserir(raiz->esq, chave);
        raiz->esq->pai = raiz;
        if (raiz->esq->prior > raiz->prior){
            raiz = rot_dir(raiz);
        }
    }
    else{
        raiz->dir = inserir(raiz->dir, chave);
        raiz->dir->pai = raiz;
        if (raiz->dir->prior > raiz->prior){
            raiz = rot_esq(raiz);
        }
    }

    return raiz;
}
p_no remover(p_no raiz, int chave){
    p_no aux,maisEsq;
    if (raiz == NULL)
        return raiz;
    if (chave < raiz->chave)
        remover(raiz->esq, chave);
    else if (chave > raiz->chave)
        remover(raiz->dir, chave);
    else {
        /*igual*/
        if (raiz->esq == NULL){
            aux = raiz->dir;
        }
        else if (raiz->dir == NULL) {
            aux = raiz->esq;
        } else {
            aux = raiz->dir;
            maisEsq = procuraMaisEsq(raiz->dir);
            maisEsq->esq = raiz->esq;
        }
        if ( raiz->pai != NULL ) {
            if ( raiz->pai->esq == raiz) {
                raiz->pai->esq = aux;
            } else {
                raiz->pai->dir = aux;
            }
        }
        free(raiz);
        raiz = aux;
    }
    return raiz;
}
p_no procuraMaisEsq(p_no raiz){
    if ( raiz->esq == NULL ) {
        return raiz;
    } else {
        return procuraMaisEsq(raiz->esq);
    }
}
void imprimir(p_no raiz){
    if (raiz != NULL){
        imprimir(raiz->dir);
        printf("%d ", raiz->chave);
        imprimir(raiz->esq);
    }
}
void destruir(p_no raiz){
    if (raiz != NULL){
        destruir(raiz->dir);
        destruir(raiz->esq);
        free(raiz);
    }
}
