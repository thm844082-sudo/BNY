#include "../include/svrb.h"

int main(int argc, char **argv)
{

    if(argc < 2)
    {
        printf("Usage: svrb_runner file.svrb\n");
        return 1;
    }


    FILE *file = fopen(argv[1], "rb");


    if(!file)
    {
        printf("Cannot open SVRB file\n");
        return 1;
    }


    if(svrb_load(file))
    {
        svrb_execute(file);
    }


    fclose(file);

    return 0;
}
