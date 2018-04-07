#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // do while loop will continue prompting user until needs are met
    do
    {

    height = get_int("Height: ");

    }

    while (height < 0 || height > 23);


// Initial for loop to print the number of lines as specified
    for (int i = 0; i < height; i++)
    {
        // Loop to print the spaces
        for (int n = 0; n < height - 1 - i; n++)
        {
            printf(" ");
        }

        // Loop to print the num signs
        for (int n = 0; n < i + 2; n++)
        {
            printf("#");
        }

        printf("\n");
    }
}