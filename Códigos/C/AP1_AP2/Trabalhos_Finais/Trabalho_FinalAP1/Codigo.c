#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Biblioteca.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    int i=0;
    int valid=0, valid1=0, valid2=0,j=10, digito1=0, digito2=0;
    char cpf[12];
    char respost;
    int mesINT[2]= {0} , diaINT[2]= {0} , anoINT[4]= {0};
    char mes[2]= {} , dia[2]= {} , ano[4]= {};
    int diaX=0,mesX=0,anoBI=0,ph=0,validPH=0,anoX=0,tam=0;
    int senhavalid, h=0, validac=0, len, len2;
    char senha[41]= {'\0'}, senha2[41]={'\0'}, codverificador[6];
    //Tela inicial da plataforma/Pedro Henrique Gomides Moraes

    printf("\n                                         /$$$$$$$  /$$                       /$$                         /$$");
    printf("\n                                        | $$__  $$| $$                      | $$                        | $$");
    printf("\n                                        | $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
    printf("\n                                        | $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
    printf("\n                                        | $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
    printf("\n                                        | $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
    printf("\n                                        | $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
    printf("\n                                        |__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");


    printf(" \n                                                  +-----------------------------------------+");
    printf(" \n                                                  |                                         |");
    printf(" \n                                                  |                                         |");
    printf(" \n                                                  |          BEM VINDO A PLANTECH          |");
    printf(" \n                                                  |                                         |");
    printf(" \n                                                  |                                         |");
    printf(" \n                                                  +-----------------------------------------+");

    printf("\n");

    printf(" \n                                                  +-----------------------------------------+");
    printf(" \n                                                  |                                         |");
    printf(" \n                                                  |         Deseja fazer sua conta ?        |");
    printf(" \n                                                  |                                         |");
    printf(" \n                                                  |-----------------------------------------|");
    printf(" \n                                                  |     SIM-1    |     OU      |    NAO-2   |");
    printf(" \n                                                  +-----------------------------------------+");


    printf("\n\n                                                  +-----------------------------------------+");
    printf("\n                                                                  -->  ");
    fflush(stdin);
    respost=getch();
    printf("%c\n",respost);
    printf("                                                  +-----------------------------------------+");

    //Tratamento de erro sim/n?o
    if((respost!='1')&&(respost!='2')){
        do{

            printf("\n\n\n\n                                               +-----------------------------------------------+");
            printf("\n                                                  Entrada invalida, digite novamente 1 ou 2!\n");
            printf("\n                                                                 -->  ");
            fflush(stdin);
            respost=getch();
            printf("%c\n",respost);
            printf("                                               +-----------------------------------------------+");

            }while((respost!='1')&&(respost!='2'));
    }
    if(respost=='2'){
        system("cls");
        printf(" \n                                                  +-----------------------------------------+");
        printf(" \n                                                  |                                         |");
        printf(" \n                                                  |       Poxaa...,Estavamos contando       |");
        printf(" \n                                                  |      com sua presen�a.                  |");
        printf(" \n                                                  |                                         |");
        printf(" \n                                                  |-----------------------------------------|");
        printf(" \n                                                  |   Caso mude de ideia, estaremos aqui ;) |");
        printf(" \n                                                  +-----------------------------------------+\n\n\n");



        printf("\n                                         /$$$$$$$  /$$                       /$$                         /$$");
        printf("\n                                        | $$__  $$| $$                      | $$                        | $$");
        printf("\n                                        | $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
        printf("\n                                        | $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
        printf("\n                                        | $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
        printf("\n                                        | $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
        printf("\n                                        | $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
        printf("\n                                        |__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");
        return 0;

    }
    //Definir o tipo
    system("cls");
    i=0;
    printf(" \n                                                  +-----------------------------------------+");
    printf(" \n                                                  |                                         |");
    printf(" \n                                                  |       Qual o seu tipo de conta ?        |");
    printf(" \n                                                  |                                         |");
    printf(" \n                                                  |-----------------------------------------|");
    printf(" \n                                                  |   Comprador-1  |  OU   |   Vendedor-2   |");
    printf(" \n                                                  +-----------------------------------------+");
    char tipo;

    printf("\n\n                                                  +-----------------------------------------+");
    printf("\n                                                                  -->  ");
    fflush(stdin);
    tipo=getch();
    printf("%c\n",tipo);
    printf("                                                  +-----------------------------------------+");

    if((tipo!='1')&&(tipo!='2')&&(tipo!='\0')){
        do{
            printf("\n\n\n\n                                               +-----------------------------------------------+");
            printf("\n                                                  Entrada invalida, digite novamente 1 ou 2!\n");
            printf("\n                                                                -->  ");
            fflush(stdin);
            tipo=getch();
            printf("%c\n",tipo);
            printf("                                               +-----------------------------------------------+");
            }while((tipo!='1')&&(tipo!='2')&&(tipo!='\0'));
    }

            system("cls");
            int validarTotal=0,bandeiradata=0,bandeiracpf=0,bandeirasenha=0;
    //Separa??o do vendedor e comprador /Pedro Henrique Gomides Moraes
        //Caso 1 , subgrupo = Pedro Henrique Gomides Moraes(Parte:Geral/interface,Data nascimento) e Gabriel Oka Duarte(Parte:cpf,senha)
    if(tipo=='1'){
        do{
            printf(" \n                                                  +-----------------------------------------+");
            printf(" \n                                                  |                                         |");
            printf(" \n                                                  |                                         |");
            printf(" \n                                                  |           REGISTRO DO CLIENTE           |");
            printf(" \n                                                  |                                         |");
            printf(" \n                                                  |                                         |");
            printf(" \n                                                  +-----------------------------------------+");

            printf("\n");
            int valid=0, valid1=0, valid2=0, i, j=10, digito1=0, digito2=0;
            char cpf[12];
            if(bandeiracpf==0){
                bandeiracpf=1;

            system("cls");
            printf(" \n                                                  +------------------------------------------+");
            printf(" \n                                                  |//////////////////////////////////////////|");
            printf(" \n                                                  +------------------------------------------+");
            printf(" \n                                                  |                                          |");
            printf(" \n                                                  |             Digite seu cpf ?             |");
            printf(" \n                                                  |                                          |");
            printf(" \n                                                  +------------------------------------------+");
            printf(" \n                                                  |//////////////////////////////////////////|");
            printf(" \n                                                  |     Digite apenas os numeros, sem . e -  |");
            printf(" \n                                                  |//////////////////////////////////////////|");
            printf(" \n                                                  +------------------------------------------+");
            //Valida??o de CPF

            do{
                    digito1=0;
                    digito2=0;

                printf("\n\n                                                  +------------------------------------------+");
                printf("\n                                                   -->  ");
                scanf("%12s", cpf);
                printf("                                                  +------------------------------------------+");
            if (strlen(cpf) != 11){
                system("cls");
                printf("\n\n                                                  +------------------------------------------+");
                printf("\n                                                  |                                          |");
                printf("\n                                                  |              CPF inv?lido                |");
                printf("\n                                                  |                                          |");
                printf("\n                                                  +------------------------------------------+");
                printf("\n                                                  |          Digite novemente seu cpf        |");
                printf("\n                                                  +------------------------------------------+");
                printf("\n                                                  |//////////////////////////////////////////|");
                printf("\n                                                  |     Digite apenas os numeros, sem . e -  |");
                printf("\n                                                  |//////////////////////////////////////////|");
                printf("\n                                                  +------------------------------------------+");



                continue;
            }else if (strlen(cpf) == 11){

                //CPFs que s?o inv?lidos naturalmente.
                if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
                   (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
                   (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
                   (strcmp(cpf,"99999999999") == 0)){
                    system("cls");
                    printf("\n\n                                                  +------------------------------------------+");
                    printf("\n                                                  |                                          |");
                    printf("\n                                                  |              CPF invalido                |");
                    printf("\n                                                  |                                          |");
                    printf("\n                                                  +------------------------------------------+");
                    printf("\n                                                  |          Digite novemente seu cpf        |");
                    printf("\n                                                  +------------------------------------------+");
                    printf("\n                                                  |//////////////////////////////////////////|");
                    printf("\n                                                  |     Digite apenas os numeros, sem . e -  |");
                    printf("\n                                                  |//////////////////////////////////////////|");
                    printf("\n                                                  +------------------------------------------+");

                    continue;
                }
                //Valida??o do primeiro d?gito verificador.
                for(i=0, j=10; i<9; i++, j--){
                    valid1= cpf[i]-48;
                    if ((valid1>=0) && (valid1<=9)){
                    digito1= digito1 + valid1*j;
                    }
                }
                    digito1= digito1*10;
                    digito1= digito1%11;
                    if(digito1==10){
                        digito1=0;
                    }

                //Valida??o do segundo d?gito verificador.
                for(i=0, j=11; i<=9; i++, j--){
                    valid2= cpf[i]-48;
                    if ((valid2>=0) && (valid2<=9)){
                        digito2= digito2 + valid2*j;
                    }
                }
                digito2= digito2*10;
                digito2= digito2%11;
                if(digito2==10){
                    digito2=0;
                    }
                if ((digito1==cpf[9]-48) && (digito2==cpf[10]-48)){
                    valid = 1;
                } else if (valid==0){
                    system("cls");
                    printf("\n\n                                                  +------------------------------------------+");
                    printf("\n                                                  |                                          |");
                    printf("\n                                                  |              CPF invalido                |");
                    printf("\n                                                  |                                          |");
                    printf("\n                                                  +------------------------------------------+");
                    printf("\n                                                  |          Digite novemente seu cpf        |");
                    printf("\n                                                  +------------------------------------------+");
                    printf("\n                                                  |//////////////////////////////////////////|");
                    printf("\n                                                  |     Digite apenas os numeros, sem . e -  |");
                    printf("\n                                                  |//////////////////////////////////////////|");
                    printf("\n                                                  +------------------------------------------+");

                    continue;
                            }
            }
            } while(valid == 0);
            }




                    if(bandeiradata==0){
                        bandeiradata=1;
                    //Tela inicial do data, primeira entrada de valores
                    system("cls");
                    i=0;
                    printf("\n                                                  +------------------------------------------+");
                    printf("\n                                                  |                                          |");
                    printf("\n                                                  |      Digite a sua data de nascimento     |");
                    printf("\n                                                  |                                          |");
                    printf("\n                                                  +------------------------------------------+");
                    printf("\n                                                  |         Dia: DD Mes: MM Ano: AAAA        |");
                    printf("\n                                                  +------------------------------------------+");
                    printf("\n                                                  |//////////////////////////////////////////|");
                    printf("\n                                                  |     Digite apenas 2 digitos de numeros   |");
                    printf("\n                                                  |//////////////////////////////////////////|");
                    printf("\n                                                  +------------------------------------------+");


                    printf("\n\n                                                  +------------------------------------------+");
                    printf("\n                                                               Dia: -->  ");
                    scanf("%3s",&dia);
                    printf("                                                  +------------------------------------------+");

                    //Valida?ao do DIA
                    do{

                        for(i=0; i<=1; i++){
                            diaINT[i]=0;
                        }
                        diaX=0;
                        tam=0;
                        validPH=0;
                        for(i=0, ph=0; i<=1; i++){
                            ph=0;
                            ph=dia[i]-48;
                            if ((ph>=0) && (ph<=9)){
                               validPH++;

                            }
                        }
                        tam=strlen(dia);
                        if(tam==2){
                            if(validPH==2){
                                for(i=0; i<=1; i++){
                                    diaINT[i]=dia[i]-48;
                                 }
                                diaX=diaINT[0]*10;
                                diaX=diaINT[1]+diaX;
                                if((diaX>=1)&&(diaX<=31)){
                                    break;
                                }
                            }
                        }
                        for(i=0; i<=2; i++){
                            dia[i]=0;
                        }
                        system("cls");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |               Dia Invalido               |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  |           Digite novamente o dia         |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  |          Dia: DD Mes: MM Ano: AAAA       |");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |            Digite entre 01 a 31          |");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |//////////////////////////////////////////|");
                        printf("\n                                                  |         Digite 2 digitos de numeros      |");
                        printf("\n                                                  |//////////////////////////////////////////|");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n\n                                                  +------------------------------------------+");
                        printf("\n                                                               Dia: -->  ");
                        scanf("%3s",&dia);
                        printf("                                                  +------------------------------------------+");
                    }while(validPH!=10);

                     printf("\n\n                                                  +------------------------------------------+");
                     printf("\n                                                               Mes: -->  ");
                     scanf("%3s",&mes);
                     printf("                                                  +------------------------------------------+");


                    //Valida?ao do  MES
                   do{
                        for(i=0; i<=1; i++){
                            mesINT[i]=0;
                        }
                        mesX=0;
                        tam=0;
                        validPH=0;
                        for(i=0, ph=0; i<=1; i++){
                            ph=0;
                            ph=mes[i]-48;
                            if ((ph>=0) && (ph<=9)){
                               validPH++;

                            }
                        }
                        tam=strlen(mes);
                        if(tam==2){
                            if(validPH==2){
                                for(i=0; i<=1; i++){
                                    mesINT[i]=mes[i]-48;
                                 }
                                mesX=mesINT[0]*10;
                                mesX=mesINT[1]+mesX;
                                if((mesX>=1)&&(mesX<=12)){
                                    break;
                                }
                            }
                        }
                        for(i=0; i<=2; i++){
                            mes[i]=0;
                        }
                        system("cls");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |               Mes Invalido               |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  |           Digite novamente o mes         |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  |          Dia: DD M?s: MM Ano: AAAA       |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |            Digite entre  1 a 12          |");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |//////////////////////////////////////////|");
                        printf("\n                                                  |         Digite 2 digitos de n?meros      |");
                        printf("\n                                                  |//////////////////////////////////////////|");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n\n                                                  +------------------------------------------+");
                        printf("\n                                                           Mes: -->  ");
                        scanf("%3s",&mes);
                        printf("                                                  +------------------------------------------+");
                    }while(validPH!=10);

                    printf("\n\n                                                  +------------------------------------------+");
                    printf("\n                                                               Ano: -->  ");
                    scanf("%5s",&ano);
                    printf("                                                  +------------------------------------------+");

                    //Valida?ao do ANO
                    do{
                        for(i=0; i<=3; i++){
                            anoINT[i]=0;
                        }
                        anoX=0;
                        tam=0;
                        validPH=0;
                        for(i=0, ph=0; i<=3; i++){
                            ph=0;
                            ph=ano[i]-48;
                            if ((ph>=0) && (ph<=9)){
                               validPH++;

                            }
                        }
                        tam=strlen(ano);
                        if(tam==4){
                            if(validPH==4){
                                for(i=0; i<=3; i++){
                                    anoINT[i]=ano[i]-48;
                                 }
                                anoX=anoINT[0]*1000;
                                anoX=anoINT[1]*100+anoX;
                                anoX=anoINT[2]*10+anoX;
                                anoX=anoINT[3]+anoX;
                                if((anoX>=1900)&&(anoX<=2022)){
                                    break;
                                }
                            }
                        }
                        for(i=0; i<=4; i++){
                            ano[i]=0;
                        }
                        system("cls");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |               Ano Invalido               |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  |           Digite novamente o ano         |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  |          Dia: DD Mes: MM Ano: AAAA       |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |         Digite entre 1900 a 2022         |");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |//////////////////////////////////////////|");
                        printf("\n                                                  |         Digite 4 digitos de numeros      |");
                        printf("\n                                                  |//////////////////////////////////////////|");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n\n                                                  +------------------------------------------+");
                        printf("\n                                                           Ano: -->  ");
                        scanf("%5s", &ano);
                        printf("                                                  +------------------------------------------+");

                    }while(validPH!=10);
                    //Valida?ao do ANO BISSEXTO
                    int Bissexto=0;
                    Bissexto=0;
                    if(anoX%4==0){
                        if(anoX%100==0){
                            if(anoX%400==0){
                                Bissexto=2;
                                }
                        }else{
                            Bissexto=2;
                        }
                    }
                        if(mesX==2){ //Fevereiro
                             if(diaX>28){
                                if(Bissexto==0){
                                    for(i=0; i<=1; i++){
                                        dia[i]=0;
                                    }
                                    do{
                                    for(i=0; i<=1; i++){
                                        diaINT[i]=0;
                                    }
                                    diaX=0;
                                    tam=0;
                                    validPH=0;
                                    for(i=0, ph=0; i<=1; i++){
                                        ph=0;
                                        ph=dia[i]-48;
                                        if ((ph>=0) && (ph<=9)){
                                           validPH++;

                                        }
                                    }
                                    tam=strlen(dia);
                                    if(tam==2){
                                        if(validPH==2){
                                            for(i=0; i<=1; i++){
                                                diaINT[i]=dia[i]-48;
                                             }
                                            diaX=diaINT[0]*10;
                                            diaX=diaINT[1]+diaX;
                                            if((diaX>=1)&&(diaX<=28)){
                                                break;
                                            }
                                        }
                                    }
                                    for(i=0; i<=2; i++){
                                        dia[i]=0;
                                    }

                                    system("cls");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |               Dia Invalido               |");
                                    printf("\n                                                  |                                          |");
                                    printf("\n                                                  |    Em ano nao bissexto, fevereiro possui |");
                                    printf("\n                                                  |               apenas 28 dias             |");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |       Digite novamente entre 1 a 28      |");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |//////////////////////////////////////////|");
                                    printf("\n                                                  |         Digite 2 digitos de numeros      |");
                                    printf("\n                                                  |//////////////////////////////////////////|");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n\n                                                  +------------------------------------------+");
                                    printf("\n                                                           Dia: -->  ");
                                    scanf("%3s", &dia);
                                    printf("                                                  +------------------------------------------+");
                                    }while(validPH!=10);
                                }

                             }//Valida?ao MES COM 30 DIAS
                        }else if((mesX==4)||(mesX==6)||(mesX==9)||(mesX==11)){

                           if(diaX>=31){
                                for(i=0; i<=1; i++){
                                        dia[i]=0;
                                }
                                do{
                                    for(i=0; i<=1; i++){
                                        diaINT[i]=0;
                                    }
                                    diaX=0;
                                    tam=0;
                                    validPH=0;
                                    for(i=0, ph=0; i<=1; i++){
                                        ph=0;
                                        ph=dia[i]-48;
                                        if ((ph>=0) && (ph<=9)){
                                           validPH++;

                                        }
                                    }
                                    tam=strlen(dia);
                                    if(tam==2){
                                        if(validPH==2){
                                            for(i=0; i<=1; i++){
                                                diaINT[i]=dia[i]-48;
                                             }
                                            diaX=diaINT[0]*10;
                                            diaX=diaINT[1]+diaX;
                                            if((diaX>=1)&&(diaX<=30)){
                                                break;
                                            }
                                        }
                                    }
                                    for(i=0; i<=2; i++){
                                        dia[i]=0;
                                    }
                                    system("cls");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |               Dia Invalido               |");
                                    printf("\n                                                  |                                          |");
                                    printf("\n                                                  |          O mes inserido possui           |");
                                    printf("\n                                                  |               apenas 30 dias             |");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |       Digite novamente entre 1 a 30      |");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |//////////////////////////////////////////|");
                                    printf("\n                                                  |         Digite 2 digitos de numeros      |");
                                    printf("\n                                                  |//////////////////////////////////////////|");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n\n                                                  +------------------------------------------+");
                                    printf("\n                                                           Dia: -->  ");
                                    scanf("%3s", &dia);
                                    printf("                                                  +------------------------------------------+");
                                }while(validPH!=10);
                           }
                        }
                        //Validar se ? maior de 18 anos (OBS: Programa esta definido para analisar essa condi??o no dia 05/12/2022)
                        if((anoX>2004)&&(anoX<2021)){
                                 system("cls");
                                printf(" \n                                                  +---------------------------------------------+");
                                printf(" \n                                                  |                                             |");
                                printf(" \n                                                  | Poxaa...,Infelizmente voce � menor de idade |");
                                printf(" \n                                                  |                                             |");
                                printf(" \n                                                  +---------------------------------------------+");
                                printf(" \n                                                  |/////////////////////////////////////////////|");
                                printf(" \n                                                  | Aceitamos apenas pessoas maiores de 18 anos |");
                                printf(" \n                                                  |/////////////////////////////////////////////|");
                                printf(" \n                                                  +---------------------------------------------+");
                                printf(" \n                                                  |  Quando for de maior  , estaremos aqui ;)   |");
                                printf(" \n                                                  +---------------------------------------------+\n\n\n");



                                printf("\n                                         /$$$$$$$  /$$                       /$$                         /$$");
                                printf("\n                                        | $$__  $$| $$                      | $$                        | $$");
                                printf("\n                                        | $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
                                printf("\n                                        | $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
                                printf("\n                                        | $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
                                printf("\n                                        | $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
                                printf("\n                                        | $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
                                printf("\n                                        |__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");
                                return 0;
                        }else if(anoX==2004){
                            if(mesX==12){
                                if(diaX>5){

                                system("cls");
                                printf(" \n                                                  +---------------------------------------------+");
                                printf(" \n                                                  |                                             |");
                                printf(" \n                                                  | Poxaa...,Infelizmente voce � menor de idade |");
                                printf(" \n                                                  |                                             |");
                                printf(" \n                                                  +---------------------------------------------+");
                                printf(" \n                                                  |/////////////////////////////////////////////|");
                                printf(" \n                                                  | Aceitamos apenas pessoas maiores de 18 anos |");
                                printf(" \n                                                  |/////////////////////////////////////////////|");
                                printf(" \n                                                  +---------------------------------------------+");
                                printf(" \n                                                  |  Quando for de maior  , estaremos aqui ;)   |");
                                printf(" \n                                                  +---------------------------------------------+\n\n\n");



                                printf("\n                                         /$$$$$$$  /$$                       /$$                         /$$");
                                printf("\n                                        | $$__  $$| $$                      | $$                        | $$");
                                printf("\n                                        | $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
                                printf("\n                                        | $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
                                printf("\n                                        | $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
                                printf("\n                                        | $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
                                printf("\n                                        | $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
                                printf("\n                                        |__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");


                                return 0;

                        }}}
                            // EASTER EGG do codigo (PESSOA QUE AINDA N?O NASCEU)
                            if(anoX==2022){
                              if(mesX==12){
                                if(diaX>5){
                                 system("cls");
                                printf(" \n                                                  +-----------------------------------------------------------+");
                                printf(" \n                                                  |                                                           |");
                                printf(" \n                                                  |     HMMMM...Como voce � esta aqui? Se ainda nao nasceu     |");
                                printf(" \n                                                  |                                                           |");
                                printf(" \n                                                  +-----------------------------------------------------------+");
                                printf(" \n                                                  |///////////////////////////////////////////////////////////|");
                                printf(" \n                                                  |          Aceitamos apenas pessoas que ja nasceram         |");
                                printf(" \n                                                  |///////////////////////////////////////////////////////////|");
                                printf(" \n                                                  +-----------------------------------------------------------+");
                                printf(" \n                                                  | Quando nascer e possuir mais de 18anos, estaremos aqui ;) |");
                                printf(" \n                                                  +-----------------------------------------------------------+\n\n\n");



                                printf("\n                                         /$$$$$$$  /$$                       /$$                         /$$");
                                printf("\n                                        | $$__  $$| $$                      | $$                        | $$");
                                printf("\n                                        | $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
                                printf("\n                                        | $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
                                printf("\n                                        | $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
                                printf("\n                                        | $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
                                printf("\n                                        | $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
                                printf("\n                                        |__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");
                                return 0;




                                return 0;

                        }}}


                        }


                        //Senha
                        i=0;
                        j=36;


                        //?rea de cadastro de senha.
                    if(bandeirasenha==0){
                        bandeirasenha=1;
                        system("cls");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  |             Digite uma senha             |");
                        printf("\n                                                  |                                          |");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |     No m?nimo 8 digitos e no maximo 40   |");
                        printf("\n                                                  +------------------------------------------+");
                        printf("\n                                                  |//////////////////////////////////////////|");
                        printf("\n                                                  |             Apenas numeros!!             |");
                        printf("\n                                                  |//////////////////////////////////////////|");
                        printf("\n                                                  +------------------------------------------+");


                        do{
                            fflush(stdin);
                        senha[7]=0;
                        h=0;
                                printf("\n\n                                                  +------------------------------------------+");
                                printf("\n                                                           Senha: -->  ");
                                gets(senha);
                                printf("                                                  +------------------------------------------+");
                                len=strlen(senha);
                                fflush(stdin);

                                //Valida??o se possui menos que 8 d?gitos.
                                if((senha[7] == '\0')){
                                    system("cls");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |                                          |");
                                    printf("\n                                                  |              Senha invalida              |");
                                    printf("\n                                                  |                                          |");
                                    printf("\n                                                  |           Comprimento invalido           |");
                                    printf("\n                                                  |                                          |");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |     No m?nimo 8 d?gitos e no m?ximo 40   |");
                                    printf("\n                                                  +------------------------------------------+");
                                    printf("\n                                                  |//////////////////////////////////////////|");
                                    printf("\n                                                  |         S? ser?o aceitos n?meros!!       |");
                                    printf("\n                                                  |//////////////////////////////////////////|");
                                    printf("\n                                                  +------------------------------------------+");

                                    validac=0;
                                    continue;
                                    }

                                //Valida??o se possui mais que 40 d?gitos.
                                if ((senha[7] != '\0') && (len > 40)){
                                            fflush(stdin);
                                            system("cls");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  |              Senha invalida              |");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  |           Comprimento invalido           |");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |     No m?nimo 8 d?gitos e no m?ximo 40   |");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |//////////////////////////////////////////|");
                                            printf("\n                                                  |         S? ser?o aceitos n?meros!!       |");
                                            printf("\n                                                  |//////////////////////////////////////////|");
                                            printf("\n                                                  +------------------------------------------+");
                                            validac=0;
                                            continue;
                                        }


                                //Valida??o para verificar se foram inseridos n?meros ou n?o.
                                for(i=0, j=strlen(senha)-1, h=0; i<=j; i++){
                                        fflush(stdin);
                                        senhavalid= senha[i]-48;
                                        if((senhavalid>=0) && (senhavalid<=9)){
                                            h++;
                                        }
                                }

                                h--;

                                    //?ltima etapa de verifica??o, validac receber? 1 se a senha conseguir passar por todas etapas de valida??o.
                                    //Se n?o receber 1 quer dizer que n?o foi validado, ent?o repetir? o la?o.
                                    if(h==j){
                                        validac=1;
                                    } else if (h!=j){
                                        fflush(stdin);
                                        validac=0;
                                        system("cls");
                                        printf("\n                                                  +------------------------------------------+");
                                        printf("\n                                                  |                                          |");
                                        printf("\n                                                  |              Senha invalida              |");
                                        printf("\n                                                  |                                          |");
                                        printf("\n                                                  |      A senha deve conter so n?meros      |");
                                        printf("\n                                                  |                                          |");
                                        printf("\n                                                  +------------------------------------------+");
                                        printf("\n                                                  |     No m?nimo 8 d?gitos e no m?ximo 40   |");
                                        printf("\n                                                  +------------------------------------------+");
                                        printf("\n                                                  |//////////////////////////////////////////|");
                                        printf("\n                                                  |         S? ser?o aceitos n?meros!!       |");
                                        printf("\n                                                  |//////////////////////////////////////////|");
                                        printf("\n                                                  +------------------------------------------+");
                                        continue;
                                    }

                                    //?rea para confirmar a senha digitada.
                                    if(validac==1){
                                        fflush(stdin);
                                        system("cls");
                                        printf("\n                                                  +------------------------------------------+");
                                        printf("\n                                                  |                                          |");
                                        printf("\n                                                  |             Confirma??o senha            |");
                                        printf("\n                                                  |                                          |");
                                        printf("\n                                                  |      Digite novamente a mesma senha      |");
                                        printf("\n                                                  |                                          |");
                                        printf("\n                                                  +------------------------------------------+");
                                        printf("\n                                                  |     No m?nimo 8 d?gitos e no m?ximo 40   |");
                                        printf("\n                                                  +------------------------------------------+");
                                        printf("\n                                                  |//////////////////////////////////////////|");
                                        printf("\n                                                  |         S? ser?o aceitos n?meros!!       |");
                                        printf("\n                                                  |//////////////////////////////////////////|");
                                        printf("\n                                                  +------------------------------------------+");
                                        while(validac==1){
                                        printf("\n\n                                                  +------------------------------------------+");
                                        printf("\n                                                           Confirma senha: -->  ");
                                        gets(senha2);
                                        printf("                                                  +------------------------------------------+");
                                        len2=strlen(senha2);

                                        //Valida??o se possui menos que 8 d?gitos.
                                        if((senha2[7] == '\0')){
                                            system("cls");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  |      Confirma??o de senha incorreta      |");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  |       #Confirme novamente a senha#       |");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |     No m?nimo 8 d?gitos e no m?ximo 40   |");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |//////////////////////////////////////////|");
                                            printf("\n                                                  |         S? ser?o aceitos n?meros!!       |");
                                            printf("\n                                                  |//////////////////////////////////////////|");
                                            printf("\n                                                  +------------------------------------------+");
                                            validac=1;
                                        }

                                        //Valida??o se possui mais que 40 d?gitos.
                                        if ((senha[7] != '\0') && (len > 40)){
                                            fflush(stdin);
                                            system("cls");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  |      Confirma??o de senha incorreta      |");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  |       #Confirme novamente a senha#       |");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |     No m?nimo 8 d?gitos e no m?ximo 40   |");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |//////////////////////////////////////////|");
                                            printf("\n                                                  |         S? ser?o aceitos n?meros!!       |");
                                            printf("\n                                                  |//////////////////////////////////////////|");
                                            printf("\n                                                  +------------------------------------------+");
                                            validac=1;
                                        }

                                        //Valida??o para verificar se foram inseridos n?meros ou n?o.
                                        for(i=0, j=strlen(senha2)-1, h=0; i<=j; i++){
                                            senhavalid= senha[i]-48;
                                            if((senhavalid>=0) && (senhavalid<=9)){
                                                h++;
                                            }
                                        }
                                    h--;

                                        //Far? a ?ltima etapa de verifica??o, onde verificar? se a senha 1 ? igual ? senha 2.
                                        if(h!=j){
                                            fflush(stdin);
                                            system("cls");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  |      Confirma??o de senha incorreta      |");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  |       #Confirme novamente a senha#       |");
                                            printf("\n                                                  |                                          |");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |     No m?nimo 8 d?gitos e no m?ximo 40   |");
                                            printf("\n                                                  +------------------------------------------+");
                                            printf("\n                                                  |//////////////////////////////////////////|");
                                            printf("\n                                                  |         S? ser?o aceitos n?meros!!       |");
                                            printf("\n                                                  |//////////////////////////////////////////|");
                                            printf("\n                                                  +------------------------------------------+");
                                            } else if(strcmp(senha, senha2)==0){
                                                validac=2;
                                                } else{
                                                       system("cls");
                                                        printf("\n                                                  +------------------------------------------+");
                                                        printf("\n                                                  |                                          |");
                                                        printf("\n                                                  |      Confirma??o de senha incorreta      |");
                                                        printf("\n                                                  |                                          |");
                                                        printf("\n                                                  |       #Confirme novamente a senha#       |");
                                                        printf("\n                                                  |                                          |");
                                                        printf("\n                                                  +------------------------------------------+");
                                                        printf("\n                                                  |     No m?nimo 8 d?gitos e no m?ximo 40   |");
                                                        printf("\n                                                  +------------------------------------------+");
                                                        printf("\n                                                  |//////////////////////////////////////////|");
                                                        printf("\n                                                  |         S? ser?o aceitos n?meros!!       |");
                                                        printf("\n                                                  |//////////////////////////////////////////|");
                                                        printf("\n                                                  +------------------------------------------+");
                                                }
                                        }
                                }
                        }while(validac==0);

                        srand(time(0));
                        for (i=0; i<6; i++){

                            //Gera??o de 6 d?gitos, para formar um c?digo de seguran?a.
                            codverificador[i]= rand() % 10;
                          }
                            system("cls");
                            printf("\n                                                  +------------------------------------------+");
                            printf("\n                                                  |                                          |");
                            printf("\n                                                  |           CODIGO DE VALIDA??O            |");
                            printf("\n                                                  |                                          |");
                            printf("\n                                                  +------------------------------------------+");
                            printf("\n                                                  |          Seu codigo ? --> ");
                            for(i=0;i<6;i++){
                                printf("%d", codverificador[i]);
                            }
                            printf("         |");
                            printf("\n                                                  +------------------------------------------+");
                            printf("\n                                                  |//////////////////////////////////////////|");
                            printf("\n                                                  |          Guarde-o com seguran?a!!        |");
                            printf("\n                                                  |//////////////////////////////////////////|");
                            printf("\n                                                  +------------------------------------------+");
                            char passe;
                            printf("\n\n                                                  +------------------------------------------+");
                            printf("\n                                                      Aperte qualquer tecla para continuar  ");
                            passe=getch();

                            }

                            //RELATORIO DE CADASTRO
                            system("cls");
                            printf("\n                                                  +-------------------------------------------+");
                            printf("\n                                                  |////////|                         |////////|");
                            printf("\n                                                  |////////| CONFIRMA??O DE CADASTRO |////////|");
                            printf("\n                                                  |////////|                         |////////|");
                            printf("\n                                                  +-------------------------------------------+");
                            printf("\n                                                  |                                           |");
                            printf("\n                                                  | 1-CPF--> %12s                               ",cpf);
                            printf("\n                                                  |                                           |");
                            printf("\n                                                  +-------------------------------------------+");
                            printf("\n                                                  |                                           |");
                            printf("\n                                                  | 2-Senha--> %hs                               ",senha);
                            printf("\n                                                  |                                           |");
                            printf("\n                                                  +-------------------------------------------+");
                            printf("\n                                                  +-------------------------------------------+");
                            printf("\n                                                  |                                           |");
                            printf("\n                                                  | 3-Data de nascimento--> %2d \\ %2d \\ %4d   ",diaX,mesX,anoX);
                            printf("\n                                                  |                                           |");
                            printf("\n                                                  +-------------------------------------------+");
                            printf("\n                                                  +-------------------------------------------+");
                            printf("\n                                                  |                                           |");
                            printf("\n                                                  | 4-Codigo de Seguran?a--> ");
                            for(i=0;i<6;i++){
                                printf("%d", codverificador[i]);
                            }
                            printf("           ");
                            printf("\n                                                  |                                           |");
                            printf("\n                                                  +-------------------------------------------+");

                            printf(" \n                                                 +--------------------------------------------+");
                            printf(" \n                                                 |                                            |");
                            printf(" \n                                                 |        Confirma os dados inseridos ?       |");
                            printf(" \n                                                 |                                            |");
                            printf(" \n                                                 |--------------------------------------------|");
                            printf(" \n                                                 |      SIM-1    |     OU      |    N?O-2     |");
                            printf(" \n                                                 +--------------------------------------------+");


                            printf("\n\n                                                  +-----------------------------------------+");
                            printf("\n                                                                  -->  ");
                            fflush(stdin);
                            respost=getch();
                            printf("%c\n",respost);
                            printf("                                                  +-----------------------------------------+");

                            //Tratamento de erro sim/n?o
                            if((respost!='1')&&(respost!='2')){
                                do{

                                    printf("\n\n\n\n                                               +-----------------------------------------------+");
                                    printf("\n                                                  Entrada inv?lida, digite novamente 1 ou 2!\n");
                                    printf("\n                                                                 -->  ");
                                    fflush(stdin);
                                    respost=getch();
                                    printf("%c\n",respost);
                                    printf("                                               +-----------------------------------------------+");

                                    }while((respost!='1')&&(respost!='2'));
                            }
                                validarTotal=0;
                            if(respost=='2'){
                                validarTotal=10;
                                system("cls");
                                printf("\n                                                  +-------------------------------------------+");
                                printf("\n                                                  |////////|                         |////////|");
                                printf("\n                                                  |////////| CONFIRMA??O DE CADASTRO |////////|");
                                printf("\n                                                  |////////|                         |////////|");
                                printf("\n                                                  +-------------------------------------------+");
                                printf("\n                                                  |                                           |");
                                printf("\n                                                  | CPF--> %12s                                ",cpf);
                                printf("\n                                                  |                                           |");
                                printf("\n                                                  +-------------------------------------------+");
                                printf("\n                                                  |                                           |");
                                printf("\n                                                  | Senha--> %hs                               ",senha);
                                printf("\n                                                  |                                           |");
                                printf("\n                                                  +-------------------------------------------+");
                                printf("\n                                                  +-------------------------------------------+");
                                printf("\n                                                  |                                           |");
                                printf("\n                                                  | Data de nascimento--> %2d \\ %2d \\ %4d    ",diaX,mesX,anoX);
                                printf("\n                                                  |                                           |");
                                printf("\n                                                  +-------------------------------------------+");
                                printf("\n                                                  +-------------------------------------------+");
                                printf("\n                                                  |                                           |");
                                printf("\n                                                  | Codigo de Seguran?a--> ");
                                for(i=0;i<6;i++){
                                    printf("%d", codverificador[i]);
                                }
                                printf("             ");
                                printf("\n                                                  |                                           |");
                                printf("\n                                                  +-------------------------------------------+");

                                printf(" \n                                              +----------------------------------------------------+");
                                printf(" \n                                              |                                                    |");
                                printf(" \n                                              |           Qual informa??o deseja alterar ?         |");
                                printf(" \n                                              |                                                    |");
                                printf(" \n                                              |----------------------------------------------------|");
                                printf(" \n                                              |   CPF-1    |     Data de Nascimento-2   | Senha-3  |");
                                printf(" \n                                              +----------------------------------------------------+");


                                printf("\n\n                                                  +-----------------------------------------+");
                                printf("\n                                                                  -->  ");
                                fflush(stdin);
                                respost=getch();
                                printf("%c\n",respost);
                                printf("                                                  +-----------------------------------------+");

                                //Tratamento de erro sim/n?o
                                if((respost!='1')&&(respost!='2')&&(respost!='3')){
                                    do{

                                        printf("\n\n\n\n                                               +-----------------------------------------------+");
                                        printf("\n                                                  Entrada inv?lida, digite novamente 1 ou 2 ou 3!\n");
                                        printf("\n                                                                 -->  ");
                                        fflush(stdin);
                                        respost=getch();
                                        printf("%c\n",respost);
                                        printf("                                               +-----------------------------------------------+");

                                        }while((respost!='1')&&(respost!='2')&&(respost!='3'));
                                }

                            switch (respost){
                                case '1':
                                    bandeiracpf=0;

                                break;
                                case '2':
                                    bandeiradata=0;
                                break;
                                case '3':
                                    bandeirasenha=0;
                                break;
                                default:
                                break;
                                }

                            }
       }while(validarTotal==10);

        system("cls");
        printf(" \n                                                  +-----------------------------------------+");
        printf(" \n                                                  |/////////////////////////////////////////|");
        printf(" \n                                                  +-----------------------------------------+");
        printf(" \n                                                  |                                         |");
        printf(" \n                                                  |  Obrigado por se cadastrar na Plantech  |");
        printf(" \n                                                  |                                         |");
        printf(" \n                                                  |-----------------------------------------|");
        printf(" \n                                                  |/////////////////////////////////////////|");
        printf(" \n                                                  +-----------------------------------------+\n\n\n");



        printf("\n                                         /$$$$$$$  /$$                       /$$                         /$$");
        printf("\n                                        | $$__  $$| $$                      | $$                        | $$");
        printf("\n                                        | $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
        printf("\n                                        | $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
        printf("\n                                        | $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
        printf("\n                                        | $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
        printf("\n                                        | $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
        printf("\n                                        |__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");




       }

        //Caso 2 , subgrupo = Michel Oliveira da Silva e Tiago Balta.
        if(tipo=='2'){

                   system("cls");
                    printf(" \n                                                  +-----------------------------------------------+");
                    printf(" \n                                                  |///////////////////////////////////////////////|");
                    printf(" \n                                                  +-----------------------------------------------+");
                    printf(" \n                                                  |                                               |");
                    printf(" \n                                                  |         Area de vendas em constru??o...       |");
                    printf(" \n                                                  |   Departamento respons?vel: Michel Oliveira e |");
                    printf(" \n                                                  |   Tiago Balta.                                |");
                    printf(" \n                                                  |                                               |");
                    printf(" \n                                                  |-----------------------------------------------|");
                    printf(" \n                                                  |///////////////////////////////////////////////|");
                    printf(" \n                                                  +-----------------------------------------------+\n\n\n");






                    printf("\n                                         /$$$$$$$  /$$                       /$$                         /$$");
                    printf("\n                                        | $$__  $$| $$                      | $$                        | $$");
                    printf("\n                                        | $$  \\ $$| $$  /$$$$$$  /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$$| $$$$$$$");
                    printf("\n                                        | $$$$$$$/| $$ |____  $$| $$__  $$|_  $$_/   /$$__  $$ /$$_____/| $$__  $$");
                    printf("\n                                        | $$____/ | $$  /$$$$$$$| $$  \\ $$  | $$    | $$$$$$$$| $$      | $$  \\ $$");
                    printf("\n                                        | $$      | $$ /$$__  $$| $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$");
                    printf("\n                                        | $$      | $$|  $$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$|  $$$$$$$| $$  | $$");
                    printf("\n                                        |__/      |__/ \\_______/|__/  |__/   \\___/   \\_______/ \\_______/|__/  |__/");



        }







    }
















