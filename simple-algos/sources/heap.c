#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "heap.h"
#include "utils.h"

static void _heapify(int32_t data[], uint32_t len, uint32_t parent){
    assert(len > 0 && len < MAX_HEAP_SIZE && parent > 0);
    //calculate left child pos
    uint32_t child = 2 * parent;
    while(child <= len){
        if(child + 1 <= len){
            //if rchild > lchild, choose rchild
            if(data[child+1] > data[child]){
                ++child;
            }
        }
        //max heap satisfied
        if(data[parent] >= data[child]){
            break;
        }
        _swap_(&data[parent], &data[child]);
        //ensure max heap among children
        parent = child;
        child = 2 * parent;
    }
}

static void _test_heap(int32_t data[], uint32_t len){
    //ensure every child val is <= its parent
    for (uint32_t child = len; child > 1/*0 dummy, 1 is root & has no parent*/;
    --child)
    {
        assert(data[child] <= data[child/2]);
    }
}

Heap* heap_new(int32_t data[], uint32_t len){
    assert(len > 0 && len < MAX_HEAP_SIZE);
    Heap* heap = (Heap*)malloc(sizeof(Heap*));
    for (uint32_t idx = len/2; idx > 0; --idx)
    {
        _heapify(data, len, idx);
    }
    heap->size = len;
    memcpy(heap->data, data, (len+1) * sizeof(int32_t));
    _test_heap(heap->data, heap->size);
    return heap;
}

Heap* heap_sort(Heap* heap){
    assert(heap != NULL && heap->size > 0 && heap->size < MAX_HEAP_SIZE);
    uint32_t idx = heap->size;
    for (idx = heap->size; idx > 1; --idx)
    {
        _swap_(&heap->data[idx], &heap->data[1]);
        //`idx - 1` ignore the last swapped element
        //`1` start heapify at root, since swapped
        _heapify(heap->data, idx - 1, 1);
    }
    //No more maximum heap after sorting
    
    return heap;
}