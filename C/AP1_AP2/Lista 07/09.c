#include <stdio.h>
#include <string.h>
int main() {
    int MAX=1000;
    
    char arquivo_nome[MAX], palavra_chave[MAX], linha[MAX];
    FILE *arquivo;

    printf("Digite o nome do arquivo: ");
    scanf("%s", arquivo_nome);
    printf("Digite a palavra-chave: ");
    scanf("%s", palavra_chave);
    arquivo = fopen(arquivo_nome, "r");

    if (arquivo == NULL) {
        printf("Erro");
    return 1;
    }
    while (fgets(linha, MAX, arquivo) != NULL) {
        if (strstr(linha, palavra_chave) != NULL) {
            printf("%s", linha);
        }
    }
    fclose(arquivo);
    return 0;
}