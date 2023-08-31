#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "Funcoes.h"

    FILE *arq_login;
    FILE *arq_empresas;
    FILE *arq_produtos;

    char resposta_1ou2, tipo_usuario_ou_empresa, cpf[12], cnpj[16], login[40], senha[40], *separador;
    char nome_protuto[40], descricao_produto[200], empresa_pesquisa[30], produto_pesquisa[30], linha[1000];
    int dia, mes, ano, idade_empresa, flag_login, i, j, valorcmp, len;

    char nome_produto[30];
    float valor_produto, preco_total = 0;;

    int botao_compra, botao_remove, compra_finalizada = 0, escolha, id, m, remover, valid;

    struct lista_produtos{
        char produto[3][30], empresa[3][30];
    }lista[100];

     struct carrinho_compra{
        char compras[3][30];
    }carrinho[100];



int main(void){

    printf("\n /$$$$$$$  /$$                       /$$                         /$$");
    printf("\n| $$__  $$| $$                      | $$                        | $$");
    printf("\n| $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
    printf("\n| $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
    printf("\n| $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
    printf("\n| $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
    printf("\n| $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
    printf("\n|__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");

    printf(" \n+---------------------------------------------------------------------------+");
    printf(" \n|                                                                           |");
    printf(" \n|                                                                           |");
    printf(" \n|                          BEM VINDO A PLANTECH                             |");
    printf(" \n|                                                                           |");
    printf(" \n|                                                                           |");
    printf(" \n+---------------------------------------------------------------------------+");

    printf("\n");

    printf(" \n+---------------------------------------------------------------------------+");
    printf(" \n|        LOGIN-1             |     OU      |            CADASTRO-2          |");
    printf(" \n+---------------------------------------------------------------------------+");

    printf("\n");

    printf(" \n+--------------------------------------------------------------------------+");
    printf("\n                         -->  ");
    fflush(stdin);
    resposta_1ou2 = getch();
    printf("%c\n",resposta_1ou2);
    printf(" \n+-------------------------------------------------------------------------+");

    if(validar_1ou2(resposta_1ou2)){ // Validação de 1 ou 2
        do{
            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n          Entrada invalida, digite novamente 1 ou 2!\n");
            printf(" \n                  -->  ");
            fflush(stdin);
            resposta_1ou2=getch();
            printf("%c\n",resposta_1ou2);
            printf(" \n+-----------------------------------------------------------------------------+\n");
        }while(validar_1ou2(resposta_1ou2) == 1 );
    }
    system("cls");
    printf("\n+-----------------------------------------------------------------------------+");
    printf("\n|                                                                             |");
    printf("\n|      Antes de prosseguir, digite o numero que ira aparecer na tela          |");
    printf("\n|           para termos certeza que voce nao e um robo.                       |");
    printf("\n|                                                                             |");
    printf("\n+-----------------------------------------------------------------------------+\n\n");
    system("pause");
    valid=0;
    do{
        srand(time(NULL)); // semente para geração de números aleatórios
        i = rand() % 9 + 1; // gera um numero aleatório de 1 a 9
        j = verificacao(i); // gera o numero para verificacao
        system("cls");
        printf(" \n+-----------------------------------------------------------------------------+");
        printf(" \n|                                                                             |");
        printf(" \n|                               Digite o numero: %d                            ", j);
        printf(" \n|                                                                             |");
        printf(" \n+-----------------------------------------------------------------------------+");
        printf(" \n+-----------------------------------------------------------------------------+");
        printf(" \n         -->  ");
        fflush(stdin);
        scanf("%d", &escolha);

        if (escolha == j) {
            valid = 1;
            system("cls");
            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n|                                                                             |");
            printf(" \n|                           Verificacao concluida!!                           |");
            printf(" \n|                                                                             |");
            printf(" \n+-----------------------------------------------------------------------------+");
            sleep(2);
            i=0;
            j=0;
        } else {
            system("cls");
            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n|                                                                             |");
            printf(" \n|                    Numero incorreto, tente novamente.                       |");
            printf(" \n|                                                                             |");
            printf(" \n+-----------------------------------------------------------------------------+");
            sleep(2);
        }
    }while (valid!=1);
    valid=0;
    switch (resposta_1ou2){ // SWITCH lOGIN / CADASTRO

        case '1': // Codigo de Login
            system("cls");
            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n|                                                                             |");
            printf(" \n|                        Qual o seu tipo de conta ?                           |");
            printf(" \n|                                                                             |");
            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n|                   Comprador-1  |  OU   |   Vendedor-2                       |");
            printf(" \n+-----------------------------------------------------------------------------+");


            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n         -->  ");
            fflush(stdin);
            tipo_usuario_ou_empresa=getch();
            printf("%c\n",tipo_usuario_ou_empresa);
            printf(" \n+-----------------------------------------------------------------------------+");
            if(validar_1ou2(tipo_usuario_ou_empresa)){ // Validadao de 1 ou 2
                do{
                    printf(" \n+-----------------------------------------------------------------------------+");
                    printf(" \n          Entrada invalida, digite novamente 1 ou 2!\n");
                    printf(" \n                  -->  ");
                    fflush(stdin);
                    tipo_usuario_ou_empresa=getch();
                    printf("%c\n",tipo_usuario_ou_empresa);
                    printf(" \n+-----------------------------------------------------------------------------+");
                }while(validar_1ou2(tipo_usuario_ou_empresa) == 1 );
            }
            switch (tipo_usuario_ou_empresa){
        case '1': // Login do tipo cliente
            flag_login=0;

            do{

                system("cls"); // Obtendo Login do Usuario
                printf("\n+------------------------------------------+");
                printf("\n|                                          |");
                printf("\n|             Digite seu login             |");
                printf("\n|                                          |");
                printf("\n+------------------------------------------+");
                printf("\n|//////////////////////////////////////////|");
                printf("\n+------------------------------------------+");
                printf("\n\n+------------------------------------------+");
                printf("\nlogin: -->  ");
                fflush(stdin);
                gets(login);
                printf("+------------------------------------------+");

                system("cls"); // Obtendo Senha do Usuario
                printf("\n+------------------------------------------+");
                printf("\n|                                          |");
                printf("\n|             Digite sua senha             |");
                printf("\n|                                          |");
                printf("\n+------------------------------------------+");
                printf("\n|//////////////////////////////////////////|");
                printf("\n+------------------------------------------+");
                printf("\n\n+------------------------------------------+");
                printf("\nSenha: -->  ");
                fflush(stdin);
                gets(senha);
                printf("+------------------------------------------+");

                if(validar_senha(senha) != 1 ){ // Valida��o Senha
                    do{
                        system("cls");
                        printf("\n+------------------------------------------+");
                        printf("\n|                                          |");
                        printf("\n|              Senha invalida              |");
                        printf("\n|                                          |");
                        printf("\n+------------------------------------------+");
                        printf("\n|//////////////////////////////////////////|");
                        printf("\n+------------------------------------------+");
                        printf("\n\n+------------------------------------------+");
                        printf("\nSenha: -->  ");
                        fflush(stdin);
                        gets(senha);
                        printf("+------------------------------------------+");
                    }while (validar_senha(senha) != 1);
                }

                if(verificar_login_cliente(login, senha)==1){
                    flag_login=1;
                    system("cls");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|                                         |");
                    printf(" \n|        Login efetuado com sucesso!      |");
                    printf(" \n|                                         |");
                    printf(" \n|-----------------------------------------|");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+\n\n\n");
                    system("pause");

                        //Ver o que colocar aqui
                        //A partir daqui passou com sucesso
                }else{
                    system("cls");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|                                         |");
                    printf(" \n|          Login/Senha Incorretos         |");
                    printf(" \n|                                         |");
                    printf(" \n|-----------------------------------------|");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+\n\n\n");
                    sleep(3);
                    continue;
                }

            }while(flag_login==0);

            break;
        case '2': // Login do tipo Loja
                       flag_login=0;

            do{

                system("cls"); // Obtendo Login do Usuario
                printf("\n+------------------------------------------+");
                printf("\n|                                          |");
                printf("\n|             Digite seu login             |");
                printf("\n|                                          |");
                printf("\n+------------------------------------------+");
                printf("\n|//////////////////////////////////////////|");
                printf("\n+------------------------------------------+");
                printf("\n\n+------------------------------------------+");
                printf("\nlogin: -->  ");
                fflush(stdin);
                gets(login);
                printf("+------------------------------------------+");

                system("cls"); // Obtendo Senha do Usuario
                printf("\n+------------------------------------------+");
                printf("\n|                                          |");
                printf("\n|             Digite sua senha             |");
                printf("\n|                                          |");
                printf("\n+------------------------------------------+");
                printf("\n|//////////////////////////////////////////|");
                printf("\n+------------------------------------------+");
                printf("\n\n+------------------------------------------+");
                printf("\nSenha: -->  ");
                fflush(stdin);
                gets(senha);
                printf("+------------------------------------------+");

                if(validar_senha(senha) != 1 ){ // Valida��o Senha
                        do{
                            system("cls");
                            printf("\n+------------------------------------------+");
                            printf("\n|                                          |");
                            printf("\n|              Senha invalida              |");
                            printf("\n|                                          |");
                            printf("\n+------------------------------------------+");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n+------------------------------------------+");
                            printf("\n\n+------------------------------------------+");
                            printf("\nSenha: -->  ");
                            fflush(stdin);
                            gets(senha);
                            printf("+------------------------------------------+");
                        }while (validar_senha(senha) != 1);
                    }

                if(verificar_login_lojas(login, senha)==1){
                        flag_login=1;
                        system("cls");
                        printf(" \n+-----------------------------------------+");
                        printf(" \n|/////////////////////////////////////////|");
                        printf(" \n+-----------------------------------------+");
                        printf(" \n|                                         |");
                        printf(" \n|        Login efetuado com sucesso!      |");
                        printf(" \n|                                         |");
                        printf(" \n|-----------------------------------------|");
                        printf(" \n|/////////////////////////////////////////|");
                        printf(" \n+-----------------------------------------+\n\n\n");
                        system("pause");

                        //Ver o que colocar aqui
                        //A partir daqui passou com sucesso
                }else{
                    system("cls");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|                                         |");
                    printf(" \n|          Login/Senha Incorretos         |");
                    printf(" \n|                                         |");
                    printf(" \n|-----------------------------------------|");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+\n\n\n");
                    sleep(3);
                    continue;
                }

            }while(flag_login==0);

                break;
            }

            break;

        case '2': //Codigo de Cadastro
            system("cls");
            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n|                                                                             |");
            printf(" \n|                        Qual o seu tipo de conta ?                           |");
            printf(" \n|                                                                             |");
            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n|                   Comprador-1  |  OU   |   Vendedor-2                       |");
            printf(" \n+-----------------------------------------------------------------------------+");


            printf(" \n+-----------------------------------------------------------------------------+");
            printf(" \n         -->  ");
            fflush(stdin);
            tipo_usuario_ou_empresa=getch();
            printf("%c\n",tipo_usuario_ou_empresa);
            printf(" \n+-----------------------------------------------------------------------------+");

            if(validar_1ou2(tipo_usuario_ou_empresa)){ // Validação de 1 ou 2
                do{
                    printf(" \n+-----------------------------------------------------------------------------+");
                    printf(" \n          Entrada invalida, digite novamente 1 ou 2!\n");
                    printf(" \n                  -->  ");
                    fflush(stdin);
                    tipo_usuario_ou_empresa = getch();
                    printf("%c\n",tipo_usuario_ou_empresa);
                    printf(" \n+-----------------------------------------------------------------------------+");
                }while(validar_1ou2(tipo_usuario_ou_empresa) == 1 );
            }

            switch (tipo_usuario_ou_empresa){ // SWITCH COMPRADOR / VENDEDOR

                case '1': // Codigo cadastro comprador
                    system("cls"); // Validação Cpf
                    printf(" \n+------------------------------------------+");
                    printf(" \n|//////////////////////////////////////////|");
                    printf(" \n+------------------------------------------+");
                    printf(" \n|                                          |");
                    printf(" \n|             Digite seu cpf ?             |");
                    printf(" \n|                                          |");
                    printf(" \n+------------------------------------------+");
                    printf(" \n|//////////////////////////////////////////|");
                    printf(" \n|     Digite apenas os numeros, sem . e -  |");
                    printf(" \n|//////////////////////////////////////////|");
                    printf(" \n+------------------------------------------+");
                    printf("\n\n+------------------------------------------+");
                    printf("\n  -->  ");
                    fflush(stdin);
                    scanf("%12s", cpf);
                    printf("+------------------------------------------+");

                    if (cpfvalid(cpf) != 1 ){
                        do{
                            system("cls"); // Validação Cpf invalido
                            printf("\n\n+------------------------------------------+");
                            printf("\n|                                          |");
                            printf("\n|              CPF invalido                |");
                            printf("\n|                                          |");
                            printf("\n+------------------------------------------+");
                            printf("\n|          Digite novemente seu cpf        |");
                            printf("\n+------------------------------------------+");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n|     Digite apenas os numeros, sem . e -  |");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n+------------------------------------------+");
                            printf("\n\n+------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            scanf("%12s", cpf);
                            printf("+------------------------------------------+");
                        }while(cpfvalid(cpf) != 1);
                    }

                    system("cls"); // Data de nascimento
                    printf("\n+------------------------------------------+");
                    printf("\n|                                          |");
                    printf("\n|      Digite a sua data de nascimento     |");
                    printf("\n|                                          |");
                    printf("\n+------------------------------------------+");
                    printf("\n|         Dia: DD Mes: MM Ano: AAAA        |");
                    printf("\n+------------------------------------------+");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n|     Permitido apenas maiores de idade    |");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n+------------------------------------------+");


                    printf("\n\n+------------------------------------------+");
                    printf("\n      Dia: -->  ");
                    fflush(stdin);
                    scanf("%d",&dia);
                    printf("\n      Mes: -->  ");
                    fflush(stdin);
                    scanf("%d",&mes);
                    printf("\n      Ano: -->  ");
                    fflush(stdin);
                    scanf("%d",&ano);
                    printf("+------------------------------------------+");

                    if(validarData(dia, mes, ano) != 1){   // Validação Data de nascimento invalida
                        do{
                            system("cls");
                            printf("\n+------------------------------------------+");
                            printf("\n|              Data Invalido               |");
                            printf("\n|                                          |");
                            printf("\n|           Digite novamente a data        |");
                            printf("\n|                                          |");
                            printf("\n|          Dia: DD Mes: MM Ano: AAAA       |");
                            printf("\n|                                          |");
                            printf("\n+------------------------------------------+");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n|     Permitido apenas maiores de idade    |");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n+------------------------------------------+");
                            printf("\n\n+------------------------------------------+");
                            printf("\n      Dia: -->  ");
                            fflush(stdin);
                            scanf("%d",&dia);
                            printf("\n      Mes: -->  ");
                            fflush(stdin);
                            scanf("%d",&mes);
                            printf("\n      Ano: -->  ");
                            fflush(stdin);
                            scanf("%d",&ano);
                            printf("+------------------------------------------+");
                        }while(validarData(dia, mes, ano) != 1);

                    }

                    system("cls"); // Obtendo Login do Usuario
                    printf("\n+------------------------------------------+");
                    printf("\n|                                          |");
                    printf("\n|             Digite seu login             |");
                    printf("\n|                                          |");
                    printf("\n+------------------------------------------+");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n+------------------------------------------+");
                    printf("\n\n+------------------------------------------+");
                    printf("\nlogin: -->  ");
                    fflush(stdin);
                    gets(login);
                    printf("+------------------------------------------+");



                    system("cls"); // Obtendo Senha do Usuario
                    printf("\n+------------------------------------------+");
                    printf("\n|                                          |");
                    printf("\n|             Digite uma senha             |");
                    printf("\n|                                          |");
                    printf("\n+------------------------------------------+");
                    printf("\n|     No minimo 8 digitos e no maximo 40   |");
                    printf("\n+------------------------------------------+");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n| No minimo 1 caracter especial e 1 digito |");
                    printf("\n|          Nao e permitido: '{'            |");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n+------------------------------------------+");
                    printf("\n\n+------------------------------------------+");
                    printf("\nSenha: -->  ");
                    fflush(stdin);
                    gets(senha);
                    printf("+------------------------------------------+");

                    if(validar_senha(senha) != 1 ){ // Validação Senha
                        do{
                            system("cls");
                            printf("\n+------------------------------------------+");
                            printf("\n|                                          |");
                            printf("\n|              Senha invalida              |");
                            printf("\n|                                          |");
                            printf("\n+------------------------------------------+");
                            printf("\n|     No minimo 8 digitos e no maximo 40   |");
                            printf("\n+------------------------------------------+");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n| No minimo 1 caracter especial e 1 digito |");
                            printf("\n|          Nao e permitido: '{'            |");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n+------------------------------------------+");
                            printf("\n\n+------------------------------------------+");
                            printf("\nSenha: -->  ");
                            fflush(stdin);
                            gets(senha);
                            printf("+------------------------------------------+");
                        }while (validar_senha(senha) != 1);
                    }

                    arq_login = fopen("bancos de dados\\Dados_login_Usuario.txt","a+");
                    fprintf(arq_login, "%s{%s\n",login,senha);
                    fclose(arq_login);

                    system("cls");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|                                         |");
                    printf(" \n|   Obrigado por se cadastrar na Plantech |");
                    printf(" \n|                                         |");
                    printf(" \n|-----------------------------------------|");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+\n\n\n");



                    printf("\n /$$$$$$$  /$$                       /$$                         /$$");
                    printf("\n| $$__  $$| $$                      | $$                        | $$");
                    printf("\n| $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
                    printf("\n| $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
                    printf("\n| $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
                    printf("\n| $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
                    printf("\n| $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
                    printf("\n|__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/\n\n");

                    system("pause");
                    break;

                case '2':   //Codigo cadastro vendedor
                    system("cls"); // Validação Cnpj
                    printf(" \n+------------------------------------------+");
                    printf(" \n|//////////////////////////////////////////|");
                    printf(" \n+------------------------------------------+");
                    printf(" \n|                                          |");
                    printf(" \n|             Digite seu cnpj ?            |");
                    printf(" \n|                                          |");
                    printf(" \n+------------------------------------------+");
                    printf(" \n|//////////////////////////////////////////|");
                    printf(" \n|     Digite apenas os numeros, sem . e -  |");
                    printf(" \n|//////////////////////////////////////////|");
                    printf(" \n+------------------------------------------+");
                    printf("\n\n+------------------------------------------+");
                    printf("\n  -->  ");
                    fflush(stdin);
                    scanf("%16s", cnpj);
                    printf("+------------------------------------------+");

                    if (cnpjvalid(cnpj) != 1 ){
                        do{
                            system("cls"); // Validação Cnpj invalido
                            printf("\n\n+------------------------------------------+");
                            printf("\n|                                          |");
                            printf("\n|              Cnpj invalido               |");
                            printf("\n|                                          |");
                            printf("\n+------------------------------------------+");
                            printf("\n|          Digite novemente seu cnpj       |");
                            printf("\n+------------------------------------------+");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n|     Digite apenas os numeros, sem . e -  |");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n+------------------------------------------+");
                            printf("\n\n+------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            scanf("%16s", cnpj);
                            printf("+------------------------------------------+");
                        }while(cnpjvalid(cnpj) != 1);
                    }

                    system("cls"); // Idade da empresa
                    printf("\n+------------------------------------------+");
                    printf("\n|                                          |");
                    printf("\n|   Digite quantos anos possui a empresa   |");
                    printf("\n|                                          |");
                    printf("\n+------------------------------------------+");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n+------------------------------------------+");


                    printf("\n\n+------------------------------------------+");
                    printf("\n       -->  ");
                    fflush(stdin);
                    scanf("%d",&idade_empresa);
                    printf("+------------------------------------------+");

                    if( idade_empresa < 0 ){   // Validação Idade da empresa invalida
                        do{
                            system("cls");
                            printf("\n+------------------------------------------+");
                            printf("\n|             Idade Invalida               |");
                            printf("\n+------------------------------------------+");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n+------------------------------------------+");
                            printf("\n\n+------------------------------------------+");
                            printf("\n       -->  ");
                            fflush(stdin);
                            scanf("%d",&idade_empresa);
                            printf("+------------------------------------------+");
                        }while(idade_empresa < 0 );

                    }

                    system("cls"); // Obtendo Login do Usuario
                    printf("\n+------------------------------------------+");
                    printf("\n|                                          |");
                    printf("\n|             Digite seu login             |");
                    printf("\n|                                          |");
                    printf("\n+------------------------------------------+");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n+------------------------------------------+");
                    printf("\n\n+------------------------------------------+");
                    printf("\nlogin: -->  ");
                    fflush(stdin);
                    gets(login);
                    printf("+------------------------------------------+");



                    system("cls"); // Obtendo Senha do Usuario
                    printf("\n+------------------------------------------+");
                    printf("\n|                                          |");
                    printf("\n|             Digite uma senha             |");
                    printf("\n|                                          |");
                    printf("\n+------------------------------------------+");
                    printf("\n|     No minimo 8 digitos e no maximo 40   |");
                    printf("\n+------------------------------------------+");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n| No minimo 1 caracter especial e 1 digito |");
                    printf("\n|//////////////////////////////////////////|");
                    printf("\n+------------------------------------------+");
                    printf("\n\n+------------------------------------------+");
                    printf("\nSenha: -->  ");
                    fflush(stdin);
                    gets(senha);
                    printf("+------------------------------------------+");

                    if(validar_senha(senha) != 1 ){ // Validação Senha
                        do{
                            system("cls");
                            printf("\n+------------------------------------------+");
                            printf("\n|                                          |");
                            printf("\n|              Senha invalida              |");
                            printf("\n|                                          |");
                            printf("\n+------------------------------------------+");
                            printf("\n|     No minimo 8 digitos e no maximo 40   |");
                            printf("\n+------------------------------------------+");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n| No minimo 1 caracter especial e 1 digito |");
                            printf("\n|          Nao e permitido: '{'            |");
                            printf("\n|//////////////////////////////////////////|");
                            printf("\n+------------------------------------------+");
                            printf("\n\n+------------------------------------------+");
                            printf("\nSenha: -->  ");
                            fflush(stdin);
                            gets(senha);
                            printf("+------------------------------------------+");
                        }while (validar_senha(senha) != 1);
                    }


                    arq_login = fopen("bancos de dados\\Dados_login_Lojas.txt","a+");
                    fprintf(arq_login, "%s{%s\n",login,senha);
                    fclose(arq_login);

                    system("cls");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+");
                    printf(" \n|                                         |");
                    printf(" \n|   Obrigado por se cadastrar na Plantech |");
                    printf(" \n|                                         |");
                    printf(" \n|-----------------------------------------|");
                    printf(" \n|/////////////////////////////////////////|");
                    printf(" \n+-----------------------------------------+\n\n\n");



                    printf("\n /$$$$$$$  /$$                       /$$                         /$$");
                    printf("\n| $$__  $$| $$                      | $$                        | $$");
                    printf("\n| $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
                    printf("\n| $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
                    printf("\n| $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
                    printf("\n| $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
                    printf("\n| $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
                    printf("\n|__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/\n\n");

                    system("pause");


                    break;

                default:
                    break;
                }

            break;
        default:
            break;
    }

    int Flag_loop = 0; // Variaveis para controlar o laço das paginas principais
    int flag_pesquisa = 0;
    int Flag_configuracao = 0;
    int Flag_cadastro = 0, Flag_cadastro02  =0;
    int frag_compra =0 ;

    switch (tipo_usuario_ou_empresa) // Pagina do usuario/Loja
    {
        case '1': // Pagina do usuario
            do{
                Flag_loop = 0;
                system("cls");
                printf("\n /$$$$$$$  /$$                       /$$                         /$$");
                printf("\n| $$__  $$| $$                      | $$                        | $$");
                printf("\n| $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
                printf("\n| $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
                printf("\n| $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
                printf("\n| $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
                printf("\n| $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
                printf("\n|__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");

                printf(" \n+---------------------------------------------------------------------------+");
                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                printf(" \n|                            Usuario :  %s                                  ",login);
                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                printf(" \n+---------------------------------------------------------------------------+");

                printf(" \n\n+---------------------------------------------------------------------------+");
                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                printf(" \n|                           1-Configuracoes                                 |");
                printf(" \n|                           2-Pesquisa de produtos                          |");
                printf(" \n|                           3-Pesquisa de empresas                          |");
                printf(" \n|                           4-Fechar programa                               |");
                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                printf(" \n+---------------------------------------------------------------------------+");

                char respost;

                printf("\n\n+---------------------------------------------------------------------------+");
                printf("\n  -->  ");
                fflush(stdin);
                respost=getch();
                printf("%c\n",respost);
                printf("+---------------------------------------------------------------------------+");


                if((respost!='1')&&(respost!='2')&&(respost!='3')&&(respost!='4')){ // tratamento de erro
                    do{
                        printf("\n\n\n\n+---------------------------------------------------------------------------+");
                        printf("\nEntrada invalida, digite novamente 1 ou 2 ou 3 ou 4!\n");
                        printf("\n  -->  ");
                        fflush(stdin);
                        respost=getch();
                        printf("%c\n",respost);
                        printf("+---------------------------------------------------------------------------+");
                    }while((respost!='1')&&(respost!='2')&&(respost!='3')&&(respost!='4'));
                }

                switch (respost) // Switch da pagina do usuario
                {
                    case '1': // Case Configurações
                        do{
                            Flag_configuracao = 0;
                            system("cls");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                             Configuracao                                  |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf(" \n\n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                           1-Alterar senha                                 |");
                            printf(" \n|                           2-Fechar configuracao                           |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            respost=getch();
                            printf("%c\n",respost);
                            printf("+---------------------------------------------------------------------------+");


                            if((respost!='1')&&(respost!='2')){ // tratamento de erro
                                do{
                                    printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                    printf("\nEntrada invalida, digite novamente 1 ou 2 !\n");
                                    printf("\n  -->  ");
                                    fflush(stdin);
                                    respost=getch();
                                    printf("%c\n",respost);
                                    printf("+---------------------------------------------------------------------------+");
                                }while((respost!='1')&&(respost!='2'));
                            }

                            switch (respost)
                            {
                                case '1': // Alterar Senha

                                    system("cls"); // Obtendo Senha do Usuario
                                    printf("\n+------------------------------------------+");
                                    printf("\n|                                          |");
                                    printf("\n|         Digite sua senha  atual          |");
                                    printf("\n|                                          |");
                                    printf("\n+------------------------------------------+");
                                    printf("\n|//////////////////////////////////////////|");
                                    printf("\n+------------------------------------------+");
                                    printf("\n\n+------------------------------------------+");
                                    printf("\nSenha: -->  ");
                                    fflush(stdin);
                                    gets(senha);
                                    printf("+------------------------------------------+");

                                    if(verificar_login_cliente(login, senha)==1){

                                    system("cls"); // Obtendo Senha do Usuario
                                    printf("\n+------------------------------------------+");
                                    printf("\n|                                          |");
                                    printf("\n|         Digite a nova senha              |");
                                    printf("\n|                                          |");
                                    printf("\n+------------------------------------------+");
                                    printf("\n|//////////////////////////////////////////|");
                                    printf("\n+------------------------------------------+");
                                    printf("\n\n+------------------------------------------+");
                                    printf("\nSenha: -->  ");
                                    fflush(stdin);
                                    gets(senha);
                                    printf("+------------------------------------------+");

                                    if(validar_senha(senha) != 1 ){ // Validação Senha
                                        do{
                                            printf("\n+------------------------------------------+");
                                            printf("\n|                                          |");
                                            printf("\n|              Senha invalida              |");
                                            printf("\n|                                          |");
                                            printf("\n+------------------------------------------+");
                                            printf("\n|     No minimo 8 digitos e no maximo 40   |");
                                            printf("\n+------------------------------------------+");
                                            printf("\n|//////////////////////////////////////////|");
                                            printf("\n| No minimo 1 caracter especial e 1 digito |");
                                            printf("\n|//////////////////////////////////////////|");
                                            printf("\n+------------------------------------------+");
                                            printf("\n\n+------------------------------------------+");
                                            printf("\nSenha: -->  ");
                                            fflush(stdin);
                                            gets(senha);
                                            printf("+------------------------------------------+");
                                        }while (validar_senha(senha) != 1);
                                    }

                                    if(atualizar_senha_cliente(login,senha)==1){
                                        system("cls");
                                        printf(" \n+-----------------------------------------+");
                                        printf(" \n|/////////////////////////////////////////|");
                                        printf(" \n+-----------------------------------------+");
                                        printf(" \n|                                         |");
                                        printf(" \n|        Senha atualizada com sucesso     |");
                                        printf(" \n|                                         |");
                                        printf(" \n|-----------------------------------------|");
                                        printf(" \n|/////////////////////////////////////////|");
                                        printf(" \n+-----------------------------------------+\n\n\n");
                                        sleep(3);
                                    }

                                    }else{
                                        system("cls");
                                        printf(" \n+-----------------------------------------+");
                                        printf(" \n|/////////////////////////////////////////|");
                                        printf(" \n+-----------------------------------------+");
                                        printf(" \n|                                         |");
                                        printf(" \n|            Senha Incorreta              |");
                                        printf(" \n|                                         |");
                                        printf(" \n|-----------------------------------------|");
                                        printf(" \n|/////////////////////////////////////////|");
                                        printf(" \n+-----------------------------------------+\n\n\n");
                                        sleep(3);
                                    }

                                    break;

                                case '2': // Sair configuraçao
                                    Flag_configuracao = 1;
                                    break;

                                default:
                                    break;
                            }
                        }while(Flag_configuracao != 1 );
                        break;

                    case '2': // Case Pesquisa de Produtos
                        flag_pesquisa = 0;
                        do{
                            arq_produtos = fopen("bancos de dados\\Dados_Produtos.txt", "r");
                            system("cls");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                             Pesquisa Produtos                             |");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                         Digite o nome do produto :                        |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fgets(produto_pesquisa, sizeof(produto_pesquisa), stdin);
                            printf("+---------------------------------------------------------------------------+\n");

                            produto_pesquisa[strcspn(produto_pesquisa, "\n")] = '\0';

                            len = strlen(produto_pesquisa);
                            if (produto_pesquisa[len - 1] == '\n') {
                                produto_pesquisa[len - 1] = '\0';
                            }

                            if(arq_produtos == NULL){
                                printf("Erro ao abrir o arquivo!");
                            }else{
                                j = 0;
                                while(fgets(linha, sizeof(linha), arq_produtos) != NULL){
                                    separador = strtok(linha, "{");
                                    i = 0;
                                    while(separador != NULL){
                                        strcpy(lista[j].produto[i], separador);
                                        separador = strtok(NULL, "{");
                                        i++;
                                    }
                                    if(i == 3 && strncasecmp(lista[j].produto[0], produto_pesquisa, len) == 0){
                                        printf("ID: %d - Produto: %s - Preco: R$%s - Empresa: %s", j, lista[j].produto[0], lista[j].produto[1], lista[j].produto[2]);
                                    }
                                    j++;
                                }
                            }
                            fclose(arq_produtos);

                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                  1- Adicinar 1 desses ao carrinho de compras              |");
                            printf(" \n|                  2- Pesquisar novamente                                   |");
                            printf(" \n|                  3- Fechar pesquisa                                       |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            respost=getch();
                            printf("%c\n",respost);
                            printf("+---------------------------------------------------------------------------+");

                            if((respost!='1')&&(respost!='2')&&(respost!='3')){ // tratamento de erro
                                do{
                                    printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                    printf("\nEntrada invalida, digite novamente 1 ou 2 ou 3 !\n");
                                    printf("\n  -->  ");
                                    fflush(stdin);
                                    respost=getch();
                                    printf("%c\n",respost);
                                    printf("+---------------------------------------------------------------------------+");
                                }while((respost!='1')&&(respost!='2')&&(respost!='3'));
                            }

                            switch (respost){
                                    case '1': // Carrinho de compras

                                        frag_compra = 0;
                                        m = -1;
                                        do{
                                            arq_produtos = fopen("bancos de dados\\Dados_Produtos.txt", "r");
                                            system("cls");
                                            printf(" \n+---------------------------------------------------------------------------+");
                                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                            printf(" \n|                   Digite os ID que deseja adicionar                       |");
                                            printf(" \n|                      Caso queira sair digite  -1                          |");
                                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                            printf(" \n+---------------------------------------------------------------------------+\n");

                                             j = 0; //para mostrar produto novamente
                                            while(fgets(linha, sizeof(linha), arq_produtos) != NULL){
                                                separador = strtok(linha, "{");
                                                i = 0;
                                                while(separador != NULL){
                                                    strcpy(lista[j].produto[i], separador);
                                                    separador = strtok(NULL, "{");
                                                    i++;
                                                }
                                                if(i == 3 && strncasecmp(lista[j].produto[0], produto_pesquisa, len) == 0){
                                                    printf("ID: %d - Produto: %s - Preco: R$%s - Empresa: %s", j, lista[j].produto[0], lista[j].produto[1], lista[j].produto[2]);
                                                }
                                                j++;
                                            }

                                            printf("\n\n+---------------------------------------------------------------------------+");
                                            printf("\n  -->  ");
                                            fflush(stdin);
                                            scanf("%d", &id);
                                            printf("+---------------------------------------------------------------------------+\n\n");

                                            if(id == -1){
                                                frag_compra = 1;
                                                continue;
                                            }

                                            for(valid = 0; valid <= j; valid++){
                                                if(id == valid){
                                                    m++;//Faz a incrementação da struct de produtos no carrinho de compras
                                                    for (i=0; i<3; i++){//Laço responsável por incluir o produto pesquisado no carrinho de compras
                                                        if(id >= 0){
                                                            strcpy(carrinho[m].compras[i], lista[id].produto[i]);
                                                        }
                                                        if(i == 1 && id >= 0) {//Condição que converte string para float, possibilitando a soma do valor total dos produtos no carrinho de compras
                                                            preco_total += atof(lista[id].produto[i]);
                                                        }
                                                    }
                                                }
                                            }
                                        fclose(arq_produtos);
                                        }while(frag_compra != 1);
                                        frag_compra = 0;
                                        do{
                                            system("cls");
                                            printf(" \n+---------------------------------------------------------------------------+");
                                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                            printf(" \n|         Esses sao os produtos adicionados ao seu carrinho                 |");
                                            printf(" \n|                                                                           |");
                                            printf(" \n|         1-Para remover algum produto                                      |");
                                            printf(" \n|         2-Para realizar a compra                                          |");
                                            printf(" \n|         3-Cancelar a compra e voltar para pagina inicial                  |");
                                            printf(" \n|                                                                           |");
                                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                            printf(" \n+---------------------------------------------------------------------------+\n");

                                            preco_total = 0;
                                            for (i=0; i<=m; i++){//Laço que lista os produtos no carrinho de compras
                                                printf("%d - Produto: %s - Preco: R$%s - Empresa: %s", i, carrinho[i].compras[0], carrinho[i].compras[1], carrinho[i].compras[2]);
                                                preco_total += atof(carrinho[i].compras[1]);
                                            }
                                            printf("\nPreco total dos Produtos: R$%.2f\n", preco_total);

                                            printf("\n\n+---------------------------------------------------------------------------+");
                                            printf("\n  -->  ");
                                            fflush(stdin);
                                            respost=getch();
                                            printf("%c\n",respost);
                                            printf("+---------------------------------------------------------------------------+");

                                            if((respost!='1')&&(respost!='2')&&(respost!='3')){ // tratamento de erro
                                                do{
                                                    printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                                    printf("\nEntrada invalida, digite novamente 1 ou 2 ou 3!\n");
                                                    printf("\n  -->  ");
                                                    fflush(stdin);
                                                    respost=getch();
                                                    printf("%c\n",respost);
                                                    printf("+---------------------------------------------------------------------------+\n");
                                                }while((respost!='1')&&(respost!='2')&&(respost!='3'));
                                            }

                                            switch (respost){
                                                case '1':
                                                    printf(" \n+---------------------------------------------------------------------------+");
                                                    printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                                    printf(" \n|             Digite o numero de qual produto deseja remover:               |");
                                                    printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                                    printf(" \n+---------------------------------------------------------------------------+");

                                                    printf("\n\n+---------------------------------------------------------------------------+");
                                                    printf("\n  -->  ");
                                                    fflush(stdin);
                                                    scanf("%d", &remover);
                                                    printf("+---------------------------------------------------------------------------+\n");

                                                    for(i=remover; i < m; i++){
                                                        strcpy(carrinho[i].compras[0],carrinho[i+1].compras[0]);
                                                        strcpy(carrinho[i].compras[1],carrinho[i+1].compras[1]);
                                                        strcpy(carrinho[i].compras[2],carrinho[i+1].compras[2]);
                                                    }
                                                    m--;
                                                    break;

                                                case '2':
                                                    frag_compra = 1;
                                                    flag_pesquisa = 1;
                                                    system("cls");
                                                    printf(" \n+---------------------------------------------------------------------------+");
                                                    printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                                    printf(" \n|                                                                           |");
                                                    printf(" \n|                     Compra realizada com sucesso                          |");
                                                    printf(" \n|                                                                           |");
                                                    printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                                    printf(" \n+---------------------------------------------------------------------------+\n\n");
                                                    system("pause");
                                                    break;

                                                default:
                                                    frag_compra = 1;
                                                    flag_pesquisa = 1;
                                                    break;
                                            }

                                        }while(frag_compra != 1);

                                        break;

                                    case '3': // Sair da pesquisa
                                        flag_pesquisa = 1;
                                        break;

                                    default:
                                        break;
                                }

                        }while(flag_pesquisa !=1);
                        break;

                    case '3': // Case Pesquisa de Empresa
                        flag_pesquisa = 0;
                        do{

                            arq_empresas = fopen("bancos de dados\\Dados_Produtos.txt", "r");

                            system("cls");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                             Pesquisa Empresa                              |");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                         Digite o nome da Empresa :                        |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fgets(empresa_pesquisa, sizeof(empresa_pesquisa), stdin);
                            printf("+---------------------------------------------------------------------------+\n");

                            empresa_pesquisa[strcspn(empresa_pesquisa, "\n")] = '\0';

                            len = strlen(empresa_pesquisa);
                            if (empresa_pesquisa[len - 1] == '\n') {
                                empresa_pesquisa[len - 1] = '\0';
                            }

                            if(arq_empresas == NULL){
                                printf("Erro ao abrir o arquivo!");
                            }else{
                                j = 0;
                                while(fgets(linha, sizeof(linha), arq_empresas) != NULL){
                                    separador = strtok(linha, "{");
                                    i = 0;
                                    while(separador != NULL){
                                        strcpy(lista[j].empresa[i], separador);
                                        separador = strtok(NULL, "{");
                                        i++;
                                    }

                                    valorcmp = strncasecmp(lista[j].empresa[2], empresa_pesquisa, len);

                                    if(i == 3 && valorcmp == 0){
                                        printf("ID: %d - Produto: %s - Preco: R$%s - Empresa: %s", j, lista[j].empresa[0], lista[j].empresa[1], lista[j].empresa[2]);
                                    }
                                    j++;
                                }
                            }
                            fclose(arq_empresas);

                            printf(" \n\n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                  1- Adicinar 1 desses ao carrinho de compras              |");
                            printf(" \n|                  2- Pesquisar novamente                                   |");
                            printf(" \n|                  3- Fechar pesquisa                                       |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            respost=getch();
                            printf("%c\n",respost);
                            printf("+---------------------------------------------------------------------------+");

                            if((respost!='1')&&(respost!='2')&&(respost!='3')){ // tratamento de erro
                                do{
                                    printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                    printf("\nEntrada invalida, digite novamente 1 ou 2 ou 3 !\n");
                                    printf("\n  -->  ");
                                    fflush(stdin);
                                    respost=getch();
                                    printf("%c\n",respost);
                                    printf("+---------------------------------------------------------------------------+\n");
                                }while((respost!='1')&&(respost!='2')&&(respost!='3'));
                            }

                            switch (respost){
                                case '1': // Carrinho de compras
                                    frag_compra = 0;
                                    m = -1;
                                    do{
                                        arq_empresas = fopen("bancos de dados\\Dados_Produtos.txt", "r");
                                        system("cls");
                                        printf(" \n+---------------------------------------------------------------------------+");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n|                   Digite os ID que deseja adicionar                       |");
                                        printf(" \n|                      Caso queira sair digite  -1                          |");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n+---------------------------------------------------------------------------+\n");

                                        j = 0; //Para mostrar os produtos novamente
                                        while(fgets(linha, sizeof(linha), arq_empresas) != NULL){
                                            separador = strtok(linha, "{");
                                            i = 0;
                                            while(separador != NULL){
                                                strcpy(lista[j].empresa[i], separador);
                                                separador = strtok(NULL, "{");
                                                i++;
                                            }

                                            valorcmp = strncasecmp(lista[j].empresa[2], empresa_pesquisa, len);

                                            if(i == 3 && valorcmp == 0){
                                                printf("ID: %d - Produto: %s - Preco: R$%s - Empresa: %s", j, lista[j].empresa[0], lista[j].empresa[1], lista[j].empresa[2]);
                                            }
                                            j++;
                                        }

                                        printf("\n\n+---------------------------------------------------------------------------+");
                                        printf("\n  -->  ");
                                        fflush(stdin);
                                        scanf("%d", &id);
                                        printf("+---------------------------------------------------------------------------+\n\n");

                                        if(id == -1){
                                            frag_compra = 1;
                                            continue;
                                        }

                                        for(valid = 0; valid <= j; valid++){
                                            if(id == valid){
                                                m++;//Faz a incrementação da struct de produtos no carrinho de compras
                                                for (i=0; i<3; i++){//Laço responsável por incluir o produto pesquisado no carrinho de compras
                                                    if(id >= 0){
                                                        strcpy(carrinho[m].compras[i], lista[id].empresa[i]);
                                                    }
                                                    if(i == 1 && id >= 0) {//Condição que converte string para float, possibilitando a soma do valor total dos produtos no carrinho de compras
                                                        preco_total += atof(lista[id].empresa[i]);
                                                    }
                                                }
                                            }
                                        }
                                    fclose(arq_empresas);
                                    }while(frag_compra != 1);
                                    frag_compra = 0;
                                    do{
                                        system("cls");
                                        printf(" \n+---------------------------------------------------------------------------+");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n|         Esses sao os produtos adicionados ao seu carrinho                 |");
                                        printf(" \n|                                                                           |");
                                        printf(" \n|         1-Para remover algum produto                                      |");
                                        printf(" \n|         2-Para realizar a compra                                          |");
                                        printf(" \n|         3-Cancelar a compra e voltar para pagina inicial                  |");
                                        printf(" \n|                                                                           |");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n+---------------------------------------------------------------------------+\n");

                                        preco_total = 0;
                                        for (i=0; i<=m; i++){//Laço que lista os produtos no carrinho de compras
                                            printf("%d - Produto: %s - Preco: R$%s - Empresa: %s", i, carrinho[i].compras[0], carrinho[i].compras[1], carrinho[i].compras[2]);
                                            preco_total += atof(carrinho[i].compras[1]);
                                        }
                                        printf("\nPreco total dos Produtos: R$%.2f\n", preco_total);
                                        printf("\n\n+---------------------------------------------------------------------------+");
                                        printf("\n  -->  ");
                                        fflush(stdin);
                                        respost=getch();
                                        printf("%c\n",respost);
                                        printf("+---------------------------------------------------------------------------+");

                                        if((respost!='1')&&(respost!='2')&&(respost!='3')){ // tratamento de erro
                                            do{
                                                printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                                printf("\nEntrada invalida, digite novamente 1 ou 2 ou 3!\n");
                                                printf("\n  -->  ");
                                                fflush(stdin);
                                                respost=getch();
                                                printf("%c\n",respost);
                                                printf("+---------------------------------------------------------------------------+\n");
                                            }while((respost!='1')&&(respost!='2')&&(respost!='3'));
                                        }

                                        switch (respost){
                                            case '1':
                                                printf(" \n+---------------------------------------------------------------------------+");
                                                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                                printf(" \n|             Digite o numero de qual produto deseja remover:               |");
                                                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                                printf(" \n+---------------------------------------------------------------------------+");
                                                printf("\n\n+---------------------------------------------------------------------------+");
                                                printf("\n  -->  ");
                                                fflush(stdin);
                                                scanf("%d", &remover);
                                                printf("+---------------------------------------------------------------------------+\n");

                                                for(i=remover; i < m; i++){
                                                    strcpy(carrinho[i].compras[0],carrinho[i+1].compras[0]);
                                                    strcpy(carrinho[i].compras[1],carrinho[i+1].compras[1]);
                                                    strcpy(carrinho[i].compras[2],carrinho[i+1].compras[2]);
                                                }
                                                m--;

                                                printf("\nEstes sao os produtos adicionados ao seu carrinho:\n");
                                                preco_total = 0;
                                                for (i=0; i<=m; i++){//Laço que lista os produtos no carrinho de compras
                                                    printf("%d - Produto: %s - Preco: R$%s - Empresa: %s", i, carrinho[i].compras[0], carrinho[i].compras[1], carrinho[i].compras[2]);
                                                    preco_total += atof(carrinho[i].compras[1]);
                                                }
                                                printf("Preco total dos Produtos: R$%.2f\n", preco_total);
                                                break;

                                            case '2':
                                                frag_compra = 1;
                                                flag_pesquisa = 1;
                                                system("cls");
                                                printf(" \n+---------------------------------------------------------------------------+");
                                                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                                printf(" \n|                                                                           |");
                                                printf(" \n|                     Compra realizada com sucesso                          |");
                                                printf(" \n|                                                                           |");
                                                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                                printf(" \n+---------------------------------------------------------------------------+\n\n");
                                                system("pause");
                                                break;

                                            default:
                                                frag_compra = 1;
                                                flag_pesquisa = 1;
                                                break;
                                        }

                                    }while(frag_compra != 1);
                                    break;

                                case '3': // Sair da pesquisa
                                    flag_pesquisa = 1;
                                    break;

                                default:
                                    break;
                            }
                        }while(flag_pesquisa !=1);

                        break;

                    case '4': // Case Fechar programa
                        Flag_loop = 1;
                        break;

                    default:
                        break;
                    }


            }while(Flag_loop != 1);
            break;

        case '2': // Pagina da Loja

            do{
                Flag_loop = 0;
                system("cls");
                printf("\n /$$$$$$$  /$$                       /$$                         /$$");
                printf("\n| $$__  $$| $$                      | $$                        | $$");
                printf("\n| $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
                printf("\n| $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
                printf("\n| $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
                printf("\n| $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
                printf("\n| $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
                printf("\n|__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");

                printf(" \n+---------------------------------------------------------------------------+");
                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                printf(" \n|                               Loja:  %s                                   ",login);
                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                printf(" \n+---------------------------------------------------------------------------+");

                printf(" \n\n+---------------------------------------------------------------------------+");
                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                printf(" \n|                           1-Configuracoes                                 |");
                printf(" \n|                           2-Cadastrar Produtos                            |");
                printf(" \n|                           3-Pesquisar Produtos                            |");
                printf(" \n|                           4-Pesquisar Empresa                             |");
                printf(" \n|                           5-Fechar programa                               |");
                printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                printf(" \n+---------------------------------------------------------------------------+");

                char respost;

                printf("\n\n+---------------------------------------------------------------------------+");
                printf("\n  -->  ");
                fflush(stdin);
                respost=getch();
                printf("%c\n",respost);
                printf("+---------------------------------------------------------------------------+");


                if((respost!='1')&&(respost!='2')&&(respost!='3')&&(respost!='4')&&(respost!='5')){ // tratamento de erro
                    do{
                        printf("\n\n\n\n+---------------------------------------------------------------------------+");
                        printf("\nEntrada invalida, digite novamente 1 ou 2 ou 3 ou 4 ou 5!\n");
                        printf("\n  -->  ");
                        fflush(stdin);
                        respost=getch();
                        printf("%c\n",respost);
                        printf("+---------------------------------------------------------------------------+");
                    }while((respost!='1')&&(respost!='2')&&(respost!='3')&&(respost!='4')&&(respost!='5'));
                }

                switch (respost) // Switch configuracao

                {
                    case '1': // Case Configurações
                        do{
                            Flag_configuracao = 0;
                            system("cls");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                             Configuracao                                  |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf(" \n\n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                           1-Alterar senha                                 |");
                            printf(" \n|                           2-Fechar configuracao                           |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            respost=getch();
                            printf("%c\n",respost);
                            printf("+---------------------------------------------------------------------------+");

                            if((respost!='1')&&(respost!='2')){ // tratamento de erro
                                do{
                                    printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                    printf("\nEntrada invalida, digite novamente 1 ou 2!\n");
                                    printf("\n  -->  ");
                                    fflush(stdin);
                                    respost=getch();
                                    printf("%c\n",respost);
                                    printf("+---------------------------------------------------------------------------+");
                                }while((respost!='1')&&(respost!='2'));
                            }

                            switch (respost)
                            {
                                case '1': // Alterar Senha

                                    system("cls"); // Obtendo Senha do Usuario
                                    printf("\n+------------------------------------------+");
                                    printf("\n|                                          |");
                                    printf("\n|          Digite sua senha  atual         |");
                                    printf("\n|                                          |");
                                    printf("\n+------------------------------------------+");
                                    printf("\n|//////////////////////////////////////////|");
                                    printf("\n+------------------------------------------+");
                                    printf("\n\n+------------------------------------------+");
                                    printf("\nSenha: -->  ");
                                    fflush(stdin);
                                    gets(senha);
                                    printf("+------------------------------------------+");


                                    if(verificar_login_lojas(login, senha)==1){

                                    system("cls"); // Obtendo Senha do Usuario
                                    printf("\n+------------------------------------------+");
                                    printf("\n|                                          |");
                                    printf("\n|         Digite a nova senha              |");
                                    printf("\n|                                          |");
                                    printf("\n+------------------------------------------+");
                                    printf("\n|//////////////////////////////////////////|");
                                    printf("\n+------------------------------------------+");
                                    printf("\n\n+------------------------------------------+");
                                    printf("\nSenha: -->  ");
                                    fflush(stdin);
                                    gets(senha);
                                    printf("+------------------------------------------+");

                                    if(validar_senha(senha) != 1 ){ // Validação Senha
                                        do{
                                            printf("\n+------------------------------------------+");
                                            printf("\n|                                          |");
                                            printf("\n|              Senha invalida              |");
                                            printf("\n|                                          |");
                                            printf("\n+------------------------------------------+");
                                            printf("\n|     No minimo 8 digitos e no maximo 40   |");
                                            printf("\n+------------------------------------------+");
                                            printf("\n|//////////////////////////////////////////|");
                                            printf("\n| No minimo 1 caracter especial e 1 digito |");
                                            printf("\n|//////////////////////////////////////////|");
                                            printf("\n+------------------------------------------+");
                                            printf("\n\n+------------------------------------------+");
                                            printf("\nSenha: -->  ");
                                            fflush(stdin);
                                            gets(senha);
                                            printf("+------------------------------------------+");
                                        }while (validar_senha(senha) != 1);
                                    }

                                    if(atualizar_senha_lojas(login,senha)==1){
                                        system("cls");
                                        printf(" \n+-----------------------------------------+");
                                        printf(" \n|/////////////////////////////////////////|");
                                        printf(" \n+-----------------------------------------+");
                                        printf(" \n|                                         |");
                                        printf(" \n|        Senha atualizada com sucesso     |");
                                        printf(" \n|                                         |");
                                        printf(" \n|-----------------------------------------|");
                                        printf(" \n|/////////////////////////////////////////|");
                                        printf(" \n+-----------------------------------------+\n\n\n");
                                        sleep(3);
                                    }

                                    }else{
                                        system("cls");
                                        printf(" \n+-----------------------------------------+");
                                        printf(" \n|/////////////////////////////////////////|");
                                        printf(" \n+-----------------------------------------+");
                                        printf(" \n|                                         |");
                                        printf(" \n|            Senha Incorreta              |");
                                        printf(" \n|                                         |");
                                        printf(" \n|-----------------------------------------|");
                                        printf(" \n|/////////////////////////////////////////|");
                                        printf(" \n+-----------------------------------------+\n\n\n");
                                        sleep(3);
                                    }

                                    break;

                                case '2': // Sair configuraçao
                                    Flag_configuracao = 1;
                                    break;

                                default:
                                    break;
                            }
                        }while(Flag_configuracao != 1 );
                        break;

                    case '2': // Case Cadastrar Produtos
                        do{
                            Flag_cadastro = 0;
                            system("cls");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                           Cadastrar Produto                               |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf(" \n\n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                           1- Cadastrar Produto                            |");
                            printf(" \n|                           2- Sair do Cadastramento de Produto             |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            respost=getch();
                            printf("%c\n",respost);
                            printf("+---------------------------------------------------------------------------+");


                            if((respost!='1')&&(respost!='2')){ // tratamento de erro
                                do{
                                    printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                    printf("\nEntrada invalida, digite novamente 1 ou 2 !\n");
                                    printf("\n  -->  ");
                                    fflush(stdin);
                                    respost=getch();
                                    printf("%c\n",respost);
                                    printf("+---------------------------------------------------------------------------+");
                                }while((respost!='1')&&(respost!='2'));
                            }

                            switch (respost)
                            {
                                case '1': // Novo produto
                                    arq_produtos = fopen("bancos de dados\\Dados_Produtos.txt", "a+");
                                    do{
                                        Flag_cadastro02 = 0;
                                        system("cls");
                                        printf(" \n+---------------------------------------------------------------------------+");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n|                           Cadastrar Produto                               |");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n+---------------------------------------------------------------------------+");

                                        printf(" \n\n+---------------------------------------------------------------------------+");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n|                         Digite o nome do produto                          |");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n+---------------------------------------------------------------------------+");

                                        printf("\n\n+---------------------------------------------------------------------------+");
                                        printf("\n  -->  ");
                                        fflush(stdin);
                                        gets(nome_produto);
                                        printf("+---------------------------------------------------------------------------+");

                                        system("cls");
                                        printf(" \n+---------------------------------------------------------------------------+");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n|                           Cadastrar Produto                               |");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n+---------------------------------------------------------------------------+");

                                        printf(" \n\n+---------------------------------------------------------------------------+");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n|                         Digite o valor do produto                         |");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n+---------------------------------------------------------------------------+");

                                        printf("\n\n+---------------------------------------------------------------------------+");
                                        printf("\n  -->  ");
                                        fflush(stdin);
                                        scanf("%f",&valor_produto);
                                        printf("+---------------------------------------------------------------------------+");


                                        system("cls");
                                        printf(" \n+---------------------------------------------------------------------------+");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n|                 Confirmacao de cadastro do produto                        |");
                                        printf(" \n|                                                                           |");
                                        printf(" \n                     Nome :  %s                                              ",nome_produto);
                                        printf(" \n                     Valor:  R$ %.2f                                         ",valor_produto);
                                        printf(" \n|                                                                           |");
                                        printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                                        printf(" \n+---------------------------------------------------------------------------+");
                                        printf(" \n|                       Confirma as informacoes ?                           |");
                                        printf(" \n+---------------------------------------------------------------------------+");
                                        printf(" \n|        Sim-1             |     OU      |            Nao-2                 |");
                                        printf(" \n+---------------------------------------------------------------------------+");

                                        printf("\n");

                                        printf(" \n+--------------------------------------------------------------------------+");
                                        printf("\n                         -->  ");
                                        fflush(stdin);
                                        resposta_1ou2 = getch();
                                        printf("%c\n",resposta_1ou2);
                                        printf(" \n+-------------------------------------------------------------------------+");

                                        if(validar_1ou2(resposta_1ou2)){ // Validação de 1 ou 2
                                            do{
                                                printf(" \n+-----------------------------------------------------------------------------+");
                                                printf(" \n          Entrada invalida, digite novamente 1 ou 2!\n");
                                                printf(" \n                  -->  ");
                                                fflush(stdin);
                                                resposta_1ou2=getch();
                                                printf("%c\n",resposta_1ou2);
                                                printf(" \n+-----------------------------------------------------------------------------+");
                                            }while(validar_1ou2(resposta_1ou2) == 1 );
                                        }

                                        if (resposta_1ou2 == '1'){
                                            Flag_cadastro02 = 1;
                                        }
                                    }while(Flag_cadastro02 != 1);

                                    fprintf(arq_produtos, "%s{%.2f{%s\n",nome_produto, valor_produto, login);

                                    fclose(arq_produtos);
                                    break;

                                case '2': // Sair do cadastramento
                                    Flag_cadastro = 1;
                                    break;

                                default:
                                    break;
                            }
                        }while(Flag_cadastro != 1 );

                        break;

                    case '3': // Case Pesquisar Produto
                        flag_pesquisa = 0;
                        do{
                            arq_produtos = fopen("bancos de dados\\Dados_Produtos.txt", "r");
                            system("cls");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                             Pesquisa Produtos                             |");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                         Digite o nome do produto :                        |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fgets(produto_pesquisa, sizeof(produto_pesquisa), stdin);
                            printf("+---------------------------------------------------------------------------+\n");

                            produto_pesquisa[strcspn(produto_pesquisa, "\n")] = '\0';

                            len = strlen(produto_pesquisa);
                            if (produto_pesquisa[len - 1] == '\n') {
                                produto_pesquisa[len - 1] = '\0';
                            }

                            if(arq_produtos == NULL){
                                printf("Erro ao abrir o arquivo!");
                            }else{
                                j = 0;
                                while(fgets(linha, sizeof(linha), arq_produtos) != NULL){
                                    separador = strtok(linha, "{");
                                    i = 0;
                                    while(separador != NULL){
                                        strcpy(lista[j].produto[i], separador);
                                        separador = strtok(NULL, "{");
                                        i++;
                                    }
                                    if(i == 3 && strncasecmp(lista[j].produto[0], produto_pesquisa, len) == 0){
                                        printf("ID: %d - Produto: %s - Preco: R$%s - Empresa: %s", j, lista[j].produto[0], lista[j].produto[1], lista[j].produto[2]);
                                    }
                                    j++;
                                }
                            }
                            fclose(arq_produtos);

                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                  1- Pesquisar novamente                                   |");
                            printf(" \n|                  2- Fechar pesquisa                                       |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            respost=getch();
                            printf("%c\n",respost);
                            printf("+---------------------------------------------------------------------------+");

                            if((respost!='1')&&(respost!='2')){ // tratamento de erro
                                do{
                                    printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                    printf("\nEntrada invalida, digite novamente 1 ou 2 !\n");
                                    printf("\n  -->  ");
                                    fflush(stdin);
                                    respost=getch();
                                    printf("%c\n",respost);
                                    printf("+---------------------------------------------------------------------------+");
                                }while((respost!='1')&&(respost!='2'));
                            }

                            switch (respost){
                                    case '1':
                                        flag_pesquisa = 0;
                                        break;

                                    case '2': // Sair da pesquisa
                                        flag_pesquisa = 1;
                                        break;

                                    default:
                                        break;
                                }

                        }while(flag_pesquisa !=1);

                        break;

                    case '4': // Case Pesquisar Empresa
                        flag_pesquisa = 0;
                        do{
                            arq_empresas = fopen("bancos de dados\\Dados_Produtos.txt", "r");

                            system("cls");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                             Pesquisa Empresa                              |");
                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                         Digite o nome da Empresa :                        |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fgets(empresa_pesquisa, sizeof(empresa_pesquisa), stdin);
                            printf("+---------------------------------------------------------------------------+\n");

                            empresa_pesquisa[strcspn(empresa_pesquisa, "\n")] = '\0';

                            len = strlen(empresa_pesquisa);
                            if (empresa_pesquisa[len - 1] == '\n') {
                                empresa_pesquisa[len - 1] = '\0';
                            }

                            if(arq_empresas == NULL){
                                printf("Erro ao abrir o arquivo!");
                            }else{
                                j = 0;
                                while(fgets(linha, sizeof(linha), arq_empresas) != NULL){
                                    separador = strtok(linha, "{");
                                    i = 0;
                                    while(separador != NULL){
                                        strcpy(lista[j].empresa[i], separador);
                                        separador = strtok(NULL, "{");
                                        i++;
                                    }

                                    valorcmp = strncasecmp(lista[j].empresa[2], empresa_pesquisa, len);

                                    if(i == 3 && valorcmp == 0){
                                        printf("ID: %d - Produto: %s - Preco: R$%s - Empresa: %s", j, lista[j].empresa[0], lista[j].empresa[1], lista[j].empresa[2]);
                                    }
                                    j++;
                                }
                            }
                            fclose(arq_empresas);

                            printf(" \n+---------------------------------------------------------------------------+");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n|                  1- Pesquisar novamente                                   |");
                            printf(" \n|                  2- Fechar pesquisa                                       |");
                            printf(" \n|///////////////////////////////////////////////////////////////////////////|");
                            printf(" \n+---------------------------------------------------------------------------+");

                            printf("\n\n+---------------------------------------------------------------------------+");
                            printf("\n  -->  ");
                            fflush(stdin);
                            respost=getch();
                            printf("%c\n",respost);
                            printf("+---------------------------------------------------------------------------+");

                            if((respost!='1')&&(respost!='2')){ // tratamento de erro
                                do{
                                    printf("\n\n\n\n+---------------------------------------------------------------------------+");
                                    printf("\nEntrada invalida, digite novamente 1 ou 2 !\n");
                                    printf("\n  -->  ");
                                    fflush(stdin);
                                    respost=getch();
                                    printf("%c\n",respost);
                                    printf("+---------------------------------------------------------------------------+");
                                }while((respost!='1')&&(respost!='2'));
                            }

                            switch (respost){
                                case '1':
                                    flag_pesquisa = 0;
                                    break;

                                case '2': // Sair da pesquisa
                                    flag_pesquisa = 1;
                                    break;

                                default:
                                    break;
                            }
                        }while(flag_pesquisa !=1);


                        break;

                    case '5': // Case Fechar programa
                        Flag_loop = 1;
                        break;

                    default:
                        break;
                }


            }while(Flag_loop != 1);

            break;

        default:
            break;
    }
}
