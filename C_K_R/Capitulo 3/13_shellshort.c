/* CURSO KERNIGHAN & RITCHIE
   ordenacion ascendente

   ordenacion de un array de forma ascendente 
   herramienta: funciones, for

*/

#include <stdio.h>

void shellshort(int v[], int n);

int main(){
    int i;
    int lista_desordenada[]={3,1,675,90,6,120,469,220,875};

    /*busqueda binaria*/
    shellshort(lista_desordenada,9);

    for(i=0;i<9;i++) printf("%d ",lista_desordenada[i]);
}

void shellshort(int v[], int n){
    int i,j,gap,temp;

    for(gap=n/2;gap>0;gap/=2)
       for (i=gap;i<n;i++)
            for(j=i-gap;(j>=0)&&(v[j]>v[j+gap]);j-=gap){
                temp=v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;
            }
        
}