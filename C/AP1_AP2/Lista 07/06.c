#include <stdlib.h>
#include <stdio.h>

void main(){
    FILE*arq;
    char copia [200];
    arq = fopen("C:\\Users\\pedro\\Documents\\GitHub\\AP2\\Pedro Henrique\\Lista 07\\Arquivos\\A.txt", "r");
       
    FILE*arq_copia;
    arq_copia = fopen("C:\\Users\\pedro\\Documents\\GitHub\\AP2\\Pedro Henrique\\Lista 08\\Arquivos\\B.txt","w");
    if ((arq_copia == NULL) || (arq == NULL)){
        printf("\n\n  Erro");
    }

    while (fgets(copia,200,arq) != NULL){
        fputs(copia,arq_copia);
    }



    int fcloseall( ); 
}