typedef struct No {
    int chave, prior;
    struct No *esq, *dir, *pai;
} No;
typedef No *p_no;

/*Inicializa um conjunto como null*/
/*Saida: um ponteiro apontando para null*/
p_no criar_conjunto();
/*Realiza uma busca em Olog(n) atraves da arvore*/
/*Entrada: o conjunto que deseja ser buscado e o elemento*/
/*Saida: retorna a raiz procurada ou null caso nao seja encontrada*/
p_no busca(p_no raiz, int chave);
/*Insere o elemento em Olog(n) desejado e rotaciona para manter a arvore balanceada*/
/*Entrada: o conjunto que tera o elemento inserido e o elemento*/
/*Saida: a arvore que representa o conjunto atualizada*/
p_no inserir(p_no raiz, int chave);
/*Imprime a arvore de modo decrescente*/
/*Entrada: a raiz da arvore que sera impressa*/
void imprimir(p_no raiz);
/*Remove em Olog(n) o elemento e atualiza a arvore (essa funcao nao sera utilizada no cliente, pois nao conseguiu rotacionar perfeitamente)*/
/*Entrada: arvore que tera o elemento removido e o elemento que sera removido*/
/*Saida: arvore atualizada com o elemento removido*/
p_no remover(p_no raiz, int chave);
/*Limpa a arvore da memoria*/
/*Entrada: arvore que sera destruida*/
void destruir(p_no raiz);
