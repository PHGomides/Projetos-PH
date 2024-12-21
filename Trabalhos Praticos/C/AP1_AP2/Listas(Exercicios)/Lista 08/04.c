#include <stdio.h>
#include <stdlib.h>

int fat(int n){
    if (n == 0){
        
        return 1; 
        
        }else{
            return  n * fat(n-1); 
        }
}

int main(){
    int n;
    float  result;
    printf("\n\n Digite N : ");
    scanf("%d",&n);
    result = fat(2*n) / fat(n);
    printf("\n\n O Resultado = %.2f", result);
    return 0 ;
}
