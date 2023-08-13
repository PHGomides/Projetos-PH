#include<stdlib.h>
#include<stdio.h>

typedef struct fila{    
    int item;
}fila;

fila p[5];

int fim = 0, inicio = 0, tip, flag = 1;

void Push(fila p[] ,int num){
    if(fim == 4){
        printf("\n\nFila esta cheia\n\n");
    }else{
        p[fim].item = num;
        fim++;
    }
}

void Pop(fila p[]){
    if(inicio == -1){
        printf("\n\nFila esta vazia\n\n");
    }else{
        p[inicio].item = 0;
        for(int i = inicio; i < fim; i++ ){
            p[i].item = p[i+1].item;
        }
        fim--;
    }
}

void Excluirfila(fila p[]){
    for (int i = 0; i < 5; i++){
        p[i].item = NULL;
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
        Push(p,num);
        system("cls");
        break;
    case 2:
        Pop(p);
        system("cls");
        break;
    case 3:
        for(int i = inicio; i < fim ; i++){
            printf("Posicao: %d, valor: %d\n",i, p[i].item);
            }
        break;
    case 4:
        flag = -1;
        Excluirfila(p);
        break;
    default:
        break;
    }
    }while(flag != -1);
 

    return 0;
}