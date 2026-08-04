#!/bin/sh

gcc -Wall -std=c23 -Isrc -Ideps -O0 ./src/main.c -o main
