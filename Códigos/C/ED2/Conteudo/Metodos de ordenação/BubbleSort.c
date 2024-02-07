#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int vetor[10];
    int aux = 0;

    printf("   Valores do vetor:\n\n");
    for (int i = 0; i < 10; i++){
        vetor[i] =  rand() % 10;
        printf(" [ %d ] ",vetor[i]);
    }

    for (int k = 1; k < 10; k++) {
        for (int j = 0; j < 10 - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

     printf("\n\n   Valores do vetor ordenados:\n\n");
    for (int i = 0; i < 10; i++){
        printf(" [ %d ] ",vetor[i]);
    }
}