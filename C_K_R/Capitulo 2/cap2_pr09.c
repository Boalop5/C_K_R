#include <stdio.h>
#define MAXLINE 1000 /* tamaño máximo de la línea de entrada */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* Imprime la línea de entrada más larga */
 main() {
    int len; /* longitud de la línea actual */
    int max; /* máxima longitud vista hasta la fecha */
    char line[MAXLINE]; /* línea actual */
    char longest[MAXLINE]; /* línea más larga */

    max = 0;
    while ((len = getline2(line, MAXLINE)) > 0) {
        int i = 0;
        while (line[i] == ' ' || line[i] == '\t') {
            i++;
        }
        len -= i; // Se restan los espacios iniciales
        if (len > max) {
            max = len;
            copy(longest, line + i); // Se copia la linea sin los espacios iniciales
        }
        if (max > 0) {
            printf("%s", longest);
        }
    }

    return 0;
}

/* getline2: lee una línea s, regresa su longitud */
int getline2(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copia from hacia to */
void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}