#include <stdio.h>

int lista_nao_descresc(p_no lista){
    if (lista == NULL){
        return 1;
    }
    if (lista->prox == 1){
        return 1
    }
    return lista->dado<=lista->prox->dado && lista_nao_descresc(lista->prox);
}
