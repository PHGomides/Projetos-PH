#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "EX02.h"
#include "EX03.h"
#include "EX04.h"
#include "EX05.h"
#include "EX06.h"
#include "EX07.h"

int flag = 1 ;
int aux,i;

int main(){
setlocale( LC_ALL, "portuguese");


do{
    
    system("cls");
    printf("\n\n              Menu Interativo Lista 04");
    printf("\n\n Escolha uma quest�o de 2 ate 7,caso deseja sair digite -1 :  ");
    scanf("%d",&aux);
    fflush(stdin);
     
    switch (aux){
    case -1:
        flag = 0;
    break;
    case 2:
        //Exercicio 02
        printf("\n Resultado da fun��o : %d \n",EX02());
        system("pause");
        

    break;

    case 03:
        //Exercicio 03
        printf("\n\n Digite o valor de x: ");
        scanf("%d",&x);
        printf("\n Digite o valor de y: ");
        scanf("%d",&y);
        printf("\n Os Resultados das fun��es s�o : \n Soma = %d   \n Subtra��o = %d   \n Multiplica��o = %d   \n Divis�o = %.1f \n",somar(), subtrair(), multiplicar(), dividir());
        system("pause");
    break;

    

    case 4:
        //Exercicio 04
        printf("\n Digite valor de N : ");
        scanf("%d",&n);
        printf("\n Resultado da fun��o Fatorial : %d \n",EX04());
        system("pause");
    break;

    case 5:
        //Exercicio 05
        printf("\n\n Digite o pre�o atual: ");
        scanf("%d",&precoatual);
        printf("\n Digite o pre�o antigo: ");
        scanf("%d",&precoantigo);
        printf("\n\n Resultado da fun��o : %d%% \n",EX05());
        system("pause");
    break;

    case 6:
        //Exercicio 06
        printf("\n Digite a nota 01: ");
        scanf("%f",&nota1);
        printf(" Digite a nota 02: ");
        scanf("%f",&nota2);
        printf(" Digite a nota 03: ");
        scanf("%f",&nota3);
        printf("\n Escolha o tipo de media // Sendo 1- M�dia Aritm�tica  ou  2-M�dia Ponderada: ");
        scanf("%d",&tipo);
        printf("\n Resultado da fun��o M�dia : %.1f \n",EX06());
        system("pause"); 
    break;

    case 7:
        //Exercicio07
        LeAluno();
        ImprimeTurma();
        system("pause");
    break;
    default:
    break;
    }
}while(flag);

}
