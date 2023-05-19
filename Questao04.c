#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 10
#define MAX_TURMA 3

	typedef struct {
    char nome[50];
    int notas;
    char turma[3];
	} Aluno;

	void obterMelhorNota(Aluno alunos[], int numAlunos, int *maiorNota) {
    int i;
    *maiorNota = 0;
    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].notas > *maiorNota) {
            *maiorNota = alunos[i].notas;
        }
    }
	}

	void obterTurmasMelhorNota(Aluno alunos[], int numAlunos, int maiorNota, char turmas[][3], int *numTurmas) {
    int i;
    *numTurmas = 0;
    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].notas == maiorNota) {
            strcpy(turmas[*numTurmas], alunos[i].turma);
            (*numTurmas)++;
        }
    }
	}

	void obterQuantidadeAlunosPorTurma(Aluno alunos[], int numAlunos, char turma[], int *quantidade) {
    int i;
    *quantidade = 0;
    for (i = 0; i < numAlunos; i++) {
        if (strcmp(alunos[i].turma, turma) == 0) {
            (*quantidade)++;
        }
    }
	}

	int main() {
    Aluno alunos[MAX_ALUNOS];
    int numAlunos, i;
    int maiorNota;
    char turmas[MAX_ALUNOS][MAX_TURMA];
    int numTurmas;
    
    printf("digite o numero de alunos (ate %d): ", MAX_ALUNOS);
    scanf("%d", &numAlunos);
    
    printf("digite os dados dos alunos:\n");
    for (i = 0; i < numAlunos; i++) {
        printf("aluno %d:\n", i+1);
        printf("nome: ");
        scanf("%s", alunos[i].nome);
        printf("notas: ");
        scanf("%d", &alunos[i].notas);
        printf("turmas: ");
        scanf("%s", alunos[i].turma);
    }
    
    obterMelhorNota(alunos, numAlunos, &maiorNota);
    obterTurmasMelhorNota(alunos, numAlunos, maiorNota, turmas, &numTurmas);
    
    printf("\numero de alunos com maior nota (%d):\n", maiorNota);
    for (i = 0; i < numAlunos; i++) {
        if (alunos[i].notas == maiorNota) {
            printf("%s\n", alunos[i].nome);
        }
    }
    
    printf("\numero de turmas com a maior nota (%d):\n", maiorNota);
    for (i = 0; i < numTurmas; i++) {
        printf("%s\n", turmas[i]);
    }
    
    printf("\numero de quantidade de alunos por turma com a maior nota (%d):\n", maiorNota);
    for (i = 0; i < numTurmas; i++) {
        int quantidade;
        obterQuantidadeAlunosPorTurma(alunos, numAlunos, turmas[i], &quantidade);
        printf("Turma %s: %d aluno(s)\n", turmas[i], quantidade);
    }
    
    return 0;
	}