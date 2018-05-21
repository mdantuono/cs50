#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* argv[])
{

    char lower_word[45];

    for (int n = 0; n < strlen(argv[1]); n++)
    {
        lower_word[n] = tolower(argv[1][n]);
    }

    printf("%s\n", lower_word);
}