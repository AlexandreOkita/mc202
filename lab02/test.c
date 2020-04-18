#include <stdio.h>

int main(){
    int matriz[100][100];
    int i = 0, j = 0;

    for (i = 0; i < 4; i++) {
        for (j=0; j < 4; j++) {
            matriz[i][j] = j+i;
            printf("%d ", matriz[i][j]);
        }
    }
    return 0;
}
