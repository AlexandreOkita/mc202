#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define MAX 2048


void combinar_e_inserir(p_autor *vet, int tam, p_hash hash);

/*Combina duas dois autores em uma string*/
/*Entrada: dois autores que serão combinados*/
/*Saida: uma string com a concatenacao do nome dos dois autores*/
char* combinar(p_autor autor_a, p_autor autor_b);

int main(){
    int tam, n, i, num_pesq, j = 0;
    p_autor vet[10];
    p_autor autor, autor1, autor2;
    char inicial, separador, sobrenome[16], *chave;
    p_hash hash = criar_hash();

    scanf("%d %d", &n, &num_pesq);
    /*Insere as combinacoes de colaboracao entre os autores*/
    for (i = 0; i < n; i++){
        tam = 0;
        j = 0;
        do {
            scanf(" %c. %[^.,]%c", &inicial, sobrenome, &separador);
            autor = criar_autor(inicial, sobrenome);
            vet[j] = autor;
            j++;
            tam++;
        } while(separador != '.');
        if(tam > 1)
            combinar_e_inserir(vet, tam, hash);
        for(j = 0; j < tam; j++)
            free(vet[j]);
    }

    /*Le os dois autores da entrada e pesquisa se ja houve colaboracao entre eles*/
    for (i = 0; i < num_pesq; i++){
        scanf(" %c. %[^.,]%c", &inicial, sobrenome, &separador);
        autor1 = criar_autor(inicial, sobrenome);
        scanf(" %c. %[^.,]%c", &inicial, sobrenome, &separador);
        autor2 = criar_autor(inicial, sobrenome);
        chave = combinar(autor1, autor2);
        if (buscar(chave, hash) != NULL){
            printf("S\n");
        }
        else{
            free(chave);
            chave = combinar(autor2, autor1);
            if (buscar(chave, hash) != NULL){
                printf("S\n");
            }
            else{
                printf("N\n");
            }
        }
        free(chave);
        free(autor1);
        free(autor2);
    }
    destruir_hash(hash);
    return 0;
}

void combinar_e_inserir(p_autor *vet, int tam, p_hash hash){
    int i, j;
    char *chave;
    p_comb comb;
    for (i = 0; i < tam; i++){
        for (j = i+1; j < tam; j++){
            chave = combinar(vet[i], vet[j]);
            comb = criar_comb(chave);
            free(chave);
            inserir(comb, hash);
        }
    }
}
char* combinar(p_autor autor_a, p_autor autor_b){
    int i, j;
    char *comb;
    comb = malloc(34*sizeof(char));
    if(comb == NULL)
        exit(1);
    comb[0] = autor_a->inicial;
    for (i = 0; i < strlen(autor_a->sobrenome); i++){
        comb[i+1] = autor_a->sobrenome[i];
    }
    comb[i+1] = autor_b->inicial;
    for (j = 0; j < strlen(autor_b->sobrenome); j++){
        comb[i+j+2] = autor_b->sobrenome[j];
    }
    comb[i+j+2]='\0';
    return comb;
}
