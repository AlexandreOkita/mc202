#include <stdio.h>

int funcao1(int a){
    int b;
    b = 7;
    for (a = 0; a < b; a++){
        b = a+b;
    }
    return b/2;
}

int funcao2(void){
    int i;
    printf("informe um inteiro: \n");
    scanf("%d", &i);
    i += 5;
    return i;
}

int main(void){
    int a = 0, b = 0, i = 0;

    a = funcao1(2);
    b = funcao2();
    i = funcao1(b);
    printf("%d, %d, %d\n", a, b, i);
    return 0;
}
