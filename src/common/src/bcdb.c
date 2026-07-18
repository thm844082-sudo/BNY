#include "../include/bcdb.h"


void bcdb_encode(FILE *input, FILE *output)
{
    unsigned char a;
    unsigned char b;


    while (fread(&a,1,1,input))
    {
        if (a >= '0' && a <= '9')
            a -= '0';
        else
            continue;


        if (fread(&b,1,1,input))
        {
            if (b >= '0' && b <= '9')
                b -= '0';
            else
                b = 0;
        }
        else
        {
            b = 0x0F;
        }


        unsigned char packed;

        packed = (a << 4) | b;

        fwrite(&packed,1,1,output);
    }
}



void bcdb_decode(FILE *input, FILE *output)
{
    unsigned char byte;


    while (fread(&byte,1,1,input))
    {
        unsigned char high;
        unsigned char low;


        high = (byte >> 4) & 0x0F;
        low = byte & 0x0F;


        if (high <= 9)
            fputc('0' + high, output);


        if (low <= 9)
            fputc('0' + low, output);
    }
}
