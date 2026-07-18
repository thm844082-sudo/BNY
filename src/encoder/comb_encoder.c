#include <stdio.h>


void compress(FILE *input, FILE *output)
{
    unsigned char current;
    unsigned char next;
    unsigned char count;


    while (fread(&current, 1, 1, input))
    {
        count = 1;


        while (count < 255 &&
               fread(&next, 1, 1, input))
        {
            if (next != current)
            {
                fseek(input, -1, SEEK_CUR);
                break;
            }

            count++;
        }


        fwrite(&count, 1, 1, output);
        fwrite(&current, 1, 1, output);
    }
}
