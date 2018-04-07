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

    change = round(change * 100);

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