#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //do while prompts the user again if input entered is outside the range 1 - 8, negative values, or strings
    int input;
    do
    {
        input = get_int("Height: ");
    }
    while (input < 1 || input > 8);

    //input corresponds to the rows
    for (int i = 0; i < input; i++)
    {
        //dot servers as the space or for right alignment
        for (int dot = 0; dot + 1 < input - i; dot++)
        {
            printf(" ");
        }
        //j is basically the columns
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        //basically mirrored
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}