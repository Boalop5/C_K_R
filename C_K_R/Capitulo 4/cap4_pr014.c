#include <stdio.h>








void swap(int *px, int *py, int *pz);

int main(){
    int num1,num2,num3;

    num1=20;
    num2=35;
    num3=50;

    printf("Numeros antes de swap num1: %d,num2: %d,num3: %d\n",num1,num2,num3);
    //swap sin punteros
    swap(&num1,&num2,&num3);
    printf("Numeros despues de swap num1: %d,num2: %d, num3: %d\n",num1,num2,num3);
}

void swap(int *px, int *py, int *pz){
    
    int temp;

    temp= *px;
    *px = *py;
    *py = *pz;
    *pz= *px;
    *pz = temp;
}
