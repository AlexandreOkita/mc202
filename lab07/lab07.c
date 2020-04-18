/*Nome: Alexandre Torres Okita*/
/*RA: 193524*/
/*Objetivo: Criar um programa que imprime a solucao para um labirinto a partir do uso de backtracking*/
/*Entrada: A entrada consiste do número de linhas e colunas totais, coordenadas para a entrada e saída e o labirinto em forma matricial*/
/*Saída: O programa deve imprimir uma matriz de espaços com a solução marcada por '*'*/

#include <stdio.h>
#include <stdlib.h>

/*Aloca dinamicamente uma matriz*/
/*Entrada: número de linhas e colunas da matriz que sera alocada*/
/*Saida: matriz dinamicamente alocada*/
char **alocaMatriz(int numLinhas, int numColunas);
/*Resolve recursivamente o labirinto a partir de um algoritmo de backtracking*/
/*Entrada: numero de linhas e colunas do labirinto, a matriz que representa o labirinto e outra que representa a solucao, e a posicao i e j da entrada*/
/*Saida: retorna True caso a saida foi encontrada ou False caso nao*/
int resolveLabirinto(int numLinhas, int numColunas, int linhaSaida, int colunaSaida, char **labirinto, char **solucao, int pos_i, int pos_j);
/*Checa se determinada posicao é valida para se mover no labirinto*/
/*Entrada: numero de linhas e colunas do labirinto, a matriz que representa o labirinto e a posicao no labirinto que deve ser checada*/
/*Saida: retorna True caso a posicao seja valida e False se nao*/
int posValida(int numLinhas, int numColunas, char **labirinto, int pos_i, int pos_j);
/*Imprime uma matriz no formato determinado*/
void imprimirLabirinto(int numLinhas, int numColunas, char **labirinto);

int main(){
    int LT, CT, LE, CE, LS, CS;
    char **labirinto;
    char **solucao;
    int i, j;
    int pos_i, pos_j;
    scanf("%d %d %d %d %d %d", &LT, &CT, &LE, &CE, &LS, &CS);
    labirinto = alocaMatriz(LT, CT);
    /*Preenche o labirinto com os dados fornecidos na entrada*/
    for(i = 0; i<LT; i++){
        for(j = 0; j<CT; j++){
            scanf("\n%c", &labirinto[i][j]);
        }
    }
    solucao = alocaMatriz(LT, CT);
    /*Preenche a solucao com espacos*/
    for(i = 0; i<LT; i++){
        for(j = 0; j<CT; j++){
            solucao[i][j] = ' ';
        }
    }
    pos_i = LE;
    pos_j = CE;
    resolveLabirinto(LT, CT, LS, CS, labirinto, solucao, pos_i, pos_j);
    imprimirLabirinto(LT, CT, solucao);
    free(labirinto);
    free(solucao);
    return 0;
}

char **alocaMatriz(int numLinhas, int numColunas){
    int i;
    char **matriz = (char**)malloc(numLinhas * sizeof(char*));
    for(i = 0; i<numLinhas; i++){
        matriz[i] = (char*)malloc(numColunas * sizeof(char));
    }
    return matriz;
}

int resolveLabirinto(int numLinhas, int numColunas, int linhaSaida, int colunaSaida, char **labirinto, char **solucao, int pos_i, int pos_j){
    int achouSol = 0, k;
    labirinto[pos_i][pos_j] = 'X';
    /*Caso base: se a posicao for a mesma que a saida a solucao foi encontrada*/
    if(pos_i == linhaSaida && pos_j == colunaSaida){
        solucao[pos_i][pos_j] = '*';
        return 1;
    }
    /*checa os pontos cardeais em volta da posicao*/
    for (k = -1; k<=1; k=k+2){
        /*checa a posicao acima e abaixo*/
        if (posValida(numLinhas, numColunas, labirinto, pos_i+k, pos_j)){
            achouSol = resolveLabirinto(numLinhas, numColunas, linhaSaida, colunaSaida, labirinto, solucao, pos_i+k, pos_j);
        }
        /*se a solucao ja foi encontrada sabe-se que essa posicao faz parte da solucao e pode ser impressa*/
        if (achouSol){
            solucao[pos_i][pos_j] = '*';
            return 1;
        }
        /*checa a posica à esquerda e à direita*/
        if (posValida(numLinhas, numColunas, labirinto, pos_i, pos_j+k)){
            achouSol = resolveLabirinto(numLinhas, numColunas, linhaSaida, colunaSaida, labirinto, solucao, pos_i, pos_j+k);
        }
        /*se a solucao ja foi encontrada sabe-se que essa posicao faz parte da solucao e pode ser impressa*/
        if (achouSol){
            solucao[pos_i][pos_j] = '*';
            return 1;
        }
    }
    return 0;
}

int posValida(int numLinhas, int numColunas, char **labirinto, int pos_i, int pos_j){
    if (pos_i >= 0 && pos_j >= 0 && pos_i < numLinhas && pos_j < numColunas && labirinto[pos_i][pos_j] == 'O'){
        return 1;
    }
    return 0;
}

void imprimirLabirinto(int numLinhas, int numColunas, char **labirinto){
    int i, j;
    for(i = 0; i<numLinhas; i++){
        for(j = 0; j<numColunas; j++){
            printf("%c", labirinto[i][j]);
        }
        printf("\n");
    }
}
