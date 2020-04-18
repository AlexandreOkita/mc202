/* Nome: Alexandre Torres Okita */
/* RA: 193524 */
/* Objetivo: Identificar a diferença simetrica entre dois conjuntos */
/* Entrada: Quantidade de elementos dos conjuntos, seguido pelos valores presentes nesses */
/* Saída: Valores presentes em um conjunto resoista que representa a diferença simetrica entre os dois conjuntos anteriores */

#include <stdio.h>

/*Cria um vetor que possui os valores dos dois conjuntos (A união com B)*/
void criarVetBase(int vetBase[], int m, int n, int i);

/*Identifica os valores que não se repetem no vetor base e cria um vetor resposta com esses valores */
void criarVetResposta(int vetBase[], int vetResposta[], int m, int n, int i, int j);

int main(){
    int vetBase[80];
    int vetResposta[80];
    int m, n;
    int i = 0, j = 0;
    scanf("%d %d", &m, &n);
    criarVetBase(vetBase, m, n, i);
    criarVetResposta(vetBase, vetResposta, m, n, i, j);
    return 0;
}
void criarVetBase(int vetBase[], int m, int n, int i){
    for (i = 0; i < m+n; i++)
        scanf("%d", &vetBase[i]);
}
void criarVetResposta(int vetBase[], int vetResposta[], int m, int n, int i, int j){
    int repeticoes = 0, indice = 0;

    /* Verifica se um valor se repete e, caso não, o insere no vetor resposta */
    for (i = 0; i < m+n; i++) {
        for (j = 0; j < m+n; j++){
            if (vetBase[i] == vetBase[j]){
                repeticoes += 1;
            }
        }
        if (repeticoes < 2){
            vetResposta[indice] = vetBase[i];
            indice += 1;
        }
        repeticoes = 0;
    }
    /* Imprime os valores do vetor resposta */
    for (i = 0; i < indice; i++) {
        printf("%d ", vetResposta[i]);
    }
}
