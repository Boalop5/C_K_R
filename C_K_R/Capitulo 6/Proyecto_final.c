/*
    CURSO C LIBRO KERNIGHAN & RITCHIE
    Estructura de datos

    Proyecto final,base de datos de software y tecnologia
    herramientas: todo lo visto en el curso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef struct {
    char *name;
    char *type;
    char *url;
} Resource;


//Demasiados prototipos
void read_file(Resource *resources, int *n_resources, const char *inputfile);
void add_resource(Resource *resources, int *n_resources);
void type_resources(Resource *resources, int n_resources);
void append_to_file(const char *inputfile, Resource *resources, int n_resources);
void search_resources(Resource *resources, int n_resources);
void menu(Resource *resources, int *n_resources, const char *inputfile);
void free_resources(Resource *resources, int n_resources);
void print_resources(Resource *resources, int n_resources);


int main() {
    char inputfile[100] = "Recursos.txt";
    Resource resources[100];
    int n_resources = 0;
    
    printf("Bienvenido al gestor de recursos\n");
    printf("\nSi agrega algun recurso, recuerde guardarlo, no se guarda automaticamente.\n");

    read_file(resources, &n_resources, inputfile);
    menu(resources, &n_resources, inputfile);
    append_to_file(inputfile, resources, n_resources);
    free_resources(resources, n_resources);
}

void menu(Resource *resources, int *n_resources, const char *inputfile) {
    int choice = 0;
    while (choice != 5) {
        printf("\n------ Menu ------\n");
        printf("1. Mostrar recursos\n");
        printf("2. Agregar recurso\n");
        printf("3. Buscar recursos\n");
        printf("4. Guardar recursos\n");
        printf("5. Salir\n");
        printf("------------------\n");
        printf("Ingrese su opcion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print_resources(resources, *n_resources);
                break;
            case 2:
                add_resource(resources, n_resources);
                type_resources(resources, *n_resources);
                break;
            case 3:
                search_resources(resources, *n_resources);
                break;
            case 4:
                append_to_file(inputfile, resources, *n_resources);
                break;
            case 5:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpcion invalida, intente de nuevo\n");
                break;
        }
    }
}

void read_file(Resource *resources, int *n_resources, const char *inputfile) {
    FILE *file = fopen(inputfile, "r");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo: %s\n", inputfile);
        exit(1);
    }

    char line[MAX_LENGTH];
    int i = 0;

    // Leo el archivo línea por línea con la funcion fgets.
    while (fgets(line, sizeof(line), file) != NULL) {
        // Elimino el carácter de la nueva línea al final de la línea
        line[strcspn(line, "\n")] = '\0';

      
        if (strncmp(line, "Name:", 5) == 0) {
            resources[i].name = strdup(line + 6);
        }

      
        if (strncmp(line, "Type:", 5) == 0) {
            resources[i].type = strdup(line + 6);
        }

        
        if (strncmp(line, "URL:", 4) == 0) {
            resources[i].url = strdup(line + 5);

           
            i++;
        }
    }

    *n_resources = i;

    fclose(file);
}

// El usuario debe añadir recursos 
void add_resource(Resource *resources, int *n_resources) {
    if (*n_resources >= 100) {
        printf("No se pueden agregar mas recursos, se ha alcanzado el limite.\n");
        return;
    }

    Resource new_resource;

    // Interacción con el usuario para obtener los detalles del recurso
    printf("Ingrese el nombre del recurso: ");
    scanf("%s", new_resource.name);
    printf("Ingrese el tipo del recurso: ");
    scanf("%s", new_resource.type);
    printf("Ingrese la URL del recurso: ");
    scanf("%s", new_resource.url);

    // Verifico si el recurso ya existe
    for (int i = 0; i < *n_resources; i++) {
        if (strcmp(resources[i].name, new_resource.name) == 0) {
            printf("El recurso ya existe, por favor agregue algo nuevo.\n");
            return;
        }
    }

    // Añado el nuevo recurso al arreglo
    resources[*n_resources] = new_resource;
    (*n_resources)++;
}

//Esta funcion no es necesaria como tal, pero la añadi para cuando ingresara otros recursos por tipo.
void type_resources(Resource *resources, int n_resources) {
    int i, j;
    Resource temp;
    for (i = 0; i < n_resources - 1; i++) {
        for (j = 0; j < n_resources - i - 1; j++) {
            if (strcmp(resources[j].type, resources[j + 1].type) > 0) {
                temp = resources[j];
                resources[j] = resources[j + 1];
                resources[j + 1] = temp;
            }
        }
    }
}

// Añado  la informacion al fichero Recursos.txt y evito los recursos duplicados
void append_to_file(const char *inputfile, Resource *resources, int n_resources) {
    FILE *file = fopen(inputfile, "r");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo: %s\n", inputfile);
        exit(1);
    }

    // Verificar duplicados antes de agregar
    for (int i = 0; i < n_resources; i++) {
        Resource currentresource = resources[i];
        int duplicatefound = 0;

        char line[MAX_LENGTH];
        while (fgets(line, sizeof(line), file) != NULL) {
            // Elimino el carácter de la nueva línea al final de la línea
            line[strcspn(line, "\n")] = '\0';

            // Comparar cada línea del archivo con el recurso actual
            if (strcmp(line, currentresource.name) == 0) {
                duplicatefound = 1;
                break;
            }
        }

        // Si no se encontró un recurso duplicado, agrego el recurso al archivo
        if (!duplicatefound) {
            fprintf(file, "%s\n", currentresource.name);
        }

        // Regreso al inicio del archivo para la próxima comparación
        rewind(file);
    }

    fclose(file);
}

//Liberacion de la  memoria
void free_resources(Resource *resources, int n_resources) {
    for (int i = 0; i < n_resources; i++) {
        free(resources[i].name);
        free(resources[i].type);
        free(resources[i].url);
    }
}

//Busco un recurso en especifico
void search_resources(Resource *resources, int n_resources) {
    char keyword[MAX_LENGTH];
    printf("Ingrese el nombre del recurso para la busqueda: ");
    scanf("%s", keyword);

    int found = 0;
    for (int i = 0; i < n_resources; i++) {
        if (strcmp(resources[i].name, keyword) == 0) {
            printf("Recurso encontrado:\n");
            printf(" Nombre: %s\n", resources[i].name);
            printf(" Tipo: %s\n", resources[i].type);
            printf(" URL: %s\n", resources[i].url);
            printf("------------------\n");
            found = 1;
            break; 
        }
    }

    if (found == 0) {
        printf("No se encontro el recurso especificado.\n");
    }
}

//Muestro al usuario los recursos
void print_resources(Resource *resources, int n_resources) {
    printf("Recursos:\n");
    for (int i = 0; i < n_resources; i++) {
        printf(" Nombre: %s\n", resources[i].name);
        printf(" Tipo: %s\n", resources[i].type);
        printf(" URL: %s\n", resources[i].url);
        printf("------------------\n");
    }
}

