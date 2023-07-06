#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point pt1;
    struct point pt2;
   
    
};

struct point makepoint(int x,int y)
{
     struct point temp;

     temp.x=x;
     temp.y=y;
     
     return temp;
};
struct rect makesquare(int s)
{
    struct rect temp;
    
    temp.pt1=makepoint(0,0);
    temp.pt2=makepoint(s,s);

    return temp;
    
};


int main ()
{ 
    struct point p;
    struct rect r;
    struct rect s;
    
    p.x= 0;
    p.y= 0;
    
    r.pt1=makepoint(0,0);
    r.pt2=makepoint(5,10);
    
    r.pt1.x;
    s.pt1.x;
   
    printf("%c",s.pt1.x); 
}





