#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/*Verifica se cada uma das três pessoas entediadas já está no vetor de entediados e, se não, os adiciona*/
/*Entrada: trẽs vértices que representam as pessoas entediadas, vetor de entediados e tamanho atual do vetor*/
/*Saída: retorna o tamanho atualizado do vetor entediados*/
int inserir_entediados(int v1, int v2, int v3, int *entediados, int tam);

/*Verifica se um grupo está entediado*/
/*Entrada: um grupo de três pessoas que será analisadoe um vetor com as idades*/
/*Saída:*/
int grupo_tedio(int v1, int v2, int v3, int *idades);

/*Ordena um vetor em O(n^2) em ordem crescente*/
/*Entrada: vetor que será ordenado e seu tamanho*/
void ordenar_vetor(int *vetor, int n);

int main(){
    int n, m, i, v1, v2, tam, *idades, *entediados;
    p_no j, k;
    p_grafo grafo;
    scanf("%d %d", &n, &m);
    grafo = criar_grafo(n);

    /*Vetor utilizado para guardar as pessoas entediadas*/
    entediados = malloc(n*sizeof(int));
    tam = 0;

    /*Vetor utilizado para guardar o valor das idades dos vertices*/
    idades = malloc(n*sizeof(int));
    for (i = 0; i<n; i++){
        scanf("%d", &idades[i]);
    }

    /*Insere as arestas no grafo*/
    for (i = 0; i<m; i++){
        scanf("%d %d", &v1, &v2);
        inserir_aresta(grafo, v1, v2);
    }

    /*Encontra os triangulos no grafo*/
    for (i = 0; i < grafo->tam; i++){
        for (j = grafo->adj[i]; j != NULL; j = j->prox){
            for (k = j->prox; k != NULL; k = k->prox){
                if (tem_aresta(grafo, k->vert, j->vert) && grupo_tedio(j->vert, k->vert, i, idades)){
                    tam = inserir_entediados(j->vert, k->vert, i, entediados, tam);
                }
            }
        }
    }
    ordenar_vetor(entediados, tam);
    for (i = 0; i < tam; i++){
        printf("%d\n", entediados[i]);
    }
    free(entediados);
    free(idades);
    destruir_grafo(grafo);
    return 0;
}


int existe_no_vetor(int a, int* vetor, int tam){
    int i;
    for (i = 0; i < tam; i++){
        if (vetor[i] == a)
            return 1;
    }
    return 0;
}

int inserir_entediados(int v1, int v2, int v3, int *entediados, int n){
    if(!existe_no_vetor(v1, entediados, n)){
        entediados[n] = v1;
        n++;
    }
    if(!existe_no_vetor(v2, entediados, n)){
        entediados[n] = v2;
        n++;
    }
    if(!existe_no_vetor(v3, entediados, n)){
        entediados[n] = v3;
        n++;
    }
    return n;
}

int grupo_tedio(int v1, int v2, int v3, int *idades){
    float media;
    media = (idades[v1] + idades[v2] + idades[v3])/3.0;
    if (media > 2.0*idades[v1] || media > 2.0*idades[v2] || media > 2.0*idades[v3]){
        return 1;
    }
    return 0;
}

void ordenar_vetor(int *vetor, int n){
    int i, j, aux;
    for (i = 0; i<n; i++){
        for (j = i+1; j<n; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
