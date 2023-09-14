/*
A pilha é uma estrutura de dados que segue o princípio "último a entrar, primeiro a sair"
o que significa que o elemento que foi inserido por último na pilha é o primeiro a ser retirado.
Esta pilha é estática, ou seja, tem um tamanho pré definido que não pode ser mudado.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    int capacidade;
    int topo;
    int *elementos;
} Pilha;

// Função para criar uma nova pilha com capacidade definida
void criarPilha(Pilha *pilha, int capacidade) {
    pilha->elementos = (int *) malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;

    if (pilha->elementos != NULL) {
        printf("Pilha criada com sucesso!\n");
    } else {
        printf("Erro ao criar pilha!\n");
    }
}

// Função para apagar uma pilha e liberar a memória
void apagarPilha(Pilha *pilha) {
    if (pilha->elementos != NULL) {
        free(pilha->elementos);
        pilha->elementos = NULL;
        printf("Pilha apagada!\n");
    } else {
        printf("Não existe pilha para apagar!\n");
    }
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *pilha) {
    return pilha->topo == -1 || pilha->elementos == NULL;
}

// Função para verificar se a pilha está cheia
int estaCheia(Pilha *pilha) {
    return pilha->elementos != NULL && pilha->topo >= pilha->capacidade - 1;
}

// Função para empilhar um valor na pilha
void empilhar(Pilha *pilha, int valor) {
    if (!estaCheia(pilha)) {
        pilha->topo++;
        pilha->elementos[pilha->topo] = valor;
        printf("Empilhou o valor %d\n", valor);
    } else {
        printf("Pilha cheia\n");
    }
}

// Função para desempilhar um valor da pilha
void desempilhar(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        printf("Desempilhou o valor %d\n", pilha->elementos[pilha->topo]);
        pilha->topo--;
    } else {
        printf("Pilha vazia!\n");
    }
}

// Função para exibir o valor no topo da pilha
void exibirTopo(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        printf("O valor no topo é %d\n", pilha->elementos[pilha->topo]);
    } else {
        printf("Pilha vazia!\n");
    }
}

// Função para pesquisar a ocorrência de um valor na pilha
void pesquisar(Pilha *pilha, int valor) {
    int posicao = pilha->topo;
    int contador = 0;

    if (!estaVazia(pilha)) {
        while (posicao >= 0) {
            if (valor == pilha->elementos[posicao]) {
                contador++;
            }
            posicao--;
        }

        printf("Houve %d ocorrencia(s) do valor %d\n", contador, valor);
    } else {
        printf("Pilha vazia!\n");
    }
}

// Função para exibir todos os elementos da pilha
void exibir(Pilha *pilha) {
    printf("\n--- Pilha atual ---\n");
    if (!estaVazia(pilha)) {
        for (int i = pilha->topo; i >= 0; i--) {
            printf("\t%d\n", pilha->elementos[i]);
        }
    } else {
        printf("Pilha vazia!\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao = -1;
    int valor = 0;
    Pilha pilha;
    pilha.elementos = NULL;
    pilha.capacidade = -1;

    while (opcao != 0) {
       
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Criar pilha\n");
        printf("2: Apagar pilha\n");
        printf("3: Empilhar\n");
        printf("4: Desempilhar\n");
        printf("5: Exibir topo\n");
        printf("6: Pesquisar\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o tamanho da pilha:\n");
                scanf("%d", &valor);
                criarPilha(&pilha, valor);
                exibir(&pilha);
                break;

            case 2:
                apagarPilha(&pilha);
                pilha.elementos = NULL;
                pilha.capacidade = -1;
                exibir(&pilha);
                break;

            case 3:
                printf("Digite um valor:\n");
                scanf("%d", &valor);
                empilhar(&pilha, valor);
                exibir(&pilha);
                break;

            case 4:
                desempilhar(&pilha);
                break;

            case 5:
                exibirTopo(&pilha);
                break;

            case 6:
                printf("Digite um valor:\n");
                scanf("%d", &valor);
                pesquisar(&pilha, valor);
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