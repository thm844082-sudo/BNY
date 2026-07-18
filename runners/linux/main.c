#include "../../src/mchb/include/mchb_runner.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: mchb_runner file.mchb\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");

    if (!fp)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    if (!mchb_load(fp))
    {
        fclose(fp);
        return 1;
    }

    if (!mchb_execute(fp))
    {
        fclose(fp);
        return 1;
    }

    fclose(fp);

    return 0;
}
