#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int posicao[20], p=0;

void busca_padrao(char busca[], char frase[], int tamanho_frase, int tamanho_busca){
    for (int u = 0; u < 20; u++){
       posicao[u]=0;
    }
    
    
    int j;
    for (int i = 0; i <= tamanho_frase - tamanho_busca; i++){
        j=0;
        while((j < tamanho_busca) && (frase[i+j] == busca[j])){
            j = j +1;
            if(j == tamanho_busca){
                i = i - tamanho_busca;
                posicao[p] = i;
                p++;
            }
        } 
    }
}


int main(void){

    char busca[50], frase[100];

    int tamanho_frase, tamanho_busca;

    int opcao=-1;

	while(opcao!=0){
		
		printf("\n---------------MENU---------------\n");
		printf("1: Inserir frase\n");
        printf("2: Buscar\n");
		printf("0: SAIR \n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
                printf("\n------INSERINDO------\n");

                printf("\n\nDigite a frase: ");
                fflush(stdin);
                scanf("%s",frase);
                tamanho_frase = strlen(frase);
                fflush(stdin);
			break;

            case 2:
                printf("\n------BUSCANDO------\n");

                printf("\n\nDigite a busca: ");
                fflush(stdin);
                scanf("%s",busca);
                tamanho_busca = strlen(busca);
                fflush(stdin);
                busca_padrao(busca, frase, tamanho_frase, tamanho_busca);
                if (posicao[0]= 0){
                    printf("\n\nNao encontrado");
                }else{
                    printf("\n\nEncontrado nos locais: ");
                    for (int i = 0; i <= p; i++){
                        printf("[%d]",posicao[p]);
                    }
                }
                
			break;

			case 0:
			    printf("\nTchau! Ate a proxima\n");
			break;

			default:
			    printf("\nOpcao inválida! \n");
			break;
		}
	}
}