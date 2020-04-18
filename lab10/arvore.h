typedef struct arvore {
    char dado[20];
    struct arvore *direita, *esquerda;
} arvore;
typedef arvore *p_arvore;

/*Cria uma arvore com a raiz, e os ponteiros indicados*/
/*Entrada: Chave da raiz, no esquerdo e no direito*/
/*Saida: ponteiro apontando para a arvore criada*/
p_arvore criar_arvore(char *dado, p_arvore esq, p_arvore dir);

/*Imprime a arvore com as especificacoes do enunciado*/
/*Entrada: arvore que sera impressa*/
void imprimirArvore(p_arvore raiz);

/*Limpa da memoria o espaco utilizado pela arvore*/
/*Entrada: arvore que sera destruida*/
void destruir_arvore(p_arvore raiz);
