#include <stdio.h>
#include <stdlib.h>
typedef struct No {
     int dado;
     struct No *prox;
     struct No *ante;
     } No;

typedef struct No * p_no;

typedef struct List{
      struct No *head;
      struct No *tail;
}List;


List criar_lista() {
    List lista;
    lista.head=NULL;
    return lista;
    }

List adicionar_elemento(List lista, int x) {
    p_no no;
    no = malloc(sizeof(No));
    no->ante=NULL;
    no->prox=NULL;
    no->dado=x;
    if(lista.head==NULL){
        lista.head=no;
        lista.tail=no;

    }
    else{
        no->prox=lista.head;
        lista.head->ante=no;
        lista.head=no;
    }


    return lista;
}

p_no destruir_recursivo(p_no lista) {
    if (lista!= NULL) {
        destruir_recursivo(lista->prox);
        free(lista);
        }
}

int daTamanho(p_no no){
    int tam=0;
    while(no){
        tam++;
        no=no->prox;
    }
    return tam;
}

List somar(List lista1,List lista2,p_no no1,p_no no2) {
    if (no1 != NULL && no2 != NULL) {
        no1->dado += no2->dado;
        if (no1->dado > 9) {
            no1->dado -= 10;
            if (no1->prox == NULL) {
                lista1=adicionar_elemento(lista1, 1);

            }
            else {
                no1->prox->dado += 1;
            }
        }
    }

    else{
        return lista1;
    }
    somar(lista1,lista2,no1->prox,no2->prox);
}



void imprime(p_no lista) {
     if (lista != NULL){
         imprime(lista->prox);
         printf("%d", lista->dado);

         }
     }



 int main() {
     int i,cont=0,size1,size2;
     char comando,num[100],somador[100];
     List lista,lista2;
     lista=criar_lista();
     lista2 = criar_lista();
     /*lê números positivos e armazena na lista*/
     scanf("%c %s\n",&comando,num);

     for(i=0;num[i]!='\0';i++) {
        if(num[i]=='0'){
            cont++;
        }
        else
            break;
     }
     for(i=cont;num[i]!='\0';i++) {

        lista = adicionar_elemento(lista, (num[i]-'0'));
        printf("%c",num[i]);
     }
     printf("\n");
     cont=0;
     while(comando!='#') {
         printf("TESTE:");
          imprime(lista.head);
          printf("\n");
         scanf("%c %s", &comando, somador);
         for (i = 0; somador[i] != '\0'; i++) {
             if (somador[i] == '0') {
                 cont++;
             } else
                 break;
         }
         for (i = cont; somador[i] != '\0'; i++) {
             lista2 = adicionar_elemento(lista2, (somador[i] - '0'));
         }
         printf("TESTE2:");
          imprime(lista.head);
          printf("\n");


         size1 = daTamanho(lista.head);
         size2 = daTamanho(lista2.head);
         imprime(lista.head);
         printf("\n");
         imprime(lista2.head);
         printf("\n");
         if (size1 >= size2) {
             lista = somar(lista, lista2, lista.head, lista2.head);
         }
         else
             lista = somar(lista2, lista, lista2.head, lista.head);

        printf("SOMA:");
         imprime(lista.head);
         printf("\n");
         destruir_recursivo(lista2.head);
         printf("TESTE3:");
          imprime(lista.head);
          printf("\n");
         lista2=criar_lista();
     }
     return 0;
}
