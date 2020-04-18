typedef struct No_duplo{
    int dado;
    struct No_duplo *ant;
    struct No_duplo *prox;
}  No_duplo;

typedef No_duplo *p_no;

/*Inicializa uma lista ligada*/
/*Entrada: variavel que sera Inicializada*/
/*Saida: lista inicializada */
p_no criar_lista();

/*Destroi recurssivamente a lista ligada*/
/*Entrada: lista que será destruida*/
void destruir_lista(p_no lista);

/*Adiciona um elemento na lista */
/*Entrada: lista que sera adicionado o elemento*/
/*Saida: lista atualizada com o elemento adicionado*/
p_no adicionar_elemento(p_no lista, int elem);

/*Imprime a lista na ordem correta*/
/*Entrada: lista que sera impressa*/
void imprimir_lista(p_no lista);

/*Soma o valor representado pelos nos das listas */
/*Entrada: duas listas as quais serao somadas*/
/*Saida: lista com o valor da soma*/
p_no somar_listas(p_no lista1, p_no lista2);

/*Retira o excesso de zeros da lista dada*/
/*Entrada: lista que sera alterada*/
void limpar_lista(p_no lista);
