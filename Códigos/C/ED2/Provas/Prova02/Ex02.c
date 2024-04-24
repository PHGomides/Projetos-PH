#include <stdio.h>
#include <stdlib.h>

int tabelaHash[10];

//-----------------------linear----------------------------------------
int Hashlinear (int chave){
    return (chave + 1) % 10;
}

void inserirlinear(int chave){
    int posicao = Hashlinear(chave);
    while (tabelaHash[posicao] != 0){
        posicao = Hashlinear(posicao);
    }
    tabelaHash[posicao] = chave;  
}
//--------------------------------------------------------------------




//-----------------------Quadratica_1----------------------------------------
int HashQuadratica_1 (int chave, int tentativa){
    return (chave + (tentativa*2)) % 10;
}
void inserirQuadratica_1(int chave){
    int tentativa = 0 ;
    int posicao = HashQuadratica_1(chave,tentativa);
    while (tabelaHash[posicao] != 0){
        tentativa++;
        posicao = HashQuadratica_1(chave,tentativa);
    }
    tabelaHash[posicao] = chave;  
}
//--------------------------------------------------------------------



//-----------------------Quadratica_2----------------------------------------
int HashQuadratica_2 (int chave, int tentativa){
    return (chave + (tentativa*2) + (tentativa*tentativa)) % 10;
}
void inserirQuadratica_2(int chave){
    int tentativa = 0 ;
    int posicao = HashQuadratica_2(chave,tentativa);
    while (tabelaHash[posicao] != 0){
        tentativa++;
        posicao = HashQuadratica_2(chave,tentativa);
    }
    tabelaHash[posicao] = chave;  
}
//--------------------------------------------------------------------




//-----------------------Duplo----------------------------------------
int HashDuplo(int chave, int tentativa){
    int h1 = chave % 10;
    int h2 = 7 - (chave % 7);
    return (h1 + tentativa * h2)%10;
}
void inserirDuplo(int chave){
    int tentativa = 0 ;
    int posicao = HashDuplo(chave,tentativa);
    while (tabelaHash[posicao] != 0){
        tentativa++;
        posicao = HashDuplo(chave,tentativa);
    }
    tabelaHash[posicao] = chave;  
}
//--------------------------------------------------------------------


int main(void){
    
	int opcao=-1;
    int vetor[] = {371,121,173,203,11,24};
    int tamanho_vetor = 6;
    int escolha;


	while(opcao!=0){
        
        for(int i = 0; i < 10; i++){
        tabelaHash[i] = 0;
        }
		
		printf("\n---------------MENU---------------\n");
		printf("1: Seleciona metodo hash \n");
		printf("0: SAIR \n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
                printf("\n------Metodos------\n");
                printf("1: Seleciona hash_linear \n");
		        printf("2: Seleciona hash_quadratica_1 \n");
                printf("3: Seleciona hash_quadratica_2 \n");
                printf("4: Seleciona hash_duplo \n");
                printf("\n\nDigite a escolha: ");
                scanf("%d",&escolha); 
                switch(escolha){

                    case 1:
                        for (int i = 0; i < tamanho_vetor; i++){
                            inserirlinear(vetor[i]);
                        }
                        
                        //imprimindo  a tabela
                        printf("\n---------------Tabela---------------\n");
                        for(int i = 0; i < 10; i++){
                            printf("[%d]",tabelaHash[i]);
                        }
                    break;

                    case 2:
                        for (int i = 0; i < tamanho_vetor; i++){
                            inserirQuadratica_1(vetor[i]);
                        }
                        
                        //imprimindo  a tabela
                        printf("\n---------------Tabela---------------\n");
                        for(int i = 0; i < 10; i++){
                            printf("[%d]",tabelaHash[i]);
                        }
                    break;

                    case 3:
                        for (int i = 0; i < tamanho_vetor; i++){
                           inserirQuadratica_2(vetor[i]);
                        }
                        
                        //imprimindo  a tabela
                        printf("\n---------------Tabela---------------\n");
                        for(int i = 0; i < 10; i++){
                            printf("[%d]",tabelaHash[i]);
                        }
                    break;

                    case 4:
                        for (int i = 0; i < tamanho_vetor; i++){
                            inserirDuplo(vetor[i]);
                        }
                        
                        //imprimindo  a tabela
                        printf("\n---------------Tabela---------------\n");
                        for(int i = 0; i < 10; i++){
                            printf("[%d]",tabelaHash[i]);
                        }
                    break;

                    default:
                        printf("\nOpcao inválida! \n");
                    break;
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