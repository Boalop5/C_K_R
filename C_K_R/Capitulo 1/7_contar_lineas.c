/* 
Curso C libro Kernighan $ Ritchie
programa flujos de entrada y salida

capitulo1,variables,expresiones, iteraciones y decisiones
modificaciones: contar lineas, sentencia if
*/

#include <stdio.h>
//copia la entrada y salida

main(){
    int c,nl;
    
    nl=0;
    while((c=getchar())!=EOF)
       if (c=='\n')
           ++nl;
    printf("%d\n",nl);
    
}