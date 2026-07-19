# BNY MCHB Format Specification

Version: 0.1.0-prealpha

## Overview

MCHB (Machine Code Binary) is the executable binary format of BNY.

MCHB uses a virtual machine architecture.
Programs are executed by platform-specific MCHB runners.

## File Structure

MCHB Header
+
Bytecode

## Header

Size: 8 bytes

Offset 0:
Magic - MCHB

Offset 4:
Version

Offset 5:
Target OS

Offset 6:
Flags

Offset 7:
Reserved

## Target OS

0 = Any
1 = Windows
2 = Linux
3 = macOS
4 = Android
5 = Web

## Instruction Set

NOP

Opcode:
00

Does nothing.

PRINT

Opcode:
01

Format:

01
[length]
[data]

Example:

01 05 Hello

EXIT

Opcode:
02

Stops execution.

## Runtime Flow

MCHB File
|
v
Loader
|
v
Virtual Machine
|
v
Runner
|
v
Operating System

