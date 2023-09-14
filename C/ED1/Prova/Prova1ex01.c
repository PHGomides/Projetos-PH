

#include <stdio.h>
#include <stdlib.h>
#include<string.h>



typedef struct Item {
    int valor;
    char nome[30];
    struct Item *proximo;
} Item;

Item *criarItem(int valor,char ent[]) {
    Item *novoItem = (Item *)malloc(sizeof(Item));

    if (novoItem == NULL) {
        printf("\nErro ao criar item!\n");
        return NULL;
    } else {
        novoItem->valor = valor;   
        strcpy(novoItem->nome, ent);
        novoItem->proximo = NULL;
        return novoItem;
    }
}


Item *inserir(int valor, Item *pilha, char ent[]) {
    Item *novoItem = criarItem(valor,ent);
    novoItem->proximo = pilha;
    return novoItem;
}


Item *remover(Item *pilha) {
    if (pilha == NULL) {
        printf("\nA pilha esta vazia!\n");
        return pilha;
    } else {
        Item *pilhaAuxiliar = pilha->proximo;
        free(pilha);
        return pilhaAuxiliar;
    }
}


void exibir(Item *pilha) {
    printf("\n--- Pilha atual ---\n");
    if (pilha == NULL) {
        printf("A pilha esta vazia!\n");
    } else {
        while (pilha != NULL) {
            printf("\nO link no topo é %d, Nome: %s\n", pilha->valor,pilha->nome);
            pilha = pilha->proximo;
        }
    }
}


void exibirTopo(Item *pilha) {
    if (pilha == NULL) {
        printf("\nA pilha está vazia!\n");
    } else {
        printf("\nO link no topo: %d, Nome: %s\n", pilha->valor,pilha->nome);
    }
}


void buscar(char ent[], Item *pilha) {
    while (pilha != NULL) {
        if (strcmp(pilha ->nome, ent) == 0) {
            pilha = inserir(pilha ->valor, pilha, pilha ->nome);
            pilha = remover(pilha);
        }
        pilha = pilha->proximo;
    }
}

int main() {

    int opcao = -1;
    int valor = 0;
    Item *pilha = NULL;
    char ent[30];
   

    while (opcao != 0) {
        
        valor = 0;
        printf("\nDIGITE 0 PARA SAIR\n");
        printf("\n1: Inserir\n");
        printf("2: Remover\n");
        printf("3: Buscar\n");
        printf("4: Exibir topo\n");
        printf("0: Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite um link(em inteiro): ");
                scanf("%d", &valor);
                printf("\n\nDigite o nome: ");
                printf("--> ");
                fflush(stdin);
                gets(ent);
                fflush(stdin);
                pilha = inserir(valor, pilha, ent);
                exibir(pilha);
                break;

            case 2:
                pilha = remover(pilha);
                exibir(pilha);
                break;

            case 3:
                printf("\n\nDigite o nome: ");
                printf("--> ");
                fflush(stdin);
                gets(ent);
                fflush(stdin);
                buscar(ent,pilha);
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