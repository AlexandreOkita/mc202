#include <stdio.h>
#define MAX 1000
int main() {
    int N, M, i, j, k, c = 0, m, aux, v1[MAX];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&v1[i]);
    }
    scanf("%d",&M);

    for(i = 0; i<N; i++){
        for(j = 0; j<N; j++){
            if(v1[i] > v1[j]){
                aux = v1[i];
                v1[i] = v1[j];
                v1[j] = aux;
            }
        }
    }


    for(i=0;i<M;i++){
        scanf("%d",&m);
        for(j=0;j<N;j++){
            for(k=j+1;k<N;k++){
                if(v1[j]-v1[k]==m){
                    c++;
                }
            }
        }
        printf("%d ",c);
        c=0;
    }
    return 0;
}
