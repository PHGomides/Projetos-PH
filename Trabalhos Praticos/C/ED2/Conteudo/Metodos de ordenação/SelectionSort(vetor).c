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

    for (int i = 0; i < 10; i++){
        for (int j = i + 1; j < 10; j++){
            if (vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux; 
            }
        }
    }

     printf("\n\n   Valores do vetor ordenados:\n\n");
    for (int i = 0; i < 10; i++){
        printf(" [ %d ] ",vetor[i]);
    }
}