#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int flag = 1 ;
int aux,i;
int a, b;
float horas[3],totalh=0,totalv=0;
#include "biblioteca.h"
int main(void){
setlocale( LC_ALL, "portuguese");


do{
    
    system("cls");
    printf("\n\n              Menu Interativo Lista 05");
    printf("\n\n Escolha uma questao de 2 ate 6,caso deseja sair digite -1 :  ");
    scanf("%d",&aux);
    fflush(stdin);
     
    switch (aux){
    case -1:
        flag = 0;
    break;
    case 2:
    
        //Exercicio 02
        printf("\n\n Digite um numero inteiro :  ");
       scanf("%d",&a);
       if( ParImpar(a)== 1){
            printf("\n\n  E par\n\n");
       }else{
            printf("\n\n  E impar\n\n");
       }
      
    break;

    case 3:

        //Exercicio 03
       printf("\n\n Digite um numero inteiros :  ");
       scanf("%d%d",&a, &b);
       printf (" O MDC = %d \n\n",Mdc(a,b));

    break;

    case 4:

        //Exercicio 04
        printf("\n\n Digite dois numeros inteiros = ");
        scanf("%d%d",&a, &b);
        Multiplica(a,b);

    break;

    case 5:

        //Exercicio 05
        printf("\n\n Digite a quantidade de Elementos : ");
        scanf("%d",&a);
        printf("\n Digite as partes dos Elementos : ");
        scanf("%d",&b);
        printf("\n\n O resultado = %d\n\n",combina(a,b));


      
    break;

    case 6:

        //Exercicio 06
        for(i=0;i<3;i++){ 
            printf("\n\n Carro 0%d",i+1);
            printf("\n\n Digite a quantidade de horas estacionada = ");
            scanf("%f",&horas[i]);
            totalh = horas[i] + totalh;
        }
            printf("\n\n Carros");
            printf("         Horas");
            printf("                  Valor $\n");
        for(i=0;i<3;i++){
            printf("\n  %d-",i+1);
            printf("            %2.2f",horas[i]);
            printf("                  %2.2f",calculataxa(horas[i]));
            totalv = calculataxa(horas[i]) + totalv;
        }
        printf("\n Total");
        printf("          %2.2f",totalh);
        printf("                 %2.2f\n\n",totalv);
        
    break;

   
    default:
    break;
    }
    system("pause");
}while(flag);

}
