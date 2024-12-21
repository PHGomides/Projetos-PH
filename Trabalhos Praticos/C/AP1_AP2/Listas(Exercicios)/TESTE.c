#include <stdlib.h>
#include <stdio.h>

int troca_pont(int *p){
    int resultado = 0;
    for (int i = 0; i < 5; i++){
         resultado = p[i] + resultado;
    }
    return resultado;
}

int main(void){
    int vetor[5] = {1,3,5,3,1};
    printf("\n\nA soma : %d",troca_pont(vetor));
    
    
}