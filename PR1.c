#include <stdio.h>
#include <stdlib.h>
#include "mystdlib.h"
int size1, size2;
FILE *file;
int chk(char **background1, int x, int y)
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
    int i, j, n;
    for (i = 0; i < size1; i++)
        for (j = 0; j < size2; j++) {
            n = chk(background1,i, j);
            if (n == 3) {
                background2[i][j] = '1';
            }
            else if (n == 2){
                background2[i][j] = background1[i][j];
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
        my_fgets(background1[i], size2 + 4, file);
        printf("%s", background1[i]);
    }
}

void display_background(char **background1, int size1, int size2)
{
    int i, j;
    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            printf("%3c ",background1[i][j]);
        }
        puts(" ");
    }
}

int main()
{
    int i, n;
    char str[10];
    char **background1, **background2;
    char *file_name_in = "life_in.txt", *file_name_out = "life_out.txt";
    file = fopen(file_name_in, "r");
    while(1){
        my_fgets(str, 5, file);
        size1 = atoi(str);
        if (size1 > 0) break;
        puts("Input error. Try again");
    }
    while(1){
        my_fgets(str, 5, file);
        size2 = atoi(str);
        if (size2 > 0) break;
        puts("Input error. Try again");
    }
    puts("Number of generation");
    my_fgets(str,5, file);
    n = atoi(str);
    background1 = (char **) calloc(size1, sizeof(char *));
    for (i = 0; i < size1; i++) {
        background1[i] = (char *) calloc(size2 + 4, sizeof(char));
    } background2 = (char **) calloc(size1, sizeof(char *));
    for (i = 0; i < size1; i++) {
        background2[i] = (char *) calloc(size2 + 4, sizeof(char));
    } enter_background(background1, size1, size2);
    i=0;
       while(n>=0){
       next_generation(background1,background2,size1,size2);
       cpy_new_instead_old_gen(background1,background2,size1,size2);
       n--;
       }
    display_background(background1,size1,size2);
    fclose(file);
    file = fopen(file_name_out, "w");
    for(i=0; i<size1 ; i++){
        fprintf(file, "%s\n",background1[i]);
    }
    return 0;
}
