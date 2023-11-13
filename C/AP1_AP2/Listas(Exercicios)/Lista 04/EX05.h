#ifndef EX05_H_INCLUDE
#define EX05_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>

int precoatual = 0 , precoantigo = 0;
int percentualacrescimo = 0;

int EX05(){
    
     percentualacrescimo = (100*precoatual - precoantigo*100)  / precoatual;
     return percentualacrescimo;
}

#endif