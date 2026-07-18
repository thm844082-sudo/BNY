#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("examples/hello.mchb", "wb");

    if (!fp)
    {
        printf("Cannot create hello.mchb\n");
        return 1;
    }

    /* MCHB Header */

    fwrite("MCHB", 1, 4, fp);

    fputc(1, fp);      /* Version */
    fputc(2, fp);      /* Linux */
    fputc(0, fp);      /* Flags */
    fputc(0, fp);      /* Reserved */

    /* PRINT */

    fputc(1, fp);

    const char *text = "Hello, MCHB!";

    fputc(12, fp);

    fwrite(text, 1, 12, fp);

    /* EXIT */

    fputc(2, fp);

    fclose(fp);

    printf("examples/hello.mchb created.\n");

    return 0;
}
