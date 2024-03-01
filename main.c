#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"

void test_pushBack_emptyVector(){
    vector v = createVector(0);
    int x = 4;

    pushBack(&v, x);

    assert(v.size == 1);
    assert(v.data[0] == 4);

    deleteVector(&v);
}

void test_pushBack_fullVector(){
    vector v = createVector(2);
    pushBack(&v, 1);
    pushBack(&v, 2);

    int x = 3;

    pushBack(&v, x);

    assert(v.size == 3);
    assert(v.data[2] == 3);
    assert(v.capacity == 4);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test(){
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    //test();

    size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        printf("%f ", x);
    }

}
