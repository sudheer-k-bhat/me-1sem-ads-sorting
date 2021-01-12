#include <stdint.h>

#include "utils.h"
#include "constants.h"

void bubble_sort(int32_t list[], uint32_t size){
    for (uint32_t pass = 0; pass < size - 1; pass++)
    {
        for (uint32_t i = size - 1; i > pass; i--)
        {
            if(list[i] < list[i-1]){
                _swap_(&list[i], &list[i-1]);
            }
        }
    }
}

void selection_sort(int32_t list[], uint32_t size){
    for (uint32_t pass = 0; pass < size-1; ++pass)
    {
        uint32_t min_pos = pass;
        for (uint32_t i = pass+1; i < size; i++)
        {
            if(list[i] < list[min_pos]){
                min_pos = i;
            }
        }
        _swap_(&list[min_pos], &list[pass]);
    }
}

void insertion_sort(int32_t list[], uint32_t size){
    //Since index will reach -ve values in this algo, don't use uint
    int32_t pass, index, key;
    for (pass = 1; pass < size; ++pass)
    {
        index = pass-1;
        key = list[pass];
        while(index >= 0 && list[index] > key){
            list[index+1] = list[index];
            --index;
        }
        list[index+1] = key;
    }
}