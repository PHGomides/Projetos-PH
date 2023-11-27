#ifndef biblioteca_H_INCLUDE
#define biblioteca_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>

void LeAluno (){
    for(int i = 0; i < 5; i++){
        printf("Digite o sua matricula:");
        scanf("%d",&Turma[i].matricula);
        for(int u = 0; u < 3; u++){
            printf("\n%d Nota: ", u+1);
            scanf("%f",&Turma[i].notas[u]);
        }
    }
}

void ImprimeTurma(){
     printf("\nTurma:");
    for(int i = 0; i < 5; i++){
        printf("-----------------------------------\n");
        printf("Matricula: %d\n",Turma[i].matricula);
        printf("-----------------------------------\n");
        for(int u = 0; u < 3; u++){
            printf("%f Nota: %d\n",u+1,Turma[i].notas[u]);
        }
    }
}

float CalculaMediaAluno(int aluno){
    return (Turma[aluno].notas[0] + Turma[aluno].notas[1] + Turma[aluno].notas[2]) / 3;
}
#endif