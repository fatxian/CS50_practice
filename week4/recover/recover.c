#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DATA 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[DATA];

    int counter = 0;
    FILE *img = NULL;
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, DATA, card) == DATA)
    {
        // Create JPEGs from the data
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                fclose(img);
            }
            char filename[8];
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename, "w");
            counter++;
        }
        if (img != NULL)
        {
            fwrite(buffer, 1, DATA, img);
        }
    }
    fclose(card);
}
