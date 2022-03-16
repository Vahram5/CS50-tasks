#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int height, i, j;
    //check inserted value
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    for (i = 1; i <= height; i++)
    {
        for (j = 1; j <= height - i; j++)
        {
            //for spaces
            printf(" ");
        }
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        //for columns
        printf("\n");
    }

}