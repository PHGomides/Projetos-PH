#include <stdio.h>

int verificarArrumado(int v[], int p, int r) {
	for (int j = p; j <= r; j++) {
    	int arrumado = 1;

    	for (int i = p; i < j; i++) {
        	if (v[i] >= v[j]) {
            	arrumado = 0;
            	break;
        	}
    	}

    	for (int i = j + 1; i <= r; i++) {
        	if (v[j] >= v[i]) {
            	arrumado = 0;
            	break;
        	}
    	}

    	if (arrumado) {
        	return j;
    	}
	}

	return -1;
}

int main() {
	int vetor[] = {1, 2, 3, 6, 8, 7, 1};
	int tamanho = sizeof(vetor) / sizeof(vetor[0]);

	int p = 0;
	int r = tamanho - 1;

	int j = verificarArrumado(vetor, p, r);

	if (j != -1) {
    	printf("O vetor está arrumado");
	} else {
    	printf("O vetor não está arrumado\n");
	}

	return 0;
}
