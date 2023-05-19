#include <stdio.h>
#define MIN_NUM 1
#define MAX_NUM 99

	int le_valida_num() {
    int num;
    do {
        printf("digite um numero entre 1 e 99 (par e nao multiplo de 5): ");
        scanf("%d", &num);
    } while ((num < MIN_NUM || num > MAX_NUM) || (num % 2 != 0 || num % 5 == 0));
    return num;
	}

	void selecao_crescente(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
	}

	void selecao_decrescente(int arr[], int n) {
    int i, j, max_idx, temp;
    for (i = 0; i < n - 1; i++) {
        max_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }
        temp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = temp;
    }
	}

	int main() {
    int numeros[10];
    int i, n;

    for (i = 0; i < 2; i++) {
        numeros[i] = le_valida_num();
    }

    n = 2;
    char deseja_sair;
    do {
        if (n >= 10) {
            printf("numero maximo de elementos atingindo\n");
            break;
        }

        printf("deseja sair? (S ou N):");
        scanf(" %c", &deseja_sair);

        if (deseja_sair == 'S' || deseja_sair == 's') {
            break;
        }

        numeros[n] = le_valida_num();
        n++;
    } while (1);

    printf("valores em ordem cresecente:\n");
    selecao_crescente(numeros, n);
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("valores em ordem descrecente:\n");
    selecao_decrescente(numeros, n);
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
	}