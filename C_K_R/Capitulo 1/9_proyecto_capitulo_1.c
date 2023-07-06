#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char letra_aleatoria(){
     int numero_aleatorio= rand() %26; //se genera un numero aleatorio entre 0 y 25
     char letra = 'a' + numero_aleatorio; //Convierte el numero en un caracter de el abecedario
     return letra;
}
     
int main(){
    
    
    srand(time(0)); 

    char letra_ganadora=letra_aleatoria();
    char letra_usuario,letra_IA;
    printf("Bienvenido debes intentar adivinar una letra del abecedario compitiendo con la computadora.\n");
   

    do {
        printf("\nEscoge una letra minuscula: ");
        scanf(" %c",&letra_usuario);
        
        letra_IA=letra_aleatoria();

        printf("Escogiste: %c\n",letra_usuario);
        printf("La IA escogio: %c\n",letra_IA);

        //Verificar si alguno acerto o se equivocaron ambos
        if (letra_usuario ==letra_ganadora) {
            printf("Felicidades, es la letra correcta\n");
        }
        else if (letra_IA == letra_ganadora) {
            printf("La IA ha adivinado la letra\n");
        }
        else{
            printf("Ninguno ha adivinado la letra, sigue intentando\n");
          
        }

        printf("\n");
    }  while(letra_usuario != letra_ganadora && letra_IA != letra_ganadora);

    return 0;  

    
}

