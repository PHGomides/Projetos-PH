#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct nodo
{
    int info;
    struct nodo *esq;
    struct nodo *dir;
} NO;

typedef NO *ARV;

int EMPTY(ARV a)
{
    return (a == NULL);
}
// Função para inserir um novo elemento 'b' na arvore'a'ARV insere (ARV a, int b){
ARV nova;

ARV insere(ARV a, int b){
    ARV nova;
    if(EMPTY(a)){
        nova = (ARV)malloc(sizeof(NO));
        nova->esq = NULL;
        nova->dir = NULL;
        nova->info = b;
        printf("Insercao do numero %d na AB realizada!", b);
        return nova;
    }
    else
    {
        if (b > a->info)
            a->dir = insere(a->dir, b);
        else
            a->esq = insere(a->esq, b); /* Repeticoessao inseridas na esquerda! */
        return a;
    }
}

int main(){

    ARV a = NULL;
    int opcao = 0;
    int num;

    while (opcao != 2)
    {
        system("cls");
        printf("\n\n----------------MENU PRINCIPAL----------------");
        printf("\n\n 1 - Inserir Novo Numero na AB");
        printf("\n 2 - Encerrar");
        printf("\n\n Opcao Escolhida: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            system("cls");
            printf("\nNovo Numero: ");
            scanf("%d", &num);
            a = insere(a, num);
            system("pause>>null");
            break;
        }
    }
    return 0;
}

/*Resposta da 4
a) Insercao do numero 40 na AB realizada!, Insercao do numero 25 na AB realizada!, Insercao do numero 77 na AB realizada!, Insercao do numero 15 na AB realizada!
Insercao do numero 8 na AB realizada!, Insercao do numero 33 na AB realizada!, Insercao do numero 56 na AB realizada!, Insercao do numero 90 na AB realizada!
Insercao do numero 48 na AB realizada!

b) Insercao do numero 1 na AB realizada!, Insercao do numero 2 na AB realizada!, Insercao do numero 3 na AB realizada!, Insercao do numero 4 na AB realizada!
Insercao do numero 5 na AB realizada!, Insercao do numero 6 na AB realizada!, Insercao do numero 7 na AB realizada!, Insercao do numero 8 na AB realizada!

c)




*/ 
