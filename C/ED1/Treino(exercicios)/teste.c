#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Vetor;

Vetor* novo_vetor(int x, int y) {
    Vetor* nv = malloc(sizeof(Vetor));
    if (nv) {
        nv->x = x;
        nv->y = y;
    }
    return nv;
}

void libera(Vetor* v) {
    free(v);
}

Vetor soma(const Vetor* v1, const Vetor* v2) {
    Vetor s;
    s.x = v1->x + v2->x;
    s.y = v1->y + v2->y;
    return s;
}

int prod_interno(const Vetor* v1, const Vetor* v2) {
    return (v1->x * v2->x) + (v1->y * v2->y);
}

float prod_vetorial(const Vetor* v1, const Vetor* v2) {
    return (v1->x * v2->y) - (v2->x * v1->y);
}

int main() {
    Vetor* Vet1 = novo_vetor(6, 15);
    Vetor* Vet2 = novo_vetor(2, 9);

    if (Vet1 && Vet2) {
        Vetor result_soma = soma(Vet1, Vet2);
        int result_prod_interno = prod_interno(Vet1, Vet2);
        float result_prod_vetorial = prod_vetorial(Vet1, Vet2);

        printf("Vetor 1 + Vetor 2 = (%d, %d)\n", result_soma.x, result_soma.y);
        printf("Produto interno entre vetores: %d\n", result_prod_interno);
        printf("Produto vetorial entre vetores: %.2f\n", result_prod_vetorial);

        libera(Vet1);
        libera(Vet2);
    } else {
        printf("Erro ao alocar memória para os vetores.\n");
    }

    return 0;
}