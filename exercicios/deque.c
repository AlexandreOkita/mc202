#include <stdio.h>
#include <stdlib.h>
typedef struct no {
    int dado;
    struct no *prox;
    struct no *ant;
} No;
typedef struct no * p_no;

typedef struct Deque{
    p_no inicio, fim;
} Deque;
typedef struct Deque *p_deque;

p_deque criar_deque(p_deque deque){
    deque = malloc(sizeof(p_deque));
    deque->inicio = NULL;
    deque->fim = NULL;
    return deque;
}
void insere_inicio(p_deque deque, int dado){
    p_no novo = malloc(sizeof(No));
    novo->dado = dado;
    if(deque->inicio == NULL){
        deque->fim = novo;
        novo->prox = NULL;
    } else{
        novo->prox = deque->inicio;
        deque->inicio->ant = novo;
    }
    deque->inicio = novo;
    novo->ant = NULL;
}
void insere_fim(p_deque deque, int dado){
    p_no novo = malloc(sizeof(No));
    novo->dado = dado;
    if(deque->fim == NULL){
        deque->inicio = novo;
        novo->ant = NULL;
    } else{
        novo->ant = deque->fim;
        deque->fim->prox = novo;
    }
    novo->prox = NULL;
    deque->fim = novo;
}
