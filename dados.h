#ifndef _DADOS_H_
#define _DADOS_H_

typedef struct
{
    char logradouro[50];
    char bairro[50];
    char cidade[50];
    char estado[10];
    char numero[10];
} Endereco;

typedef struct
{
    char matricula[10];
    char cpf[12];
    char nome[50];
    Endereco *endereco;
} Aluno;

Endereco *criarEndereco(char *logradouro,
                        char *bairro,
                        char *cidade,
                        char *estado,
                        char *numero);

Aluno *criarAluno(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end);

void destruirAluno(Aluno *aluno);
void destruirEndereco(Endereco *);
Aluno *atualizarAluno(Aluno *aluno, Aluno *novo_aluno); 


typedef struct
{
    char matricula[10];
    char cpf[12];
    char nome[50];
    Endereco *endereco;
} Professor;

Professor *criarProfessor(char *matricula,
                  char *cpf,
                  char *nome,
                  Endereco *end);
void destruirProfessor(Professor *professor);
Professor *atualizarProfessor(Professor *professor, Professor *novo_professor);

typedef struct 
{
    char codigo[50];
    char nome_disciplina[50];
    Professor *professor;
    Aluno lista_alunos[100];
    float media_turma;
    int qtd_alunos;
} Turma;

Turma *criarTurma(char *codigo_turma,
                  char *nome_disciplina,
                  float media_turma);

Turma *adicionarAluno(Turma *turma, Aluno *aluno);

#endif