#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *vetor, int tamanho)
{
    int meio = tamanho / 2;
    int i = 0, j = meio, k = 0;
    int auxiliar[tamanho];
    while (i < meio && j < tamanho)
    {
        if (vetor[i] <= vetor[j])
            auxiliar[k] = vetor[i++];
        else
            auxiliar[k] = vetor[j++];
        k++;
    }
    if (i == meio)
    {
        while (j < tamanho)
        {
            auxiliar[k++] = vetor[j++];
        }
    }
    else
    {
        while (i < meio)
        {
            auxiliar[k++] = vetor[i++];
        }
    }
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = auxiliar[i];
    }
}

void mergeSort(int *vetor, int tamanho)
{
    int meio = tamanho / 2;
    if (tamanho > 1)
    {
        mergeSort(vetor, meio);
        mergeSort(vetor + meio, tamanho - meio);
        merge(vetor, tamanho);
    }
}

int main(void)
{
    int vetor[10];

    printf("   Valores do vetor :\n\n");
    for (int i = 0; i < 10; i++)
    {
        vetor[i] = rand() % 10;
        printf(" [ %d ] ", vetor[i]);
    }

    mergeSort(vetor, 10);

    printf("\n\n   Valores do vetor ordenado:\n\n");
    for (int i = 0; i < 10; i++)
    {
        printf(" [ %d ] ", vetor[i]);
    }
}