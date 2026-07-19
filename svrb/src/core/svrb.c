#include "../include/svrb.h"

#include <string.h>
#include <sys/stat.h>


void trigger_alert(char *title, char *message)
{
    printf("EVENT ALERT\n");
    printf("Title  : %s\n", title);
    printf("Message: %s\n", message);
}



void inspect_file_type(char *path)
{
    struct stat info;


    if(stat(path,&info)!=0)
    {
        printf("ERROR: File not found\n");
        printf("Code: 0x%02X\n",SVRB_ERR_NOT_FOUND);
        return;
    }


    char *ext=strrchr(path,'.');


    if(ext && strcmp(ext,".txt")==0)
        printf("Return: simple txt file\n");

    else if(ext && strcmp(ext,".json")==0)
        printf("Return: structured json data\n");

    else
        printf("Return: unknown file type\n");
}



void evaluate_file_size(char *path)
{
    struct stat info;


    if(stat(path,&info)!=0)
    {
        printf("ERROR: File not found\n");
        return;
    }


    printf("File size: %ld bytes\n",info.st_size);
}



int svrb_load(FILE *file)
{
    SVRB_Header header;


    fread(&header,sizeof(header),1,file);


    if(strncmp(header.magic,SVRB_MAGIC,4)!=0)
    {
        printf("Invalid SVRB file\n");
        return 0;
    }


    printf("SVRB Loaded\n");
    printf("Version : %d\n",header.version);
    printf("Target  : %d\n",header.target);


    return 1;
}



int svrb_execute(FILE *file)
{
    uint8_t opcode;


    while(fread(&opcode,1,1,file))
    {

        uint8_t argc;

        fread(&argc,1,1,file);


        char args[8][256];


        for(int i=0;i<argc;i++)
        {
            uint8_t len;

            fread(&len,1,1,file);

            fread(args[i],1,len,file);

            args[i][len]='\0';
        }



        switch(opcode)
        {

            case SVRB_INSPECT_FILE_TYPE:

                inspect_file_type(args[0]);

                break;


            case SVRB_EVALUATE_FILE_SIZE:

                evaluate_file_size(args[0]);

                break;


            case SVRB_TRIGGER_OS_ALERT:

                trigger_alert(args[0],args[1]);

                break;


            default:

                printf("Unknown signal: 0x%02X\n",opcode);

        }

    }


    return 1;
}
