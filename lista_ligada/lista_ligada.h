#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} No;
typedef struct no * p_no;


p_no criar_lista();

void destruir_lista(p_no lista);

void destruir_listaI(p_no lista);

p_no adicionar_elemento(p_no lista, int elem);

void imprimirI(p_no lista);

void imprimirR(p_no lista);
