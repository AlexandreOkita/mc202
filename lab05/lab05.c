/*RA: 193524 */
/*Nome: Alexandre Torres Okita*/
/*Objetivo: Criar um vetor de tamanho dinâmico e ordenado para comportar um sorteio*/
/*Entrada: A entrada é composta por várias linhas, cada uma contendo o nome do
participante seguido do número de telefone. Na última linha há a palavra fim seguida
da posição (ordenada de forma crescente pelo número de telefone) do ganhador do sorteio*/
/*Saída: O programa produz uma única linha contendo o nome e o telefone do ganhador*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STD 4
#define MAX 31

typedef struct {
    char nome[MAX];
    int telefone;
} participante;

/*
Cria um registro participante
Entrada: nome e telefone do participante
Saída: retorna o participante criado
*/
participante criarParticipante(char nome[MAX], int telefone);
/*
Dobra a memória alocada para o vetor dinamicamente(usado quando se atinge o tamanho limite do vetor)
Entrada: vetor com os participantes inscritos e limite atual desse vetor
Saída: Vetor copiado com o dobro de memória alocada
*/
participante* dobrarVetor(participante *inscritos, int limite);
/*
Ordena o vetor de forma crescente em função do número de telefone de cada participante
Entrada: vetor com os participantes inscritos e uma variável auxiliar com função de índice
*/
void ordenarVetor(participante *inscritos, int i);

int main(){
    participante *inscritos;
    participante participante;
    char nome[MAX];
    int telefone, sorteado;
    int i = 0, ehIgual = 1, acabou = 0, limite = STD;
    inscritos = malloc(limite * sizeof(participante));

    /*Lê os participantes e os insere no vetor "inscritos"*/
    while(!acabou){
        scanf("%s", nome);
        ehIgual = strcmp(nome, "fim");
        if (ehIgual != 0){
            scanf("%d", &telefone);
            participante = criarParticipante(nome, telefone);
            inscritos[i] = participante;
            /*Dobra a quantidade de memória alocada quando o limite do vetor é atingido*/
            if (i+1 == limite){
                limite = limite*2;
                inscritos = dobrarVetor(inscritos, limite);
            }
            i++;
        }
        else{
            acabou = 1;
        }
    }
    scanf("%d", &sorteado);
    ordenarVetor(inscritos, i);
    printf("%s %d\n", inscritos[sorteado-1].nome, inscritos[sorteado-1].telefone);
    free(inscritos);
    return 0;
}

participante criarParticipante(char nome[MAX], int telefone){
    participante p;
    strcpy(p.nome, nome);
    p.telefone = telefone;
    return p;
}

participante* dobrarVetor(participante *inscritos, int limite){
    participante *inscritosNovo;
    int i;
    inscritosNovo = malloc(limite * sizeof(participante));
    for(i = 0; i<limite/2; i++){
        inscritosNovo[i] = inscritos[i];
    }
    free(inscritos);
    return inscritosNovo;
}

void ordenarVetor(participante *inscritos, int i){
    int j, k;
    participante acum;
    for (j = 0; j<i; j++){
        for (k = j; k<i; k++){
            if (inscritos[j].telefone > inscritos[k].telefone){
                acum = inscritos[j];
                inscritos[j] = inscritos[k];
                inscritos[k] = acum;
            }
        }
    }
}
