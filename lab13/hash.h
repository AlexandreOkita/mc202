/*Struct utilizada para guardar o sobrenome e primeiro nome de um autor*/
typedef struct{
    char sobrenome[16];
    char inicial;
} Autor;
typedef Autor *p_autor;

/*Struct utilizada durante a implementacao, atualmente utilizada apenas para guardar a chave entre uma combinacao de dois autores*/
typedef struct{
    char chave[34];
} Comb;
typedef Comb *p_comb;

typedef struct{
    p_comb *vet;
    int n;
} Hash;
typedef Hash *p_hash;

/*Inicializa uma combinacao*/
/*Entrada: uma chave representada pela concatenacao de dois autores*/
/*Saida: um ponteiro para a combinacao*/
p_comb criar_comb(char *chave);

/*Inicializa um hash*/
/*Saida: um ponteiro para o hash inicializado*/
p_hash criar_hash();

/*Destroi um hash e seu conteudo*/
/*Entrada: hash que sera destruido*/
void destruir_hash(p_hash hash);

/*Insere uma combinacao em um hash*/
/*Entrada: a combinacao e o hash que ela sera inserida*/
void inserir(p_comb comb, p_hash hash);

/*Busca por uma combinacao a partir de uma chave*/
/*Entrada: chave e hash que sera buscado*/
/*Saida: combinacao encontrada ou NULL caso nada tenha sido encontrado*/
p_comb buscar(char* chave, p_hash hash);

/*Inicializa um autor*/
/*Entrada: letra do primeiro nome e o sobrenome*/
/*Saida: ponteiro para autor criado*/
p_autor criar_autor(char inicial, char *sobrenome);
