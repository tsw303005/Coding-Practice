#include "function.h"
#include <stdlib.h>

unsigned** new_2d_array(unsigned n,unsigned m) {
    unsigned** arr;
    unsigned* tmp;

    arr = (unsigned**)malloc(sizeof(unsigned*) * n);
    tmp = (unsigned*)malloc(sizeof(unsigned) * n * m);
    for (int i = 0; i < n; i++) {
        arr[i] = &tmp[i * m];
    }
    return arr;
}

void delete_2d_array(unsigned **arr) {
    free(arr[0]);
    free(arr);
}