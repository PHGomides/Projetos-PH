#include <stdio.h>
#include <stdio.h>
#include <time.h>
#define MAX 10000000

int vetor[MAX];

void selection(){
    
    int aux = 0;

    for (int i = 0; i < MAX; i++){
        for (int j = i + 1; j < MAX; j++){
            if (vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux; 
            }
        }
    }
}

void insertion(){
    
    int j, aux = 0;

    for (int i = 1; i < MAX; i++){
       aux = vetor[i];
       j = i-1;
       while (j>= 0 && aux < vetor[j]){
            vetor[j + 1] = vetor[j];
            j = j-1;
       }
       vetor[j + 1] = aux;
    }
}

void bubble(){

    int aux = 0;

    for (int k = 1; k < MAX; k++) {
        for (int j = 0; j < MAX - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void medirTempo(void (*funcaoOrdenacao)()) {
    clock_t inicio, fim;
    double tempoDecorrido;

    inicio = clock();

    funcaoOrdenacao();

    fim = clock();

    tempoDecorrido = ((double)(fim - inicio)) / (CLOCKS_PER_SEC / 1000.0);

    printf("\n\n-------------------------------------------------");
    printf("\n   Valores do vetor ordenado:\n\n");
    for (int i = 0; i < MAX; i++){
        printf(" [%d] ",vetor[i]);
    }
    printf("\n-------------------------------------------------\n\n");

    printf("Tempo decorrido: %.10f milissegundos\n\n", tempoDecorrido);
}

int main(void){
    int tipo, flag = 0;
    
    do{
        printf("\n\n-------------------------------------------------");
        printf("\n   Valores do vetor Original:\n\n");
        for (int i = 0; i < MAX; i++){
            vetor[i] =  rand() % MAX;
            //printf(" [%d] ",vetor[i]);
        }

        printf("\n-------------------------------------------------");
        printf("\n1-SelectionSort: \n2-InsertionSort: \n3-BubbleSort \n4-Fechar\n");
        printf("--> ");
        scanf("%d",&tipo);
    
        switch (tipo)
        {
        case 1:
            medirTempo(selection); 
            system("pause");
            break;
        case 2:
            medirTempo(insertion);
            system("pause");
            break;
        case 3:
            medirTempo(bubble); 
            system("pause");      
            break;
        case 4:
            flag = -1;
            break;
        default:
            break;
        }
    }while(flag != -1);
}