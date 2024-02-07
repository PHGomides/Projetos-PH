#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Vetor;

Vetor* criarvetor(int x, int y) {
    Vetor* nv = malloc(sizeof(Vetor));
    if (nv) {
        nv->x = x;
        nv->y = y;
    }
    return nv;
}

Vetor soma(const Vetor* v1, const Vetor* v2) {
    Vetor s;
    s.x = v1->x + v2->x;
    s.y = v1->y + v2->y;
    return s;
}

int interno(const Vetor* v1, const Vetor* v2) {
    return (v1->x * v2->x) + (v1->y * v2->y);
}

float vetorial(const Vetor* v1, const Vetor* v2) {
    return abs((v1->x * v2->y) - (v2->x * v1->y));
}

void libera(Vetor* v) {
    free(v);
}

int main() {

int tipo,tipo02;
int n1,n2;
    do{
        printf("\n\nDigite o x e y do vetor01:\n");
        scanf("%d",&n1);
        scanf("%d",&n2);
        Vetor* Vet1 = criarvetor(n1, n2);

        printf("\n\nDigite o x e y do vetor02:\n");
        scanf("%d",&n1);
        scanf("%d",&n2);
        Vetor* Vet2 = criarvetor(n1, n2);
        do{

            printf("\n\nOperacao\n\n 1-Somar vetor\n 2-Produto interno\n 3-Produto vetorial\n 4-Trocar valores dos vetores \n 5-Sair\n\n --> ");
            scanf("%d",&tipo);

            switch (tipo)
            {
            case 1:
                    if (Vet1 && Vet2) {

                        Vetor somar = soma(Vet1, Vet2);

                        printf("\n\nResultado da soma: (%d, %d)", somar.x, somar.y);

                    } else {
                        printf("\n\nErro ao alocar memoria");
                    }
                break;
            
            case 2:
                    if (Vet1 && Vet2) {

                        printf("\n\nResultado do produto interno: %d", interno(Vet1, Vet2));

                    } else {
                        printf("\n\nErro ao alocar memoria");
                    }
                break;

            case 3:
                    if (Vet1 && Vet2) {

                        printf("\n\nResultado do produto vetorial: %.2f", vetorial(Vet1, Vet2));

                      
                    } else {
                        printf("\n\nErro ao alocar memoria");
                    }
                    
                break;
            
            case 4:

                break;

            case 5:
                tipo = 4;
                tipo02 = -1;
                break;
            
            default:
                printf("\n\nNumero invalido\n");
                break;
            }
        }while(tipo != 4);
        libera(Vet1);
        libera(Vet2);
    }while(tipo02 != -1);
   
    return 0;
}
