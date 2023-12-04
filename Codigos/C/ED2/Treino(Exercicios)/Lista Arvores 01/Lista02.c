#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int num[500];
    int i, cod, cont = 0;

    for (i = 0; i < 500; i++) {
      

        
        num[i]= rand() % 500;
        printf("%d\n",num[i]);
    }

  
    BuscaBinaria(num);
    

    return 0;
}

void BuscaBinaria(int dado[500]) {
    int i, meio, nume;
    printf("Digite o numero que deseja buscar\n");
    scanf("%d", &nume);

    int inicio = 0;
    int fim = 500;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (dado[meio] == nume) {
            printf("Dado: %d", dado[meio]);
            return;
        } else if (dado[meio] < nume) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    printf("nao encontrado\n");
}