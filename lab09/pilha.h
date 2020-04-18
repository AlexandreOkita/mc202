typedef struct {
    char *vet;
    int ini;
}  Pilha;
typedef Pilha *p_pilha;

/*Cria uma pilha utilizando um vetor de tamanho n*/
/*Entrada: tamanho da pilha*/
/*Saída: pilha criada*/
p_pilha criar_pilha(int n);

/*Limpa a memoria alocada pela pilha*/
/*Entrada: pilha que sera destruida*/
void destruir_pilha(p_pilha pilha);

/*Insere um dado no topo da pilha*/
/*Entrada: dado que sera inserido e a pilha*/
void empilhar(p_pilha pilha, int dado);

/*Retira e devolve o topo da pilha*/
/*Entrada: pilha que tera o topo removido*/
/*Saida: dado do topo da pilha*/
int desempilhar(p_pilha pilha);
