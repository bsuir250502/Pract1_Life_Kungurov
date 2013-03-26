#include <stdio.h>
#include <stdlib.h>
#include "mystdlib.h"
#define SIZE 4

char background1[SIZE][SIZE],background2[SIZE][SIZE];

int chk(int x, int y)
{
    int i=0;
    if (background1[(x+SIZE-1)%SIZE][y]==1) i++;
    if (background1[(x+SIZE-1)%SIZE][(y+SIZE-1)%SIZE]==1) i++;
    if (background1[(x+SIZE-1)%SIZE][(y+1)%SIZE]==1) i++;
    if (background1[x][(y+SIZE-1)%SIZE]==1) i++;
    if (background1[x][(y+1)%SIZE]==1) i++;
    if (background1[(x+1)%SIZE][(y+SIZE-1)%SIZE]==1) i++;
    if (background1[(x+1)%SIZE][y]==1) i++;
    if (background1[(x+1)%SIZE][(y+1)%SIZE]==1) i++;
    return i;
}

int main()
{
	int i,j;
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++){
            printf(" Enter element %d:%d\n",i,j);
            my_gets(&background1[i][j],3);
        }
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%3c",background1[i][j]);
        }
        puts(" ");
    }
    return 0;
}