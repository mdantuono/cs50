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
        break;
    }
    int key;
    string ciphertext;

    key = get_int(argv[1]);
    int converted = atoi(key);

    string plaintext = get_string("plaintext: ");

    for (int i = 0; i < strlen(plaintext); i++)
        {
            int converted = atoi(plaintext);
            ciphertext = sprintf("%s", converted + key);
            printf("%s\n", ciphertext);
        }

    printf("ciphertext: %s\n", ciphertext);

}