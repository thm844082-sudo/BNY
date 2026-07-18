#include <stdlib.h>
#include "../include/comb.h"


void comb_compress(FILE *input, FILE *output)
{
    unsigned char *data;
    unsigned char *compressed;

    long size;


    fseek(input, 0, SEEK_END);
    size = ftell(input);
    rewind(input);


    data = malloc(size);
    compressed = malloc(size * 2);


    fread(data, 1, size, input);


    long csize = 0;


    for (long i = 0; i < size; )
    {
        unsigned char count = 1;
        unsigned char value = data[i];


        while (i + count < size &&
               data[i + count] == value &&
               count < 255)
        {
            count++;
        }


        compressed[csize++] = count;
        compressed[csize++] = value;


        i += count;
    }


    if (csize < size)
    {
        // compressed mode
        unsigned char mode = 1;

        fwrite(&mode, 1, 1, output);
        fwrite(compressed, 1, csize, output);
    }
    else
    {
        // raw mode
        unsigned char mode = 0;

        fwrite(&mode, 1, 1, output);
        fwrite(data, 1, size, output);
    }


    free(data);
    free(compressed);
}
