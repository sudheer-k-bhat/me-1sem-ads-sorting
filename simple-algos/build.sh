#!/bin/sh
rm -rf bin/out
gcc -I headers/ \
sources/utils.c sources/sort.c sources/quick_sort.c sources/merge_sort.c sources/heap.c sources/main.c \
-o bin/out
bin/out