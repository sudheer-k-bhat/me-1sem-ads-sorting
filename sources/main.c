#include <stdint.h>
#include <stdio.h>
#include <assert.h>

#include "sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap.h"

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

void test_insertion_sort(){
    int32_t arr[] = {25,15,53,76,8,67,30,92,41,84};
    uint32_t size = 10;
    insertion_sort(arr, size);
    assert_sorting(arr, size);
}

void test_quick_sort(){
    int32_t arr[] = {25,15,53,76,8,67,30,92,41,84};
    uint32_t size = 10;
    quick_sort(arr, 0, size - 1);
    assert_sorting(arr, size);
}

void test_merge_lists(){
    uint32_t size = 3;
    int32_t arr1[] = {25,15,53}, arr2[] = {41,84,92}, merged_list[size*2];
    merge_list(arr1, size, arr2, size, merged_list);
    print(merged_list, size);
    // assert_sorting(merged_list, size);
}

void test_merge_sort(){
    int32_t arr[] = {25,15,53};//,76,8,67,30,92,41,84
    uint32_t size = 3;
    merge_sort(arr, 0, size - 1);
    print(arr, size);
    // assert_sorting(arr, size);
}

void test_heap_sort(){
    //0th element ignored
    int32_t arr[] = {0,25,15,53,76,8,67,30,92,41,84};
    uint32_t size = 10;
    Heap* heap = heap_new(arr, size);
    heap = heap_sort(heap);
    assert_sorting(heap->data, heap->size+1);
}

int main(){
    test_bubble_sort();
    test_selection_sort();
    test_insertion_sort();
    test_quick_sort();
    // test_merge_sort();
    test_heap_sort();
    return 0;
}