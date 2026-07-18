#include "../include/bny.h"

int bny_check_header(BNY_Header *header)
{
    if (header->magic[0] != 'B' ||
        header->magic[1] != 'N' ||
        header->magic[2] != 'Y')
    {
        return 0;
    }

    return 1;
}
