#include <stdio.h>
#include <stdlib.h>
#include "treap.h"

/*Realiza a diferenca simetrica fazendo o conjunto uniao menos o conjunto interscecao*/
/*Entrada: dois conjuntos os quais sera realizada a diferenca simetrica*/
/*Saida: retorna um conjunto que representa a diferenca simetrica*/
p_no diferenca_simetrica(p_no conjunto1, p_no conjunto2);
/*Adiciona os numeros inicias nos conjuntos*/
/*Entrada: conjunto que sera preenchido*/
/*Saida: retorna o conjunto atualizado*/
p_no adicionar_numeros(p_no conjunto);

int main(){
    p_no *conjuntos;
    p_no conjuntoR;
    int num_conjuntos, i;

    scanf("%d", &num_conjuntos);
    conjuntos = malloc(num_conjuntos * sizeof(p_no));

    /* Cria todos os conjuntos dados pela entrada */
    for (i = 0; i < num_conjuntos; i++) {
        conjuntos[i] = criar_conjunto();
        conjuntos[i] = adicionar_numeros(conjuntos[i]);
    }
    /* Conjunto em que vai ser armazenado as diferencas simetricas */
    conjuntoR = criar_conjunto();
    conjuntoR = diferenca_simetrica(conjuntos[0], conjuntos[1]);
    for (i = 2; i < num_conjuntos; i++)
        conjuntoR = diferenca_simetrica(conjuntoR, conjuntos[i]);

    imprimir(conjuntoR);
    destruir(conjuntoR);
    free(conjuntos);
    printf("\n");
    return 0;
}

p_no adicionar_numeros(p_no conjunto){
    int n, i, num;
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        scanf("%d", &num);
        conjunto = inserir(conjunto, num);
    }
    return conjunto;
}
int pertence_conjunto(int num, p_no conjunto){
    if(busca(conjunto, num) == NULL)
        return 0;
    return 1;
}
p_no unir(p_no conjunto1, p_no conjunto2){
    if(conjunto2 != NULL){
        /*Adiciona todos os elementos do conjunto2 os quais nao estao no conjunto1*/
        if(!pertence_conjunto(conjunto2->chave, conjunto1)){
            conjunto1 = inserir(conjunto1, conjunto2->chave);
        }
        conjunto1 = unir(conjunto1, conjunto2->esq);
        conjunto1 = unir(conjunto1, conjunto2->dir);
    }
    return conjunto1;
}
p_no intersec(p_no conjunto1, p_no conjunto2, p_no conv){
    if(conjunto2 != NULL){
        /*Adiciona no conjunto de intersceccao os elementos que estao no conjunto 1 e 2*/
        if(pertence_conjunto(conjunto2->chave, conjunto1)){
            conv = inserir(conv, conjunto2->chave);
        }
        conv = intersec(conjunto1, conjunto2->esq, conv);
        conv = intersec(conjunto1, conjunto2->dir, conv);
    }
    return conv;
}
p_no diferenca(p_no uniao, p_no convergencia, p_no dif){
    if(uniao != NULL){
        /*Adiciona no conjunto de diferenca todos os elementos da uniao que nao estao no conjunto de interseccao*/
        if(!pertence_conjunto(uniao->chave, convergencia)){
            dif = inserir(dif, uniao->chave);
        }
        dif = diferenca(uniao->esq, convergencia, dif);
        dif = diferenca(uniao->dir, convergencia, dif);
    }
    return dif;
}
p_no diferenca_simetrica(p_no conjunto1, p_no conjunto2){
    p_no uniao, conv, dif_sim;
    conv = criar_conjunto();
    uniao = criar_conjunto();
    dif_sim = criar_conjunto();
    conv = intersec(conjunto1, conjunto2, conv);
    uniao = unir(conjunto1, conjunto2);
    dif_sim = diferenca(uniao, conv, dif_sim);
    destruir(conv);
    destruir(uniao);
    destruir(conjunto2);
    return dif_sim;
}
