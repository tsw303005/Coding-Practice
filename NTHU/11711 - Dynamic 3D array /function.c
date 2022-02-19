#include "function.h"
#include <stdlib.h>
#include <stdio.h>

unsigned*** new_3d_array(unsigned n, unsigned m, unsigned k) {
    unsigned*** arr_3d;
    unsigned** arr_2d;
    unsigned* arr;

    arr = (unsigned*)malloc(sizeof(unsigned) * n * m * k);
    arr_2d = (unsigned**)malloc(sizeof(unsigned*) * n * m);
    arr_3d = (unsigned***)malloc(sizeof(unsigned**) * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr_2d[i * m + j] = &arr[(i * m + j) * k];
        }
        arr_3d[i] = &arr_2d[i * m];
    }

    return arr_3d;
}

void delete_3d_array(unsigned ***arr) {
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}  