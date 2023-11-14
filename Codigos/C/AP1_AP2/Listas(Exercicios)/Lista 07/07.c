#include <stdlib.h>
#include <stdio.h>

void main(){
    struct Alunos{
        char nome[100] , curso[100];
        float media;
    }x[5];

    int i = 0;

    for(i = 0 ; i < 5 ; i++){
        printf("\n-----------------------------------\n");
        printf("\nDigite seu Nome : ");
        scanf("%[^\n]s",x[i].nome);
        fflush(stdin);

        printf("\nDigite seu Curso : ");
        scanf("%[^\n]s",x[i].curso);
        fflush(stdin);

        printf("\nDigite sua Media : ");
        scanf("%f",&x[i].media);
        fflush(stdin);
    }
    
    FILE *arq;
    arq = fopen("C:\\Users\\pedro\\Documents\\GitHub\\AP2\\Pedro Henrique\\Lista 08\\Arquivos\\ALUNOS.txt", "w");

    fprintf(arq , "\n-----------------------------------\n");

    for(i = 0 ; i < 5 ; i++){
        fprintf(arq, "\n-----------------------------------\n");
        fprintf(arq, "Nome : %s\n", x[i].nome);
        fprintf(arq, "Curso: %s\n", x[i].curso);
        fprintf(arq, "Media: %.2f\n", x[i].media);
    }

    fclose(arq);
}