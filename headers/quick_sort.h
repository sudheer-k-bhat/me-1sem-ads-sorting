#include <stdint.h>

//Implementation recursively calls this method with potentially -ve start & end
//so not using uint32_t type.
void quick_sort(int32_t list[], int32_t start, int32_t end);