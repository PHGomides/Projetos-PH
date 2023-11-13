#ifndef EX06_H_INCLUDE
#define EX06_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
float nota1=0,nota2=0,nota3=0;
int tipo=0;
float resultado=0;

float EX06(){
    switch (tipo)
    {
    case 1:
        resultado = (nota1 + nota2 + nota3) / 3;
        break;
    
    case 2:
        resultado = ((nota1*5) + (nota2*3) + (nota3*2)) / 10;
        break;

    default:
        break;
    }
    return resultado;
}

#endif