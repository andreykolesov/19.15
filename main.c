#include <stdio.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vectorVoid/vectorVoid.h"

// тест vector
// тест на создание вектора
void test_create_vector_1() {
    vector v = createVector(5);

    assert(v.data != NULL && v.size == 0 && v.capacity == 5);

    deleteVector(&v);
}

void test_create_vector_2() {
    vector v = createVector(0);

    assert(v.size == 0 && v.capacity == 0);

    deleteVector(&v);
}

void test_create_vector() {
    test_create_vector_1();
    test_create_vector_2();
}

// тест на изменение количества памяти, выделенное под хранение элементов вектора
void test_reserve_vector() {
    vector v = createVector(2);

    reserve(&v, 10);
    assert(v.capacity == 10);

    reserve(&v, 15);
    assert(v.capacity == 15);

    deleteVector(&v);
}

// тест на освобождение памяти, выделенную под неиспользуемые элементы
void test_shrink_to_fit_vector() {
    vector v = createVector(10);
    int x = 2;

    for (int i = 0; i < 7; i++)
        pushBack(&v, x);

    shrinkToFit(&v);
    assert(isFull(&v));

    deleteVector(&v);
}

// тест на считывание элемента
void test_get_value_vector() {
    vector v = createVector(5);

    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);

    int value = getVectorValue(&v, 1);
    assert(value == v.data[1]);

    deleteVector(&v);
}

// тест на добавление элемента x в конец вектора
void test_pushBack_emptyVector() {
    vector v = createVector(0);
    int x = 4;

    pushBack(&v, x);

    assert(v.size == 1);
    assert(v.data[0] == 4);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
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

void test_push_back() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

// тест на удаление последнего элемента вектора
void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_pop_back() {
    test_popBack_notEmptyVector();
}

// тест на получение адреса i-ого элемента вектора
void test_at_vector_not_empty_vector() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);

    int *address = atVector(&v, 2);
    assert(v.data[2] == *address);

    deleteVector(&v);
}

void test_at_vector() {
    test_at_vector_not_empty_vector();
}

// тест на получение адреса последнего элемента вектора
void test_back_not_empty_vector() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);

    int *address = back(&v);
    assert(&v.data[1] == address);

    deleteVector(&v);
}

void test_back_one_element_vector() {
    vector v = createVector(1);
    pushBack(&v, 1);

    int *address = back(&v);
    assert(&v.data[0] == address);

    deleteVector(&v);
}

void test_back() {
    test_back_not_empty_vector();
    test_back_one_element_vector();
}

// тест на получение адреса первого элемента вектора
void test_front_not_empty_vector() {
    vector v = createVector(4);
    pushBack(&v, 1);
    pushBack(&v, 2);

    int *address = front(&v);
    assert(&v.data[0] == address);

    deleteVector(&v);
}

void test_front_one_element_vector() {
    vector v = createVector(1);
    pushBack(&v, 1);

    int *address = back(&v);
    assert(&v.data[0] == address);

    deleteVector(&v);
}

void test_front() {
    test_front_not_empty_vector();
    test_front_one_element_vector();
}

void test_vector() {
    test_create_vector();
    test_reserve_vector();
    test_shrink_to_fit_vector();
    test_get_value_vector();
    test_push_back();
    test_pop_back();
    test_at_vector();
    test_back();
    test_front();
}

// тест для voidVector
// тест на создание вектора
void test_create_void_vector_1() {
    vectorVoid v = createVectorV(5, sizeof(int));

    assert(v.data != NULL && v.size == 0 && v.capacity == 5);

    deleteVectorV(&v);
}

void test_create_void_vector_2() {
    vectorVoid v = createVectorV(0, sizeof(float));

    assert(v.data != NULL && v.size == 0 && v.capacity == 0);

    deleteVectorV(&v);
}

void test_create_void_vector() {
    test_create_void_vector_1();
    test_create_void_vector_2();
}

// тест на изменение количества памяти, выделенное под хранение элементов вектора
void test_reserve_void_vector() {
    vectorVoid v = createVectorV(2, sizeof(int));

    reserveV(&v, 10);
    assert(v.capacity == 10);

    reserveV(&v, 15);
    assert(v.capacity == 15);

    deleteVectorV(&v);
}

// тест на освобождение памяти, выделенную под неиспользуемые элементы
void test_shrink_to_fit_void_vector() {
    vectorVoid v = createVectorV(10, sizeof(int));
    int x = 2;

    for (int i = 0; i < 7; i++)
        pushBackV(&v, &x);

    shrinkToFitV(&v);
    assert(isFullV(&v));

    deleteVectorV(&v);
}

// тест на считывание элемента
void test_get_value_void_vector() {
    vectorVoid v = createVectorV(10, sizeof(int));
    int x = 2;

    pushBackV(&v, &x);

    int value;

    getVectorValueV(&v, 0, &value);
    assert(value == x);

    deleteVectorV(&v);
}

// тест на запись элемента
void test_set_value_void_vector() {
    vectorVoid v = createVectorV(10, sizeof(int));
    int x = 3;

    setVectorValueV(&v, 0, &x);

    int value;

    getVectorValueV(&v, 0, &value);
    assert(value == x);

    deleteVectorV(&v);
}

// тест на добавление элемента x в конец вектора
void test_pushBack_empty_void_vector() {
    vectorVoid v = createVectorV(1, sizeof(int));
    int x = 4;

    pushBackV(&v, &x);

    int value;

    getVectorValueV(&v, 0, &value);

    assert(v.size == 1);
    assert(value == x);
    assert(v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_pushBack_full_void_vector() {
    vectorVoid v = createVectorV(0, sizeof(int));
    int x = 4;

    pushBackV(&v, &x);

    int value;

    getVectorValueV(&v, 0, &value);

    assert(v.size == 1);
    assert(value == x);
    assert(v.baseTypeSize == sizeof(int));

    deleteVectorV(&v);
}

void test_push_back_void_vector() {
    test_pushBack_empty_void_vector();
    test_pushBack_full_void_vector();
}

// тест на удаление последнего элемента вектора
void test_popBack_not_empty_void_vector() {
    vectorVoid v = createVectorV(0, sizeof(int));
    int x = 10;
    pushBackV(&v, &x);

    assert(v.size == 1);

    popBackV(&v);

    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVectorV(&v);
}

void test_pop_back_void_vector() {
    test_popBack_not_empty_void_vector();
}

void test_void_vector() {
    test_create_void_vector();
    test_reserve_void_vector();
    test_shrink_to_fit_void_vector();
    test_get_value_void_vector();
    test_set_value_void_vector();
    test_push_back_void_vector();
    test_pop_back_void_vector();
}

void test() {
    test_vector();
    test_void_vector();
}

int main() {
    test();

    return 0;
}
