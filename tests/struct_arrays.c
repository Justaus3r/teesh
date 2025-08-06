#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Pos;


Pos* construct_store(){
   Pos *p = (Pos*)malloc(40);

   for(int i=0; i<5; ++i){
        p[i].x = 1;
        p[i].y = 2; //= {i*1, i*2};
   }

   return p;
}


void main(){

    Pos *p;

    p = construct_store();

    printf("%d", p[4].y);
}
