#include <stdio.h>
#include <string.h>
int main() {
    int MAX = 1000
    char arquivo_nome[MAX];
    char palavra_antiga[MAX];
    char palavra_nova[MAX];
    char buffer[MAX];

    printf("Digite o nome do arquivo: ");
    scanf("%s", arquivo_nome);
    printf("Digite a palavra antiga: ");
    scanf("%s", palavra_antiga);
    printf("Digite a palavra nova: ");
    scanf("%s", palavra_nova);

    FILE* arquivo = fopen(arquivo_nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo_nome);
        return 1;
    }

    FILE* arquivo_temp = fopen("temp.txt", "w");
    if (arquivo_temp == NULL) {
        printf("Erro ao criar arquivo temporário\n");
        fclose(arquivo);
        return 1;
    }
    while (fgets(buffer, MAX, arquivo) != NULL) {
        char* pos = buffer;
        while ((pos = strstr(pos, palavra_antiga)) != NULL) {
            int offset = pos - buffer;
            strncpy(arquivo_temp, buffer, offset);
            fprintf(arquivo_temp, "%s", palavra_nova);
            pos += strlen(palavra_antiga);
            buffer[offset] = '\0';
            fprintf(arquivo_temp, "%s", pos);
        }
        fputs(buffer, arquivo_temp);
    }
    
    fclose(arquivo);
    fclose(arquivo_temp);
    remove(arquivo_nome);
    rename("temp.txt", arquivo_nome);
    printf("Substituição realizada com sucesso!\n");
    return 0;
}