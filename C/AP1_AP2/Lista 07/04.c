#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE*arq;
    float real = 49.99;
    int inteiro = 242;
    char nome[6] = {"Pedro"};

    arq = fopen("C:\\Users\\pedro\\OneDrive\\Documentos\\GitHub\\AP2\\Pedro Henrique\\Lista 07\\Arquivos\\EX04_Normal.txt","w");
    if (arq == NULL){
        printf("\n\n  Erro");
    }
    fprintf(arq , "Nome : %s\nNumero inteiro : %d\nNumero real : %.2f",nome,inteiro,real);
    fclose(arq);
   

    //Binario
    FILE*arq_bin;

    arq_bin = fopen("C:\\Users\\pedro\\OneDrive\\Documentos\\GitHub\\AP2\\Pedro Henrique\\Lista 08\\Arquivos\\EX04_Binario.bin","wb");
    if (arq_bin == NULL){
        printf("\n\n  Erro");
    }
    size_t nome_size = strlen(nome) + 1;
    fwrite(nome, sizeof(char), nome_size , arq_bin);
    fwrite(&inteiro, sizeof(int), 1 , arq_bin);
    fwrite(&real, sizeof(float), 1 , arq_bin);
    fclose(arq_bin);
}
