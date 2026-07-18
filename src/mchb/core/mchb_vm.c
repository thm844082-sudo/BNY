#include "../include/mchb_runner.h"

int mchb_execute(FILE *fp)
{
    unsigned char opcode;

    while (fread(&opcode,1,1,fp))
    {
        switch(opcode)
        {
            case OP_NOP:
                break;

            case OP_PRINT:
            {
                unsigned char len;

                fread(&len,1,1,fp);

                for(int i=0;i<len;i++)
                {
                    char c;
                    fread(&c,1,1,fp);
                    putchar(c);
                }

                break;
            }

            case OP_EXIT:
            {
                printf("\nProgram exited.\n");
                return 1;
            }

            default:
            {
                printf("\nUnknown opcode %u\n",opcode);
                return 0;
            }
        }
    }

    return 1;
}
