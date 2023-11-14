#include <stdio.h>
#include <stdlib.h>

// ALUNO PEDRO HENRIQUE GOMIDES MORAES 
typedef struct Produto{
    char nome[50];
    int id, estoque;
    float valor;
}Produto;

Produto p[10];

void cadastrarProduto(Produto p[], int *codigo){
    if(*codigo < 10){
        printf("\n\nDigite o nome do produto: ");
        scanf(" %50[^\n]", p[*codigo].nome);
        printf("\n\nDigite a quantidade: ");
        scanf("%d", &p[*codigo].estoque);
        printf("\n\nDigite o valor do produto: ");
        scanf("%f", &p[*codigo].valor);
        p[*codigo].id = *codigo;
        printf("\nProduto foi cadastrado, no id %d.", p[*codigo].id + 1);
        (*codigo)++;
    }else{
        printf("\n\n Cadastro de produtos esta lotado");
    }
}

void buscasProduto(Produto p[]){
    int pesq;
    printf("\n\n Digite o numero do id do produto: ");
    scanf("%d",&pesq);
    pesq--;
    if ((pesq >= 0) && (pesq <= 10) && (pesq == p[pesq].id)) {
        printf("\n\n O nome do produto : %s",p[pesq].nome);
        printf("\nEstoque do produto: %d", p[pesq].estoque);
        printf("\nValor: %.2f", p[pesq].valor);
    } else {
        printf("\nProduto invalido");
    }
}

void deletarProduto(Produto p[]){
    int pesq;
    printf("\n\n Digite o numero do id do produto: ");
    scanf("%d",&pesq);
    pesq--;
    if ((pesq >= 0) && (pesq <= 10) && (pesq == p[pesq].id)) {
        p[pesq].id = -1;
        p[pesq].nome[0] = '\0';
        p[pesq].estoque = 0;
        p[pesq].valor = 0.00;
        printf("\n\nProduto excluido com sucesso.");
    } else {
        printf("\nProduto invalido");
    }

}


int main(){
    int tipo;
    int codigo = 0;
   do{
        printf("\n\nArea de Produtos:\n\n 1-Cadastrar\n 2-Buscar\n 3-Deletar\n 4-Sair\n\n --> ");
        scanf("%d",&tipo);

        switch (tipo)
        {
        case 1:
                cadastrarProduto(p, &codigo);
            break;
        
        case 2:
                buscasProduto(p);
            break;

        case 3:
                deletarProduto(p);
            break;
        
        default:
            break;
        }
   }while(tipo != 4);
   
   return 0;
}
