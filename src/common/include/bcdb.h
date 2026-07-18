#ifndef BCDB_H
#define BCDB_H

#include <stdio.h>

void bcdb_encode(FILE *input, FILE *output);
void bcdb_decode(FILE *input, FILE *output);

#endif
