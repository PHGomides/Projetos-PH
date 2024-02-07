#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct fila{    
    char nome[30];
    int cod;
}fila;

fila p[8];
fila aux[8];

int fim = 0, inicio = 0, tip, flag = 1,fimaux =0 , inicioaux = 0;

int continverte =0;

void Push(fila p[] ,int num, char ent[]){
    if(fim >= 7){
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
    if(fim == 0){
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


void inveterfila(fila p[],int i, int j){
    continverte = 1;
    if(j == 0){
        printf("\n\nFila esta vazia\n\n");
    }else{
        while (i < j) {
        aux[fimaux].cod = p[i].cod;
        p[i].cod = p[j].cod;
        p[j].cod = aux[fimaux].cod;
        
        strcpy(aux[fimaux].nome, p[i].nome);
        strcpy(p[i].nome, p[j].nome);
        strcpy(p[j].nome, aux[fimaux].nome);
        i++;
        j--;
       }
    }
}


int main(){
    char ent[30];
    int num;

    do{
    printf("\n-------------------------------------------------");
    printf("\n\n1-Incrementar aviao na fila: \n2-Decolar aviao \n3-Verificar fila  \n4-Primeiro aviao\n5-Inverter a fila\n6-Sair\n");
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
        printf(" Quantidade de aviao na fila: %d\n\n",fim);
        break;
    case 4:
        if (continverte > 0){
            printf(" Codigo: %d, nome: %s\n",p[inicio+1].cod, p[inicio+1].nome);
        }else{
            printf(" Codigo: %d, nome: %s\n",p[inicio].cod, p[inicio].nome);
        }
        
    break;

    case 5:
       inveterfila(p,inicio,fim);
    break;
    case 6:
        flag = -1;
    break;
    default:
        break;
    }
    }while(flag != -1);
 

    return 0;
}