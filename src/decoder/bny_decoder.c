#include <stdio.h>
#include "../common/include/bny.h"
#include "../common/include/comb.h"
#include "../common/include/hexb.h"
#include "../common/include/unib.h"
#include "../common/include/ebcb.h"
#include "../common/include/bcdb.h"


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: bny_decoder input output\n");
        return 1;
    }


    FILE *input = fopen(argv[1], "rb");

    if (!input)
    {
        printf("Cannot open BNY file\n");
        return 1;
    }


    BNY_Header header;

    fread(&header,sizeof(BNY_Header),1,input);


    FILE *output = fopen(argv[2],"wb");

    if (!output)
    {
        printf("Cannot create output file\n");
        return 1;
    }


    printf("BNY File Detected\n");


    if (header.type == BNY_COMB)
    {
        printf("Type: COMB\n");
        comb_decompress(input,output);
    }

    else if (header.type == BNY_HEXB)
    {
        printf("Type: HEXB\n");
        hexb_decode(input,output);
    }

    else if (header.type == BNY_UNIB)
    {
        printf("Type: UNIB\n");
        unib_decode(input,output);
    }

    else if (header.type == BNY_EBCB)
    {
        printf("Type: EBCB\n");
        ebcb_decode(input,output);
    }

    else if (header.type == BNY_BCDB)
    {
        printf("Type: BCDB\n");
        bcdb_decode(input,output);
    }

    else
    {
        printf("Type: ASCB\n");

        unsigned char byte;

        while (fread(&byte,1,1,input))
            fwrite(&byte,1,1,output);
    }


    fclose(input);
    fclose(output);

    printf("BNY decoding complete!\n");

    return 0;
}
