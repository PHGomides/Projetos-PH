#ifndef EX02_H_INCLUDE
#define EX02_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sub02=0;

int EX02(){
    srand(time(NULL));
    sub02 = -10 + ( rand() % 20 );
    printf("\n\n Valor gerado da variavel Global: %d",sub02);
    if (sub02>=0){
        return 1;
    }else{
        return 0;
    }
    
}

#endif