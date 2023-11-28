#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int vetor[10];
    int aux = 0;
    int j;

    printf("   Valores do vetor:\n\n");
    for (int i = 0; i < 10; i++){
        vetor[i] =  rand() % 10;
        printf(" [ %d ] ",vetor[i]);
    }

    for (int i = 1; i < 10; i++){
       aux = vetor[i];
       j = i-1;
       while (j>= 0 && aux < vetor[j]){
            vetor[j + 1] = vetor[j];
            j = j-1;
       }
       vetor[j + 1] = aux;
    }

     printf("\n\n   Valores do vetor ordenados:\n\n");
    for (int i = 0; i < 10; i++){
        printf(" [ %d ] ",vetor[i]);
    }
}