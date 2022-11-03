#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int const BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the file and check it's readability
    char *input_file_name = argv[1];
    FILE *input_pointer = fopen(input_file_name, "r");
    if (input_pointer == NULL)
    {
        printf("Could not open %s\n", input_file_name);
        return 2;
    }

    // Variable declaration
    BYTE buffer[BLOCK_SIZE];
    int jpg_counter = 0;
    FILE *img_pointer = NULL;
    char filename[8];

    // Loops untill the end of the input file
    while (fread(buffer, 1, BLOCK_SIZE, input_pointer) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If it isn't the first .jpeg, close the previous
            if (jpg_counter != 0)
            {
                fclose(img_pointer);
            }

            // Initialize each file
            sprintf(filename, "%03i.jpg", jpg_counter);
            img_pointer = fopen(filename, "w");
            jpg_counter++;
        }

        // Write to the buffer if the .jpeg has been found
        if (jpg_counter != 0)
        {
            fwrite(buffer, 1, BLOCK_SIZE, img_pointer);
        }
    }

    // Close the files
    fclose(input_pointer);
    fclose(img_pointer);

    return 0;
}