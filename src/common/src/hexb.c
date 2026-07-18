#include "../include/hexb.h"


void hexb_encode(FILE *input, FILE *output)
{
    unsigned char byte;

    char hex[] = "0123456789ABCDEF";


    while (fread(&byte, 1, 1, input))
    {
        fputc(hex[byte >> 4], output);
        fputc(hex[byte & 0x0F], output);
    }
}


int hex_value(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';

    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;

    return 0;
}


void hexb_decode(FILE *input, FILE *output)
{
    char a, b;


    while (fread(&a, 1, 1, input) &&
           fread(&b, 1, 1, input))
    {
        unsigned char byte;

        byte = (hex_value(a) << 4) |
               hex_value(b);

        fwrite(&byte, 1, 1, output);
    }
}
