#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "pilha.h"

/*Distribui de maneira alternada as duas cartas iniciais para os jogadores*/
/*Entrada: um vetor contendo os jogadores, o número de jogadores e o baralho*/
void distribuir_primeiras_cartas(p_jogador *jogadores, int num_jogadores, p_pilha baralho);
/*Lê o input como um char tendo a precaução de consumir espaços e de verificar casos especiais*/
/*Saída: retorna o char lido, caso seja inserido um 10, retorna o 0*/
char ler_char();

int main(){
    p_fila fila;
    p_pilha baralho;
    p_jogador dealer, jogador, *jogadores;
    int num_cartas, num_jogadores, i;
    char carta;
    int carta_val;
    char comando;


    fila = criar_fila();
    scanf("%d %d ", &num_cartas, &num_jogadores);
    baralho = criar_pilha(num_cartas);
    jogadores = malloc((num_jogadores+1)*sizeof(p_jogador));
    /*Insere as cartas no baralho*/
    for (i=0; i<num_cartas; i++){
        carta = ler_char();
        empilhar(baralho, carta);
    }
    /*Enfileira os jogadores*/
    for (i=0; i<num_jogadores; i++){
        jogadores[i] = criar_jogador();
        enfileirar(fila, jogadores[i]);
    }
    dealer = criar_jogador();
    jogadores[num_jogadores] = dealer;
    enfileirar(fila, dealer);

    distribuir_primeiras_cartas(jogadores, num_jogadores, baralho);

    while (fila->ini != NULL){
        if(fila->ini->dado->soma < 21){
            comando = ler_char();
            if (comando == '#'){
                /*Se o comando for '#', significa que o jogo acabou'*/
                break;
            }
            /*Checa se o jogador realizou um hit*/
            if (comando == 'H'){
                jogador = desenfileirar(fila);
                carta = desempilhar(baralho);
                carta_val = valor_carta(jogador, carta);
                jogador = somar_cartas(jogador, carta_val);
                /*Se o jogador ainda estiver apto a jogar, ele será enfileirado novamente*/
                if (jogador -> estado){
                    enfileirar(fila, jogador);
                }
            }
            /*Checa se o jogador realizou um stand*/
            else if (comando == 'S'){
                /*O jogador é apenas desinfileirado*/
                jogador = desenfileirar(fila);
            }
            /*Se o comando não for um '#', 'H' ou um 'S', o dealer está colocando uma carta no topo do baralho*/
            else {
                empilhar(baralho, comando);
            }
        /*Caso o jogador já tenha 21 ou mais, ele deve ser desinfileirado*/
        } else{
            jogador = desenfileirar(fila);
        }

    }
    /*Imprime a soma na ordem e limpa o jogador em seguida*/
    for(i = 0; i<num_jogadores+1; i++){
        printf("%d\n", jogadores[i]->soma);
        destruir_jogador(jogadores[i]);
    }
    free(jogadores);
    destruir_fila(fila);
    destruir_pilha(baralho);
    return 0;
}

void distribuir_primeiras_cartas(p_jogador *jogadores, int num_jogadores, p_pilha baralho){
    char carta;
    int carta_val, i, j;
    for (i=0; i<2; i++) {
        for (j=0; j<(num_jogadores+1); j++){
            carta = desempilhar(baralho);
            carta_val = valor_carta(jogadores[j], carta);
            somar_cartas(jogadores[j], carta_val);
            if (jogadores[j]->soma >= 21){
                jogadores[j]->estado = 0;
            }
        }
    }
}

char ler_char(){
    char carta, carta2;
    scanf("%c", &carta);
    if (carta == '#'){
        return carta;
    }
    if(carta == '1' ){
        scanf("%c",&carta2);
        if ( carta2 == '0' ) {
            carta = '0';
            /*getchar utilizado para consumir o espaco depois do char lido*/
            getchar();
        }
    /*caso nao seja '#' tera um espaco apos o char*/
    } else {
        /*mesmo uso do getchar acima*/
        getchar();
    }
    return carta;
}
