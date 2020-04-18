#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

/*Como não havia um espaco para implementar uma struct de pilha no susy, foi implementado no lab10.c como sugerido pelo professor*/
/*As pilhas possuem a funcao de empilhar arvores durante a recursao*/
typedef struct no {
    p_arvore dado;
    struct no *prox;
} No;
typedef struct no *p_no;

typedef struct pilha {
    p_no topo;
} Pilha;
typedef struct pilha *p_pilha;

/*Cria uma pilha com topo null*/
/*Saida: pilha criada*/
p_pilha criar_pilha(){
    p_pilha pilha;
    pilha = malloc(sizeof(pilha));
    if(pilha==NULL){
        exit(1);
    }
    pilha->topo = NULL;
    return pilha;
}
/*Insere o dado no topo da pilha*/
/*Entrada: pilha e dado que sera inserido */
void empilhar(p_pilha pilha, p_arvore dado){
    p_no novo = malloc(sizeof(No));
    if(novo == NULL){
        exit(1);
    }
    novo->dado = dado;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}
/*Retira e retorna o dado do topo da pilha*/
/*Entrada: pilha que sera retirada*/
/*Saida: dado que estava no topo*/
p_arvore desempilhar(p_pilha pilha){
    p_no primeiro = pilha->topo;
    p_arvore dado;
    dado = primeiro->dado;
    pilha->topo = primeiro->prox;
    free(primeiro);
    return dado;
}



/*Calculadora que realiza operacoes de soma, subtracao, multiplicacao e divisao*/
/*Entrada: operandos e sinal de operacao*/
/*Saida: inteiro referente a operacao realizada*/
int calcular(int operando1, char* operacao, int operando2);
/*Funcao recursiva que constroi a arvore a partir da entrada recebida pelo programa, a pilha eh utilizada nessa funcao para ler as ultimas 3 arvores e criar uma nova*/
/*Entrada: a entrada consiste na pilha que sera utilizada*/
/*Saida: retorna a arvore montada*/
p_arvore resolver(p_pilha);
/*Realiza as operacoes possiveis (compostas por numeros) indicadas pela arvore*/
/*Entrada: Arvore que sera realizada as operacoes*/
void otimizar(p_arvore raiz);

int main(){
    p_pilha pilha;
    char iniciar;
    p_arvore arvore;

    scanf("%c", &iniciar);
    pilha = criar_pilha();
    if (iniciar == '('){
        arvore = resolver(pilha);
        otimizar(arvore);
        imprimirArvore(arvore);
        printf(" \n");
        destruir_arvore(arvore);
        free(pilha);
    }
    else
        exit(1);
    return 0;
}

p_arvore resolver(p_pilha pilha){
    p_arvore arvore = NULL, arv_simb, operando1, operando2, sinal;
    char leitura[20];

    while(1){
        scanf("%s", leitura);
        if (!strcmp(leitura, "(")){
            arv_simb = resolver(pilha);
            empilhar(pilha, arv_simb);
        }
        else if(!strcmp(leitura, ")")){
            operando2 = desempilhar(pilha);
            sinal = desempilhar(pilha);
            operando1 = desempilhar(pilha);
            arvore = criar_arvore(sinal->dado, operando1, operando2);
            return arvore;
        }
        else{
            arv_simb = criar_arvore(leitura, NULL, NULL);
            empilhar(pilha, arv_simb);
        }
    }
}
/*Funcao auxiliar que indica se a string apresentada eh um int*/
/*Entrada: string que sera analisada*/
/*Saida: retorna True se for um inteiro e False caso contrario*/
int numero (char *buf) {
    return (buf[1] >= '0' && buf[1] <= '9') || (buf[0] >= '0' && buf[0] <= '9');
}

void otimizar(p_arvore raiz){
    int operando1, operando2, resultado;
    char string[20];
    if (raiz != NULL){
        otimizar(raiz->esquerda);
        otimizar(raiz->direita);
        if (raiz -> esquerda != NULL && raiz->direita != NULL && numero(raiz->esquerda->dado) && numero(raiz->direita->dado)){
            operando1 = atoi(raiz->esquerda->dado);
            operando2 = atoi(raiz->direita->dado);
            resultado = calcular(operando1, raiz->dado, operando2);
            sprintf(string,"%d", resultado);
            strcpy(raiz->dado, string);
            raiz->esquerda = NULL;
            raiz->direita = NULL;
        }
    }
}

int calcular(int operando1, char* operacao, int operando2){
    switch (operacao[0]) {
    case '+':
        return operando1 + operando2;
    case '*':
        return operando1 * operando2;
    case '/':
        return operando1 / operando2;
    }
    return operando1 - operando2;
}
