#include <stdio.h>
#include "merge_sort.h"

#define ARR_SIZE 100

//TODO
void merge_list(int32_t list1[], uint32_t size1, int32_t list2[], uint32_t size2, int32_t merged_list[]){
    uint32_t idx1 = 0, idx2 = 0, idx3 = 0;
    while(idx1 < size1 && idx2 < size2){
        if(list1[idx1] < list2[idx2]){
            merged_list[idx3++] = list1[idx1++];
        }else{
            merged_list[idx3++] = list2[idx2++];
        }
        if(idx1 == size1){
            while(idx2 < size2)
            {
                merged_list[idx3++] = list2[idx2++];
            }
        }
        if(idx2 == size2){
            while(idx1 < size1)
            {
                merged_list[idx3++] = list1[idx1++];
            }
        }
    }
}

void print1(int32_t arr[], uint32_t size){
    printf("\narr[%d]:", size);
    for (uint32_t i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

static void _merge(int32_t list[], int32_t low, int32_t mid, int32_t high){
    int32_t temparray[ARR_SIZE];
    int32_t f_index = low, s_index = mid + 1, t_index = low;
    while(f_index <= mid && s_index <= high){
        if(list[f_index] < list[s_index]){
            temparray[t_index++] = list[f_index++];
        }else{
            temparray[t_index++] = list[s_index++];
        }
    }
    if(f_index > mid){
        while(s_index <= high){
            temparray[t_index++] = list[s_index++];
        }
    }else {
        while(f_index <= mid){
            temparray[t_index++] = list[f_index++];
        }
    }
    for (int32_t k = high; k >= low; --k)
    {
        list[k] = temparray[--t_index];
    }
}

void merge_sort(int32_t list[], int32_t low, int32_t high){
    int32_t mid;
    if(low < high){
        mid = (low + high) / 2;
        merge_sort(list, low, mid);
        merge_sort(list, mid + 1, high);
        _merge(list, low, mid, high);
    }
}