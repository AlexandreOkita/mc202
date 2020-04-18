#include <stdio.h>
#include <stdlib.h>

int main(){
    double media, *notas;
    int i, n;
    scanf("%d", &n);
    notas = malloc(n * sizeof(double));
    for (i = 0; i<n; i++){
        scanf("%lf", &notas[i]);
        if (i == n){
            notas = malloc(2*n*sizeof(double));
        }
    }
    media = 0;
    for (i = 0; i<n; i++){
        printf("%lf\n", notas[i]);;
    }
    printf("Media %f\n", media);
    return 0;
}
