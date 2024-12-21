#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int codigo;
    char genero[30];
    char diretor[30];
    char pais[30];
    char nome[30];
    int notaIMDb;
}Produto;

Produto vetor[30];
int quantidade_total = -1;

void cadastrasproduto(int codigo, char genero[], int valor, char diretor[], char pais[], char nome[]){
    quantidade_total++;
    vetor[quantidade_total].codigo = codigo;
    vetor[quantidade_total].notaIMDb = valor;
    strcpy(vetor[quantidade_total].diretor, diretor);
    strcpy(vetor[quantidade_total].genero, genero);
    strcpy(vetor[quantidade_total].pais, pais);
    strcpy(vetor[quantidade_total].nome, nome);
}

void buscarsequencial(int valor){
    for(int i = 0; i <= quantidade_total ; i++){
        if(valor == vetor[i].codigo){
            printf("\n---------------------------\nCodigo: %d\nNome: %s\nGenero: %s\nDiretor: %s\nNotaIMDb: %d\nPais: %s\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].genero, vetor[i].diretor, vetor[i].notaIMDb,vetor[i].pais);
            return;
        }
    }
    printf("\nNao encontrou\n");
   
}

void buscarsequencialNome(char nome[]){
    for(int i = 0; i <= quantidade_total ; i++){
        if(strcmp(vetor[i].nome,nome) == 0){
            printf("\n---------------------------\nCodigo: %d\nNome: %s\nGenero: %s\nDiretor: %s\nNotaIMDb: %d\nPais: %s\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].genero, vetor[i].diretor, vetor[i].notaIMDb,vetor[i].pais);
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
        printf("\n---------------ACERVO---------------\n");
        for (int i = 0; i <= quantidade_total; i++){
            printf("\n");
            printf("Codigo: %d \n",vetor[i].codigo);
            printf("Nome: %s \n",vetor[i].nome);
            printf("Genero: %s \n",vetor[i].genero);
            printf("Diretor: %s \n",vetor[i].diretor);
            printf("NotaIMDb: %d \n", vetor[i].notaIMDb);
            printf("Pais: %s \n",vetor[i].pais);
            printf("------------------------------------------\n");
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

    if(valor >= vetor[metade_quantidade].codigo){
        for (int i = metade_quantidade; i <= quantidade_total; i++){
            if(valor == vetor[i].codigo){
                printf("\n---------------------------\nCodigo: %d\nNome: %s\nGenero: %s\nDiretor: %s\nNotaIMDb: %d\nPais: %s\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].genero, vetor[i].diretor, vetor[i].notaIMDb,vetor[i].pais);
                return;
            }
        }
    }else{
        for (int i = metade_quantidade; i >= 0 ; i--){
            if(valor == vetor[i].codigo){
                printf("\n---------------------------\nCodigo: %d\nNome: %s\nGenero: %s\nDiretor: %s\nNotaIMDb: %d\nPais: %s\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].genero, vetor[i].diretor, vetor[i].notaIMDb,vetor[i].pais);
                return;
            }
        }
    }
     printf("\nNao encontrou\n");
}

void buscabinariaNome(char nome[]){
    int metade_quantidade = 0, j;
    Produto auxiliar;

    metade_quantidade = (int)quantidade_total / 2;
    
    for (int i = 1; i <= quantidade_total; i++){
       auxiliar = vetor[i];
       j = i-1;
       while (j>= 0 && strcmp(vetor[j].nome, auxiliar.nome) > 0){
            vetor[j + 1] = vetor[j];
            j = j-1;
       }
       vetor[j + 1] = auxiliar;
    }

    if(strcmp(nome, vetor[metade_quantidade].nome) >= 0){
        for (int i = metade_quantidade; i <= quantidade_total; i++){
            if(strcmp(vetor[i].nome,nome) == 0){
                printf("\n---------------------------\nCodigo: %d\nNome: %s\nGenero: %s\nDiretor: %s\nNotaIMDb: %d\nPais: %s\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].genero, vetor[i].diretor, vetor[i].notaIMDb,vetor[i].pais);
                return;
            }
        }
    }else{
        for (int i = metade_quantidade; i >= 0 ; i--){
            if(strcmp(vetor[i].nome,nome) == 0){
                printf("\n---------------------------\nCodigo: %d\nNome: %s\nGenero: %s\nDiretor: %s\nNotaIMDb: %d\nPais: %s\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].genero, vetor[i].diretor, vetor[i].notaIMDb,vetor[i].pais);
                return;
            }
        }
    }
     printf("\nNao encontrou\n");
}



void editarFilme(int codigo, char genero[], int valor, char diretor[], char pais[], char nome[]){
    for(int i = 0; i <= quantidade_total ; i++){
        if(codigo == vetor[i].codigo){
            vetor[i].notaIMDb = valor;
            strcpy(vetor[i].diretor, diretor);
            strcpy(vetor[i].genero, genero);
            strcpy(vetor[i].pais, pais);
            strcpy(vetor[i].nome, nome);
            printf("\n----------------Filme editado--------------\n");
             printf("\n---------------------------\nCodigo: %d\nNome: %s\nGenero: %s\nDiretor: %s\nNotaIMDb: %d\nPais: %s\n---------------------------\n",vetor[i].codigo, vetor[i].nome, vetor[i].genero, vetor[i].diretor, vetor[i].notaIMDb,vetor[i].pais);
        }
    }

}













int main (){
    for (int i = 0; i <= 30; i++){
        vetor[i].codigo = 0;
    }
    

    int tipo, flag = 0, codigo, valor;
    char genero[30], diretor[30], pais[30], nome[30];

    int tipobusca = 0, tipobusca2 = 0;

    do{

        printf("\n\n\n---------------MENU---------------\n");
        printf("1-Cadastrar: \n2-Buscar Filme: \n3-Mostrar arcevo: \n4-Editar Filme: \n5-Sair: \n");
        printf("--> ");
        scanf("%d",&tipo);
        printf("\n----------------------------------\n");
    
        switch (tipo){
        case 1:
            printf("\n\nDigite o Codigo: ");
            printf("--> ");
            scanf("%d",&codigo);
            fflush(stdin);
            printf("\nDigite o Nome: ");
            printf("--> ");
            fgets(nome, 30, stdin);
            printf("\nDigite o Genero: ");
            printf("--> ");
            fgets(genero, 30, stdin);
            fflush(stdin);
            printf("\nDigite o Diretor: ");
            printf("--> ");
            fgets(diretor, 30, stdin);
            fflush(stdin);
            printf("\nDigite a NotaIMDb: ");
            printf("--> ");
            scanf("%d",&valor);
            fflush(stdin);
            printf("\nDigite o Pais: ");
            printf("--> ");
            fgets(pais, 30, stdin);
            fflush(stdin);
            cadastrasproduto(codigo, genero, valor,diretor,pais,nome);
            system("cls");
            break;
        case 2:
            printf("\n\n\n---------------Busca---------------\n");
            printf("1-Buscar por codigo: \n2-Buscar por nome: \n");
            printf("--> ");
            fflush(stdin);
            scanf("%d",&tipobusca);
            fflush(stdin);
            printf("\n----------------------------------\n");
            switch (tipobusca)
            {
            case 1:
                printf("1-Buscar sequencial: \n2-Buscar binaria: \n");
                printf("--> ");
                fflush(stdin);
                scanf("%d",&tipobusca2);
                fflush(stdin);
                printf("\n----------------------------------\n");
                switch (tipobusca2)
                {
                case 1:
                    printf("\n\nDigite o codigo do produto: ");
                    printf("--> ");
                    scanf("%d",&codigo);
                    fflush(stdin);
                    buscarsequencial(codigo);
                    break;

                case 2:
                    printf("\n\nDigite o codigo do produto: ");
                    printf("--> ");
                    scanf("%d",&codigo);
                    fflush(stdin);
                    buscabinaria(codigo);
                    break;
                
                default:
                    printf("\nEscolha invalida\n");
                    system("cls");
                    break;
                }
                break;
            
            case 2:
                printf("1-Buscar sequencial: \n2-Buscar binaria: \n");
                printf("--> ");
                scanf("%d",&tipobusca2);
                fflush(stdin);
                printf("\n----------------------------------\n");
                switch (tipobusca2)
                {
                case 1:
                    printf("\n\nDigite o nome do produto: ");
                    printf("--> ");
                    fgets(nome, 30, stdin);
                    fflush(stdin);
                    buscarsequencialNome(nome);
                    break;

                case 2:
                    printf("\n\nDigite o nome do produto: ");
                    printf("--> ");
                    fgets(nome, 30, stdin);
                    fflush(stdin);
                    buscabinariaNome(nome);
                    break;
                
                default:
                    printf("\nEscolha invalida\n");
                system("cls");
                    break;
                }
                break;
            
            default:
                printf("\nEscolha invalida\n");
                system("cls");
                break;
            }

            break;
        case 3:
            mostrarvetor(vetor);
            break;
        case 4:
            printf("\n\nDigite o Codigo: ");
            printf("--> ");
            scanf("%d",&codigo);
            fflush(stdin);
            printf("\nDigite o Nome: ");
            printf("--> ");
            fgets(nome, 30, stdin);
            printf("\nDigite o Genero: ");
            printf("--> ");
            fgets(genero, 30, stdin);
            fflush(stdin);
            printf("\nDigite o Diretor: ");
            printf("--> ");
            fgets(diretor, 30, stdin);
            fflush(stdin);
            printf("\nDigite a NotaIMDb: ");
            printf("--> ");
            scanf("%d",&valor);
            fflush(stdin);
            printf("\nDigite o Pais: ");
            printf("--> ");
            fgets(pais, 30, stdin);
            fflush(stdin);
            editarFilme(codigo, genero, valor,diretor,pais,nome);
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

