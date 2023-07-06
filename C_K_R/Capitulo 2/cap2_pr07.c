/*
   CURSO C KERNIGHAN & RITCHIE
   uso de las funciones

   capitulo 2, funciones, parametros
   herramientas: funciones
*/
#include <stdio.h>

int temp(int fahr);

main(){
    int fahr;

    for (fahr = 0; fahr<=300; fahr = fahr +20)
    {
        printf("%3d \n",fahr);
    }
    return fahr;
}

int temp(int fahr){
      return 5 * (fahr-32)/9;
     
}
