// A program that is used to recover jpeg files from a memory card
#include <stdio.h>
#include <cs50.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover file\n");
        return 1;
    }

    // open the memory card file using fopen
    FILE *card_ptr = fopen(argv[1], "r");
    if (card_ptr == NULL)
    {
        fprintf(stderr, "Pointer null\n");
        return 2;
    }

    int file_count = 0; // create start to file names
    bool found_jpg = false; // create new jpg bool
    FILE *img_ptr; // create img pointer file

    // read 512 bytes of memory until end of file
    char memory[512];
    while (fread(memory, 1, 512, card_ptr) == 512)
    {
    // find beginning of jpeg in the memory
    if (memory[0] == (char)0xff &&
        memory[1] == (char)0xd8 &&
        memory[2] == (char)0xff &&
        (memory[3] & 0xf0) == 0xe0)
        {
            if (found_jpg == true)
            {
                fclose(img_ptr);
            }

            found_jpg = true;

            // variable to store file names
            char filename[8];

            // create a new jpeg to write to
            sprintf(filename, "%03i.jpg", file_count++);

            // open new jpeg
            img_ptr = fopen(filename, "w");

            // write 512 bytes until new jpeg is found using fwrite
            fwrite(memory, 1, 512, img_ptr);

        }
        else if (found_jpg == true)
        {
            // write 512 bytes until new jpeg is found using fwrite
            fwrite(memory, 1, 512, img_ptr);
        }
    }
    fclose(card_ptr);
}


