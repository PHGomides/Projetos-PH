/*
A definição de fila se dá como uma fila na vida real. Esta é uma fila dinâmica, ou seja,
possui um tamanho que varia durante a compilação.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição da estrutura de um item na fila
typedef struct Item {
	int valor;
	struct Item *proximo;
} Item;

// Definição do tipo da fila
typedef Item* tipoFila;

// Função para criar um novo item na fila
Item* criarItem(int valor) {
	Item* novoItem = (Item*)malloc(sizeof(Item));
	if (novoItem == NULL) {
		printf("\nErro ao criar item!\n");
		return NULL;
	} else {
		novoItem->valor = valor;
		novoItem->proximo = NULL;
		return novoItem;
	}
}

// Função para inserir um valor no final da fila
tipoFila inserir(int valor, tipoFila fila) {
	Item* novoItem = criarItem(valor);
	if (fila == NULL) {
		return novoItem;
	} else {
		Item* filaAuxiliar = fila;
		while (filaAuxiliar->proximo != NULL) {
			filaAuxiliar = filaAuxiliar->proximo;
		}
		filaAuxiliar->proximo = novoItem;
		return fila;
	}
}

// Função para remover o primeiro item da fila
tipoFila remover(tipoFila fila) {
	if (fila == NULL) {
		printf("\nFila vazia!\n");
	} else {
		Item* filaAuxiliar = fila;
		fila = fila->proximo;
		free(filaAuxiliar);
	}
	return fila;
}

// Função para exibir todos os itens da fila
void exibir(tipoFila fila) {
	printf("\n--- Fila ---\n");
	if (fila == NULL) {
		printf("Fila vazia!\n");
	} else {
		Item* filaAuxiliar = fila;
		while (filaAuxiliar != NULL) {
			printf("[%d] ", filaAuxiliar->valor);
			filaAuxiliar = filaAuxiliar->proximo;
		}
	}
}

// Função para exibir o valor do primeiro item da fila
void exibirPrimeiro(tipoFila fila) {
	if (fila == NULL) {
		printf("\nFila vazia!\n");
	} else {
		printf("\nO valor do primeiro é %d\n", fila->valor);
	}
}

// Função para pesquisar a ocorrência de um valor na fila
void pesquisar(int valor, tipoFila fila) {
	int contador = 0;
	Item* filaAuxiliar = fila;
	while (filaAuxiliar != NULL) {
		if (filaAuxiliar->valor == valor) {
			contador++;
		}
		filaAuxiliar = filaAuxiliar->proximo;
	}
	printf("\nHouve %d ocorrência(s) do valor %d\n", contador, valor);
}

int main() {

    setlocale(LC_ALL, "Portuguese");

	int opcao = -1;
	int valor = 0;
	tipoFila fila = NULL;

	while (opcao != 0) {
		valor = 0;

		printf("\n\nDIGITE 0 PARA SAIR\n");
		printf("Escolha uma opção:\n");
		printf("1: Inserir\n");
		printf("2: Remover\n");
		printf("3: Pesquisar\n");
		printf("4: Exibir primeiro\n");
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
				printf("Digite um valor para inserir: ");
				scanf("%d", &valor);
				fila = inserir(valor, fila);
				break;

			case 2:
				fila = remover(fila);
				break;

			case 3:
				printf("Digite um valor para pesquisar: ");
				scanf("%d", &valor);
				pesquisar(valor, fila);
				break;

			case 4:
				exibirPrimeiro(fila);
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