//Peer review comments signed MAN by Michael A. Nowiszewski
#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float change;
    int coins = 0;

    float quarter = 25;
    float dime = 10;
    float nickle = 5;
    float penny = 1;

    // Prompts user for change amount and verifies it is valid
    do
    {
        change = get_float("Change: ");
    }
    while (change <= 0);

    change = round(change * 100); //What does this line do? MAN ("convert user input to cents", etc.)

    // Check for quarters
    while (change >= 25)
    {
        coins++;
        change = change - quarter;
    }

    // Check for dimes
    while (change >= 10)
    {
        coins++;
        change = change - dime;
    }

    // Check for nickles
    while (change >= 5)
    {
        coins++;
        change = change - nickle;
    }

    //Check for pennies
    while (change >= 1)
    {
        coins++;
        change = change - penny;
    }

    printf("Coins: %d \n", coins);

}
/*Clean, precise, logical variable names. Well played sir. MAN
check50 passes, output below:
:) cash exists
:) cash compiles
:) input of 0.41 yields output of 4
:) input of 0.01 yields output of 1
:) input of 0.15 yields output of 2
:) input of 1.6 yields output of 7
:) input of 23 yields output of 92
:) input of 4.2 yields output of 18
:) rejects a negative input like -.1
:) rejects a non-numeric input of "foo"
:) rejects a non-numeric input of ""
See https://cs50.me/checks/4e8575cb43630c31de024208943b5e431e4c433e for more detail. */