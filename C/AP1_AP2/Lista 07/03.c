#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE*arq;
    char c;
    int i=1;
    
    arq = fopen("C:\\Users\\pedro\\OneDrive\\Documentos\\GitHub\\AP2\\Pedro Henrique\\Lista 08\\Arquivos\\dados.txt","r");
    
    if (arq == NULL){
        printf("\n\n  Erro");
    }
    
    while (!feof(arq)){
        
        c = fgetc(arq);
         
        if(c == '\n'){
            i++;
        }
    }

    fclose(arq);
    printf("A quantidade de linha = %d ",i);
}