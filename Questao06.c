#include <stdio.h>

// Funcao que recebe um parâmetro por valor
void passagemPorValor(int valor) {
    valor += 10; // Adiciona 10 ao valor recebido
    printf("Dentro da funcao por valor: %d\n", valor);
}

// Funcao que recebe um parametro por referencia
void passagemPorReferencia(int *valor) {
    *valor += 10; // Adiciona 10 ao valor apontado por 'valor'
    printf("Dentro da funcao por referencia: %d\n", *valor);
}

int main() {
    int numero = 5;

    printf("Valor original: %d\n", numero);

    passagemPorValor(numero);
    printf("Após passagem por valor: %d\n", numero);

    passagemPorReferencia(&numero);
    printf("Após passagem por referência: %d\n", numero);

    return 0;
}
