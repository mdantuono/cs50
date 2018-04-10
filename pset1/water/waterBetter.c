//Peer review comments signed MAN by Michael A. Nowiszewski
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Initial declaring of variables
    int minutes;
    int bottles = 12;

    // Prompt user for minutes and verify it is a valid number
    do
    {
        minutes = get_int("Minutes: ");
    }
    while (minutes < 0);

    // Multiply bottles and minutes and set number to bottles
    bottles = bottles * minutes;

    // Print number of bottles
    printf("Bottles: %i \n", bottles);


}


/*Clear, concise code. Code flows logically. Well done! check50 passed, output below. MAN
:) water.c exists.
:) water.c compiles.
:) 1 minute equals 12 bottles.
:) 2 minute equals 24 bottles.
:) 5 minute equals 60 bottles.
:) 10 minute equals 120 bottles.
:) rejects "foo" minutes
:) rejects "" minutes
:) rejects "123abc" minutes
See https://cs50.me/checks/6b2b5fcd33e47e8cee05a88908cb73ea5546f15f for more detail.*/
