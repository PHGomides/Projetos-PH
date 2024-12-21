
#ifndef biblioteca_H_INCLUDE
#define biblioteca_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>


 void ex02(int *a, int *b, int *c){
  
  int maior , menor, meio;


  if( (*a > *b) && (*a > *c)){
    maior=*a;
      }else if ((*a>=*b) || (*a>=*c)){
        meio=*a;
        }else if((*a == *b) || (*a == *c) ){
          menor=*a;
        }else{
          menor=*a;
        }

  if( (*b > *a) && (*b > *c)){
    maior=*b;
      }else if ((*b>*a) || (*b>*c)){
        meio=*b;
        }else if((*b == *a) || (*b == *c) ){
          menor=*b;
        }else{
          menor=*b;
        }
        
        

  if( (*c > *a) && (*c > *b)){
    maior=*c;
      }else if ((*c>*a) || (*c>*b)){
        meio=*c;
        }else if((*c == *a) || (*c == *b) ){
          menor=*c;
        }else{
          menor=*c;
        }

  if((*a==*b) && (*b==*c)){
    maior=*a;
    meio=*a;
    menor=*a;
  }
  *a=maior;
  *b=meio;
  *c=menor;

}

 void ex03(int *a, int *b){
  (*a)--;
  (*b)++;
 }

 void Elementos(int *v){
  for ( i = 0; i < 8; i++){
    if((v[i] > 15) && (v[i]<20)){
        v[i] = 0;
    }
  }
 }

 void criptografia(char *p, char v, int tam){
    for(i=0; i < tam ; i++){
        if((p[i] == 'a') || (p[i] == 'A') || (p[i] == 'e') || (p[i] == 'E') || (p[i] == 'i') || (p[i] == 'I') || (p[i] == 'o') || (p[i] == 'O') || (p[i] == 'u') || ( p[i] == 'U')){
          p[i] = v;
        }

    }
 }

  void ex06(char *p, int a){
    int x;
    for(i=0; i < a ; i++){
       x=p[i];
      if((x >= 97) && (x <= 122)){
        x -= 32;
        p[i] = x;
      }
    }
 }

 void ex07(float *a){

  float maior, meio, menor;
  maior = 0;
  meio = 0;
  menor = 0;
  for ( i = 0; i < 3; i++){
    if (a[i] > maior){
      maior = a[i];
    }else if ((a[i] < maior) && (a[i] > meio)){
      meio = a[i];
    }else{
      menor = a[i];
    }
  }
  
  a[0] = menor;
  a[1] = meio;
  a[2] = maior;

 }

  void ex08(int m[][3]){
    int a , b;
    for (a=0; a < 2 ; a++){
      for(b=0 ; b < 3 ; b++){
        if((m[a][b] % 2) == 0){
          m[a][b]= 1000;        
        }
      }
    }   
  }

  void ex09(ALUNO *x){
    printf("\n\n Digite sua nota 01: ");
    scanf("%f", &x->nota1);
    printf("\n Digite sua nota 02: ");
    scanf("%f", &x->nota2);
    printf("\n Digite sua nota 03: ");
    scanf("%f", &x->nota3);
    x-> media = (x->nota1 + x->nota2 + x->nota3) / 3;
  }



#endif