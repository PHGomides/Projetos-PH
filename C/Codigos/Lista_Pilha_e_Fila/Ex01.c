#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct pilha{    
    char item;
}pilha;

pilha p[30];
pilha h[30];
char aux[30];

int topo = -1,topoh= -1, tip, flag = 1,tamanho;

int verificador = 0 ;

void Push(pilha p[] , char ent[]){
    if(topo > 0){
        printf("\n\nPilha tem itens, retire os itens para depois incrementar\n\n");
        system("pause");

    }else{
        for (topo = 0; topo < tamanho; topo++){
            p[topo].item = ent[topo];
        }
    }
}
void Pop(pilha p[]){
    if(topo == -1){
        printf("\n\nPilha esta vazia\n\n");
        system("pause");
 
    }else{
        for (int i = tamanho ; i > -1; i--){
            p[topo].item = ' ';
            topo--;
        }
    }
}

int main(){
    char ent[30];

    do{
    printf("\n-------------------------------------------------");
    printf("\n\n1-Incrementar item: \n2-Retirar item \n3-Verificar  \n4-Fechar\n");
    printf("--> ");
    scanf("%d",&tip);
    switch (tip){
    
    case 1:
    if(topo > 0){
        printf("\n\nPilha tem itens, retire os itens para depois incrementar\n\n");
        system("pause");

    }else{
        printf("\n\nDigite a palavra: ");
        printf("--> ");
        fflush(stdin);
        gets(ent);
        tamanho = strlen(ent);
        fflush(stdin);
        Push(p,ent);
        system("cls");
    }
        break;
    case 2:
        Pop(p);
        system("cls");
        break;
    case 3:
        if(topo == -1){
            printf("\n\nPilha esta vazia\n\n");
        }else{
            printf("\n\nPilha com tamanho: %d\n",(topo));
            printf("Itens na pilhap: %s\n\n",p);
            topoh = -1;
            for (int i = topo; i > -1 ; i--){
                    topoh++;
                    aux[topoh]= p [topo].item;
                    topo--;
                    h[topoh].item = aux[topoh];  
            }
            
            printf("Itens na pilhah: %s\n\n",h);
            for (int i = 0; i <= tamanho ; i++){
                if (h[i].item != p[i].item){
                    printf("Nao pertence a forma WcM");
                    break;
                }else if ((p[i].item == 'c') && (h[i].item == 'c')){
                     printf("Pertence a forma WcM");
                    break;
                }
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