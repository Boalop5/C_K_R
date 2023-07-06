/*
    CURSO C LIBRO KERNIGHAN & RITCHIE
    lectura de un fichero

    lectura de ficheros y escritura en el terminal
    herramientas: punteros y i/o de ficheros
*/
#include <stdio.h>

void filecopy(FILE *, FILE *);

int main(int argc, int *argv[])
{
    FILE *fp;

    if(argc==1)
       filecopy(stdin,stdout);
    else
       while(--argc>0)
            if((fp=fopen(*++argv,"r"))==NULL){
                printf("cat: no se puede abrir %s",*argv);
                return 1; 
            }else{
                filecopy(fp,stdout);
                fclose(fp);
            }
           
       

        return 0;

}

/*Filecopy: copia un puntero a otro*/

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c=getc(ifp)) != EOF)
    {
        putc(c,ofp);
    }
    

}