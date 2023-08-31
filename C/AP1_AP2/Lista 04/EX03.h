#ifndef EX03_H_INCLUDE
#define EX03_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>

int x,y;
int total=0;

    
         int somar(){
            total = x + y;
            return total;
         }
        
        int subtrair(){
            total = x - y;
            return total;
        }

 
    
        int multiplicar(){        
            total = x * y;
            return total;
        }

      
    
        float dividir(){
            total = x / y;
            return total;
        }

    

#endif