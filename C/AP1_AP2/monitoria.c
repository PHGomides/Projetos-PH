#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
 int matricula;
 float notas[3];
}Aluno;

Aluno Turma[5];

#include "biblioteca.h"

int main(){
    setlocale( LC_ALL, "portuguese");

    int flag = 0;
    int tip = 0;
    int aluno;
    float media;
    
    do{
        printf("\n\n1 ler ; 2 Imprimir ; 3 Media ; 4 Sair ");
        scanf("%d",&tip);
        switch (tip){
        case 1:
            LeAluno(); 
            break;

        case 2:
            ImprimeTurma( );
            break;

        case 3:
            printf("Qual aluno 1,2,3,4,5: \n");
            scanf("%d",&aluno);
            media = CalculaMediaAluno(aluno);
            printf("\nMedia : %.2f",media);
            
            break;

        case 4:
            flag = -1;
            break;

        default:
            break;
        }
    } while (flag == 0);

    return 0;
}