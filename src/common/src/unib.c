#include "../include/unib.h"


void unib_encode(FILE *input, FILE *output)
{
    unsigned char byte;

    while (fread(&byte, 1, 1, input))
    {
        fwrite(&byte, 1, 1, output);
    }
}


void unib_decode(FILE *input, FILE *output)
{
    unsigned char byte;

    while (fread(&byte, 1, 1, input))
    {
        fwrite(&byte, 1, 1, output);
    }
}
