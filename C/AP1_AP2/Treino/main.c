#include <stdio.h>
#include <stdlib.h>

float freq = 0;
int tip_freq;
float tempo;
float ontime = 0;
float offtime = 0;
int tipo;

void main(){
    switch (tipo)
    {
    case 0:            //respiraçâo = 0
        ontime = 0;
        offtime = 0;
        
        break;

    case 1:           // respiração lenta
        switch (tip_freq)
        {
        case 1:           // Tipo minimo
            freq = 3;
            break;
        case 2:           // Tipo médio
            freq = 4,5;
            break;
        case 3:          // Tipo maximo
            freq = 6;
            break;
        
        default:
            break;
        }  
        ontime = 60/freq;
        ontime = ontime / 4;
        offtime = ontime*3;
        ontime = offtime*1000;
        offtime = ontime*1000;
        break;

    case 2:           // respiração normal
        switch (tip_freq)
        {
        case 1:           // Tipo minimo
            freq = 10;
            break;
        case 2:           // Tipo médio
            freq = 12;
            break;
        case 3:          // Tipo maximo
            freq = 14;
            break;
        
        default:
            break;
        }
        ontime = 60/freq;
        ontime = ontime / 3;
        offtime = ontime*2;
        ontime = offtime*1000;
        offtime = ontime*1000;
        break;

    case 3:           // respiração rapida 
        switch (tip_freq)
        {
        case 1:           // Tipo minimo
            freq = 30;
            break;
        case 2:           // Tipo médio
            freq = 40;
            break;
        case 3:          // Tipo maximo
            freq = 50;
            break;
        
        default:
            break;
        }
        ontime = 60/freq;
        offtime = ontime / 2;
        ontime = ontime / 2;
        ontime = offtime*1000;
        offtime = ontime*1000;
        break;
    
    default:
        break;
    }
}