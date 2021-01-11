_heapify_(data, len, parent){

    child = 2 * parent;
    while(child <= len){
        if(child + 1 <= len){
            if(data[child+1] > data[child]){
                child++;
            }
        }
        if(data[parent] >= data[child]){
            break;
        }
        _swap_(&data)
        parent = child;
        child = 2 * parent;
    }
}

Heap heap_new(data[], len){
    Heap heap;

    for (uint32_t idx = len/2; idx > 0; --idx)
    {
        _heapify_(data, len, idx);
    }
    heap.size = len;
    memcpy(heap.data, data, (len+1) * sizeof(int32_t));
    _test_heap_(heap.data, heap.size);
    return heap;
}