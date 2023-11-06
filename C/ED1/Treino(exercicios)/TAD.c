#include <stdio.h>
#include <stdlib.h>

// ALUNO PEDRO HENRIQUE GOMIDES MORAES 
typedef struct contaBancaria{
    char nome[50];
    int conta;
    float saldo;
}contaBancaria;

contaBancaria cb[10];

int i = 0, x = 0;
int verifconta = 0;

void abrirconta(contaBancaria cb[], int a){
    printf("\n  Digite o seu nome : ");
    fflush(stdin);
    scanf("%[^\n]s",cb[a].nome);
    printf("\n\n Digite o numero da conta : ");
    scanf("%d",&cb[a].conta);
    printf("\n\n Digite o saldo inicial : ");
    scanf("%f",&cb[a].saldo);
}

void depositar(contaBancaria cb[]){
    float addsaldo;
    printf("\n\n Digite o numero da conta : ");
    scanf("%d",&verifconta);
    for (int i = 0; i <= 10; i++){
        if (verifconta == cb[i].conta){
            printf("\n\n Digite o valor a depositar :");
            scanf("%f",&addsaldo);
            cb[i].saldo = addsaldo + cb[i].saldo;
            break;
        }
    }
    if (verifconta != cb[i].conta){
            printf("\n\n Conta invalida");
        }
}

void sacar(contaBancaria cb[]){
    float delsaldo;
    printf("\n\n Digite o numero da conta : ");
    scanf("%d",&verifconta);
    for (int i = 0; i <= 10; i++){
        if (verifconta == cb[i].conta){
            printf("\n\n Digite o valor a sacar :");
            scanf("%f",&delsaldo);
            cb[i].saldo = cb[i].saldo - delsaldo;
            break;
        }
    }
    if (verifconta != cb[i].conta){
            printf("\n\n Conta invalida");
    }
}

void versaldo(contaBancaria cb[]){

    printf("\n\n Digite o numero da conta : ");
    scanf("%d",&verifconta);
    for (int i = 0; i <= 10; i++){
        if (verifconta == cb[i].conta){
            printf("\n\n Nome : %s",cb[i].nome);
            printf("\n\n Conta : %d",cb[i].conta);
            printf("\n\n Seu saldo : %.2f",cb[i].saldo);
            break;
        }
    }
    if (verifconta != cb[i].conta){
        printf("\n\n Conta invalida");
    } 
}


int main(){
    int tipo;
   do{
        printf("\n\n 1-Criar conta\n 2-Depositar\n 3-Sacar\n 4-Ver dados\n 5-Sair\n\n --> ");
        scanf("%d",&tipo);

        switch (tipo)
        {
        case 1:
                 abrirconta(cb,x);
                x++;
            break;
        
        case 2:
                depositar(cb);
            break;

        case 3:
                sacar(cb);
            break;

        case 4:
                versaldo(cb);
            break;
        
        default:
            break;
        }
   }while(tipo != 5);
}
