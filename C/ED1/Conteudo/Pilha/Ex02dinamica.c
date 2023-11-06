#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Node{    
    char nome[30];
    int idade;
    struct Node *prox;
}pilha;

pilha *topo;
pilha *aux;
pilha *aux02;
pilha *verf;


char teste[30];
int tip, flag = 1, cont=0,i=0;

void Push(char ent[], int num){
    pilha *novoNoh = (pilha*)malloc(sizeof(pilha));
    if(novoNoh == NULL){
        printf("\n\nErro na alocacao de memoria\n\n");
        system("pause");
    }else{
        cont++;
        novoNoh -> idade = num;
        for (int i = 0; i < 30; i++){
            novoNoh -> nome[i] = ent[i];
        }
        novoNoh -> prox = topo;
        topo = novoNoh;
        verf = topo;
        aux02 = topo;
    }
}
void Pop(){
    printf("\n\nDigite o nome: ");
    printf("--> ");
    fflush(stdin);
    gets(teste);
    fflush(stdin);

    if(topo == NULL){
        printf("\n\nPilha esta vazia\n\n");
        system("pause");
    }else{
        while (verf != NULL) {
            i++;
            if (strcmp(verf ->nome, teste) == 0){
                aux = verf -> prox;    
                free(&verf);
                *verf = *aux;
                aux02 -> prox = verf;
                
                cont--;
            }
            if (i > 0){
                aux02 = aux02 ->prox;
            }
            verf = verf ->prox; 
            i++;   
        }
    }
}

int main(){
    char ent[30];
    int num;

    do{
    printf("\n-------------------------------------------------");
    printf("\n\n1-Incrementar item: \n2-Retirar item \n3-Verificar  \n4-Fechar\n");
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
        printf("\n\nDigite a idade: ");
        printf("--> ");
        scanf("%d",&num);
        Push(ent,num);
        system("cls");
        break;
    case 2:
        Pop();
        break;
    case 3:
        if(topo == NULL){
            printf("\n\nPilha esta vazia\n\n");  
        }else{
            printf("\n\nPilha com tamanho: %d\n",cont);
            printf("\n\tItens\n");
            while (verf != NULL) {
                printf("\tNome: %s Idade: %d\n", verf->nome, verf->idade);
                verf = verf ->prox;    
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