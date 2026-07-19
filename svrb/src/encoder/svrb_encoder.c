#include "../include/svrb.h"

#include <string.h>


void write_arg(FILE *file,char *text)
{
    unsigned char len=strlen(text);

    fwrite(&len,1,1,file);
    fwrite(text,1,len,file);
}


void write_signal(FILE *file,unsigned char opcode,int argc,char **argv)
{
    fwrite(&opcode,1,1,file);

    unsigned char count=argc;

    fwrite(&count,1,1,file);


    for(int i=0;i<argc;i++)
        write_arg(file,argv[i]);
}



int main()
{
    FILE *file=fopen("svrb/examples/hello.svrb","wb");


    SVRB_Header header;


    memcpy(header.magic,"SVRB",4);

    header.version=1;
    header.target=2;
    header.flags=0;
    header.reserved=0;


    fwrite(&header,sizeof(header),1,file);



    char *inspect[]={
        "/Users/symon/Desktop/Test.txt"
    };


    write_signal(
        file,
        SVRB_INSPECT_FILE_TYPE,
        1,
        inspect
    );



    char *alert[]={
        "SVRB Alert",
        "Inspection complete"
    };


    write_signal(
        file,
        SVRB_TRIGGER_OS_ALERT,
        2,
        alert
    );


    fclose(file);


    printf("SVRB multi-argument file created!\n");

    return 0;
}
