#ifndef BNY_H
#define BNY_H

#define BNY_MAGIC "BNY"
#define BNY_VERSION 1

typedef enum {
    BNY_ASCB = 0,
    BNY_EBCB = 1,
    BNY_UNIB = 2,
    BNY_BCDB = 3,
    BNY_HEXB = 4,
    BNY_MCHB = 5,
    BNY_COMB = 6
} BNY_Type;


typedef struct __attribute__((packed))
{
    char magic[3];
    unsigned char version;
    unsigned char type;
} BNY_Header;


#endif

#define COMB_VERSION 1

