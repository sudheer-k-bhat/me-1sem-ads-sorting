#include <stdint.h>

#include "constants.h"

typedef struct {
    uint32_t size;
    int32_t data[MAX_HEAP_SIZE];
}Heap;

Heap* heap_new(int32_t data[], uint32_t len);
Heap* heap_sort(Heap* heap);
Heap* heap_insert(Heap* heap, int32_t key);
Heap* heap_test(Heap* heap);
int32_t heap_get_max(Heap* heap);
int32_t heap_extract_max(Heap* heap);
uint32_t heap_size(Heap* heap);