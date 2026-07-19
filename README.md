# SVRB Workspace

A Linux-only ncurses development environment
for the SVRB signal-based runtime system.

## Features

- Terminal IDE interface
- SVRB file editing
- Signal execution engine
- Runtime output terminal
- Linux socket server foundation

## Build

```bash
g++ src/*.cpp signals/*.cpp \
-Iinclude \
-std=c++17 \
-lncurses \
-o svrb-workspace
