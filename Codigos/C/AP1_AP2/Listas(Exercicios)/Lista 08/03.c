#include <stdio.h>
#include <stdlib.h>

int MDC(int x, int n){
    if (n == 0){
        
        return x; 
        
        }else{

            return MDC(n, x%n); 
        }
}

int main(){
    int x, n;
    printf("\n\n Digite X : ");
    scanf("%d",&x);
    printf("\n\n Digite N : ");
    scanf("%d",&n);
    printf("\n\n O MDC de %d e %d = %d", x, n, MDC(x,n));
}
