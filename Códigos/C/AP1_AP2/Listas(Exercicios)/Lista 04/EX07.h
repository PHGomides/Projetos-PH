#ifndef EX07_H_INCLUDE
#define EX07_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int v,j;

struct Alunos{
    char nome[100];
    int matricula;
    int nota[3];
    float notafinal;
}aluno[5];

void LeAluno(){
    for(v=0; v<5 ; v++){
        printf("------------------------------------");
        printf("\n\n");
        fflush(stdin);
        printf("\n Nome do Aluno -> ");
        scanf("%[^\n]s", aluno[v].nome);
        fflush(stdin);
        
        // Gerador de matricula
        srand(time(NULL));
        aluno[v].matricula = 202300000 + ( rand() % 1100 );

        for (j=0 ; j<3 ; j++){
            fflush(stdin);
            printf("\n Digite a nota N%d -> ",j+1);
            scanf("%d",&aluno[v].nota[j]);
            fflush(stdin);
        }
    }
}

float CalculaMediaAluno(){
    for(j=0 ; j<3 ; j++){
        aluno[v].notafinal += aluno[v].nota[j];
    }
    aluno[v].notafinal = aluno[v].notafinal / 3;
    return aluno[v].notafinal;
}

void ImprimeTurma(){
        system("cls");
        for(v=0 ; v<5 ; v++){
        printf("------------------------------------");
        printf("\n\n");
        printf("\n Nome do Aluno: %s",aluno[v].nome);
        printf("\n\n Matricula do Aluno: %d",aluno[v].matricula);
        printf("\n Nota do aluno:");
        for (j = 0; j < 3; j++){
            printf("\\  N%d : %d  ",j+1 , aluno[v].nota[j] );
        }
        printf("\n\n Media = %.1f\n",CalculaMediaAluno());
        }  
    }  


#endif