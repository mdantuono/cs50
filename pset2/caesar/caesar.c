#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    argc = 2; // Specify the number of arguments that will be executed in the command line (1 for file name, 1 for key argument)
    if (!argv[1] || argc > 2) // make sure argv[1] exists and make sure there is no more than 2 arguments made
    {
        printf("You dun goof'd\n");
        return 1; // If so, return error
    }
    string k = argv[1]; // Declare and set key variable to argv[1] argument

    int key = atoi(k); // Convert key to an integer

    string plaintext = get_string("plaintext: "); // Get the plaintext from the user, store in variable

    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++) // Loop to CONVERT plaintext
    {
        char ciphertext;

        if (isalpha(plaintext[i])) // Checks if characters is alphabetical
        {
            if (isupper(plaintext[i])) // Checks if uppercase
            {
                ciphertext = plaintext[i] + key; // Add key value to each letter of plaintext

                while (ciphertext > 90) // While character exceeds uppercase characters...
                {
                    ciphertext -= 26; // ... wrap it back around.
                }

                printf("%c", ciphertext); // Print each character
            }

            else if (islower(plaintext[i])) // Checks if lowercase
            {
                ciphertext = plaintext[i] + key; // Add key value to each letter of plaintext

                while (ciphertext > 122) // While character exceeds lowercase characters...
                {
                    ciphertext -= 26; // ... wrap it back around.
                }

                printf("%c", ciphertext); // Print each character
            }
        }
        else
        {
            ciphertext = plaintext[i];
            printf("%c", ciphertext); // Print characters non-alpha
        }
    } // End loop

    printf("\n"); // New line

}