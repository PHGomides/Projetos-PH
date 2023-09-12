#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Node{    
    int item;
    struct Node *prox;
}*lista;

lista topo;
lista inicio;
int cont;



lista criarNOH(int num){
    
    lista novoNoh = (lista*)malloc(sizeof(lista));
    if(novoNoh == NULL){
        printf("\n\nErro na alocacao de memoria\n\n");
        system("pause");
        return NULL;
    }else{
        novoNoh -> item = num;
        novoNoh -> prox = NULL;
        return novoNoh;
    }
}

lista Inserir_inicio(int num){
    
    lista novoNoh = criarNOH(num);
    cont++;
    if(lista == NULL){
        return novoNoh;
    }else{
        novoNoh -> prox = inicio;
        printf("%d", novoNoh ->item); 
        system("pause");
        return novoNoh;
    }
}

lista Inserir_fim(int num){
    lista novoNoh = criarNOH(num);
    cont++;
    if(lista == NULL){
        return novoNoh;
    }else{
        lista lista_aux = lista;
        while (lista_aux != NULL) {
            if(lista_aux->prox == NULL){
                lista_aux->prox = novoNoh;
                return novoNoh;
            }
           lista_aux = lista_aux->prox;
        }
    }
}


int main() {

    int num;
    int tip , flag = 1;
    int resp;

    do{
    printf("\n-------------------------------------------------");
    printf("\n\n1-Incrementar \n2-Retirar \n3-Verificar  \n4-Sair\n");
    printf("--> ");
    scanf("%d",&tip);
    
    switch (tip)
    {
    case 1:
        printf("\n\nDigite a item: ");
        printf("--> ");
        scanf("%d",&num);
        if(lista == NULL){
            Pushinicio(num);
        }else{
            printf("Deseja alocar no (qualquer numero)-inicio ou (qualquer numero)-fim"){
                scanf("%d",&resp);
                if (resp !=0){
                    inicio = Inserir_inicio(num);
                }else{
                    Inserir_fim(num);
                }
            }
        }
        Push(num);
        system("cls");
        break;
    case 2:
        Pop();
        system("cls");
        break;
    case 3:
        if (lista == NULL) {
            printf("lista vazia!\n");
            } else {
            lista lista_aux = lista;
            while (lista_aux != NULL) {
                printf("\nQuantidade:%d \n  Item: %d,\n",cont,lista_aux->idade);
                lista_aux = lista_aux->prox;
            }
        }
        break;

    case 4:
        flag = -1;
        break;
    default:
        break;
    }
    }while(flag != -1);
 

    return 0;
}