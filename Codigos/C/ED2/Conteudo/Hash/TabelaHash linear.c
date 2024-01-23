#include <stdio.h>
#include <stdlib.h>

int tabelaHash[10];
int chave;

int gerarCodigoHash (int chave){
    return chave % 10;
}

void inserir(){
    int posicao = gerarCodigoHash(chave);
    while (tabelaHash[posicao] != -1){
        posicao = gerarCodigoHash(posicao + 1);
    }
    tabelaHash[posicao] = chave;
     
}

int main(void){
    for(int i = 0; i < 10; i++){
        tabelaHash[i] = -1;
    }

	int opcao=-1;

	while(opcao!=0){
		//imprimindo  a tabela
        printf("\n---------------Tabela---------------\n");
        for(int i = 0; i < 10; i++){
            printf("[%d]",tabelaHash[i]);
        }
		
		printf("\n---------------MENU---------------\n");
		printf("1: Inserir \n");
		printf("0: SAIR \n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
                printf("\n------INSERINDO------\n");
                printf("\n\nDigite a chave: ");
                scanf("%d",&chave); 
                inserir();
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