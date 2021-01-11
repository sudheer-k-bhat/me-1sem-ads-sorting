#include <stdint.h>

#define ARR_SIZE 100

static void _swap_(int32_t *val1, int32_t* val2){
    int32_t temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
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

static uint32_t _partition_(int32_t list[], uint32_t start, uint32_t end){
    uint32_t up = start, down = end;
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
    if(start < end){
        mid = _partition_(list, start, end);
        quick_sort(list, start, mid - 1);
        quick_sort(list, mid + 1, end);
    }
}

static void _merge_(int32_t list[], int32_t low, int32_t mid, int32_t high){
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
    }else{
        while(f_index <= mid){
            temparray[t_index++] = list[f_index++];
        }
    }
    for(int32_t k = low; k < high; ++k){
        list[k] = temparray[k];
    }
}

void merge_sort(int32_t list[], int32_t low, int32_t high){
    int32_t mid;
    if(low < high){
        mid = (low + high) / 2;
        merge_sort(list, low, mid);
        merge_sort(list, mid + 1, high);
        _merge_(list, low, mid, high);
    }
}