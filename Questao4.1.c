#include <stdio.h>
#include <string.h>

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50

typedef struct {
    char descricao[50];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    char fabricante[50];
} Produto;

typedef struct {
    char marca[50];
    char site[50];
    char telefone[20];
    char UF[3];
} Fabricante;

void listarMarcas(Fabricante fabricantes[], int numFabricantes) {
    int i;
    printf("Marcas cadastradas:\n");
    for (i = 0; i < numFabricantes; i++) {
        printf("%s\n", fabricantes[i].marca);
    }
}

void listarProdutos(Produto produtos[], int numProdutos) {
    int i;
    printf("Produtos cadastrados:\n");
    for (i = 0; i < numProdutos; i++) {
        printf("Descrição: %s\n", produtos[i].descricao);
        printf("Fabricante: %s\n", produtos[i].fabricante);
        printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
        printf("---------------------\n");
    }
}

void listarProdutosEstado(Produto produtos[], int numProdutos, char UF[]) {
    int i;
    printf("Produtos do estado %s:\n", UF);
    for (i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante, UF) == 0) {
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Fabricante: %s\n", produtos[i].fabricante);
            printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
            printf("---------------------\n");
        }
    }
}

void listarProdutosMarca(Produto produtos[], int numProdutos, char marca[]) {
    int i;
    printf("Produtos da marca %s:\n", marca);
    for (i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante, marca) == 0) {
            printf("Descrição: %s\n", produtos[i].descricao);
            printf("Fabricante: %s\n", produtos[i].fabricante);
            printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
            printf("---------------------\n");
        }
    }
}

void encontrarEstadoProdutoMaisCaro(Produto produtos[], int numProdutos, Fabricante fabricantes[], int numFabricantes) {
    int i, j;
    float maiorValor = 0;
    char estadoMaisCaro[3] = "";
    
    for (i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda > maiorValor) {
            maiorValor = produtos[i].valorVenda;
            strcpy(estadoMaisCaro, produtos[i].fabricante);
        }
    }
    
    printf("Estado(s) onde está registrado o produto mais caro:\n");
    for (j = 0; j < numFabricantes; j++) {
        if (strcmp(fabricantes[j].UF, estadoMaisCaro) == 0) {
            printf("%s\n", fabricantes[j].UF);
        }
    }
}

void encontrarFabricanteProdutoMaisBarato(Produto produtos[], int numProdutos, Fabricante fabricantes[], int numFabricantes) {
    int i, j;
    float menorValor = produtos[0].valorVenda;
    char fabricanteMaisBarato[50] = "";
    
    for (i = 1; i < numProdutos; i++) {
        if (produtos[i].valorVenda < menorValor) {
            menorValor = produtos[i].valorVenda;
            strcpy(fabricanteMaisBarato, produtos[i].fabricante);
        }
    }
    
    printf("Fabricante(s) onde está registrado o produto mais barato:\n");
    for (j = 0; j < numFabricantes; j++) {
        if (strcmp(fabricantes[j].marca, fabricanteMaisBarato) == 0) {
            printf("%s\n", fabricantes[j].marca);
        }
    }
}

