#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASCII 128


//Prototipo de funciones
void encriptado(char frase[ASCII],int numero);
void desencriptado(char frase[ASCII],int numero);
//Funcion de desencriptado

void desencriptado(char frase[ASCII],int numero){
    int i=0;
    while(frase[i]!='\0'&&frase[i]!='\n')
    {
        frase[i]= frase[i] - numero;
        i++;

    }
    printf("\nLa frase desencriptada es : \n%s\n",frase);
}


//Funcion de encriptado
void encriptado(char frase[ASCII],int numero){

    int i=0;
    char letter;
    while(frase[i]!='\0'&&frase[i]!='\n'){
            frase[i]= frase[i] + numero;
            i++;

    }
    printf("\nLa frase encriptada es :\n%s\n",frase);
}
//Función principal
main(){
    //Variables
    int x;
    char texto[ASCII];
    //Mensaje para el usuario
    printf("El metodo cesar consiste en encriptar una frase, usamos los caracteres ASCII para encriptar.\n ");
    printf("\nPor ejemplo ABCDFEGHIJKLMNOPQRSTUVWXYZ, si movemos 3 letras, su mensaje encriptado seria\n");
    printf("DEFGIHJKLMNOPRSTUVWXYZABC esto claramente en el alfabeto ingles.\n");
    //Inicializacion
    printf("\nIntroduce la frase : ");
    scanf("%128[^\n]",texto);
    //Obtenemos la frase
    while(getchar()!='\n');
    //Pedimos el numero a mover el abecedario con el metodo cesar, originalmente es 3
    printf("\nAhora el numero de veces a mover: ");
    scanf("%d",&x);
    //Obtenemos el numero
    while(getchar()!='\n');
    //Ahora llamamos a la funcion de encriptado
    encriptado(texto,x);
    getchar();
    //Hacemos lo mismo con la funcion de desencriptado
    desencriptado(texto,x);
    getchar();
    //Terminamos el programa
    return 0;

}



