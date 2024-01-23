#include <stdio.h>
#include <stdlib.h>

#define T 10

typedef struct {
	char nome[50];
	int cpf;
} Pessoa;

typedef struct no{
	Pessoa pessoa;
	struct no *proximo;
} No;

typedef struct {
	No *inicio;
	int tamanho;
} Lista;

Lista *tabela[T];


Pessoa criarPessoa(){
	Pessoa p; 
	printf("\n Digite o nome: ");
	fflush(stdin);
	fgets(p.nome, 50, stdin);
	printf("\n Digite o cpf: ");
	scanf("%d", &p.cpf);
	return p;
}

Lista* criarLista(){
	Lista *p = malloc(sizeof(Lista));
	p ->inicio = NULL;
	p ->tamanho = 0;
	return p;
}

void inserirInicio(Pessoa p, Lista *lista){
	No *no = malloc(sizeof(No));
	no->pessoa = p;
	no->proximo = lista->inicio;
	lista->inicio = no;
	lista->tamanho++;
}

No* buscarNo(int cpf, No *inicio){
	while (inicio != NULL){
		if (inicio->pessoa.cpf == cpf){
			return inicio;
		}else{
			inicio = inicio->proximo;
		}
	}
	return NULL;
}

int funcaoEspelhamento(int cpf){
	return cpf % T;
}

void inserirTabela(){
	Pessoa p = criarPessoa();
	int chave = funcaoEspelhamento(p.cpf);
	inserirInicio(p, tabela[chave]);
}

Pessoa* buscarPessoaTabela(int cpf){
	int chave = funcaoEspelhamento(cpf);
	No *no = buscarNo(cpf, tabela[chave]->inicio);
	if(no){
		return &no->pessoa;
	}else{
		return NULL;
	}
}

void imprimindoPessoa(Pessoa p){
	printf("\tNome: %s\tCpf: %d\n", p.nome, p.cpf);
}

void imprimindoLista(No *inicio){
	while (inicio != NULL){
		imprimindoPessoa(inicio->pessoa);
		inicio = inicio->proximo;
	}
}


int main(void){
    for(int i = 0; i < 10; i++){
        tabela[i] = criarLista();
    }

	int opcao=-1;
	int cpf;
	Pessoa *p;

	while(opcao!=0){
		//imprimindo  a tabela
		printf("\n---------------TABELA-------------\n");
		for (int i = 0; i < T; i++){
			printf("[%d] Lista tamanho: %d\n",i,tabela[i]->tamanho);
			imprimindoLista(tabela[i]->inicio);
		}
		
        
		
		printf("\n---------------MENU---------------\n");
		printf("1: Inserir \n");
		printf("2: Buscar \n");
		printf("0: SAIR \n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
                printf("\n------INSERINDO------\n");
				inserirTabela();
			break;

			case 2:
                printf("\n------BUSCANDO------\n");
                printf("\n\nDigite o cpf: ");
                scanf("%d",&cpf); 
                p = buscarPessoaTabela(cpf);
				if(p){
					printf("Pessoa -> Cfp: %d/tNome: %s", p->cpf, p->nome);
				}else{
					printf("Pessoa nao encontrado!\n");
				}
			break;

			case 0:
				for (int i = 0; i < T; i++){
					free(tabela[i]->inicio);
				}
			    printf("\nTchau! Ate a proxima\n");

			break;

			default:
			    printf("\nOpcao inválida! \n");
			break;
		}
	}

    


}