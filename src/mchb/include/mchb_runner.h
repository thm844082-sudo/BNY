#ifndef MCHB_RUNNER_H
#define MCHB_RUNNER_H

#include <stdio.h>
#include <stdint.h>

#define MCHB_MAGIC "MCHB"
#define MCHB_VERSION 1

#define OP_NOP    0x00
#define OP_PRINT  0x01
#define OP_EXIT   0x02

typedef struct
{
    char magic[4];
    uint8_t version;
    uint8_t target_os;
    uint8_t flags;
    uint8_t reserved;
} MCHB_Header;

int mchb_load(FILE *fp);
int mchb_execute(FILE *fp);

#endif
