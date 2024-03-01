#include <stdio.h>
#include "vectorVoid.h"
#include <stdlib.h>

vectorVoid createVectorV(size_t n, size_t baseTypeSize){
    vectorVoid v;

    v.data = malloc(baseTypeSize * n);
    v.size = 0;
    v.capacity = n;

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity){
    if (newCapacity == 0) {
        deleteVectorV(v);
    } else {
        int *new_data = realloc(v->data, newCapacity * v->baseTypeSize);

        if (new_data == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }

        v->data = new_data;
        v->capacity = newCapacity;

        if (v->size > newCapacity) {
            v->size = newCapacity;
        }
    }
}

void clearV(vectorVoid *v){
    v->size = 0;
}

void shrinkToFitV(vectorVoid *v){
    reserveV(v, v->size);
}

void deleteVectorV(vectorVoid *v){
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
    v->baseTypeSize = 0;
}
