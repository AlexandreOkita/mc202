#include "universidade.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

p_professor criarProfessor(char nome[], char sobrenome[], double salario, char disciplina[]){
    p_professor novoProf;
    novoProf = malloc(sizeof(Professor));
    strcpy(novoProf->nome, nome);
    strcpy( novoProf->sobrenome, sobrenome);
    novoProf->salario = salario;
    strcpy(novoProf->disciplina, disciplina);
    return novoProf;
}
void destruirProfessor(p_professor professor){
    free(professor);
}
p_aluno criarAluno(char nome[], char sobrenome[]){
    p_aluno novoAluno;
    novoAluno = malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    strcpy(novoAluno->sobrenome, sobrenome);
    novoAluno->qtd_disciplinas = 0;
    return novoAluno;
}
void adicionarDisciplina(p_aluno aluno, char disciplina[], double nota){
    strcpy(aluno->disciplinas[aluno->qtd_disciplinas], disciplina);
    aluno->notas[aluno->qtd_disciplinas] = nota;
    aluno->qtd_disciplinas++;
}
void destruirAluno(p_aluno aluno){
    free(aluno);
}
void obterNotasExtremas(p_aluno alunos[], int qtd_alunos, char disciplina[], double *nota_min, double *nota_max){
    int i;
    int posicao;
    int flag = 1;
    *nota_min = 10;
    *nota_max = 0;
    for (i = 0; i<qtd_alunos; i++){
        for (posicao = 0; posicao<alunos[i]->qtd_disciplinas; posicao++){
            flag = strcmp(alunos[i]->disciplinas[posicao], disciplina);
            if (flag == 0){
                if (*nota_min > alunos[i]->notas[posicao]){
                    *nota_min = alunos[i]->notas[posicao];
                }
                if (*nota_max < alunos[i]->notas[posicao]){
                    *nota_max = alunos[i]->notas[posicao];
                }
            }
        }
    }
}
void reajusteSalario(p_professor professor, double media_notas){
    if (media_notas == 10){
        professor->salario += professor->salario*0.15;
    }
    else if (media_notas >= 9){
        professor->salario += professor->salario*0.10;
    }
    else if (media_notas >= 8.5){
        professor->salario += professor->salario*0.05;
    }
}
void imprimirProfessor(p_professor professor){
    printf("%s %s %0.2f\n", professor->nome, professor->sobrenome, professor->salario);
}
