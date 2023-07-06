/* 
Curso C libro Kernighan $ Ritchie
programa flujos de entrada y salida

capitulo1,variables,expresiones, iteraciones y decisiones
herramientas:getchar, putchar
*/

#include <stdio.h>
//copia la entrada y salida

main(){
    int c;

    c=getchar();
    while(c!=EOF){
       printf("%c",c);
       c=getchar();
    }
    
}