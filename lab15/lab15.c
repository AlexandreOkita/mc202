#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/*Realiza a combinação de pares entre os elementos do vetore adicionando as arestas no grafo*/
/*Entrada: tamanho do vetor, vetor e grafo*/
void insere_grupo_no_grafo(p_grafo grafo, int* grupo, int n);

int main(){
    int num_alunos, num_grupos, num_integrantes, aluno, *grupo, *componentes, i, j, c, min;
    p_grafo grafo;

    scanf("%d %d", &num_alunos, &num_grupos);
    grupo = malloc(num_alunos*sizeof(int));
    if(grupo == NULL)
        exit(1);
    grafo = criar_grafo(num_alunos);
    componentes = malloc(num_alunos*sizeof(int));
    if(componentes == NULL)
        exit(1);

    /*le e cria os grupos no grafo*/
    for(i = 0; i < num_grupos; i++){
        scanf("%d", &num_integrantes);
        for(j = 0; j < num_integrantes; j++){
            scanf("%d", &aluno);
            grupo[j] = aluno;
        }
        insere_grupo_no_grafo(grafo, grupo, num_integrantes);
    }
    free(grupo);
    componentes = encontra_conexoes(grafo);

    /*Encontra os dados e os imprime conforme o enunciado*/
    for(i = 0; i < num_alunos; i++){
        c = componentes[i];
        for(j = 0; j < num_alunos; j++){
            if(componentes[j] != c)
                printf("%d ", j);
        }
        min = arestas_min_entre_vertices(grafo, i);
        printf("- %d\n", min);
    }
    destruir_grafo(grafo);
    free(componentes);
    return 0;
}

void insere_grupo_no_grafo(p_grafo grafo, int* grupo, int n){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = i+1; j < n; j++){
            inserir_aresta(grafo, grupo[i], grupo[j]);
        }
    }
}
