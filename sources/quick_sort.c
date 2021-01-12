#include "quick_sort.h"
#include "utils.h"

static int32_t _partition(int32_t list[], int32_t start, int32_t end){
    int32_t up = start, down = end;
    int32_t pivot = list[start];
    do{
        //second condition to avoid out of bounds
        while(list[up] <= pivot && up <= down){ ++up; }
        while(list[down] > pivot && up <= down){ --down; }
        //if all elements aren't scanned, swap up & down els & continue.
        if(up <= down){
            _swap_(&list[up], &list[down]);
        }
    }while(up <= down);
    //move pivot to center of partition
    _swap_(&list[down], &list[start]);
    return down;
}

void quick_sort(int32_t list[], int32_t start, int32_t end){
    int32_t mid;
    //Ensure at least 2 elements
    if(start < end){
        mid = _partition(list, start, end);
        //divide & conquer using balanced partition.
        quick_sort(list, start, mid - 1);
        quick_sort(list, mid + 1, end);
    }
}