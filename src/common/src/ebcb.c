#include "../include/ebcb.h"


unsigned char ascii_to_ebcdic(unsigned char c)
{
    if (c >= 'A' && c <= 'Z')
        return 0xC1 + (c - 'A');

    if (c >= 'a' && c <= 'z')
        return 0x81 + (c - 'a');

    if (c >= '0' && c <= '9')
        return 0xF0 + (c - '0');

    if (c == ' ')
        return 0x40;

    return c;
}


unsigned char ebcdic_to_ascii(unsigned char c)
{
    if (c >= 0xC1 && c <= 0xE9)
        return 'A' + (c - 0xC1);

    if (c >= 0x81 && c <= 0xA9)
        return 'a' + (c - 0x81);

    if (c >= 0xF0 && c <= 0xF9)
        return '0' + (c - 0xF0);

    if (c == 0x40)
        return ' ';

    return c;
}


void ebcb_encode(FILE *input, FILE *output)
{
    unsigned char byte;

    while (fread(&byte,1,1,input))
    {
        byte = ascii_to_ebcdic(byte);
        fwrite(&byte,1,1,output);
    }
}


void ebcb_decode(FILE *input, FILE *output)
{
    unsigned char byte;

    while (fread(&byte,1,1,input))
    {
        byte = ebcdic_to_ascii(byte);
        fwrite(&byte,1,1,output);
    }
}
