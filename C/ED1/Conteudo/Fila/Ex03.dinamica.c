
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Item {
	int codigo;
    char nome[30];
	struct Item *proximo;
} Item;

 
typedef Item* tipoFila;


Item* criarItem(char ent[], int num) {
	Item* novoItem = (Item*)malloc(sizeof(Item));
	if (novoItem == NULL) {
		printf("\nErro ao criar item!\n");
		return NULL;
	} else {
		novoItem->codigo = num;
        for (int i = 0; i < 30; i++){
            novoItem -> nome[i] = ent[i];
        }
		novoItem->proximo = NULL;
		return novoItem;
	}
}


tipoFila Push(char ent[] ,int num, tipoFila fila) {
	Item* novoItem = criarItem(ent, num);
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


tipoFila Pop(tipoFila fila) {
	if (fila == NULL) {
		printf("\nFila vazia!\n");
	} else {
		Item* filaAuxiliar = fila;
		fila = fila->proximo;
		free(filaAuxiliar);
	}
	return fila;
}


void exibirPrimeiro(tipoFila fila) {
	if (fila == NULL) {
		printf("\nFila vazia!\n");
	} else {
		printf(" Codigo: %d, nome: %s\n",fila->codigo, fila->nome);
	}
}

int main() {

	tipoFila fila = NULL;

    char ent[30];
    int num;
    int tip , flag = 1;

    do{
    printf("\n-------------------------------------------------");
    printf("\n\n1-Incrementar aviao: \n2-Retirar aviao \n3-Verificar fila  \n4-Primeiro aviao\n5-Sair\n");
    printf("--> ");
    scanf("%d",&tip);
    
    switch (tip)
    {
    case 1:
        printf("\n\nDigite o nome: ");
        printf("--> ");
        fflush(stdin);
        gets(ent);
        fflush(stdin);
        fflush(stdin);
        printf("\n\nDigite o codigo do aviao: ");
        printf("--> ");
        scanf("%d",&num);
        fila = Push(ent,num, fila);
        system("cls");
        break;
    case 2:
        fila = Pop(fila);
        system("cls");
        break;
    case 3:
        if (fila == NULL) {
            printf("Fila vazia!\n");
            } else {
            Item* filaAuxiliar = fila;
            while (filaAuxiliar != NULL) {
                printf(" Codigo: %d, nome: %s\n",filaAuxiliar->codigo, filaAuxiliar->nome);
                filaAuxiliar = filaAuxiliar->proximo;
            }
        }
        break;

    case 4:
        exibirPrimeiro(fila);
    break;

    case 5:
        flag = -1;
        break;
    default:
        break;
    }
    }while(flag != -1);
 

    return 0;
}