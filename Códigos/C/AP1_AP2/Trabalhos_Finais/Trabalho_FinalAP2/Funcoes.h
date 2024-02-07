#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED



int validar_1ou2(char resposta){
    if((resposta == '1') || (resposta == '2')){
        return 0;
    }else{
        return 1;
    }
}

int cpfvalid(char *cpf){

    // Verifica se o CPF tem 11 digitos
    if (strlen(cpf) != 11){
        return 0;
    }

    // Verifica se todos os digitos sao iguais
    int i;
    for (i = 0; i < 10; i++){
        if (cpf[i] != cpf[i+1]){
            break;
        }
    }
    if (i == 10){
        return 0;
    }

    // Validacao do primeiro digito verificador
    int digito1 = 0, valid1;
    for (i = 0; i < 9; i++){
        valid1 = cpf[i] - '0';
        if (valid1 < 0 || valid1 > 9){
            return 0;
        }
        digito1 += valid1 * (10 - i);
    }
    digito1 = 11 - (digito1 % 11);
    if (digito1 >= 10){
        digito1 = 0;
    }
    if (cpf[9] - '0' != digito1){
        return 0;
    }

    // Validacao do segundo digito verificador
    int digito2 = 0, valid2;
    for (i = 0; i < 10; i++){
        valid2 = cpf[i] - '0';
        if (valid2 < 0 || valid2 > 9){
            return 0;
        }
        digito2 += valid2 * (11 - i);
    }
    digito2 = 11 - (digito2 % 11);
    if (digito2 >= 10){
        digito2 = 0;
    }
    if (cpf[10] - '0' != digito2){
        return 0;
    }

    // Se retorna 1 e valido
    return 1;
}

int cnpjvalid(char *cnpj) {
    // Verifica se o CNPJ tem 14 digitos
    if (strlen(cnpj) != 14) {
        return 0;
    }

    // Verifica se todos os digitos sao iguais
    int i;
    for (i = 0; i < 13; i++) {
        if (cnpj[i] != cnpj[i+1]) {
            break;
        }
    }
    if (i == 13) {
        return 0;
    }

    // Validacao do primeiro digito verificador
    int digito1 = 0, valid1;
    for (i = 0; i < 12; i++) {
        valid1 = cnpj[i] - '0';
        if (valid1 < 0 || valid1 > 9) {
            return 0;
        }
        digito1 += valid1 * ((i < 4) ? 5 - i : 13 - i);
    }
    digito1 = 11 - (digito1 % 11);
    if (digito1 >= 10) {
        digito1 = 0;
    }
    if (cnpj[12] - '0' != digito1) {
        return 0;
    }

    // Validacao do segundo digito verificador
    int digito2 = 0, valid2;
    for (i = 0; i < 13; i++) {
        valid2 = cnpj[i] - '0';
        if (valid2 < 0 || valid2 > 9) {
            return 0;
        }
        digito2 += valid2 * ((i < 5) ? 6 - i : 14 - i);
    }
    digito2 = 11 - (digito2 % 11);
    if (digito2 >= 10) {
        digito2 = 0;
    }
    if (cnpj[13] - '0' != digito2) {
        return 0;
    }

    // Se retorna 1 e valido
    return 1;
}

int validarData(int dia, int mes, int ano) {
    // Obter a data atual
    time_t agora = time(NULL);
    struct tm *data_atual = localtime(&agora);

    // Verificar se a data fornecida � maior que a data atual
    if (ano > data_atual->tm_year + 1900) {
        return 0; // Ano maior que o atual
    }
    else if (ano == data_atual->tm_year + 1900 && mes > data_atual->tm_mon + 1) {
        return 0; // Ano igual, m�s maior que o atual
    }
    else if (ano == data_atual->tm_year + 1900 && mes == data_atual->tm_mon + 1 && dia > data_atual->tm_mday) {
        return 0; // Ano e m�s iguais, dia maior que o atual
    }

    // Verificar se a pessoa tem pelo menos 18 anos
    if (data_atual->tm_year + 1900 - ano < 18) {
        return 0; // Pessoa tem menos de 18 anos
    }
    else if (data_atual->tm_year + 1900 - ano == 18) {
        if (data_atual->tm_mon + 1 < mes) {
            return 0; // Pessoa tem menos de 18 anos
        }
        else if (data_atual->tm_mon + 1 == mes && data_atual->tm_mday < dia) {
            return 0; // Pessoa tem menos de 18 anos
        }
    }

    // Verificar se o mes fornecido e maior que o atual
    if (mes > data_atual->tm_mon + 1) {
        return 0; // Mes fornecido maior que o atual
    }

    // Verificar se o dia fornecido e valido para o mes em questao
    int dias_mes;
    switch (mes) {
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) {
                dias_mes = 29;
            }
            else {
                dias_mes = 28;
            }
            break;
        case 4:
            dias_mes = 30;
            break;
        case 6:
            dias_mes = 30;
            break;
        case 9:
            dias_mes = 30;
            break;
        case 11:
            dias_mes = 30;
            break;
        default:
            dias_mes = 31;
    }

    if (dia > dias_mes) {
        return 0; // Dia fornecido invalido para o mes em questao
    }

    // A data e valida
    return 1;
}

