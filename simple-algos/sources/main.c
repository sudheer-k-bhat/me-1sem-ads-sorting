#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "sort.h"

void print(int32_t arr[], uint32_t size){
    printf("\narr[%d]:", size);
    for (uint32_t i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void assert_sorting(int32_t arr[], uint32_t size){
    for (uint32_t i = 0; i < size-1; i++)
    {
        assert(arr[i] <= arr[i+1]);
    }
    
}

void test_bubble_sort(){
    int32_t arr[] = {25,15,53,76,8,67,30,92,41,84};
    uint32_t size = 10;
    bubble_sort(arr, size);
    assert_sorting(arr, size);
}

void test_selection_sort(){
    int32_t arr[] = {25,15,53,76,8,67,30,92,41,84};
    uint32_t size = 10;
    selection_sort(arr, size);
    assert_sorting(arr, size);
}

int main(){
    test_bubble_sort();
    test_selection_sort();
    return 0;
}