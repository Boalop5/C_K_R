/* 
Curso C libro Kernighan $ Ritchie
programa flujos de entrada y salida

capitulo1,variables,expresiones, iteraciones y decisiones
modificaciones: contar caracteres
*/

#include <stdio.h>
//copia la entrada y salida

main(){
    long nc;
    nc=0;
    
    while(getchar()!=EOF)
       ++nc;
      
    
    printf("%ld\n",nc);
    
}