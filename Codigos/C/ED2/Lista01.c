#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto{
	int codigo;
    char nome[30];
    char laboratorio[30];
    int preco;
}produto;

produto vetor[30];
int quant = -1;


void cadastrasproduto(int codigo, char nome[], int valor, char laboratorio[]){
    quant++;
    vetor[quant].codigo = codigo;
    vetor[quant].preco = valor;
    strcpy(vetor[quant].laboratorio, laboratorio);
    strcpy(vetor[quant].nome, nome);
}

void buscarsequencial(int valor){
    for(int i = 0; i <= quant ; i++){
        if(valor == vetor[i].codigo){
            printf("\n---------------------------\nCodigo: %d\nNome: %s\nLaboratorio: %s\nPreco: %d\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].laboratorio, vetor[i].preco);
            return;
        }
    }
    printf("\nNao encontrou\n");
   
}

void buscabinaria(int valor){
    int menor = vetor[0].codigo, aux_quant = 0;
    produto auxiliar[30];
    
    aux_quant = (int)quant / 2;

    for (int i = 0; i <= quant; i++){
        for (int x = i; x <= quant ; x++){
            if(menor > vetor[x].codigo){
                menor = vetor[x].codigo;
                auxiliar[i].codigo = menor;
            }       
        }
    }
    mostrarvetor(auxiliar);


    if(auxiliar[aux_quant].codigo >= valor){
        for (int i = aux_quant; i <=quant; i++){
            if(valor == auxiliar[i].codigo){
                printf("\n---------------------------\nCodigo: %d\nNome: %s\nLaboratorio: %s\nPreco: %d\n---------------------------\n",auxiliar[i].codigo, auxiliar[i].nome, auxiliar[i].laboratorio, auxiliar[i].preco);
                return;
            }
        }
    }else{
        for (int i = aux_quant; i >=0; i--){
            if(valor == auxiliar[i].codigo){
                printf("\n---------------------------\nCodigo: %d\nNome: %s\nLaboratorio: %s\nPreco: %d\n---------------------------\n",auxiliar[i].codigo, auxiliar[i].nome, auxiliar[i].laboratorio, auxiliar[i].preco);
                return;
            }
        }
    }
     printf("\nNao encontrou\n");

}

void mostrarvetor(produto vet[]){
    if(quant == -1){
        printf("\n----------------------\nVetor Vazio\n----------------------\n");
        return;
    }
    for (int i = 0; i <= quant; i++){
        printf("\n----------------------\nCodigo: %d\n----------------------\n",vet[i].codigo);
    }    
}

int main (){
    for (int i = 0; i <= 30; i++){
        vetor[i].codigo = 0;
    }
    

    int tipo, flag = 0, codigo, valor;
    char nome[30], labo[30];

    do{

        printf("\n-------------------------------------------------");
        printf("\n\n1-Cadastrar: \n2-Pesquisa sequencial \n3-Pesquisa binaria \n4-Mostrar vetor\n5-Fechar\n");
        printf("--> ");
        scanf("%d",&tipo);
    
        switch (tipo)
        {
        case 1:
            printf("\n\nDigite o codigo: ");
            printf("--> ");
            scanf("%d",&codigo);
            fflush(stdin);
            printf("\nDigite o nome: ");
            printf("--> ");
            gets(nome);
            fflush(stdin);
            printf("\nDigite o laboratorio: ");
            printf("--> ");
            gets(labo);
            fflush(stdin);
            printf("\nDigite o valor: ");
            printf("--> ");
            scanf("%d",&valor);
            fflush(stdin);
            cadastrasproduto(codigo, nome, valor,labo);
            system("cls");
            break;
        case 2:
            printf("\n\nDigite o codigo do produto: ");
            printf("--> ");
            scanf("%d",&codigo);
            fflush(stdin);
            buscarsequencial(codigo);
            break;
        case 3:
            printf("\n\nDigite o codigo do produto: ");
            printf("--> ");
            scanf("%d",&codigo);
            fflush(stdin);
            buscabinaria(codigo);
            break;
        case 4:
            mostrarvetor(vetor);
            break;
        case 5:
            flag = -1;
            break;
        default:
            break;
        }
    }while(flag != -1);
 

    return 0;
}

