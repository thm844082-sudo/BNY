#include "../include/comb.h"


void comb_decompress(FILE *input, FILE *output)
{
    unsigned char mode;

    fread(&mode, 1, 1, input);


    if (mode == 0)
    {
        unsigned char byte;

        while (fread(&byte, 1, 1, input))
        {
            fwrite(&byte, 1, 1, output);
        }
    }


    else if (mode == 1)
    {
        unsigned char count;
        unsigned char value;


        while (fread(&count, 1, 1, input))
        {
            fread(&value, 1, 1, input);


            for (int i = 0; i < count; i++)
            {
                fwrite(&value, 1, 1, output);
            }
        }
    }
}
