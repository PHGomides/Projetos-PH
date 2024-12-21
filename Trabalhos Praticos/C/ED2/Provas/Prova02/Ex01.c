#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 10

typedef struct {
    int chave;
    char cpf[50];
    char nome[50];
    char infos[500];
} Pessoa;

typedef struct no {
    Pessoa pessoa;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tamanho;
} Lista;

Lista *tabela[T];

//função hash
int funcaoEspelhamento(int chave) {
    return chave % T;
}

Lista *criarLista() {
    Lista *p = malloc(sizeof(Lista));
    p->inicio = NULL;
    p->tamanho = 0;
    return p;
}

void inserirInicio(Pessoa p, Lista *lista) {
    No *no = malloc(sizeof(No));
    no->pessoa = p;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tamanho++;
}

No *buscarNo(int chave, No *inicio) {
    while (inicio != NULL) {
        if (inicio->pessoa.chave == chave) {
            return inicio;
        } else {
            inicio = inicio->proximo;
        }
    }
    return NULL;
}

void inserirTabela(Pessoa p) {
    int chave = funcaoEspelhamento(p.chave);
    inserirInicio(p, tabela[chave]);
}

Pessoa *buscarPessoaTabela(int chave) {
    int indice = funcaoEspelhamento(chave);
    No *no = buscarNo(chave, tabela[indice]->inicio);
    if (no) {
        return &no->pessoa;
    } else {
        // Se a pessoa não foi encontrada na tabela hash, procuramos no arquivo
        FILE *arquivo = fopen("ArquivoEx01.txt", "r");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return NULL;
        }
        
        Pessoa *p = malloc(sizeof(Pessoa)); // Aloca memória para a pessoa encontrada no arquivo
        while (fscanf(arquivo, "%d;%[^;];%[^;];%[^\n]\n", &p->chave, p->cpf, p->nome, p->infos) != EOF) {
            if (p->chave == chave) {
                fclose(arquivo);
                return p;
            }
        }

        fclose(arquivo);
        free(p); // Libera a memória alocada para a pessoa
        return NULL;
    }
}

void salvarRegistro(Pessoa p) {
    FILE *arquivo = fopen("ArquivoEx01.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fprintf(arquivo, "%d;%s;%s;%s\n", p.chave, p.cpf, p.nome, p.infos);
    fclose(arquivo);
}

void carregarTabela() {
    FILE *arquivo = fopen("ArquivoEx01.txt", "r");
    if (arquivo == NULL) {
        printf("Arquivo de ArquivoEx01 vazio ou não encontrado.\n");
        return;
    }

    Pessoa p;
    while (fscanf(arquivo, "%d;%[^;];%[^;];%[^\n]\n", &p.chave, p.cpf, p.nome, p.infos) != EOF) {
        inserirTabela(p);
    }

    fclose(arquivo);
}

int main() {
    for (int i = 0; i < T; i++) {
        tabela[i] = criarLista();
    }

    carregarTabela();

    int opcao = -1;
    int chave;
    Pessoa *p;

    while (opcao != 0) {
        printf("\n---------------MENU---------------\n");
        printf("1: Cadastrar registro\n");
        printf("2: Buscar registro\n");
        printf("0: SAIR\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n------CADASTRANDO------\n");
                Pessoa novaPessoa;

                printf("Digite a chave: ");
                scanf("%d", &novaPessoa.chave);

                printf("Digite o CPF: ");
                scanf(" %s", novaPessoa.cpf);
                while (getchar() != '\n');

                printf("Digite o nome: ");
                fgets(novaPessoa.nome, sizeof(novaPessoa.nome), stdin);
                novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0';

                printf("Digite as informacoes: ");
                fgets(novaPessoa.infos, sizeof(novaPessoa.infos), stdin);
                novaPessoa.infos[strcspn(novaPessoa.infos, "\n")] = '\0';

                inserirTabela(novaPessoa);
                salvarRegistro(novaPessoa);
                break;

            case 2:
                printf("\n------BUSCANDO------\n");
                printf("\nDigite a chave: ");
                scanf("%d", &chave);
                p = buscarPessoaTabela(chave);
                if (p) {
                    printf("Pessoa encontrada:\n");
                    printf("Chave: %d\nCPF: %s\nNome: %s\nInfos: %s\n", p->chave, p->cpf, p->nome, p->infos);
                } else {
                    printf("Pessoa não encontrada!\n");
                }
                break;

            case 0:
                for (int i = 0; i < T; i++) {
                    free(tabela[i]->inicio);
                    free(tabela[i]);
                }
                printf("\nTchau! Até a próxima\n");
                break;

            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }
    return 0;
}

