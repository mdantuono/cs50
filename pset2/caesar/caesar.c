#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    argc = 2;
    if (!argv[1])
    {
        return 1;
    }
    int key;
    string ciphertext;

    key = get_int(argv[1]); // Get key from command line argument
    int converted = atoi(key); // Convert key to an integer

    string plaintext = get_string("plaintext: "); // Get the plaintext from the user

    for (int i = 0; i < strlen(plaintext); i++) // Loop to convert plaintext
        {
            ciphertext = converted[i] + key; // Figure out way to convert each letter of the word

            printf("%s\n", ciphertext);
        }

    printf("ciphertext: %s\n", ciphertext); // Must include code to bypass numbers and include capital letters

}