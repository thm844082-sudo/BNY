# BNY COMB Format

## Version
COMB v1

## Algorithm
Adaptive Run-Length Encoding

## Header

BNY header:
- Magic: BNY
- Version
- Type: COMB

## Data blocks

Compressed block:

[COUNT][BYTE]

Example:

05 41

means:

AAAAA


## Modes

Mode byte:

00 = Raw data
01 = RLE compressed data

The decoder checks the mode before reading data.
