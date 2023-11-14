#include <stdlib.h>
#include <stdio.h>

void main(){
    
    FILE *arq;
    char c;
    int i = 0;
    arq = fopen("C:\\Users\\pedro\\Documents\\GitHub\\AP2\\Pedro Henrique\\Lista 08\\Arquivos\\Copia.txt", "r");

    while (!feof(arq))
    {
        c = fgetc(arq);
        if( (c == ' ')){
            i++;
        }
    }
    printf("Numero = %d" , i+1);

    
    

    fclose(arq);
}