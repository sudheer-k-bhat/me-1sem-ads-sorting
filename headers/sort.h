#include <stdint.h>

void bubble_sort(int32_t list[], uint32_t size);
//Prefer selection sort to bubble sort as number of swaps are minimized.
void selection_sort(int32_t list[], uint32_t size);
//Better than selection sort
void insertion_sort(int32_t list[], uint32_t size);