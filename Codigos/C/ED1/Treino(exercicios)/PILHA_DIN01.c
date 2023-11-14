#include<stdlib.h>
#include<stdio.h>

typedef struct Node{    
    int item;
    struct Node *prox;
}pilha;

pilha *topo;
pilha *aux;


int tip, flag = 1, cont=0;

void Push(int num){
    pilha *novoNoh = (pilha*)malloc(sizeof(pilha));
    if(novoNoh == NULL){
        printf("\n\nErro na alocacao de memoria\n\n");
        system("pause");
    }else{
        cont++;
        novoNoh -> item = num;
        novoNoh -> prox = topo;
         printf("%d", novoNoh ->item);
         system("pause");
        topo = novoNoh;
    }
}
void Pop(){
    if(topo == NULL){
        printf("\n\nPilha esta vazia\n\n");
        system("pause");
    }else{
        aux = topo -> prox;
        free(&topo);
        *topo = *aux;
        cont--;
    }
}


int main(){
    int num;

    do{
    printf("\n-------------------------------------------------");
    printf("\n\n1-Incrementar item: \n2-Retirar item \n3-Verificar tamanho \n4-Fechar\n");
    printf("--> ");
    scanf("%d",&tip);
    switch (tip)
    {
    case 1:
        printf("\n\nDigite o numero para armazenar: ");
        printf("--> ");
        scanf("%d",&num);
        Push(num);
        system("cls");
        break;
    case 2:
        Pop(&topo);
        system("cls");
        break;
    case 3:
        if(topo == NULL){
            printf("\n\nPilha esta vazia\n\n");  
        }else{
            printf("\n\nPilha com tamanho: %d\n",cont);
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