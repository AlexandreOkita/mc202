#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

typedef struct{
    p_no inicio;
    p_no fim;
} Fila;
typedef Fila *p_fila;

p_fila criar_fila(){
    p_fila nova_fila;
    nova_fila = malloc(sizeof(Fila));
    if(nova_fila == NULL)
        exit(1);
    nova_fila->inicio = NULL;
    nova_fila->inicio = NULL;
    return nova_fila;
}

void destroi_fila(p_fila fila){
    p_no atual, aux;
    atual = fila->inicio;
    while(atual != NULL){
        aux = atual;
        free(atual);
        atual = aux->prox;
    }
    free(fila);
}

int fila_vazia(p_fila fila){
    if (fila->inicio == NULL){
        return 1;
    }
    return 0;
}

p_fila enfileira(p_fila fila, int v){
    p_no elem = malloc(sizeof(No));
    if(elem == NULL)
        exit(1);
    elem->vert = v;
    elem->prox = NULL;
    if(fila->inicio == NULL){
        fila->inicio = elem;
    } else{
        fila->fim->prox = elem;
    }
    fila->fim = elem;
    return fila;
}
void imprimir_fila(p_fila fila){
    p_no aux;
    aux = fila->inicio;
    while (aux!=NULL){
        printf("%d, ", aux->vert);
        aux = aux->prox;
    }
    printf("\n");
}
int desenfileira(p_fila fila){
    int aux;
    p_no primeiro;
    primeiro = fila->inicio;
    aux = primeiro->vert;
    fila->inicio = primeiro->prox;
    if (fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(primeiro);
    return aux;
}

p_grafo criar_grafo(int tam){
    int i;
    p_grafo novo;
    novo = malloc(sizeof(Grafo));
    novo->adj = malloc(tam*sizeof(No));

    if(novo == NULL)
        exit(1);
    if(novo->adj == NULL)
        exit(1);

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
    if(novo == NULL)
        exit(1);
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

int arestas_min_entre_vertices(p_grafo g, int vert){
    int i, ind, max = 0;
    p_no desenfileirado;
    int *pai = malloc(g->tam * sizeof(int));
    int *visitados = malloc(g->tam * sizeof(int));
    p_fila fila = criar_fila();

    if(pai == NULL)
        exit(1);
    if(visitados == NULL)
        exit(1);

    for(i = 0; i < g->tam; i++){
        pai[i] = 0;
        visitados[i] = 0;
    }
    enfileira(fila, vert);
    visitados[vert] = 1;

    while(!fila_vazia(fila)){
        ind = desenfileira(fila);
        desenfileirado = g->adj[ind];
        while(desenfileirado!=NULL){
            if (visitados[desenfileirado->vert] != 1){
                visitados[desenfileirado->vert] = 1;
                pai[desenfileirado->vert] = pai[ind]+1;
                if (max < pai[desenfileirado->vert]){
                    max = pai[desenfileirado->vert];
                }
                enfileira(fila, desenfileirado->vert);
            }
            desenfileirado = desenfileirado->prox;
        }
    }

    destroi_fila(fila);
    free(visitados);
    free(pai);
    return max;
}

void visita_rec (p_grafo g, int *componentes, int comp, int v) {
    p_no t;
    componentes[v] = comp;
    for (t = g->adj[v]; t != NULL; t = t->prox){
        if (componentes[t->vert] == -1)
            visita_rec(g, componentes, comp, t->vert);
    }
}


int* encontra_conexoes(p_grafo g){
    int s, c = 0, *componentes = malloc(g->tam * sizeof(int));
    for (s = 0; s < g->tam; s++)
        componentes[s] = -1;
    for (s = 0; s < g->tam; s++){
        if (componentes[s] == -1){
            visita_rec(g, componentes, c, s);
            c++;
        }
    }
    return componentes;
}
