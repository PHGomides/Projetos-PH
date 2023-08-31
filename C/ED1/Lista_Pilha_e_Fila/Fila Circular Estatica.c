/*
A definição de fila se dá como uma fila na vida real. Esta é uma fila circular estática, ou seja,
possui um tamanho pré-definido e funciona de maneira circular.
*/


#include <stdio.h>
#include <stdlib.h>
#define TAM 5 // Define o tamanho da fila

typedef struct {
    int primeiro;
    int ultimo;
    int itens[TAM];
} Fila;

// Função para inicializar a fila
void iniciar(Fila *fila) {
    fila->primeiro = TAM - 1;
    fila->ultimo = TAM - 1;
}

// Função para verificar se a fila está cheia
int cheia(Fila *fila) {
    if (fila->ultimo == TAM - 1) {
        if (fila->primeiro == 0) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if (fila->primeiro == (fila->ultimo + 1)) {
            return 1;
        } else {
            return 0;
        }
    }
}

// Função para verificar se a fila está vazia
int vazia(Fila *fila) {
    return fila->ultimo == fila->primeiro;
}

// Função para enfileirar um valor na fila
void enfileirar(Fila *fila, int valor) {
    if (cheia(fila) == 1) {
        printf("\nFila cheia!\n");
    } else {
        fila->ultimo = (fila->ultimo + 1) % TAM;
        fila->itens[fila->ultimo] = valor;
    }
}

// Função para desenfileirar um valor da fila
int desenfileirar(Fila *fila) {
    if (vazia(fila) == 1) {
        printf("\nFila vazia!\n");
        return -1; // Valor inválido para representar fila vazia
    } else {
        int valorRemovido = fila->itens[fila->primeiro];
        if (fila->primeiro == TAM - 1) {
            fila->primeiro = 0;
        } else {
            (fila->primeiro)++;
        }
        return valorRemovido;
    }
}

// Função para pesquisar a ocorrência de um valor na fila
void pesquisar(Fila *fila, int valor) {
    if (vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    } else {
        int guardaPrimeiro = fila->primeiro;
        int auxiliar = desenfileirar(fila);
        int contador = 0;

        while (auxiliar != -1) {
            if (valor == auxiliar) {
                contador++;
            }
            auxiliar = desenfileirar(fila);
        }

        fila->primeiro = guardaPrimeiro;
        printf("\nHouve %d ocorrência(s) do valor %d\n", contador, valor);
    }
}

// Função para calcular o tamanho atual da fila
int tamanho(Fila *fila) {
    if (fila->primeiro <= fila->ultimo) {
        return (fila->ultimo - fila->primeiro);
    } else {
        return (TAM - (fila->primeiro - fila->ultimo));
    }
}

// Função para exibir todos os elementos da fila
void exibir(Fila *fila) {
    if (vazia(fila) == 1) {
        printf("\nFila vazia!\n");
    } else {
        int guardaPrimeiro = fila->primeiro;
        int auxiliar = desenfileirar(fila);

        printf("\n--- Fila atual ---\n");
        while (auxiliar != -1) {
            printf("[%d] ", auxiliar);
            auxiliar = desenfileirar(fila);
        }

        fila->primeiro = guardaPrimeiro;
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
        printf("3: Pesquisar\n");
        printf("4: Tamanho\n");
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

            case 3:
                printf("Digite um valor\n");
                scanf("%d", &valor);
                pesquisar(&fila, valor);
                exibir(&fila);
                break;

            case 4:
                printf("\nTamanho da fila é %d\n", tamanho(&fila));
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