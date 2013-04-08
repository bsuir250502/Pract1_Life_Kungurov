#include <stdio.h>
#include <stdlib.h>
#include "mystdlib.h"
char **background1, **background2;
int size1, size2;
FILE *file;
void clrscr(void)
{
    char a[80];
    printf("\033[2J");          /* Clear the entire screen. */
    printf("\033[0;0f");        /* Move cursor to the top left hand corner */
} int chk(int x, int y)
{
    int i = 0;
    if (background1[(x + size1 - 1) % size1][y] == '1')
        i++;
    if (background1[(x + size1 - 1) % size1][(y + size2 - 1) % size2] ==
        '1')
        i++;
    if (background1[(x + size1 - 1) % size1][(y + 1) % size2] == '1')
        i++;
    if (background1[x][(y + size2 - 1) % size2] == '1')
        i++;
    if (background1[x][(y + 1) % size2] == '1')
        i++;
    if (background1[(x + 1) % size1][(y + size2 - 1) % size2] == '1')
        i++;
    if (background1[(x + 1) % size1][y] == '1')
        i++;
    if (background1[(x + 1) % size1][(y + 1) % size2] == '1')
        i++;
    return i;
}

void next_generation(char **background1, char **background2, int size1,
                     int size2)
{
    int i, j;
    for (i = 0; i < size1; i++)
        for (j = 0; j < size2; j++) {
            chk(i, j);
            if (i == 2 || i == 3) {
                background2[i][j] = '1';
            }

            else {
                background2[i][j] = '0';
            }
        }
}

void cpy_new_instead_old_gen(char **background1, char **background2,
                             int size1, int size2)
{
    int i, j;
    for (i = 0; i < size1; i++)
        for (j = 0; j < size2; j++) {
            strcpy(&background1[i][j], &background2[i][j]);
        }
}

void enter_background(char **background1, int size1, int size2)
{
    int i;
    for (i = 0; i < size1; i++) {
        printf(" Enter elements %d:\n", i);
        my_gets(background1[i], size2 + 4);
        printf("%s", background1[i]);
    }
}

void display_background(char **background1, int size1, int size2)
{
    int i, j;
    printf("%d,%d \n",size1,size2);
    for (i = 0; i < size1; i++) {
        printf("%d:",i);
        for (j = 0; j < size2; j++) {
            printf("%d ", background1[i][j]);
        }
        puts(" ");
    }
}

int main()
{
    int i, j, n;
    char str[10];
    char *file_name = "test.txt";
    file = fopen(file_name, "r");
    my_gets(str, 5);
    size1 = atoi(str);
    my_gets(str, 5);
    size2 = atoi(str);
    puts("Number of generation");
    fscanf(file, "%d", &n);
    background1 = (char **) calloc(size1, sizeof(char *));
    for (i = 0; i < size1; i++) {
        background1[i] = (char *) calloc(size2 + 4, sizeof(char));
    } background2 = (char **) calloc(size1, sizeof(char *));
    for (i = 0; i < size1; i++) {
        background2[i] = (char *) calloc(size2 + 4, sizeof(char));
    } enter_background(background1, size1, size2);
    display_background(background1, size1, size2);

    /*i=0;
       while(n>=0){
       clrscr();
       next_generation(background1,background2,size1,size2);
       cpy_new_instead_old_gen(background1,background2,size1,size2);
       display_background(background1,size1,size2);

       n--;
       } */
    return 0;
}
