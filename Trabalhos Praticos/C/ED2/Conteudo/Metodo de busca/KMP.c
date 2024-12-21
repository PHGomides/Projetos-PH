#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void knuthMorrisPratt(char *texto, char *palavra, int tamanhoTexto, int tamanhoPalavra){

	int contador=0;


	int proximos[tamanhoPalavra+1];

	for (int i = 0; i < tamanhoPalavra + 1; i++){
		proximos[i] = 0;
	}

	for (int i = 1; i < tamanhoPalavra; i++)
	{
		int j = proximos[i+1];

		while (j > 0 && palavra[j] != palavra[i]){
			j = proximos[j];
		}

		if (j > 0 || palavra[j] == palavra[i]){
			proximos[i+1] = j + 1;
		}
	}

	for (int i = 0, j = 0; i < tamanhoTexto; i++)
	{
		if (*(texto + i) == *(palavra + j))
		{
			if (++j == tamanhoPalavra){
				contador++;
			}
		}
		else if (j > 0) {
			j = proximos[j];
			i--;	
		}
	}
	printf("\nHouve %d ocorrencia(s) do padrao %s\n",contador, palavra);
}


int main(){
	char texto[10000] = "ABCABAABCABAC";
	char palavra[50] = "ABA";

	int opcao=-1;

	while(opcao!=0){
	
		printf("\n---------------MENU---------------\n");
		printf("1: Inserir Texto \n");
		printf("2: Pesquisar palavra\n");
		printf("0: SAIR \n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
			printf("\n------INSERINDO------\n");
			printf("Digite a  frase\n");
			fflush(stdin);
			fgets(texto, 10000 , stdin);

			break;

			case 2:
			printf("\n------PESQUISANDO------\n");
			printf("Digite um valor\n");
			fflush(stdin);
			fgets(palavra, 50 , stdin);
			int tamanhoTexto = strlen(texto);
			int tamanhoPalavra = strlen(palavra);
			knuthMorrisPratt(texto, palavra, tamanhoTexto, tamanhoPalavra);
			break;

			case 0:
			printf("\nTchau! Ate a proxima\n");
			opcao = 0;
			break;

			default:
			printf("\nOpcao inválida! \n");
			break;
		}


	}
	return 0;
}