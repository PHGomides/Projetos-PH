#include <stdio.h>
#include <stdlib.h>


void main() {
    FILE*arq;
    int i;
    arq = fopen("C:\\Users\\pedro\\OneDrive\\Documentos\\GitHub\\AP2\\Pedro Henrique\\Lista 08\\Arquivos\\dados.txt","w");
    if (arq == NULL){
        printf("\n\n  Erro");
    }
    for(i = 0 ; i <= 100 ; i++){
        fprintf(arq , "%d \n",i);
    }
    fclose(arq);
}