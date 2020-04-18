/*Nome: Alexandre Torres Okita*/
/*RA: 193524*/
/*Objetivo: Funções para auxiliar o gerencimaneto das ações e realizar os cálculos das variações*/

#include <stdio.h>
#include <string.h>
#include "acao.h"

acao criar_acao(char *nome, double investimento){
    acao nova;
    strcpy(nova.nome, nome);
    nova.investimento = investimento;
    nova.n_variacoes = 0;
    return nova;
}

acao adicionar_variacao(acao a, double variacao){
    a.variacoes[a.n_variacoes] = variacao;
    a.n_variacoes++;
    return a;
}

/*Realiza o cálculo das variações e imprime o valor atual e se houve lucro ou não.*/
void reportar_acao(acao a){
    int i;
    double valorAtual = a.investimento;
    for(i = 0; i<a.n_variacoes; i++){
        valorAtual = valorAtual*((100 + a.variacoes[i])/100);
    }
    printf("%s %0.2f ",a.nome, valorAtual);
    if (valorAtual<a.investimento){
        printf("PERDA\n");
    } else{
        printf("GANHO\n");
    }
}
