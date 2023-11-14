#include <stdio.h>
#include <stdlib.h>

typedef struct Conteudo{
	int valor;
}tipoItem;

typedef struct NOH{
	tipoItem item;
	struct NOH *esquerda;
	struct NOH *direita;
	int fatorBalanceamento;
	int altura;
}tipoNoh;





int main (){

}