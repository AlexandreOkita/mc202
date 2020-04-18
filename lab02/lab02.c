/*Nome: Alexandre Torres Okita */
/*RA: 193524 */
/*Objetivo: Criar duas matrizes A e B, sendo A uma matriz de permutação, e calcular uma matriz resposta A * B */
/*Entrada: A primeira linha da entrada consiste na ordem das matrizes, a segunda na matriz permutação e as n linhas a seguir na matriz B */
/*Saída: A saída deve imprimir nas especificações desejadas a matriz resposta correspondente por A * B*/

#include <stdio.h>
#define MAX 312

/*Lê o vetor de permutação e gera a matriz A a partir desse */
void criaMatrizA(int permuta[], int matrizA[MAX][MAX], int n, int i, int j);

void criaMatrizB(float matrizB[MAX][MAX], int n, int i, int j);
/*Multiplica a matriz A pela matriz B gerando uma matriz resposta com o resultado */
void multiplicaMatriz(int matrizA[MAX][MAX], float matrizB[MAX][MAX], float matrizResposta[MAX][MAX], int n, int i, int j);
/*Imprime a matriz resposta de acordo com as especificações indicadas */
void imprimir(float matrizResposta[MAX][MAX], int n, int i, int j);

int main(){
    int matrizA[MAX][MAX];
    int permuta[MAX];
    float matrizB[MAX][MAX];
    float matrizResposta[MAX][MAX];
    int n;
    int i = 0, j = 0;

    scanf("%d/n", &n);
    criaMatrizA(permuta, matrizA, n, i, j);
    criaMatrizB(matrizB, n, i, j);
    multiplicaMatriz(matrizA, matrizB, matrizResposta, n, i, j);
    imprimir(matrizResposta, n, i, j);
    return 0;
}

void criaMatrizA(int permuta[], int matrizA[MAX][MAX], int n, int i, int j){
    for(i = 0; i<n; i++){
        scanf("%d", &permuta[i]);
        permuta[i]--;
    }
    for (i = 0; i < n; i++){
        for (j=0; j < n; j++){
            matrizA[i][j] = 0;
        }
    }
    for(i = 0; i<n; i++){
        /*Insere 1 nos locais indicados pelo vetor de permutação */
        matrizA[permuta[i]][i] = 1;
    }
}

void criaMatrizB(float matrizB[MAX][MAX], int n, int i, int j){
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%f", &matrizB[i][j]);
        }
    }
}

void multiplicaMatriz(int matrizA[MAX][MAX], float matrizB[MAX][MAX], float matrizResposta[MAX][MAX], int n, int i, int j){
    float soma = 0;
    int k;
    for (i = 0; i<n; i++){
        for (k = 0; k<n; k++){
            for (j = 0; j<n; j++){
                soma += matrizA[i][j]*matrizB[j][k];
            }
            matrizResposta[i][k] = soma;
            soma = 0;
        }
    }
}

void imprimir(float matrizResposta[MAX][MAX], int n, int i, int j){
    for (i = 0; i<n; i++){
        for (j = 0; j<n; j++){
            printf("%.1f", matrizResposta[i][j]);
            /*Condição para impedir a impressão de um espaço extra no final das linhas */
            if (j<n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}
