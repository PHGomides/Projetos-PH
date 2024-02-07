#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if (n <= 2){ 
        return 1; 
        }else{
            return  fib(n-1) + fib(n-2); 
        }
}

int main(){
    int n;
    printf("\n\n Digite N : ");
    scanf("%d",&n);
    printf("\n\n O Resultado = %d", fib(n));
    return 0 ;
}
