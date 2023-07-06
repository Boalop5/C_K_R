#define ALLOCSIZE 1000000 
#include <stdio.h>

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    
    } else
         return NULL;

}

void afree(char *p)
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
       allocp = p;
}

void *buffer(int n)
{
    printf("Buffer ocupado %d",ALLOCSIZE - (allocp - allocbuf));
    printf("Buffer libre %d",allocbuf + ALLOCSIZE-allocp);

}