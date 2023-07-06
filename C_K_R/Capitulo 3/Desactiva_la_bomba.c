/*El desafio de el capitulo 3 consiste en estos requisitos
1-Se generará un número aleatorio de 1 a 100
2-Se generarán 5 números aleatorios de 1 a 10
3-El usuario tiene que introducir la solución usando esos 5 números y las operaciones de suma, resta y multiplicación
4-Se debe comprobar la solución final.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "tinyexpr.h"
#include "tinyexpr.c"



int main(){
    srand(time(NULL));

    //Inicializacion
    int i;
    int rnum2[5];
    int rnum = (rand() % 100) + 1;
   
    //Mensaje al usuario, indicaciones y explicaciones
    printf("\nSe ha generado un numero aleatorio entre 1 y 100.\n");
    printf("\nSe han generado 5 numeros aleatorios entre 1 y 10.\n");
    printf("\nDebes usar los 5 numeros aleatorios para hacer operaciones aritmeticas(suma,resta,multiplicacion)\n");
    printf("\nEl numero debe ser igual al primer numero generado\n");

    //imprimo por pantalla el numero antes generado, y genero 5 numeros aleatorios
    printf("\nTu numero aleatorio es: %d\n",rnum);

    printf("\nLos numeros aleatorios son:\n");
    for (i = 0; i < 5; i++) {
        rnum2[i] = (rand() % 10) + 1;
        printf("%d ", rnum2[i]);
    }
    printf("\n");
    
    //Tiempo para desactivar la bomba

    int tiempo_restante = 300;
    printf("\nTienes %d segundos para desactivar la bomba.\n", tiempo_restante);
    
    // Obtengo la operacion de el usuario
    char cadena[100];
    printf("\nIntroduce la operacion aritmetica con los 5 numeros aleatorios: \n");
    scanf("%s",cadena);

    

    //Muestro el resultado por pantalla, gracias a la libreria tinyexpr
    int resultado = te_interp(cadena,0);

    printf("%s es: %d",cadena,resultado);

    // Comprobación de que el resultado es correcto.

    if (resultado == rnum) {
        printf("Has desactivado la bomba, enhorabuena\n");
    } 
    if(resultado!=rnum){
        printf("\nEl numero es incorrecto, comenzando detonacion....\n");
    }

    return 0;

    
}


//No use la funcion clock(), porque no entendi bien en donde implementarla.
//Supongo que se debe a problemas con mi logica de programacion, pero no podia poner la cuenta regresiva.
//Y que el usuario realizara la operacion aritmetica a la vez, lei algo de hacer hilos o (threads)
//Pero eso ya supera mi conocimiento, se supone que en el tiempo deberia estar la funcion de la cuenta regresiva
