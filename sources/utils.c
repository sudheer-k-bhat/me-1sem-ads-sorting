#include "util.h"

void _swap_(int32_t *val1, int32_t* val2){
    int32_t temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}