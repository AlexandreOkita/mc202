typedef struct No{
    int vert;
    struct No *prox;
} No;
typedef No *p_no;

typedef struct{
    int tam;
    p_no *adj;
} Grafo;
typedef Grafo *p_grafo;

/*Cria um grafo de tamanho pré-definido*/
/*Entrada: tamanho do grafo*/
/*Saída: ponteiro para o grafo criado*/
p_grafo criar_grafo(int tam);

/*Limpa a memória utilizada pelo grafo em sua totalidade*/
/*Entrada: grafo que será destruído*/
void destruir_grafo(p_grafo grafo);

/*Insere uma aresta no grafo, inserindo v1 na lista de v2 e v2 na lista de v1*/
/*Entrada: grafo e vertices relacionados que serao adicionados*/
void inserir_aresta(p_grafo grafo, int v1, int v2);

/*Remove uma aresta no grafo, removindo v1 da lista de v2 e v2 da lista de v1*/
/*Entrada: grafo e relacao que sera removida*/
void remover_aresta(p_grafo grafo, int v1, int v2);

/*Retorna verdadeiro caso tenha uma relacao entre v1 e v2 no grafo*/
/*Entrada: grafo e vertices que sera checada a relacao*/
/*Saída: retorna 1 caso verdadeiro e 0 se falso*/
int tem_aresta(p_grafo grafo, int v1, int v2);

/*Imprime as arestas do grafo*/
/*Entrada: grafo que tera as arestas impressas*/
void imprimir_arestas(p_grafo grafo);

/*Encontra as componentes conexas de um grafo*/
/*Entrada: grafo que será realizada a operacao*/
/*Saída: vetor de componentes*/
int* encontra_conexoes(p_grafo g);

/*Encontra a distancia maxima de um caminho minimo de um vertice ate outro no grafo*/
/*Entrada: grafo e vertice*/
/*Saída: devolve o valor da distancia encontrada*/
int arestas_min_entre_vertices(p_grafo g, int vert);
