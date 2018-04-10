//Peer review comments signed MAN by Michael A. Nowiszewski
//DUPLICATE FILE, CHECKED WITH STUDENT AND PEER REVIEWED LATEST VERSION 'waterBetter.c'
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Initial declaring of variables
    int minutes;
    int bottles = 0;

    // Prompt user for minutes and verify it is a valid number
    do
    {
        minutes = get_int("Minutes: ");
    }
    while (minutes < 0);

    // For loop adding number of bottles based on minutes entered
    for (int i = 0; i < minutes; i++)
    {
        bottles = bottles + 12;
    }

    // Print number of bottles
    printf("Bottles: %i \n", bottles);


}