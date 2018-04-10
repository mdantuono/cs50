//Peer review comments signed MAN by Michael A. Nowiszewski
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // do while loop will continue prompting user until needs are met //specify 'needs'? be technical! MAN
    do
    {

        height = get_int("Height: ");

    }

    while (height < 0 || height > 23); //what does this line do? MAN ("loop fires while height is within range etc.")


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

/*Excellent commenting and indentation, well done Mike! MAN
check50 output below:
:) mario.c exists.
:) mario.c compiles.
:) rejects a height of -1
:) handles a height of 0 correctly
:) handles a height of 1 correctly
:) handles a height of 2 correctly
:) handles a height of 23 correctly
:) rejects a height of 24, and then accepts a height of 2
:) rejects a non-numeric height of "foo"
:) rejects a non-numeric height of ""
See https://cs50.me/checks/3ecdf1e44d022cff5dfca512d9852928c8d8cb26 for more detail.*/