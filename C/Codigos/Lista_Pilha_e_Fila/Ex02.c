#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct pilha{    
    char nome[30];
    int idade;
}pilha;

pilha p[5];
pilha h[5];

char teste[30];

int topo = -1, tip, flag = 1, tamanho;
int t;

void Push(pilha p[], char ent[],int num){
    if(topo == 4){
        printf("\n\nPilha esta cheia\n\n");
        system("pause");

    }else{
        topo++;
        for (int i = 0; i <= tamanho ; i++){
            p[topo].nome[i] = ent[i];
        }

        p[topo].idade = num;


    }
}
void Pop(pilha p[]){
    if(topo == -1){
        printf("\n\nPilha esta vazia\n\n");
        system("pause");
 
    }else{
        printf("Digite o nome que deseja retirar\n\n");
        fflush(stdin);
        gets(teste);
        for (int i = topo; i > -1; i--){
            if (strcmp(p[i].nome, teste) == 0){
                t = i;
                for (int x = 0; x < 30; x++){
                    p[i].nome[x] = ' ';
                }
                p[i].idade = 0;
            }
                for (int u = topo; u >= t; u--){
                    for (int x = 0; x < 30; x++){
                        p[u].nome[x] = p[u-1].nome[x];
                    }
                    p[u].idade = p[u-1].idade;
                }
            }
        
    }
}


int main(){
    char ent[30];
    int num;

    do{
    printf("\n-------------------------------------------------");
    printf("\n\n1-Incrementar item: \n2-Retirar item \n3-Verificar tamanho \n4-Fechar\n");
    printf("--> ");
    scanf("%d",&tip);
    switch (tip)
    {
    case 1:
        printf("\n\nDigite o nome: ");
        printf("--> ");
        fflush(stdin);
        gets(ent);
        tamanho = strlen(ent);
        printf("\n\nDigite a idade: ");
        printf("--> ");
        scanf("%d",&num);
        Push(p,ent,num);
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
            for(int i = 0; i <= topo; i++ ){
                printf(" nome: %s  idade: %d",p[i].nome, p[i].idade);
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