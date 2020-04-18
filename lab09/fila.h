#include "jogador.h"

/*Fila criada utilizando lista ligada*/
typedef struct No{
    p_jogador dado;
    struct No *prox;
}  No;
typedef No *p_no;

typedef struct Fila{
    p_no ini;
    p_no fim;
}  Fila;
typedef Fila *p_fila;

/*Aloca memória e seta uma fila como inicio e fim null*/
/*Saída: ponteiro para a fila alocada*/
p_fila criar_fila();

/*Destroi a fila liberando recurssivamente os nós e depois liberando a fila*/
/*Entrada: Fila que será destruída*/
void destruir_fila(p_fila fila);

/*Coloca um jogador no fim da fila*/
/*Entrada: fila a qual o jogador será enfileirado e o jogador*/
void enfileirar(p_fila fila, p_jogador jogador);

/*Tira um jogador do inicio da fila*/
/*Entrada: fila que será realizada a acao*/
/*Saida: jogador que foi desenfileirado*/
p_jogador desenfileirar(p_fila fila);
