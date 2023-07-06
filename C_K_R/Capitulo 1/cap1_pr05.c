/* 
Curso C libro Kernighan $ Ritchie
programa flujos de entrada y salida

capitulo1,variables,expresiones, iteraciones y decisiones
modificaciones: contar lineas, sentencia if
*/

#include <stdio.h>
//copia la entrada y salida

main(){
    int c,nl,nt,nv;
    
    nl=0;
    nt=0;
    nv=0;
    while((c=getchar())!=EOF)
    {
       if (c=='\n')
           ++nl;
       if (c=='\t')
           ++nt;
       if (c==' ')    
           ++nv;
    }      
    printf("%d %d %d\n",nl,nv,nt);
   
    
}