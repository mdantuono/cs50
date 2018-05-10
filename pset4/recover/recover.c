// A program that is used to recover jpeg files from a memory card
#include <stdio.h>


int main(void)
{
    if (argc != 2)
    {
        printf("Usage: ./recover file");
        return 1;
    }

    // open the memory card file using fopen
    FILE *memory = fopen(card.raw, "r");

    for (int i = 0; i < sizeof(memory); i++)
    {
        // find beginning of jpeg in the memory
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
            {
                int filename = 000;
                // create a new jpeg to write to
                sprintf(filename, "%03i.jpg", 2);
                // open new jpeg
                FILE *img = fopen(filename, "w");
            }
        // open new jpeg using sprintf to create file

        // write 512 bytes until new jpeg is found using fwrite

        // detect end of file
    }


}


