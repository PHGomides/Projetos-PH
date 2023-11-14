#include <stdio.h>
#include <stdlib.h>

int POT(int x , int n){
    if (n == 0){
        return 1;

        }else if (n == 1){
            return x;

            }else{
                return x * POT(x, n - 1); 
            }
}


int main(){
    int x, n;
    printf("\n\n Digite X : ");
    scanf("%d",&x);
    printf("\n\n Digite N : ");
    scanf("%d",&n);
    printf("\n\n O resultado de %d ^ %d = %d", x, n, POT(x,n));
}
