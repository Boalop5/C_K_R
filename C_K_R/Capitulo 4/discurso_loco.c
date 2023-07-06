#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PALABRAS 1000

//Prototipo de funcion
void generar_frase_aleatoria(char** name, char** adj, char** verb, int num_name, int num_adj, int num_verb);

int main() {
    srand(time(NULL));

    int i;
    int num_name, num_adj, num_verb;
    
    printf("Bienvenido, se generan frases aleatorias de acuerdo a sus elecciones\n");

    //Obtengo los datos de el usuario
    printf("\nIngrese el numero de nombres a escribir: ");
    scanf("%d", &num_name);

    printf("\nIngrese el numero de adjetivos a escribir: ");
    scanf("%d", &num_adj);

    printf("\nIngrese el numero de verbos a escribir: ");
    scanf("%d", &num_verb);

    char** name = (char**)malloc(num_name * sizeof(char*));
    char** adj = (char**)malloc(num_adj * sizeof(char*));
    char** verb = (char**)malloc(num_verb * sizeof(char*));

    printf("\nIngrese los nombres recuerde pulsar enter despues de cada nombre:\n");
    for (i = 0; i < num_name; i++) {
        name[i] = (char*)malloc(MAX_PALABRAS * sizeof(char));
        scanf("%s", name[i]);
    }

    printf("\nIngrese los adjetivos recuerde pulsar enter despues de cada adjetivo:\n");
    for (i = 0; i < num_adj; i++) {
        adj[i] = (char*)malloc(MAX_PALABRAS * sizeof(char));
        scanf("%s", adj[i]);
    }

    printf("\nIngrese los verbos recuerde pulsar enter despues de cada verbo:\n");
    for (i = 0; i < num_verb; i++) {
        verb[i] = (char*)malloc(MAX_PALABRAS * sizeof(char));
        scanf("%s", verb[i]);
    }

    // Genero frases aleatorias
    int num_frases;
    printf("\nIngrese el numero de frases a generar: ");
    scanf("%d", &num_frases);

    printf("Frases generadas:\n");
    for (i = 0; i < num_frases; i++) {
        generar_frase_aleatoria(name, adj, verb, num_name, num_adj, num_verb);
    }

    // Libero la memoria
    for (i = 0; i < num_name; i++) {
        free(name[i]);
    }
    for (i = 0; i < num_adj; i++) {
        free(adj[i]);
    }
    for (i = 0; i < num_verb; i++) {
        free(verb[i]);
    }
    free(name);
    free(adj);
    free(verb);

    return 0;
}

//Funcion
void generar_frase_aleatoria(char** name, char** adj, char** verb, int num_name, int num_adj, int num_verb) {
    int index_name = rand() % num_name;
    int index_adj = rand() % num_adj;
    int index_verb = rand() % num_verb;

    printf("%s %s %s\n", name[index_name], adj[index_adj], verb[index_verb]);
}
    
   
//Esto no es exactamente lo que se pidio, pero la verdad no supe como implementar los apuntadores de arreglos.
//Asi que decidi que sea el usuario el que dictamine el tempo
//Siempre pongo comentarios, disculpe.
    


    
    
    

  
    
    

  

 
    











