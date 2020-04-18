#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

p_fila criar_fila(){
    p_fila fila;
    fila = malloc(sizeof(Fila));
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

void destruir_fila(p_fila fila){
    free(fila);
}

void enfileirar(p_fila fila, p_jogador jogador){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->dado = jogador;
    if (fila->fim == NULL){
        fila->ini = novo;
    } else{
        fila->fim->prox = novo;
    }
    fila->fim = novo;
    novo->prox = NULL;
}

p_jogador desenfileirar(p_fila fila){
    p_no primeiro = fila->ini;
    p_jogador dado = primeiro->dado;
    fila->ini = fila->ini->prox;
    if (fila->ini == NULL){
        fila->fim = NULL;
    }
    free(primeiro);
    return dado;
}
