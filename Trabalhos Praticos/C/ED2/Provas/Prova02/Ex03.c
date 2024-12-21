#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define T 10000
#define tamanhoAlfabeto 256

char busca[T], texto[T];

void inserirArquivo(char *texto) {
    FILE *arquivo = fopen("ArquivoEx03.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    texto[strcspn(texto, "\n")] = '\0'; 
    fprintf(arquivo, "%s\n", texto);
    fclose(arquivo);
}

void buscarArquivo() {
    FILE *arquivo = fopen("ArquivoEx03.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fgets(texto, T, arquivo);
    texto[strcspn(texto, "\n")] = '\0';
    fclose(arquivo);
}

void forcaBruta(char *texto, char *busca) {
    int encontrado = 0;
    int tamanhobusca = strlen(busca), tamanhoTexto = strlen(texto), i, j;
    for (i = 0; i <= tamanhoTexto - tamanhobusca; i++) {
        for (j = 0; j < tamanhobusca; j++) {
            if (texto[i + j] != (busca[j])) {
                break;
            }
        }
        if (j == tamanhobusca) {
            encontrado++;
        }
    }
    printf("\nHouve %d ocorrencia(s) do padrao %s\n", encontrado, busca);
}

void KMP(char *texto, char *busca) {
    int contador = 0;
    int tamanhobusca = strlen(busca), tamanhoTexto = strlen(texto), i, j;

    int proximos[tamanhobusca + 1];

    for (i = 0; i < tamanhobusca + 1; i++) {
        proximos[i] = 0;
    }

    for (i = 1; i < tamanhobusca; i++) {
        j = proximos[i + 1];

        while (j > 0 && busca[j] != busca[i]) {
            j = proximos[j];
        }

        if (j > 0 || busca[j] == busca[i]) {
            proximos[i + 1] = j + 1;
        }
    }

    for (i = 0, j = 0; i < tamanhoTexto; i++) {
        if (*(texto + i) == *(busca + j)) {
            if (++j == tamanhobusca) {
                contador++;
            }
        } else if (j > 0) {
            j = proximos[j];
            i--;
        }
    }
    printf("\nHouve %d ocorrencia(s) do padrao %s\n", contador, busca);
}

void preProcessamento(char *palavra, int tamanhoPalavra, int alfabeto[]) {

    int i = 0;

    for (i = 0; i < tamanhoAlfabeto; ++i) {
        alfabeto[i] = tamanhoPalavra;
    }

    for (i = 0; i < tamanhoPalavra - 1; ++i) {
        alfabeto[palavra[i]] = tamanhoPalavra - i - 1;
    }

}

void BMH(char *texto, char *busca) {

    int tamanhobusca = strlen(busca), tamanhoTexto = strlen(texto), i = 0;
    int alfabeto[tamanhoAlfabeto];
    char caracterAuxiliar;
    int contador = 0;

    preProcessamento(busca, tamanhobusca, alfabeto);

    while (i <= tamanhoTexto - tamanhobusca) {
        caracterAuxiliar = texto[i + tamanhobusca - 1];

        if (busca[tamanhobusca - 1] == caracterAuxiliar) {

            if (memcmp(busca, texto + i, tamanhobusca - 1) == 0) 
            {
                contador++;
            }

        }

        i += alfabeto[caracterAuxiliar];
    }
    printf("\nHouve %d ocorrencia(s) do padrao %s\n", contador, busca);
}

int main(void) {

    int opcao = -1;
    int escolha;

    while (opcao != 0) {

        printf("\n---------------MENU---------------\n");
        printf("1: Inserir texto arquivo\n");
        printf("2: Buscar por padrao\n");
        printf("0: SAIR \n");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {

        case 1:
            printf("\n------INSERINDO------\n");

            printf("\n\nDigite a texto: ");
            fgets(texto, T, stdin);
            texto[strcspn(texto, "\n")] = '\0';
            inserirArquivo(texto);

            break;

        case 2:
            printf("\n------BUSCANDO------\n");

            buscarArquivo();

            printf("\n\nDigite a busca: ");
            fgets(busca, T, stdin);
            busca[strcspn(busca, "\n")] = '\0';

            printf("\n------Metodos------\n");
            printf("1: Seleciona Forca_Bruta\n");
            printf("2: Seleciona BMH \n");
            printf("3: Seleciona KMP \n");
            printf("\n\nDigite a escolha: ");
            scanf("%d", &escolha);
            getchar();

            switch (escolha) {
            case 1:
                forcaBruta(texto, busca);
                break;

            case 2:
                BMH(texto, busca);
                break;

            case 3:
                KMP(texto, busca);
                break;

            default:
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