#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

p_pilha criar_pilha(int n){
    p_pilha novo;
    novo = malloc(sizeof(Pilha));
    novo->vet = malloc(n+1*sizeof(char));
    if(novo->vet == NULL)
        exit(1);
    return novo;
}

void destruir_pilha(p_pilha pilha){
    free(pilha->vet);
    free(pilha);
}

void empilhar(p_pilha pilha, int dado){
    pilha->vet[pilha->ini] = dado;
    pilha->ini++;
}

int desempilhar(p_pilha pilha){
    pilha->ini--;
    return pilha->vet[pilha->ini];
}
