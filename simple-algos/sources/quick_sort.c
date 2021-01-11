#include "quick_sort.h"

static void _swap_(int32_t *val1, int32_t* val2){
    int32_t temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

static int32_t _partition(int32_t list[], int32_t start, int32_t end){
    int32_t up = start, down = end;
    int32_t pivot = list[start];
    do{
        while(list[up] <= pivot && up <= down){
            ++up;
        }
        while(list[down] > pivot && up <= down){
            --down;
        }
        if(up <= down){
            _swap_(&list[up], &list[down]);
        }
    }while(up <= down);
    _swap_(&list[down], &list[start]);
    return down;
}

void quick_sort(int32_t list[], int32_t start, int32_t end){
    int32_t mid;
    //Ensure at least 2 elements
    if(start < end){
        mid = _partition(list, start, end);
        quick_sort(list, start, mid - 1);
        quick_sort(list, mid + 1, end);
    }
}