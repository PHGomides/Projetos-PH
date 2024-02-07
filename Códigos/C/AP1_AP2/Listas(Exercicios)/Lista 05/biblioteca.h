#ifndef biblioteca_H_INCLUDE
#define biblioteca_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>

int  ParImpar(int n){
  if( n % 2 == 0){
    return 1;
  }else{
    return 0;
  }
    
}

int Mdc(int a, int b){
int maior,menor;
int r;
if(a>b){
    maior=a;
    menor=b;
}else{
    maior=b;
    menor=a;
}
do{

    r = maior % menor;

    if(r!=0){
        maior = menor;
        menor = r;

    }

}while(r!=0);

return menor;
}

int Multiplica(int fator1, int fator2){
  int res;
  int soma=0;
  int i=0;
  printf("\n\n %d x %d = ",fator1,fator2);
  res = fator1*fator2; 
  while(res != soma){
      if(i!=0){
      printf(" + ");
      }
      i++;
      soma = fator1 + soma;
      printf(" %d ",fator1);
      

}
printf(" = %d\n\n",soma);
return soma;
}

int fatorial(int x){
  int i=0;
  for(i=x-1; i>=1 ; i--){
    x = i * x;
  }
  return x;
}

int combina(int n, int p){
  int c;
  int sub;
  sub = n - p;
  c = fatorial(n) / (fatorial(p)*fatorial(sub));
  return c;
}

float calculataxa(int x){
  float total=2;
  if (x>=24){
    return 10;
  }
  else if(x>3){
    x = x-3;
  }else{
    return total;
  }
  
  total = x*0.5 + total;

  return total;
}



#endif