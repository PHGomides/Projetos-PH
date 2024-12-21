/*
A plha dinânima segue o mesmo princípio de "último a entrar, primeiro a sair"
porém seu tamanho não é mais limitado ao tamanho de uma variável.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definição da estrutura de um item na pilha
typedef struct Item {
    int valor;
    struct Item *proximo;
} Item;


// Função para criar um novo item na pilha
Item *criarItem(int valor) {
    Item *novoItem = (Item *)malloc(sizeof(Item));

    if (novoItem == NULL) {
        printf("\nErro ao criar item!\n");
        return NULL;
    } else {
        novoItem->valor = valor;
        novoItem->proximo = NULL;
        return novoItem;
    }
}

// Função para inserir um novo item (push) na pilha
Item *inserir(int valor, Item *pilha) {
    Item *novoItem = criarItem(valor);
    novoItem->proximo = pilha;
    return novoItem;
}

// Função para remover o item do topo da pilha (pop)
Item *remover(Item *pilha) {
    if (pilha == NULL) {
        printf("\nA pilha está vazia!\n");
        return pilha;
    } else {
        Item *pilhaAuxiliar = pilha->proximo;
        free(pilha);
        return pilhaAuxiliar;
    }
}

// Função para exibir todos os itens da pilha
void exibir(Item *pilha) {
    printf("\n--- Pilha atual ---\n");
    if (pilha == NULL) {
        printf("A pilha está vazia!\n");
    } else {
        while (pilha != NULL) {
            printf("\t%d\n", pilha->valor);
            pilha = pilha->proximo;
        }
    }
}

// Função para exibir o valor no topo da pilha
void exibirTopo(Item *pilha) {
    if (pilha == NULL) {
        printf("\nA pilha está vazia!\n");
    } else {
        printf("\nO valor no topo é %d\n", pilha->valor);
    }
}

// Função para pesquisar a ocorrência de um valor na pilha
void pesquisar(int valor, Item *pilha) {
    int contador = 0;

    while (pilha != NULL) {
        if (pilha->valor == valor) {
            contador++;
        }
        pilha = pilha->proximo;
    }
    printf("\nHouve %d ocorrencia(s) do valor %d\n", contador, valor);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao = -1;
    int valor = 0;
    Item *pilha = NULL;

    while (opcao != 0) {
        
        valor = 0;
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("1: Inserir\n");
        printf("2: Remover\n");
        printf("3: Pesquisar\n");
        printf("4: Exibir topo\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                pilha = inserir(valor, pilha);
                exibir(pilha);
                break;

            case 2:
                pilha = remover(pilha);
                exibir(pilha);
                break;

            case 3:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                pesquisar(valor, pilha);
                exibir(pilha);
                break;

            case 4:
                exibirTopo(pilha);
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