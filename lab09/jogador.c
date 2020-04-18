#include <stdlib.h>
#include <stdio.h>
#include "jogador.h"

p_jogador criar_jogador(){
    p_jogador novo;
    novo = malloc(sizeof(Jogador));
    novo->soma = 0;
    novo->estado = 1;
    return novo;
}

p_jogador somar_cartas(p_jogador jogador, int carta){
    jogador->soma += carta;
    while (jogador->num_a > 0 && jogador->soma > 21) {
        jogador->soma -= 10;
        jogador->num_a--;
    }
    if (jogador->soma >= 21){
        jogador->estado = 0;
    }
    return jogador;
}

int valor_carta(p_jogador jogador, char carta){
    if(carta == 'V' || carta == 'R' || carta == 'D' || carta == '0'){
        return 10;
    }
    else if(carta == 'A'){
        jogador->num_a ++;
        return 11;
    }
    return carta - '0';
}

void destruir_jogador(p_jogador jogador){
    free(jogador);
}
