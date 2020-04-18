/*Nome: Alexandre Torres Okita*/
/*RA: 193524*/
/*Objetivo: Criar uma calculadora que edita strings*/
/*Entrada: Comando com os parâmetros necessários em seguida*/
/*Saída: É impresso o buffer da calculadora ou outro texto especificado pelo comando*/

#include <stdio.h>
#define MAX 101
#define MAXCOMANDO 3

/* Retorna o tamanho de uma string */
int verTamanho(char string[]);
/* Adiciona uma string ao buffer e retorna o novo tamanho do buffer */
int concatenar(char buffer[], char string[], int i, int tam_buff);
/* Compara duas strings, retornando True caso sejam iguais e False caso não */
int eIgual(char buffer[], char string[], int i, int tam_buff);
/* Substitui o buffer pela string de tamanho 'tam' após a posição 'pos' */
int substituir(char buffer[], int i, int pos, int tam);
/* Imprime a string */
void imprimir(int tam_buff, char buffer[]);

int main(){
    char buffer[MAX];
    char string[MAX];
    char comando[MAXCOMANDO];
    int i = 0, tam_buff = 0;
    int pos;
    int tam;

    /*Comandos realizados a partir da funcão eIgual*/
    while (!eIgual(comando, "END", i, MAXCOMANDO)){
        scanf("%s", comando);
        /*Comando para concatenar*/
        if (eIgual(comando, "CAT", i, MAXCOMANDO)){
            scanf("%s", string);
            tam_buff = concatenar(buffer, string, i, tam_buff);
            imprimir(tam_buff, buffer);
        }
        /*Comando para comparar*/
        else if (eIgual(comando, "CMP", i, MAXCOMANDO)){
            scanf("%s", string);
            if (eIgual(buffer, string, i, tam_buff)){
                printf("IGUAL\n");
            }
            else{
                printf("DIFERENTE\n");
            }
        }
        /*Comando para substituir*/
        else if (eIgual(comando, "SUB", i, MAXCOMANDO)){
            scanf("%d %d", &pos, &tam);
            tam_buff = substituir(buffer, i, pos, tam);
            imprimir(tam_buff, buffer);
        }
    }
    return 0;
}

int concatenar(char buffer[], char string[], int i, int tam_buff){
    int n;
    n = verTamanho(string);
    for (i = 0; i<n; i++){
        buffer[tam_buff] = string[i];
        tam_buff++;
    }
    return tam_buff;
}

int eIgual(char buffer[], char string[], int i, int tam_buff){
    int eIgual = 1;
    for (i = 0; i<tam_buff; i++){
        if (buffer[i] != string[i]){
            eIgual = 0;
            break;
        }
    }
    return eIgual;
}

int substituir(char buffer[], int i, int pos, int tam){
    for (i = 0; i < tam; i++){
        buffer[i] = buffer[i+pos];
    }
    return tam;
}

int verTamanho(char string[]){
    int n;
    for (n = 0; string[n] != '\0'; n++);
    return n;
}

void imprimir(int tam_buff, char buffer[]){
    int i;
    for (i = 0; i< tam_buff; i++){
        printf("%c", buffer[i]);
    }
    printf("\n");
}
