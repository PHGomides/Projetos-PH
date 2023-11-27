#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct bolsa_valores
{
    char nome_companhia[30],area_atuacao[30];
    float valor_atual;
    float valor_anterior;
    double variacao;
};
int main()
{
    struct bolsa_valores bv;
    bv.variacao=bv.valor_atual-bv.valor_anterior;

    setlocale(LC_ALL,"Portuguese");
    printf("Digite o nome da companhia:\n");
    fgets(bv.nome_companhia,30,stdin);
    fflush(stdin);
    printf("Digite a área de atuação da companhia:\n");
    fgets(bv.area_atuacao,30,stdin);
    fflush(stdin);
    printf("Qual o valor atual da ação?:\n");
    scanf("%f",&bv.valor_atual);
    fflush(stdin);
    printf("Qual era o valor anterior da ação?:\n");
    fflush(stdin);
    scanf("%f",&bv.valor_anterior);

    gets()
    scanf("%[^\n]s",x[i].curso);
    f




    //imprimir na tela:
    printf("Nome da companhia: %s\n",bv.nome_companhia);
    printf("Área de atuação: %s\n",bv.area_atuacao);
    printf("Valor atual: %f\n",bv.valor_atual);
    printf("Valor anterior: %f\n",bv.valor_anterior);
    printf("Variação = %f\n",bv.variacao);



    return 0;
}