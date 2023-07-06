/* 
Curso C libro Kernighan $ Ritchie
programa de conversion Fahrenheit a Celsius

capitulo1,variables,expresiones e iteraciones
*/

#include <stdio.h>
//imprime la tabla F-C para fahr=0,20, ...,300

main(){
    int fahr;
    

    for (fahr = 300; fahr>=0;fahr = fahr-20)
    {
        printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
    }
    


   
}