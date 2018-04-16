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

    for (int i = 0; i < strlen(plaintext);) // Loop to iterate through and CONVERT plaintext
    {
        for (int n = 0; n < strlen(keyword);) // Loop to iterate through keyword
        {
            char ciphertext;
            int key;

            if (isupper(keyword[n])) // If/else statement indexing the keyword characters to 0 - 25
            {
                key = keyword[n] - 'A';
            }
            else if (islower(keyword[n]))
            {
                key = keyword[n] - 'a';
            }

            if (n < strlen(keyword))
            {
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
            }
            else
            {
                n -= strlen(keyword); // Wrap keyword back around
            }

            i++;
        } // End of KEYWORD loop

    } // End of PLAINTEXT loop

    printf("\n"); // Print new line
}