void ordenarProdutosPorValor(Produto produtos[], int numProdutos) {
    int i, j;
    Produto temp;
    
    for (i = 0; i < numProdutos - 1; i++) {
        for (j = i + 1; j < numProdutos; j++) {
            if (produtos[i].valorVenda > produtos[j].valorVenda) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
    
    printf("Produtos em ordem crescente de valor:\n");
    for (i = 0; i < numProdutos; i++) {
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Fabricante: %s\n", produtos[i].fabricante);
        printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
        printf("---------------------\n");
    }
}

void ordenarProdutosPorLucro(Produto produtos[], int numProdutos) {
    int i, j;
    Produto temp;
    
    for (i = 0; i < numProdutos - 1; i++) {
        for (j = i + 1; j < numProdutos; j++) {
            if (produtos[i].valorLucro < produtos[j].valorLucro) {
                temp = produtos[i];
                produtos[i] = produtos[j];
                produtos[j] = temp;
            }
        }
    }
    
    printf("Produtos em ordem decrescente de valor do lucro:\n");
    for (i = 0; i < numProdutos; i++) {
        printf("Descricão: %s\n", produtos[i].descricao);
        printf("Fabricante: %s\n", produtos[i].fabricante);
        printf("Valor do lucro: %.2f\n", produtos[i].valorLucro);
        printf("---------------------\n");
    }
}

int main() {
    Fabricante fabricantes[MAX_FABRICANTES];
    Produto produtos[MAX_PRODUTOS];
    int numFabricantes, numProdutos, i;
    
    printf(" Cadastro de Fabricantes \n");
    printf("Digite o numero de fabricantes (entre 2 e %d): ", MAX_FABRICANTES);
    scanf("%d", &numFabricantes);
    
    while (numFabricantes < 2 || numFabricantes > MAX_FABRICANTES) {
        printf("numero invalido. Digite novamente: ");
        scanf("%d", &numFabricantes);
    }
    
    for (i = 0; i < numFabricantes; i++) {
        printf(" Fabricante %d ---\n", i + 1);
        printf("Marca: ");
        scanf("%s", fabricantes[i].marca);
        printf("Site: ");
        scanf("%s", fabricantes[i].site);
        printf("Telefone: ");
        scanf("%s", fabricantes[i].telefone);
        printf("UF: ");
        scanf("%s", fabricantes[i].UF);
    }
    
    printf(" Cadastro de Produtos \n");
    printf("Digite o numero de produtos (entre 5 e %d): ", MAX_PRODUTOS);
    scanf("%d", &numProdutos);
    
    while (numProdutos < 5 || numProdutos > MAX_PRODUTOS) {
        printf("numero invalido. Digite novamente: ");
        scanf("%d", &numProdutos);
    }
    
    for (i = 0; i < numProdutos; i++) {
        printf(" Produto %d ---\n", i + 1);
        printf("Descricao: ");
        scanf("%s", produtos[i].descricao);
        printf("Peso: ");
        scanf("%f", &produtos[i].peso);
        printf("Valor de compra: ");
        scanf("%f", &produtos[i].valorCompra);
        printf("Valor de venda: ");
        scanf("%f", &produtos[i].valorVenda);
        
        produtos[i].valorLucro = produtos[i].valorVenda - produtos[i].valorCompra;
        produtos[i].percentualLucro = (produtos[i].valorLucro / produtos[i].valorCompra) * 100;
        
        printf("Fabricante: ");
        scanf("%s", produtos[i].fabricante);
    }
    
    int opcao;
    
    do {
        printf("\n Menu \n");
        printf("1. Listar todas as marcas\n");
        printf("2. Listar todos os produtos\n");
        printf("3. Listar os produtos de um determinado estado\n");
        printf("4. Listar os produtos de uma determinada marca\n");
        printf("5. Apresentar o(s) estado(s) onde esta registrado o produto mais caro\n");
        printf("6. Apresentar o(s) fabricante(s) onde esta registrado o produto mais barato\n");
        printf("7. Listar todos os produtos em ordem crescente de valor\n");
        printf("8. Listar todos os produtos em ordem decrescente de valor do lucro\n");
        printf("9. sair\n");
        printf("digite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                listarMarcas(fabricantes, numFabricantes);
                break;
            case 2:
                listarProdutos(produtos, numProdutos);
                break;
            case 3: {
                char UF[3];
                printf("digite o UF  do estado: ");
                scanf("%s", UF);
                listarProdutosEstado(produtos, numProdutos, UF);
                break;
            }
            case 4: {
                char marca[50];
                printf("digite a marca: ");
                scanf("%s", marca);
                listarProdutosMarca(produtos, numProdutos, marca);
                break;
            }
            case 5:
                encontrarEstadoProdutoMaisCaro(produtos, numProdutos, fabricantes, numFabricantes);
                break;
            case 6:
                encontrarFabricanteProdutoMaisBarato(produtos, numProdutos, fabricantes, numFabricantes);
                break;
            case 7:
                ordenarProdutosPorValor(produtos, numProdutos);
                break;
            case 8:
                ordenarProdutosPorLucro(produtos, numProdutos);
                break;
            case 9:
                printf("saindo...\n");
                break;
            default:
                printf("opcao invalida\n");
        }
    } while (opcao != 9);
    
    return 0;
}