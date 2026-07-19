#ifndef SVRB_H
#define SVRB_H

#include <stdio.h>
#include <stdint.h>


#define SVRB_MAGIC "SVRB"
#define SVRB_VERSION 1


typedef struct
{
    char magic[4];

    uint8_t version;
    uint8_t target;
    uint8_t flags;
    uint8_t reserved;

} SVRB_Header;



#define SVRB_NULL_IO_PROBE        0xF0
#define SVRB_INSPECT_FILE_TYPE    0xF1
#define SVRB_EVALUATE_FILE_SIZE   0xF2


#define SVRB_TRIGGER_OS_ALERT     0xB0
#define SVRB_REGISTER_EVENT       0xB1
#define SVRB_EVENT_TRIGGER        0xB2


int svrb_load(FILE *file);

int svrb_execute(FILE *file);


#endif
