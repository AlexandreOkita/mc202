/*Nome: Alexandre Torres Okita*/
/*RA: 193524*/
/*Objetivo: Criar um programa que calcula o ajuste salarial do professor a partir da média dos alunos*/
/*Entrada: A entrada é composta, primeiramente, de linhas contendo o nome e sobrenome, o salário
e a disciplina lecionada pelo professor. Depois disso, há o nome e sobrenome, as disciplinas seguidas
das respectivas notas dos alunos.*/
/*Saída: O programa deve imprimir o nome do professor seguido do novo salário*/

#include <stdio.h>
#include <stdlib.h>
#include "universidade.h"

int main(){
    int numProfs, numAlunos, numDisciplinas;
    int i, j;
    char nome[MAX_NOME];
    char sobrenome[MAX_NOME];
    double salario, nota, nota_min = 0, nota_max = 10, media;
    char disciplina[MAX_CODIGO];
    p_professor *professores;
    p_professor professor;
    p_aluno *alunos;
    p_aluno aluno;
    /*Lê e cria os professores da universidade*/
    scanf("%d\n", &numProfs);
    professores = malloc(numProfs * sizeof(p_professor));
    for (i = 0; i<numProfs; i++){
        scanf("%s %s %lf %s", nome, sobrenome, &salario, disciplina);
        professor = criarProfessor(nome, sobrenome, salario, disciplina);
        professores[i] = professor;
    }
    /*Lê e cria os alunos da universidade*/
    scanf("%d\n", &numAlunos);
    alunos = malloc(numAlunos * sizeof(p_aluno));
    for (i = 0; i<numAlunos; i++){
        scanf("%s %s %d", nome, sobrenome, &numDisciplinas);
        aluno = criarAluno(nome, sobrenome);
        for (j = 0; j<numDisciplinas; j++){
            scanf("%s %lf", disciplina, &nota);
            adicionarDisciplina(aluno, disciplina, nota);
        }
        alunos[i] = aluno;
    }
    /*Calcula o novo salario dos professores a partir da média dos alunos*/
    for (i = 0; i<numProfs; i++){
        obterNotasExtremas(alunos, numAlunos, professores[i]->disciplina, &nota_min, &nota_max);
        media = (nota_min + nota_max)/2;
        reajusteSalario(professores[i], media);
        imprimirProfessor(professores[i]);
    }
    /*Impede vazamento de memória*/
    for (i = 0; i<numProfs; i++){
        destruirProfessor(professores[i]);
    }
    free(professores);
    for (i = 0; i<numAlunos; i++){
        destruirAluno(alunos[i]);
    }
    free(alunos);
    return 0;
}
