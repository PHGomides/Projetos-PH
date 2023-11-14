#ifndef EX04_H_INCLUDE
#define EX04_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
int n=0;

int EX04(){
    int fat;
    for(fat = 1; n > 1; n--){
        fat = fat * n;
    }     
    return fat;
}

#endif