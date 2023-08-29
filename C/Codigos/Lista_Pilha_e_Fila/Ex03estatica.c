#include<stdlib.h>
#include<stdio.h>

typedef struct fila{    
    char nome[30];
    int cod;
}fila;

fila p[5];

int fim = 0, inicio = 0, tip, flag = 1;

void Push(fila p[] ,int num, char ent[]){
    if(fim == 4){
        printf("\n\nFila esta cheia\n\n");
    }else{
        for (int i = 0; i < 30; i++){
           p[fim].nome[i] = ent[i];
        }
        p[fim].cod = num;
        fim++;
    }
}

void Pop(fila p[]){
    if(inicio == -1){
        printf("\n\nFila esta vazia\n\n");
    }else{
        for(int i = inicio; i < fim; i++ ){
            p[i].cod = p[i+1].cod;
            for (int x = 0; x < 30; x++){
                p[i].nome[x] = p[i+1].nome[x];
            }
        }
        fim--;
    }
}

int main(){
    char ent[30];
    int num;

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
        Push(p,num,ent);
        system("cls");
        break;
    case 2:
        Pop(p);
        system("cls");
        break;
    case 3:
        for(int i = inicio; i < fim ; i++){
            printf(" Codigo: %d, nome: %s\n",p[i].cod, p[i].nome);
            }
        break;

    case 4:
        printf(" Codigo: %d, nome: %s\n",p[0].cod, p[0].nome);
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