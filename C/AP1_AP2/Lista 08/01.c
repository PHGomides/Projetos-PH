#include <stdio.h>
#include <stdlib.h>

int soma(int x){
    if (x == 0){
        return 0;
    }else{
        return x + soma(x - 1); 
    }
}

int main(){
    int n;
    printf("\n\n Digite n :");
    scanf("%d",&n);
    printf("\n\n A soma de 0 a %d = %d",n , soma(n));
}
