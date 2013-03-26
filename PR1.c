#include <stdio.h>
#include <stdlib.h>
#include "mystdlib.h"
#define SIZE 4

char background1[SIZE][SIZE],background2[SIZE][SIZE];

void clrscr(void) 
{ 
char a[80]; 
printf("\033[2J"); /* Clear the entire screen. */ 
printf("\033[0;0f"); /* Move cursor to the top left hand corner */ 
}

int chk(int x, int y)
{
    int i=0;
    if (background1[(x+SIZE-1)%SIZE][y]=='1') i++;
    if (background1[(x+SIZE-1)%SIZE][(y+SIZE-1)%SIZE]=='1') i++;
    if (background1[(x+SIZE-1)%SIZE][(y+1)%SIZE]=='1') i++;
    if (background1[x][(y+SIZE-1)%SIZE]=='1') i++;
    if (background1[x][(y+1)%SIZE]=='1') i++;
    if (background1[(x+1)%SIZE][(y+SIZE-1)%SIZE]=='1') i++;
    if (background1[(x+1)%SIZE][y]=='1') i++;
    if (background1[(x+1)%SIZE][(y+1)%SIZE]=='1') i++;
    return i;
}

void next_generation(char **background1,char **background2)
{
    int i,j;
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++){
            chk(i,j);
            if (i<2) { background2[i][j] = '0'; }
            if (i==2 || i==3) { background2[i][j] = '1'; }
            if (i>3) { background2[i][j] = '0'; }
        }
}

void cpy_new_instead_old_gen()
{
    int i,j;
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++){
            strcpy(&background1[i][j],&background2[i][j]);
        }
}

void enter_background()
{
    int i,j;
    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++){
            while(1){
            printf(" Enter element %d:%d\n",i,j);
            my_gets(&background1[i][j],3);
            if(background1[i][j]!='1' && background1[i][j]!='0') { puts("Enter correct value!"); }
            else break;
        }
        }
        
}

void display_background()
{
    int i,j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%3c",background1[i][j]);
        }
        puts(" ");
    }
}

int main()
{
	int i,j,n;
    char str;
    enter_background();
    display_background();
    puts("Number of generation");
    my_gets(&str,5);
    n=atoi(&str);
    i=0;
    while(n>=0){
    clrscr();
    next_generation(&background1,&background2);
    cpy_new_instead_old_gen(&background1,&background2);
    display_background();
    n--;
    }
    return 0;
}