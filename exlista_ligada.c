#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"

int main(){
    p_no lista;
    int n, i, elemento;
    lista = criar_lista();
    scanf("%d\n", &n);
    for (i = 0; i<n; i++){
        scanf("%d", &elemento);
        adicionar_elemento(lista, elemento);
    }
    imprimirI(lista);
    destruir_lista(lista);
    return 0;
}
