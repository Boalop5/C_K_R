#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

// Estructuras
typedef struct person
{
    char name[MAXWORD];
    char hobby[MAXWORD];
    struct person *left;
    struct person *right;
} Personnode;

typedef struct category
{
    char *name;
    char **hobbies;
    int num_hobbies;
    Personnode *root;
} Category;

// Prototipos
Personnode *addperson(char *, char *);
void insertperson(Personnode **, char *, char *);
void insertp_category(Category *, char *, char *);
void personprint(Personnode *);
void freetree(Personnode *);

// Variables constantes
Category categories[] = {
    {"Deportes", (char *[]){"futbolista", "basketbolista", "tenista"}, 3, NULL},
    {"Arte", (char *[]){"pintar", "escribir", "bailar"}, 3, NULL},
    {"Ejercicio", (char *[]){"correr", "natacion", "yoga"}, 3, NULL},
    {"Manualidades", (char *[]){"coser", "alfareria", "origami"}, 3, NULL},
    {"Recreativo", (char *[]){"videojuegos", "peliculas", "viajar"}, 3, NULL},
    {"Ocio", (char *[]){"musica", "leer", "cocinar"}, 3, NULL}};

int n_categories = sizeof(categories) / sizeof(Category);

int main()
{
    char name[MAXWORD];
    char hobby[MAXWORD];
    char answer;

    // Main loop
    do
    {
        printf("\nBienvenido, estamos haciendo un registro, ingresa una persona y su aficion\n");
        printf("nuestra base de datos es escasa asi que tu aficion puede no existir\n");
        printf("\nIngrese el nombre de una persona: ");
        scanf("%s", name);

        int hobby_category_index = -1;
        do
        {   if (hobby[0] != '\t')
            printf("\nIngrese la aficion de la persona (en minusculas): ");
            scanf("%s", hobby);

            // Verificar la categoría de la afición
            for (int i = 0; i < n_categories; i++)
            {
                for (int j = 0; j < categories[i].num_hobbies; j++)
                {
                    if (strcmp(hobby, categories[i].hobbies[j]) == 0)
                    {
                        hobby_category_index = i;
                        break;
                    }
                }
                if (hobby_category_index != -1)
                    break;
            }

            if (hobby_category_index == -1|| hobby[0] == '\t')
                printf("La aficion ingresada no coincide con ninguna categoria, intenta de nuevo\n");

        } while (hobby_category_index == -1 );

        insertp_category(&categories[hobby_category_index], name, hobby);

        printf("Desea agregar otra persona? (s/n): \n");
        scanf(" %c", &answer);
    } while (answer == 's' || answer == 'S');

    // Imprimir las personas por categoría
    for (int i = 0; i < n_categories; i++)
    {
        printf("\nCategoria: %s\n", categories[i].name);
        personprint(categories[i].root);
    }

    return 0;
}

// Funciones

Personnode *addperson(char *name, char *hobby)
{
    Personnode *newp = (Personnode *)malloc(sizeof(Personnode));
    strcpy(newp->name, name);
    strcpy(newp->hobby, hobby);
    newp->left = NULL;
    newp->right = NULL;

    return newp;
}

void insertperson(Personnode **n, char *name, char *hobby)
{
    if (*n == NULL)
    {
        *n = addperson(name, hobby);
    }
    else
    {
        int cmp = strcmp(name, (*n)->name);
        if (cmp < 0)
        {
            insertperson(&((*n)->left), name, hobby);
        }
        else if (cmp > 0)
        {
            insertperson(&((*n)->right), name, hobby);
        }
        else
        {
            // Si la persona ya existe, se ignora la inserción
            printf("La persona %s ya existe, nuestra base de datos solo permite personas diferentes por aficion\n", name);
        }
    }
}

void insertp_category(Category *c, char *name, char *hobby)
{
    insertperson(&(c->root), name, hobby);
}

void personprint(Personnode *node)
{
    if (node != NULL)
    {
        personprint(node->left);
        printf("\nNombre: %s, Aficion: %s\n", node->name, node->hobby);
        personprint(node->right);
    }
}

void freetree(Personnode *node)
{
    if (node != NULL)
    {
        freetree(node->left);
        freetree(node->right);
        free(node);
    }
}

//Solo me falto poder agregar varias personas en la misma categoria.