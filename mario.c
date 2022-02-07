#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do // determines a valid int for height
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int row = 1;

    while (height > 0) //  creates the triangle
    {
        int temp = height - 1;

        while (temp > 0) //prints the spaces before the 1st hash in each row
        {
            printf(" ");
            temp--;
        }

        for (int i = 0; i < row; i++)//   prints the 1st set of hashes on each row
        {
            printf("#");
        }

        printf("  "); // the gap in between

        for (int i = 0; i < row; i++)//   prints the 2nd set of hashes on each row
        {
            printf("#");
        }

        printf("\n"); // new line

        row++;

        height--;
    }
}
// Programmer: Gareth Rogers
// User: garethrogers