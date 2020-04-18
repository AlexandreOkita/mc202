#include <stdio.h>

int buscaBin(int *vet, int l, int r, int x){
    int meio = (l + r)/2;
    if (l > r){
        return -1;
    }
    if (vet[meio] == x){
        return meio;
    }
    else if (vet[meio > x]){
        return buscaBin(vet, meio + 1, r, x);
    }
    else{
        return buscaBin(vet, l, meio -1, x);
    }
}
int buscaBinI(int *vet, int l, int r, int x){
    int meio = (l+r)/2;
    while (l<=r && vet[meio] != x){
        if (vet[meio > x]){
            l = meio+1;
        } else{
            r = meio-1;
        }
    }
    if (l>r){
        return -1;
    }
    return meio;
}


int main(){
    int x, l, r, i;
    int vet[10];
    scanf("%d %d %d\n", &x, &l, &r);
    for (i = 0; i<9; i++){
        scanf("%d\n", &vet[i]);
    }
    printf("%d\n", buscaBin(vet, l, r, x));
    return 0;
}
