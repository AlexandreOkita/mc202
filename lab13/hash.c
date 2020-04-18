#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define MAX 2048
#define PRIMO 19

p_comb criar_comb(char *chave){
    p_comb novo;
    novo = malloc(sizeof(Comb));
    if(novo == NULL)
        exit(1);
    strcpy(novo->chave, chave);
    return novo;
}

p_hash criar_hash(){
    int i;
    p_hash novo;
    novo = malloc(sizeof(Hash));
    if(novo == NULL)
        exit(1);
    novo->vet = malloc(MAX * sizeof(p_comb));
    if(novo->vet == NULL)
        exit(1);
    for(i = 0; i < MAX; i++){
        novo->vet[i] = NULL;
    }
    novo->n = 0;
    return novo;
}
p_autor criar_autor(char inicial, char *sobrenome){
    p_autor autor;
    autor = malloc(sizeof(Autor));
    autor->inicial = inicial;
    strcpy(autor->sobrenome, sobrenome);
    return autor;
}

void destruir_hash(p_hash hash){
    int i;
    for (i = 0; i < MAX; i++){
        if(hash->vet[i]!=NULL){
            free(hash->vet[i]);
        }
    }
    free(hash->vet);
    free(hash);
}
/*Primeira funcao de hashing*/
int hash_code1(char* chave){
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++){
        n = (n*256 + chave[i])%MAX;
    }
    return n;
}
/*Segunda funcao de hashing*/
int hash_code2(char* chave){
    int i, n = 0;
    for (i = 0; i < strlen(chave); i++){
        n = (PRIMO - ((n*256 + chave[i])%PRIMO));
    }
    return n;
}
void inserir(p_comb comb, p_hash hash){
    int local, i = 1;
    if(hash->n == MAX){
        printf("Hash cheio!");
    }
    hash->n += 1;
    local = hash_code1(comb->chave);
    while (hash->vet[local] != NULL){
        local = (hash_code1(comb->chave) + i*hash_code2(comb->chave))%MAX;
        i++;
    }
    hash->vet[local] = comb;
}

p_comb buscar(char* chave, p_hash hash){
    int i = 1;
    int local = hash_code1(chave);
    while (hash->vet[local] != NULL && strcmp(chave, hash->vet[local]->chave) != 0){
        local = (hash_code1(chave) + i*hash_code2(chave))%MAX;
        i++;
    }
    return hash->vet[local];
}
