#include <stdio.h>
#include <string.h>
#include "../common/include/bny.h"
#include "../common/include/comb.h"
#include "../common/include/hexb.h"
#include "../common/include/unib.h"
#include "../common/include/ebcb.h"
#include "../common/include/bcdb.h"


BNY_Type get_type(char *name)
{
    if (strcmp(name, "COMB") == 0)
        return BNY_COMB;

    if (strcmp(name, "HEXB") == 0)
        return BNY_HEXB;

    if (strcmp(name, "UNIB") == 0)
        return BNY_UNIB;

    if (strcmp(name, "EBCB") == 0)
        return BNY_EBCB;

    if (strcmp(name, "BCDB") == 0)
        return BNY_BCDB;

    return BNY_ASCB;
}


int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: bny_encoder input output TYPE\n");
        return 1;
    }


    FILE *input = fopen(argv[1], "rb");

    if (!input)
    {
        printf("Cannot open input file\n");
        return 1;
    }


    FILE *output = fopen(argv[2], "wb");

    if (!output)
    {
        printf("Cannot create output file\n");
        fclose(input);
        return 1;
    }


    BNY_Header header;

    memcpy(header.magic, BNY_MAGIC, 3);
    header.version = BNY_VERSION;
    header.type = get_type(argv[3]);


    fwrite(&header, sizeof(BNY_Header), 1, output);


    if (header.type == BNY_COMB)
        comb_compress(input, output);

    else if (header.type == BNY_HEXB)
        hexb_encode(input, output);

    else if (header.type == BNY_UNIB)
        unib_encode(input, output);

    else if (header.type == BNY_EBCB)
        ebcb_encode(input, output);

    else if (header.type == BNY_BCDB)
        bcdb_encode(input, output);

    else
    {
        unsigned char byte;

        while (fread(&byte,1,1,input))
            fwrite(&byte,1,1,output);
    }


    fclose(input);
    fclose(output);

    printf("BNY encoding complete! Type: %s\n", argv[3]);

    return 0;
}
