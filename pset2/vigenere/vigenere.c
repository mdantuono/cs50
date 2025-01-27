#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    argc = 2; // Specify the number of arguments that will be executed in the command line (1 for file name, 1 for key argument)
    if (!argv[1] || argc > 2 || argv[2]) // make sure argv[1] exists and make sure there is no more than 2 arguments made
    {
        printf("You dun goof'd\nOnly two arguments required\n");
        return 1; // If so, return error
    }
    else for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("You dun goof'd\nSecond argument must be an alphabetical string\n");
            return 1;
        }
    }

    string keyword = argv[1]; // Declare and set key variable to argv[1] argument (is a string)

    string plaintext = get_string("plaintext: "); // Get the plaintext from the user, store in variable

    printf("ciphertext: ");

    for (int i = 0, n = 0; i < strlen(plaintext); i++) // Loop to iterate through and CONVERT plaintext
    {

        char ciphertext;
        int key;

        if (n > strlen(keyword) - 1)
        {
            n -= strlen(keyword); // Wrap keyword back around
        }

        if (isupper(keyword[n])) // If/else statement indexing the keyword characters to 0 - 25
        {
            key = keyword[n] - 'A';
        }
        else if (islower(keyword[n]))
        {
            key = keyword[n] - 'a';
        }


        if (isalpha(plaintext[i])) // Checks if characters is alphabetical
        {
            if (isupper(plaintext[i])) // Checks if uppercase
            {
                ciphertext = (((plaintext[i] - 'A') + key) % 26 + 'A'); // Add keyword letter value to each letter of plaintext, adjusting to overflow with modulo
                printf("%c", ciphertext); // Print each character
                n++;
            }

            else // Checks if lowercase
            {
                ciphertext = (((plaintext[i] - 'a') + key) % 26 + 'a'); // Add keyword letter value to each letter of plaintext, adjusting to overflow with modulo
                printf("%c", ciphertext); // Print each character
                n++;
            }
        }
        else
        {
            ciphertext = plaintext[i];
            printf("%c", ciphertext); // Print characters non-alpha
        }

    } // End loop

    printf("\n"); // Print new line
}

// obvious working code, be carefull with the amount of if and else if statements you use, see if you can handle two circumstances at a time by using the if statements
// when you know there is only two ways the code will play out. besides that code is still cleanly spaced and commented well, great job overall.