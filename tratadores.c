#include "tratadores.h"
#include "menus.h"
#include <stdio.h>
#include "constantes.h"
#include <string.h>

void tratador_menu_aluno(Aluno **alunos, int *qtd_atual_aluno)
{
    int opcao = menu_crud_aluno();
    Aluno *aluno = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_aluno >= MAX_ALUNO)
        {
            printf("Número máximo de alunos atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_aluno; i++)
            {
                if (alunos[i] != NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Aluno *aluno = construir_aluno(alunos);
            alunos[i] = aluno;
            *qtd_atual_aluno++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            imprimir_aluno(aluno);
        }
        else
        {
            printf("Aluno não encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            atualizar_aluno(aluno);
            printf("Aluno atualizado!!\n");
        }
        else
        {
            printf("Aluno não encontrado!!\n");
        }
    }

    break;
    case 4:
    {
        int posicao = 0;
        aluno = buscar_aluno(alunos, &posicao);
        if (aluno)
        {
            destruirAluno(aluno);
            alunos[posicao] = NULL;
            printf("Aluno destruido\n");
        }
        else
        {
            printf("Aluno não encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}



Aluno *construir_aluno(Aluno **alunos)
{
    Aluno aluno;
    printf("Matrícula\t> ");
    fgets(aluno.matricula, 9, stdin);
    if (alunos[0] != NULL) {
        int posicao = 0;
        printf("Verificando se a matrícula já existe, pfv insira novamente:\n");
        Aluno *resultado = buscar_aluno(alunos, &posicao);
        if (resultado) {
            printf("Matrícula já existente!\n");
            return 0;
        }
    }
    printf("CPF\t> ");
    fgets(aluno.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(aluno.nome, 49, stdin);
    aluno.endereco = construir_endereco();
    return criarAluno(aluno.matricula, aluno.cpf, aluno.nome, aluno.endereco);
}

Aluno *atualizar_aluno(Aluno *aluno)
{
    Aluno novo_aluno;
    printf("CPF\t> ");
    fgets(novo_aluno.cpf, 12, stdin);
    printf("Nome\t> ");
    fgets(novo_aluno.nome, 49, stdin);
    novo_aluno.endereco = construir_endereco();
    return atualizarAluno(aluno, &novo_aluno); 
}

Aluno *buscar_aluno(Aluno **alunos, int *posicao)
{
    char matricula[50];
    printf("Matrícula > ");
    fgets(matricula, 49, stdin);
    Aluno *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_ALUNO; i++)
    {
        // Vamos testar se o aluno existe e se a matricula e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (alunos[i] && !strcmp(matricula, alunos[i]->matricula))
        {
            resultado = alunos[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void imprimir_aluno(Aluno *aluno)
{
    printf("Matrícula: %s", aluno->matricula);
    printf("Nome: %s", aluno->nome);
    printf("CPF: %s", aluno->cpf);
    imprimir_endereco(aluno->endereco);
}

// ----Professor----

void tratador_menu_professor(Professor **professores, int *qtd_atual_professor)
{
    int opcao = menu_crud_professor();
    Professor *professor = NULL;
    switch (opcao)
    {
    case 1:
        if (*qtd_atual_professor >= MAX_PROFESSOR)
        {
            printf("Número máximo de professores atingido\n");
        }
        else
        {
            // Passo 1: buscar posicao disponível
            int i = 0;
            for (; i < *qtd_atual_professor; i++)
            {
                if (professores[i] == NULL)
                {
                    // significa que esta posição está livre para uso
                    break;
                }
            }
            Professor *professor = construir_professor(professores);
            professores[i] = professor;
            *qtd_atual_professor++;
        }
        break;
    case 2:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            imprimir_professor(professor);
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }
    break;
    case 3:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            atualizar_professor(professor);
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }

    break;
    case 4:
    {
        int posicao = 0;
        professor = buscar_professor(professores, &posicao);
        if (professor)
        {
            destruirProfessor(professor);
            professores[posicao] = NULL;
            printf("Professor destruido\n");
        }
        else
        {
            printf("Professor não encontrado!!\n");
        }
    }

    break;
    default:
        printf("Retornando ao menu principal\n");
        break;
    }
}

Professor *construir_professor(Professor **professores)
{
    Professor professor;
    printf("Matrícula\t> ");
    fgets(professor.matricula, 9, stdin);
    if (professores[0] != NULL) {
        int posicao = 0;
        printf("Verificando se a matrícula já existe, pfv insira novamente:\n");
        Professor *resultado = buscar_professor(professores, &posicao);
        if (resultado) {
            printf("Matrícula já existente!\n");
            return 0;
        }
    }
    printf("CPF\t> ");
    fgets(professor.cpf, 9, stdin);
    printf("Nome\t> ");
    fgets(professor.nome, 49, stdin);
    professor.endereco = construir_endereco();
    return criarProfessor(professor.matricula, professor.cpf, professor.nome, professor.endereco);
}

Professor *atualizar_professor(Professor *professor)
{
    Professor novo_professor;
    printf("CPF\t> ");
    fgets(novo_professor.cpf, 12, stdin);
    printf("Nome\t> ");
    fgets(novo_professor.nome, 49, stdin);
    novo_professor.endereco = construir_endereco();
    return atualizarProfessor(professor, &novo_professor); 
}



Professor *buscar_professor(Professor **professores, int *posicao)
{
    char matricula[50];
    printf("Matrícula > ");
    fgets(matricula, 49, stdin);
    Professor *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_PROFESSOR; i++)
    {
        // Vamos testar se o aluno existe e se a matricula e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (professores[i] && !strcmp(matricula, professores[i]->matricula))
        {
            resultado = professores[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}



void imprimir_professor(Professor *professor)
{
    printf("Matrícula: %s", professor->matricula);
    printf("Nome: %s", professor->nome);
    printf("CPF: %s", professor->cpf);
    imprimir_endereco(professor->endereco);
}


//---Endereço---

Endereco *construir_endereco()
{
    Endereco endereco;

    printf("Logradouro\t> ");
    fgets(endereco.logradouro, 49, stdin);
    printf("Bairro\t> ");
    fgets(endereco.bairro, 49, stdin);
    printf("Cidade\t> ");
    fgets(endereco.cidade, 49, stdin);
    printf("Estado\t> ");
    fgets(endereco.estado, 9, stdin);
    printf("Número\t> ");
    fgets(endereco.numero, 9, stdin);

    return criarEndereco(endereco.logradouro, endereco.bairro, endereco.cidade, endereco.estado, endereco.numero);
}

void imprimir_endereco(Endereco *endereco)
{
    printf("Logradouro: %s", endereco->logradouro);
    printf("Número: %s", endereco->numero);
    printf("Bairro: %s", endereco->bairro);
    printf("Cidade: %s", endereco->cidade);
    printf("Estado: %s", endereco->estado);
}

//---Turma---

void tratador_menu_turma(Turma **turmas, Aluno **alunos, int *qtd_atual_turma)
{
    int opcao = menu_crud_turma();
    Turma *turma = NULL;
    Aluno *aluno = NULL;
    switch (opcao)
    {
        case 1:
        
            if (*qtd_atual_turma >= MAX_TURMA)
            {
                printf("Número máximo de turmas atingido\n");
            }
            else
            {
                // Passo 1: buscar posicao disponível
                int i = 0;
                for (; i <= *qtd_atual_turma; i++)
                {
                    if (turmas[i] == NULL)
                    {
                        // significa que esta posição está livre para uso
                        break;
                    }
                }
                Turma *turma = construir_turma();
                turmas[i] = turma;
                *qtd_atual_turma++;
            }
            break;
        case 2:
        {
            int posicao = 0;
            turma = buscar_turma(turmas, &posicao);
            if (turma)
            {
                imprimir_turma(turma);
            }
            else
            {
                printf("Turma não encontrada!!\n");
            }
            break;
        }
        case 3:
        {
            int posicao = 0;
            turma = buscar_turma(turmas, &posicao);
            if (turma)
            {
                posicao = 0;
                aluno = buscar_aluno(alunos, &posicao);

                if (aluno)
                {
                    adicionar_aluno(turma, aluno);
                    printf("Aluno adicionado com sucesso!\n");
                }
                else
                {
                    printf("Aluno não encontrado!!\n");
                }
            }
            else
            {
                printf("Turma não encontrada!!\n");
            }
            break;
        }
        default:
            printf("Retornando ao menu principal\n");
            break;
    }
}

Turma *construir_turma()
{
    Turma turma;
    printf("Codigo da turma\t> ");
    fgets(turma.codigo, 50, stdin);
    printf("Nome da disciplina\t> ");
    fgets(turma.nome_disciplina, 50, stdin);
    printf("Nome do professor\t> ");
    fgets(turma.professor, 50, stdin);
    printf("Media\t> ");
    scanf("%f", &turma.media_turma);
    getchar();
    return criarTurma(turma.codigo, turma.nome_disciplina, turma.professor, turma.media_turma);
}

void imprimir_turma(Turma *turma)
{
    printf("== Turma %s ==", turma->codigo);
    printf("Codigo: %s", turma->codigo);
    printf("Nome da Disciplina: %s", turma->nome_disciplina);
    printf("Media da Turma: %.2f\n", turma->media_turma);
    printf("Quantidade de alunos: %d\n", turma->qtd_alunos);

    if (turma->professor != NULL)
    {
        printf("Professor: %s", turma->professor->nome);
    }
    
    if (turma->qtd_alunos != 0) {
        for (int i = 0; i < turma->qtd_alunos; i++)
        {
            printf("Nº do aluno: %d\n", i+1);
            printf("Nome do aluno: %s", turma->lista_alunos[i].nome);
            printf("Matrícula do aluno: %s", turma->lista_alunos[i].matricula);
        }
    }
}

Turma *buscar_turma(Turma **turmas, int *posicao)
{
    char codigo[50];
    printf("Codigo da turma > ");
    fgets(codigo, 49, stdin);
    Turma *resultado = NULL;
    int pos_resultado = -1;
    for (int i = 0; i < MAX_TURMA; i++)
    {
        // Vamos testar se o aluno existe e se a codigo e a buscada
        // strcmp compara strings. Se for 0 indica que são iguais
        if (turmas[i] && !strcmp(codigo, turmas[i]->codigo))
        {
            resultado = turmas[i];
            break;
        }
    }
    *posicao = pos_resultado;
    return resultado;
}

void adicionar_aluno(Turma *turma, Aluno *aluno) {
    adicionarAluno(turma, aluno);
}
