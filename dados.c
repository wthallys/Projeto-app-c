#include "dados.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end)
{
    Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
    if (aluno)
    {
        strcpy(aluno->matricula, matricula); // Copia matricula para aluno->matricula
        strcpy(aluno->cpf, cpf);
        strcpy(aluno->nome, nome);
        aluno->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return aluno;
}

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero)
{
    Endereco *endereco = (Endereco *)malloc(sizeof(Endereco));
    if (endereco)
    {
        strcpy(endereco->logradouro, logradouro);
        strcpy(endereco->bairro, bairro);
        strcpy(endereco->cidade, cidade);
        strcpy(endereco->estado, estado);
        strcpy(endereco->numero, numero);
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return endereco;
}

void destruirAluno(Aluno *aluno)
{
    if (aluno)
    {
        Endereco *end = aluno->endereco;
        destruirEndereco(end);
        free(aluno);
    }
}

void destruirEndereco(Endereco *endereco)
{
    if (endereco)
        free(endereco);
}

Professor *criarProfessor(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end)
{
    Professor *professor = (Professor *)malloc(sizeof(Professor));
    if (professor)
    {
        strcpy(professor->matricula, matricula); // Copia matricula para professor->matricula
        strcpy(professor->cpf, cpf);
        strcpy(professor->nome, nome);
        professor->endereco = end;
    }
    else
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }
    return professor;
}

void destruirProfessor(Professor *professor)
{
    if (professor)
    {
        Endereco *end = professor->endereco;
        destruirEndereco(end);
        free(professor);
    }
}

Professor *atualizarProfessor(Professor *professor, Professor *novo_professor)
{
    if (professor && novo_professor)
    {
        strcpy(professor->cpf, novo_professor->cpf);
        strcpy(professor->nome, novo_professor->nome);
        professor->endereco = novo_professor->endereco;
    }
    return professor;
}

Aluno *atualizarAluno(Aluno *aluno, Aluno *novo_aluno)
{
    if (aluno && novo_aluno)
    {
        strcpy(aluno->cpf, novo_aluno->cpf);
        strcpy(aluno->nome, novo_aluno->nome);
        aluno->endereco = novo_aluno->endereco;
    }
    return aluno;
}

Turma *criarTurma(char *codigo_turma,
                  char *nome_disciplina,
                  Professor *professor,
                  float media_turma) 
{
    Turma *turma = (Turma *)malloc(sizeof(Turma));
    if(turma)
    {
        strcpy(turma->codigo, codigo_turma);
        strcpy(turma->nome_disciplina, nome_disciplina);
        strcpy(turma->professor, professor);
        turma->media_turma = media_turma;
        turma->qtd_alunos = 0;
    }
    else 
    {
        perror("Não há memória disponível. Encerrando\n\n");
    }

    return turma;
}

Turma *adicionarAluno(Turma *turma, Aluno *aluno) {
    if (turma && aluno) 
    {
        strcpy(turma->lista_alunos[turma->qtd_alunos].matricula, aluno->matricula);
        strcpy(turma->lista_alunos[turma->qtd_alunos].nome, aluno->nome);
        strcpy(turma->lista_alunos[turma->qtd_alunos].cpf, aluno->cpf);
        turma->lista_alunos[turma->qtd_alunos].endereco = aluno->endereco;
        turma->qtd_alunos += 1;
        
        printf("%s", turma->lista_alunos[turma->qtd_alunos].nome);
    }
    return turma;
}