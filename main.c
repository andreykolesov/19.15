#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "libs/data_structures/vector/vector.h"

int main() {
    vector v = createVector(SIZE_MAX);

    free(v.data);

    return 0;
}
