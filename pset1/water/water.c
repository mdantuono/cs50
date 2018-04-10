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