#include "../include/mchb_runner.h"
#include <string.h>

static MCHB_Header header;

int mchb_load(FILE *fp)
{
    if (!fp)
    {
        return 0;
    }

    if (fread(&header, sizeof(MCHB_Header), 1, fp) != 1)
    {
        return 0;
    }

    if (memcmp(header.magic, MCHB_MAGIC, 4) != 0)
    {
        printf("Invalid MCHB file.\n");
        return 0;
    }

    if (header.version != MCHB_VERSION)
    {
        printf("Unsupported MCHB version.\n");
        return 0;
    }

    printf("MCHB Loaded\n");
    printf("Version : %d\n", header.version);
    printf("Target  : %d\n", header.target_os);

    return 1;
}
