#!/bin/sh
rm -rf bin/out
gcc -I headers/ sources/sort.c sources/main.c -o bin/out
bin/out