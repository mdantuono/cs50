#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Get the string of a name
    string name = get_string("");
    // Print the first character in upper case
    printf("%c", toupper(name[0]));

    // Create loop to iterate through other letters
    for (int i = 0; i < strlen(name); i++)
    {
        // If i is a space, check the next letter for a stop and if no stop, print the next letter
        if (name[i] == ' ' && name[i + 1] != '\0')
        {
            printf("%c", toupper(name[i + 1]));
            i++;
        }
    }

    printf("\n");
}

