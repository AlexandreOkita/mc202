/*Nome: Alexandre Torres Okita*/
/*RA: 193524*/
/*Objetivo: Criar um programa para uma corretora que gerencie os clientes e suas respectivas ações.*/
/*Entrada: A entrada consiste no nome do cliente seguido de suas ações e as variações de cada ação.*/
/*Saída: Deve ser impresso o relatório do cliente tendo contido nele seu nome, o valor atual das ações e se houver perda ou ganho do investimento inicial. */

#include <stdio.h>
#include <stdlib.h>
#include "acao.h"
#include "portfolio.h"
int main(){
    portfolio pessoa;

    acao acao;
    char *nomePessoa = malloc(30 * sizeof(char));
    char *nomeAcao = malloc(30 * sizeof(char));
    char *sobrenomePessoa = malloc(30 * sizeof(char));
    double investimento, variacao;
    int numAcoes, numVariacoes, i, j;

    scanf("%s", nomePessoa);
    scanf("%s %d", sobrenomePessoa, &numAcoes);
    pessoa = criar_portfolio(nomePessoa, sobrenomePessoa);

    /*Cria as ações e adiciona suas respectivas variações*/
    for(i = 0; i<numAcoes; i++){
        scanf("%s %lf %d", nomeAcao, &investimento, &numVariacoes);
        acao = criar_acao(nomeAcao, investimento);
        for(j = 0; j<numVariacoes; j++){
            scanf("%lf", &variacao);
            acao = adicionar_variacao(acao, variacao);
        }
        pessoa = adicionar_acao(pessoa, acao);
    }

    criar_relatorio(pessoa);
    /*Evitar vazamento de memória*/
    free(nomePessoa); free(sobrenomePessoa); free(nomeAcao);
    return 0;
}
