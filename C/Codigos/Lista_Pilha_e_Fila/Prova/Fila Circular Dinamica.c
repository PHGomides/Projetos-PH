/*
A definição de fila se dá como uma fila na vida real. Esta é uma fila dinâmica, ou seja,
possui um tamanho que varia durante a compilação, além disso, esta fila funciona de maneira circular.
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct ITEM {
    int item;
    struct ITEM *proximo;
} Item;

typedef struct {
    Item *inicio;
    Item *fim;
    int tamanho;
} Fila;

// Função para inicializar a fila
void iniciar(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

// Função para verificar se a fila está vazia
int vazia(Fila *fila) {
    return fila->tamanho == 0;
}

// Função para enfileirar um valor na fila
void enfileirar(Fila *fila, int valor) {
    Item *novoItem = (Item *)malloc(sizeof(Item));
    if (novoItem == NULL) {
        printf("\nErro ao criar item!\n");
        return;
    }
    novoItem->item = valor;
    novoItem->proximo = NULL;

    if (vazia(fila)) {
        fila->inicio = novoItem;
    } else {
        fila->fim->proximo = novoItem;
    }
    fila->fim = novoItem;
    fila->tamanho++;
}

// Função para desenfileirar um valor da fila
int desenfileirar(Fila *fila) {
    if (vazia(fila)) {
        printf("\nFila vazia!\n");
        return -1; // Valor inválido para representar fila vazia
    }

    Item *itemRemovido = fila->inicio;
    int valorRemovido = itemRemovido->item;

    fila->inicio = fila->inicio->proximo;
    free(itemRemovido);
    fila->tamanho--;

    if (vazia(fila)) {
        fila->fim = NULL;
    }

    return valorRemovido;
}

// Função para exibir todos os elementos da fila
void exibir(Fila *fila) {
    if (vazia(fila)) {
        printf("\nFila vazia!\n");
    } else {
        printf("\n--- Fila atual ---\n");
        Item *itemAtual = fila->inicio;
        while (itemAtual != NULL) {
            printf("[%d] ", itemAtual->item);
            itemAtual = itemAtual->proximo;
        }
        printf("\n");
    }
}

int main() {
    int opcao = -1;
    int valor = 0;
    Fila fila;

    iniciar(&fila);

    while (opcao != 0) {

        valor = 0;

        printf("\n\nDIGITE 0 PARA SAIR\n");
        printf("Escolha uma opção\n");
        printf("1: Enfileirar\n");
        printf("2: Desenfileirar\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor para enfileirar\n");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                exibir(&fila);
                break;

            case 2:
                valor = desenfileirar(&fila);
                if (valor != -1) {
                    printf("\nRemoveu o %d\n", valor);
                }
                exibir(&fila);
                break;

            case 0:
                printf("Programa Encerrado\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}