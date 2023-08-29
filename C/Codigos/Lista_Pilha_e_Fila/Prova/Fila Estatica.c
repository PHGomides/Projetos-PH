/*
A definição de fila se dá como uma fila na vida real. Esta é uma fila estática, ou seja,
possui um tamanho pré-definido.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


#define TAM 3 // Tamanho da fila

// Definição da estrutura da fila
typedef struct {
    int primeiro;
    int ultimo;
    int itens[TAM];
} Fila;

// Função para inicializar a fila
void iniciar(Fila *fila) {
    fila->primeiro = 0;
    fila->ultimo = -1;
}

// Função para verificar se a fila está cheia
int cheia(Fila *fila) {
    return fila->ultimo == TAM - 1;
}

// Função para verificar se a fila está vazia
int vazia(Fila *fila) {
    return fila->primeiro > fila->ultimo;
}

// Função para enfileirar um valor na fila
void enfileirar(Fila *fila, int valor) {
    if (cheia(fila)) {
        printf("\nFila cheia!\n");
    } else {
        fila->ultimo++;
        fila->itens[fila->ultimo] = valor;
    }
}

// Função para desenfileirar um valor da fila
void desenfileirar(Fila *fila) {
    if (vazia(fila)) {
        printf("\nFila vazia!\n");
    } else {
        fila->primeiro++;
    }
}

// Função para mostrar o primeiro valor da fila
void mostrarPrimeiro(Fila *fila) {
    if (vazia(fila)) {
        printf("\nA Fila está vazia!\n");
    } else {
        printf("\nO primeiro da fila é %d\n", fila->itens[fila->primeiro]);
    }
}

// Função para mostrar o tamanho atual da fila
void tamanho(Fila *fila) {
    if (vazia(fila)) {
        printf("\nFila vazia\n");
    } else {
        printf("\nO tamanho da fila é %d\n", (fila->ultimo - fila->primeiro) + 1);
    }
}

// Função para exibir todos os elementos da fila
void exibir(Fila *fila) {
    int i = fila->primeiro;
    printf("\n--- Fila ---\n");
    while (i <= fila->ultimo) {
        printf("[%d] ", fila->itens[i]);
        i++;
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int opcao = -1;
    int valor = 0;
    Fila fila;
    iniciar(&fila);

    while (opcao != 0) {
        exibir(&fila);
        valor = 0;

        printf("\n\nDIGITE 0 PARA SAIR\n");
        printf("Escolha uma opção:\n");
        printf("1: Enfileirar\n");
        printf("2: Desenfileirar\n");
        printf("3: Mostrar primeiro\n");
        printf("4: Tamanho\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor que será enfileirado: ");
                scanf("%d", &valor);
                enfileirar(&fila, valor);
                exibir(&fila);
                break;

            case 2:
                desenfileirar(&fila);
                exibir(&fila);
                break;

            case 3:
                mostrarPrimeiro(&fila);
                break;

            case 4:
                tamanho(&fila);
                break;

            case 0:
                printf("Programa Encerrado.\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    }

    return 0;
}