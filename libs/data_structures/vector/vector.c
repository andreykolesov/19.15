#include <stdio.h>
#include "vector.h"
#include <stdlib.h>

vector createVector(size_t n) {
    vector v;

    v.data = malloc(sizeof(int) * n);
    v.size = 0;
    v.capacity = n;

    if (v.data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
        v->size = 0;
        v->capacity = 0;
    } else {
        int *new_data = realloc(v->data, newCapacity * sizeof(int));

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

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v) {
    v->data = realloc(v->data, v->size * sizeof(*v->data));
}

void deleteVector(vector *v){
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}