int validar_senha(char *pass) {
    int i, numero = 0, caractere_especial = 0;

    // Verifica se a senha tem pelo menos 8 caracteres
    if (strlen(pass) < 8) {
        return 0;
    }

    // Verifica se a senha tem pelo menos um numero e um caractere especial
    for (i = 0; pass[i] != '\0'; i++) {
        if(pass[i]=='{'){
            return 0;
        }
        if (isdigit(pass[i])) {
            numero = 1; // Verifica se possui pelo menos um digito
        } else if (!isalnum(pass[i])) {
            caractere_especial = 1; // Verifica se possui um caractere especial
        }
    }

    if (!numero || !caractere_especial) {
        return 0;
    }

    return 1;
}

int verificar_login_cliente(char *login, char *senha) {

    FILE *arq_login = fopen("bancos de dados\\Dados_login_Usuario.txt", "r"); // abre o arquivo em modo de leitura

    if (arq_login != NULL) { // verifica se o arquivo foi aberto corretamente
        char linha[100];
        char *armazenamento;

        while (fgets(linha, sizeof(linha), arq_login)) { // le cada linha do arquivo de login
            armazenamento = strtok(linha, "{"); // extrai o login da linha usando o caractere '{'
            if (strcmp(armazenamento, login) == 0) { // verifica se o login corresponde ao login digitado
                armazenamento = strtok(NULL, "{"); // extrai a senha da linha usando o caractere '{'
                armazenamento[strcspn(armazenamento, "\n")] = 0; // remove o caractere de quebra de linha da senha
                if (strcmp(armazenamento, senha) == 0) { // verifica se a senha corresponde a senha digitada
                    fclose(arq_login); // fecha o arquivo
                    return 1; // retorna 1 se o login e a senha sao validos
                }
            }
        }

        fclose(arq_login); // fecha o arquivo
    } else {
        printf("Erro ao abrir o arquivo de login.\n");
    }

    return 0; // retorna 0 se o login e a senha nao sao validos
}

int verificar_login_lojas(char *login, char *senha) {

    FILE *arq_login = fopen("bancos de dados\\Dados_login_Lojas.txt", "r"); // abre o arquivo em modo de leitura

    if (arq_login != NULL) { // verifica se o arquivo foi aberto corretamente
        char linha[100];
        char *armazenamento;

        while (fgets(linha, sizeof(linha), arq_login)) { // le cada linha do arquivo de login
            armazenamento = strtok(linha, "{"); // extrai o login da linha usando o caractere '{'
            if (strcmp(armazenamento, login) == 0) { // verifica se o login corresponde ao login digitado
                armazenamento = strtok(NULL, "{"); // extrai a senha da linha usando o caractere '{'
                armazenamento[strcspn(armazenamento, "\n")] = 0; // remove o caractere de quebra de linha da senha
                if (strcmp(armazenamento, senha) == 0) { // verifica se a senha corresponde a senha digitada
                    fclose(arq_login); // fecha o arquivo
                    return 1; // retorna 1 se o login e a senha sao validos
                }
            }
        }

        fclose(arq_login); // fecha o arquivo
    } else {
        printf("Erro ao abrir o arquivo de login.\n");
    }

    return 0; // retorna 0 se o login e a senha nao sao validos
}

int atualizar_senha_cliente(char *login, char *senha) {
    FILE *arq_login = fopen("bancos de dados\\Dados_login_Usuario.txt", "r");

    if (arq_login != NULL) {
        char linha[100];
        char novo_arquivo[10000] = "";
        int encontrado = 0;

        while (fgets(linha, sizeof(linha), arq_login)) {
            if (strstr(linha, login) != NULL) {
                encontrado = 1;
                sprintf(linha, "%s{%s\n", login, senha);
            }
            strcat(novo_arquivo, linha);
        }

        fclose(arq_login);

        if (!encontrado) {
            return 0;
        }

        arq_login = fopen("bancos de dados\\Dados_login_Usuario.txt", "w");

        if (arq_login != NULL) {
            fprintf(arq_login, "%s", novo_arquivo);
            fclose(arq_login);
            return 1;
        } else {
            printf("Erro ao abrir o arquivo de login.\n");
            return 0;
        }
    } else {
        printf("Erro ao abrir o arquivo de login.\n");
        return 0;
    }
}

int atualizar_senha_lojas(char *login, char *senha) {
    FILE *arq_login = fopen("bancos de dados\\Dados_login_Lojas.txt", "r");

    if (arq_login != NULL) {
        char linha[100];
        char novo_arquivo[10000] = "";
        int encontrado = 0;

        while (fgets(linha, sizeof(linha), arq_login)) {
            if (strstr(linha, login) != NULL) {
                encontrado = 1;
                sprintf(linha, "%s{%s\n", login, senha);
            }
            strcat(novo_arquivo, linha);
        }

        fclose(arq_login);

        if (!encontrado) {
            return 0;
        }

        arq_login = fopen("bancos de dados\\Dados_login_Lojas.txt", "w");

        if (arq_login != NULL) {
            fprintf(arq_login, "%s", novo_arquivo);
            fclose(arq_login);
            return 1;
        } else {
            printf("Erro ao abrir o arquivo de login.\n");
            return 0;
        }
    } else {
        printf("Erro ao abrir o arquivo de login.\n");
        return 0;
    }
}

int verificacao(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + verificacao(n-1);
    }
}

#endif // FUNCOES_H_INCLUDED
