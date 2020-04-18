#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

p_grafo criar_grafo(int tam){
    int i;
    p_grafo novo;
    novo = malloc(sizeof(Grafo));
    novo->adj = malloc(tam*sizeof(No));
    for (i = 0; i<tam; i++){
        novo->adj[i] = NULL;
    }
    novo->tam = tam;
    return novo;
}

/*Função interna para auxiliar destruir o grafo*/
void limpar_lista(p_no lista){
    if (lista != NULL){
        limpar_lista(lista->prox);
        free(lista);
    }
}

void destruir_grafo(p_grafo grafo){
    int i;
    for (i = 0; i < grafo->tam; i++)
        limpar_lista(grafo->adj[i]);
    free(grafo->adj);
    free(grafo);
}

/*Função interna para auxiliar inserir a aresta*/
p_no inserir_vertice(p_no lista, int v){
    p_no novo;
    novo = malloc(sizeof(No));
    novo->vert = v;
    novo->prox = lista;
    return novo;
}

void inserir_aresta(p_grafo grafo, int v1, int v2){
    grafo->adj[v1] = inserir_vertice(grafo->adj[v1], v2);
    grafo->adj[v2] = inserir_vertice(grafo->adj[v2], v1);
}

/*Função interna para auxiliar remover a aresta*/
p_no remover_vertice(p_no lista, int v){
    p_no prox;
    if (lista == NULL){
        return NULL;
    }
    else if (lista->vert == v){
        prox = lista->prox;
        free(lista);
        return prox;
    }
    else{
        lista->prox = remover_vertice(lista->prox, v);
        return lista;
    }
}

void remover_aresta(p_grafo grafo, int v1, int v2){
    grafo->adj[v1] = remover_vertice(grafo->adj[v1], v2);
    grafo->adj[v2] = remover_vertice(grafo->adj[v2], v1);
}

int tem_aresta(p_grafo grafo, int v1, int v2){
    p_no i;
    for (i = grafo->adj[v1]; i != NULL; i = i->prox){
        if (i->vert == v2)
            return 1;
    }
    return 0;
}

void imprimir_arestas(p_grafo grafo){
    int i;
    p_no j;
    for (i = 0; i< grafo->tam; i++){
        for (j = grafo->adj[i]; j != NULL; j = j->prox){
            printf("{%d, %d}\n", i, j->vert);
        }
    }
}
