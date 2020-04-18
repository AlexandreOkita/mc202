typedef struct{
    int estado;
    int soma;
    int num_a;
} Jogador;
typedef Jogador *p_jogador;

/*Cria um jogador com soma = 0 e estado como 1, que significa que esta apto a jogar*/
/*Saída: retorna o jogador criado*/
p_jogador criar_jogador();

/*Soma a carta dada com a soma atual das outras cartas em sua mao, tambem atualiza o valor dos 'A's*/
/*Entrada: carta que sera somada e jogador*/
/*Saida: jogador com a soma atualizada*/
p_jogador somar_cartas(p_jogador jogador, int carta);

/*Transforma o char em um numero (letras e '0' se tornam 10, 'A' se torna 11) alem de atualizar o numero de 'A's na mao do jogador*/
/*Entrada: jogador e a carta como char*/
/*Saida: inteiro que representa a carta dada na entrada*/
int valor_carta(p_jogador jogador, char carta);

/*Limpa a memoria alocada pelo jogador*/
/*Saida: jogador que sera destruido*/
void destruir_jogador(p_jogador jogador);
