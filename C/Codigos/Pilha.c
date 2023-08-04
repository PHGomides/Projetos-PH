#include<stdlib.h>
#include<stdio.h>

typedef struct pilha{    
    int item;
}pilha;

pilha p[5];

int topo = -1, tip, flag = 1;

int Push(pilha p[] ,int num){
    if(topo >= 4){
        printf("\n\nPilha esta cheia\n\n");
        return 0;
    }else{
        topo++;
        p[topo].item = num;
        return 0;
    }
}

int Pop(pilha p[]){
    if(topo <= -1){
        printf("\n\nPilha esta vazia\n\n");
        return 0;
    }else{
        p[topo].item = NULL;
        topo--;
        return 0;
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
        if(topo == -1){
            printf("\n\nPilha esta vazia\n\n");
        }else if(topo == 4){
            printf("\n\nPilha esta cheia\n\n");
        }else{
            printf("\n\nPilha com tamanho: %d\n",(topo+1));
            printf("Valor no topo da pilha: %d\n\n",p[topo].item);
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