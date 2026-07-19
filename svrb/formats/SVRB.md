# BNY SVRB Specification

Version: 0.1.0-prealpha

## Overview

SVRB (Server Binary) is a binary instruction format designed for
server runtime operations, signals, events, connections, and system
interfaces.

SVRB programs consist of:

- Header
- Signal instructions
- Arguments
- Runtime responses

---

## File Header

Size: 8 bytes

Offset 0:
Magic:
SVRB

Offset 4:
Version

Offset 5:
Target Runtime

Offset 6:
Flags

Offset 7:
Reserved

---

## Signal Format

Structure:

[Opcode]
[Argument Length]
[Argument Data]

Example:

0xF1("test.txt")

Meaning:

F1 = INSPECT_FILE_TYPE

---

## Signal Groups

0xF0 - 0xFF

File System

0xE0 - 0xEF

Network

0xD0 - 0xDF

Hardware

0xC0 - 0xCF

System Processes

0xB0 - 0xBF

Events

---

## Initial Signals

0xF0
NULL_IO_PROBE

0xF1
INSPECT_FILE_TYPE

0xE0
ICMP_ECHO_PROBE

0xB0
TRIGGER_OS_ALERT

---

## Runtime Flow

SVRB File
    |
    v
SVRB Loader
    |
    v
Signal Interpreter
    |
    v
Operating System Interface

