#include <stdio.h>

void criarBase(int vetBase[], int m, int n, int i){
  for (i = 0; i < m+n; i++)
    scanf("%d", &vetBase[i]);
  }

void criarResposta(int vetBase[], int vetResposta[], int m, int n, int i, int j){

  int repeticoes, indice = 0;

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
  for (i = 0; i < indice; i++) {
    printf("%d ", vetResposta[i]);
  }
}

int main(){
  int vetBase[40];
  int vetResposta[80];
  int m, n;
  int i, j;
  scanf("%d %d", &m, &n);
  criarBase(vetBase, m, n, i);
  criarResposta(vetBase, vetResposta, m, n, i, j);
}
