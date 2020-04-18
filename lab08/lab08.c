/*Nome: Alexandre Torres Okita*/
/*RA: 193524*/
/*Objetivo: calcular a soma entre dois numeros astronomicos*/
/*Entrada: comandos dados pelo formato: '+'+'espaco'+'dado'+'enter'*/
/*Saida: resultado das operacoes dadas pela entrada e o buffer */
#include <stdio.h>
#include "numero_astronomico.h"
#define ESPERANDO_MAIS 0
#define ESPERANDO_ENTER 1
#define ESPERANDO_ESPACO 2

int main(){
    char comando;
    int dado;
    p_no buffer, lista;
    int estado = ESPERANDO_MAIS;
    buffer = criar_lista();
    do{
        scanf("%c", &comando);
        /*Switch case utilizado para registrar os dados a partir do especificado na entrada*/
        switch (estado) {
        case ESPERANDO_MAIS:
            if(comando=='+'){
                estado = ESPERANDO_ESPACO;
            }
            break;
        case ESPERANDO_ESPACO:
            if(comando==' '){
                estado = ESPERANDO_ENTER;
                /*Cria a lista que contera os dados do comando */
                lista = criar_lista();
            }
            break;
        case ESPERANDO_ENTER:
            if(comando=='\n'){
                /*Quando ocorrer o 'enter' o numero estara finalizado e podera-se-a realizar as operacoes*/
                estado = ESPERANDO_MAIS;
                limpar_lista(lista);
                if (buffer == NULL){
                    buffer = lista;
                } else{
                    buffer = somar_listas(buffer, lista);
                    destruir_lista(lista);
                }
                imprimir_lista(buffer);
                printf("\n");
            } else{
                /*Enquanto estiver 'esperando enter' mas ele nao ocorrer, sera inserido os dados*/
                dado = comando - '0';
                lista = adicionar_elemento(lista, dado);
            }
        }
    }
    while(comando!='#');
    destruir_lista(buffer);
    return 0;
}
