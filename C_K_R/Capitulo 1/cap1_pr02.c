/* 
Curso C libro Kernighan $ Ritchie
programa de conversion  Celsius a Fahrenheit

capitulo1,variables,expresiones e iteraciones
*/

#include <stdio.h>
//imprime la tabla C-F para celsius=-10,0, ...,50

main(){
    float celsius,fahr;
    int upper,lower,step;
    
    lower = -10;
    upper = 50;
    step = 10;

    celsius=lower;

    while(celsius <= 50){
       fahr = (5.0/9.0)*(celsius + 32.0);
       printf("%3.0f\t%6.1f\n",celsius,fahr);
       celsius = celsius + step;
    }
}