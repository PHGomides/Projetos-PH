#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int codigo;
    char nome[30];
    char laboratorio[30];
    int preco;
}Produto;

Produto vetor[30];
int quantidade_total = -1;

void cadastrasproduto(int codigo, char nome[], int valor, char laboratorio[]){
    quantidade_total++;
    vetor[quantidade_total].codigo = codigo;
    vetor[quantidade_total].preco = valor;
    strcpy(vetor[quantidade_total].laboratorio, laboratorio);
    strcpy(vetor[quantidade_total].nome, nome);
}

void buscarsequencial(int valor){
    for(int i = 0; i <= quantidade_total ; i++){
        if(valor == vetor[i].codigo){
            printf("\n---------------------------\nCodigo: %d\nNome: %s\nLaboratorio: %s\nPreco: %d\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].laboratorio, vetor[i].preco);
            return;
        }
    }
    printf("\nNao encontrou\n");
   
}

void mostrarvetor(Produto vetor[]){

    if(quantidade_total == -1){
        printf("\n----------------------\nVetor Vazio\n----------------------\n");
        return;
    }else{
        printf("\n---------------VETOR---------------\n");
        printf("Codigo: ");
        for (int i = 0; i <= quantidade_total; i++){
            printf(" [%d] ",vetor[i].codigo);
        }
    }
}

void buscabinaria(int valor){
    int metade_quantidade = 0, j;
    Produto auxiliar;

    metade_quantidade = (int)quantidade_total / 2;
    
    for (int i = 1; i <= quantidade_total; i++){
       auxiliar = vetor[i];
       j = i-1;
       while (j>= 0 && auxiliar.codigo < vetor[j].codigo){
            vetor[j + 1] = vetor[j];
            j = j-1;
       }
       vetor[j + 1] = auxiliar;
    }

    mostrarvetor(vetor);


    if(valor >= vetor[metade_quantidade].codigo){
        for (int i = metade_quantidade; i <= quantidade_total; i++){
            if(valor == vetor[i].codigo){
                printf("\n---------------------------\nCodigo: %d\nNome: %s\nLaboratorio: %s\nPreco: %d\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].laboratorio, vetor[i].preco);
                return;
            }
        }
    }else{
        for (int i = metade_quantidade; i >= 0 ; i--){
            if(valor == vetor[i].codigo){
                printf("\n---------------------------\nCodigo: %d\nNome: %s\nLaboratorio: %s\nPreco: %d\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].laboratorio, vetor[i].preco);
                return;
            }
        }
    }
     printf("\nNao encontrou\n");
}

int main (){
    for (int i = 0; i <= 30; i++){
        vetor[i].codigo = 0;
    }
    

    int tipo, flag = 0, codigo, valor;
    char nome[30], labo[30];

    do{

        printf("\n\n\n---------------MENU---------------\n");
        printf("1-Cadastrar: \n2-Pesquisa sequencial: \n3-Pesquisa binaria: \n4-Mostrar vetor: \n5-Fecha\n");
        printf("--> ");
        scanf("%d",&tipo);
        printf("\n----------------------------------\n");
    
        switch (tipo){
        case 1:
            printf("\n\nDigite o codigo: ");
            printf("--> ");
            scanf("%d",&codigo);
            fflush(stdin);
            printf("\nDigite o nome: ");
            printf("--> ");
            fgets(nome, 30, stdin);
            fflush(stdin);
            printf("\nDigite o laboratorio: ");
            printf("--> ");
            fgets(labo, 30, stdin);
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

