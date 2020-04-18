#include <stdio.h>

int main(){
    int k;
    char plain, cripto;
    scanf("%d\n", &k);
    scanf("%c\n", &plain);
    while (plain != '#'){
        cripto = plain + k;
        printf("%c", cripto);
        scanf("%c ", &plain);
    }
    printf("\n");
    return 0;
}
