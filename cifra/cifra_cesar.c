#include <stdio.h>

int main() {
    int k;
    char plain, cripto;
    scanf("%d ", &k);
    scanf("%c ", &plain);
    while (plain != '#'){
        cripto = 'A' + (plain - 'A' + 26 + k) % 26;
        printf("%c", cripto);
        scanf("%c", &plain);
    }
    printf("\n");
    return 0;
}
