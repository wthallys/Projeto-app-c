#ifndef _TRATADORES_H_
#define _TRATADORES_H_

#include "dados.h"
void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno);
void tratador_menu_professor(Professor **professores, int *qtd_atual_professor);
void tratador_menu_turma(Turma **turmas, Aluno **alunos, int *qtd_atual_turma);

/*
    endereço
*/

Endereco *construir_endereco();

void imprimir_endereco(Endereco *endereco);

/*
    aluno
*/

Aluno *construir_aluno();

Aluno *buscar_aluno(Aluno **alunos, int *posicao);

void imprimir_aluno(Aluno *aluno);

Aluno *atualizar_aluno();



/*
    professor
*/

Professor *construir_professor();

Professor *buscar_professor(Professor **professores, int *posicao);

void imprimir_professor(Professor *profesores);

Professor *atualizar_professor();

/*
    turma
*/

Turma *construir_turma();
Turma *buscar_turma(Turma **turmas, int *posicao);
void imprimir_turma(Turma *turma);
void adicionar_aluno(Turma *turma, Aluno *aluno);

#endif