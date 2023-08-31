
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE*arq;
    char copia [200];
    
    arq = fopen("C:\\Users\\pedro\\Documents\\GitHub\\AP2\\Pedro Henrique\\Lista 07\\Arquivos\\EX04_Normal.txt","r");

    
    FILE*arq_copia;
    arq_copia = fopen("C:\\Users\\pedro\\Documents\\GitHub\\AP2\\Pedro Henrique\\Lista 08\\Arquivos\\Copia.txt","w");
    if ((arq_copia == NULL) || (arq == NULL)){
        printf("\n\n  Erro");
    }

    while (fgets(copia,200,arq) != NULL){
        fputs(copia,arq_copia);
    }
    

    fclose(arq_copia);
    fclose(arq);
}