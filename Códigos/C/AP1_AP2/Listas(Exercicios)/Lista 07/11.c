#include <stdlib.h>
#include <stdio.h>

void main(){
    struct Alunos{
        char nome[100] , curso[100];
        
        float nota[2], media;
    }x;

    int i = 0;

        printf("\n-----------------------------------\n");
        printf("\nDigite seu Nome : ");
        scanf("%[^\n]s",x.nome);
        fflush(stdin);

        printf("\nDigite seu Curso : ");
        scanf("%[^\n]s",x.curso);
        fflush(stdin);

        for (i = 0; i < 2 ; i++)
        {
            printf("\nDigite sua Nota : ");
            scanf("%f",&x.nota[i]);
            fflush(stdin);
        }
        x.media = (x.nota[0] + x.nota[1]) / 2;
        
    
    
    FILE *arq;
    arq = fopen("C:\\Users\\pedro\\Documents\\GitHub\\AP2\\Pedro Henrique\\Lista 08\\Arquivos\\ALUNOS.txt", "w");


        fprintf(arq, "\n-----------------------------------\n");
        fprintf(arq, "Nome : %s\n", x.nome);
        fprintf(arq, "Curso: %s\n", x.curso);
        fprintf(arq, "Media: %.2f\n", x.media);
        fprintf(arq, "\n-----------------------------------\n");

    fclose(arq);
}