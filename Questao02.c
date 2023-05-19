#include <stdio.h>
#include <stdlib.h>

#define MIN_NUM 10
#define MAX_NUM 20

    int le_valida_num() {
    int num;
    while (1) {
    printf("Informe um numero impar que nao seja multiplo de 3 (entre 1 e 99): ");
    scanf("%d", &num);
            if (num < 1 || num > 99) {
            printf("Valor incorreto! O numero deve estar entre 1 e 99\n");
            continue;
        }
            if (num % 2 == 0) {
            printf("Valor incorreto! O numero deve ser impar\n");
            continue;
        }
            if (num % 3 == 0) {
            printf("Valor incorreto! O numero nao deve ser multiplo de 3\n");
            continue;
        }
    return num;
    }
    }

    void ordena_insercao(int *numeros, int tam) {
    int i, j, chave;
    for (i = 1; i < tam; i++) {
    chave = numeros[i];
    j = i - 1;
    while (j >= 0 && numeros[j] < chave) {
    numeros[j + 1] = numeros[j];
    j = j - 1;
        }
    numeros[j + 1] = chave;
    }
    }

    int main() {
    int numeros[MAX_NUM];
    int i, num, qtd_numeros = 0;
    while (qtd_numeros < MIN_NUM) {
        num = le_valida_num();
        numeros[qtd_numeros++] = num;
        if (qtd_numeros == MIN_NUM) {
            char opcao;
            printf("Deseja informar outros numeros (s/n)? ");
            scanf(" %c", &opcao);
            if (opcao != 's' && opcao != 'S') {
                break;
            }
        }
    }
    ordena_insercao(numeros, qtd_numeros);
    printf("Numeros ordenados de forma decrescente:\n");
    for (i = 0; i < qtd_numeros; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    return 0;
}