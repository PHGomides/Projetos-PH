#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    // Pedro Henrique Gomides Moraes
    
    //Questão 01
    int flag = 10;
    int a, b, c, *p,*q, vet[6];
    int add, sub, mult;
    int *maior, *meio, *menor;
    int maior04, menor04;
    int cont;
    char frase[50], *w;
    float div;
    
    do{
    
        printf("\n\n\nQual questao de 1 ao 6 deseja fazer, digite 0 para finalizar\n->");
        scanf(" %d",&flag);

        switch (flag){
        case 1:
            
            p = &a;
            q = &b;
            printf("Digite 2 valores inteiros:\n");
            scanf("%d",p);
            scanf("%d",q);
            mult = *p * *q;
            div = *p / *q;
            add = *p + *q;
            sub = *p - *q;
            printf("Valores : %d e %d \n\n\nResultados\n\nSoma: %d\nSubtracao: %d\nDivisao: %.2f\nMultiplicacao: %d",*p,*q, add, sub, div, mult);
            break;

        case 2:
        //Questão 02
        printf("\n\n\nDigite 3 valores inteiros:\n");
        
        scanf("%d",&a);

        maior = &a;
        meio = &a;
        menor = &a;

        scanf("%d",&b);
        
        if (*maior < b){
            maior = &b;
        }else if (*menor > b){
            menor = &b;
        }else {
            meio = &b;
        }

        scanf("%d",&c);

        if (*maior < c){
            maior = &c;
        }else if (*menor > c){
            menor = &c;
        }else {
            meio = &c;
        }
        
        printf("\n\nA ordem :\n Maior: %d\nEndereco: %p\nMeio: %d\nEndereco: %p\nMenor: %d\nEndereco: %p",*maior, maior, *meio, meio, *menor, menor);
            break;

        case 3:
            p = &vet[0];
            printf("\n\nDigite 6 numeros:\n");
            for (int i = 0; i < 6; i++){
                scanf("%d",p);
                p++;
            }
            p = &vet[0];
            printf("\n\n Os valores salvos:");
            for (int i = 0; i < 6; i++){
                printf("\n%d seu endereco: %p",*p, p);
                p++;
            }
            
            break;

        case 4:

            p = &vet[0];
            printf("\n\nDigite 3 numeros:\n");
            for (int i = 0; i < 3; i++){
                scanf("%d",p);
                if(i == 0){
                    maior04 = *p;
                    menor04 = *p;
                }
                if(maior04 < *p){
                    maior04 = *p;
                }else if(menor04 > *p){
                    menor04 = *p;
                }
                p++;
            }
            p = &vet[0];
            printf("\n\n Os valores salvos:");
            for (int i = 0; i < 3; i++){
                printf("\n%d seu endereco: %p",*p, p);
                p++;
            }
            printf("\n\nO maior: %d\nO menor: %d",maior04, menor04);

            break;

        case 5:
            w = &frase[0];
            cont = 0;
            printf("\n\n Digite uma frase:");
            fflush(stdin);
            gets(frase);

            for(int i = 0; i < 50 ; i++){

                if(*w == '\0'){
                    break;
                }
                if((*w == ' ')){
                    cont+= 0;
                }else {
                    cont ++;
                }
                w++;
            }
            printf("\n\n O numero de letras : %d",cont);

            break;
        case 6:
            w = &frase[0];
            printf("\n\n Digite uma frase:");
            fflush(stdin);
            gets(frase);

            printf("\n Resultado :\n");
            for(int i = 0; i < 50 ; i++){

                if(*w == '\0'){
                    break;
                }
                if((*w == ' ')){
                    printf("\n");
                }else {
                    printf("%c",*w);
                }
                w++;
            }
            break;
        case 0:

            break;
        default:
            break;
        }
    }while (flag != 0);
}