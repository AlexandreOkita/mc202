typedef struct{
    char nome[20];
    int peso;
} Item;
typedef Item *p_item;

typedef struct{
    p_item *vet;
    int n, tamanho;
} Fila_prior;
typedef Fila_prior *p_fp;

/*Cria uma fila de prioridade com um vetor de tamanho tam e com zero elementos */
/*Entrada: Tamanho do vetor*/
/*Saída: Ponteiro para a fila criada*/
p_fp criar_fila_prior(int tam);

/*Cria um item com o nome e peso especificado*/
/*Entrada: Nome do item e peso*/
/*Saída: Ponteiro para o item criado*/
p_item criar_item(char nome[], int peso);

/*Insere um item no heap e faz com que a propriedade de heap maximo nao seja perdida*/
/*Entrada: Item que sera inserido e o heap*/
void insere_max(p_item item, p_fp fprio);

/*Insere um item no heap e faz com que a propriedade de heap minimo nao seja perdida*/
/*Entrada: Item que sera inserido e o heap*/
void insere_min(p_item item, p_fp fprio);

/*Extrai o valor maximo da fila de prioridade e mantem a propriedade de heap maximo*/
/*Entrada: heap que sera extraido*/
/*Saída: item de valor maximo extraido do heap*/
p_item extrai_maximo(p_fp fprio);

/*Extrai o valor minimo da fila de prioridade e mantem a propriedade de heap minimo*/
/*Entrada: heap que sera extraido*/
/*Saída: item de valor minimo extraido do heap*/
p_item extrai_minimo(p_fp fprio);

/*Limpa a memoria utilizada pelo heap*/
/*Entrada: Heap que sera destruido*/
void destruir_fila_prior(p_fp fila);
