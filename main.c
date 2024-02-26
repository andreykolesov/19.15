#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct unordered_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
} unordered_array_set;

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {
            malloc(sizeof(int) * capacity),
            0,
            capacity
    };
}

size_t linearSearch_(const int a[], const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

size_t unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_(set->data, set->size, value);
}

bool unordered_array_set_isAbleAppend(unordered_array_set *set) {
    return (set->size < set->capacity);
}

void append_(int a[], size_t *n, int value) {
    a[*n] = value;
    (*n)++;
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

unordered_array_set unordered_array_set_intersection(unordered_array_set set1, unordered_array_set set2) {
    size_t new_capacity = set1.size;
    unordered_array_set set = unordered_array_set_create(new_capacity);

    for (int i = 0; i < set2.size; i++)
        if (unordered_array_set_in(&set1, set2.data[i]) != set1.size)
            unordered_array_set_insert(&set, set2.data[i]);

    return set;
}

void unordered_array_set_print(unordered_array_set set) {
    printf("{ ");
    for (size_t i = 0; i < set.size; i++) {
        printf("%d ", set.data[i]);
    }
    printf("}\n");
}

int main(){
    int n;
    scanf("%d", &n);

    int r;
    scanf("%d", &r);

    unordered_array_set set1 = unordered_array_set_create(r);

    for (int i = 0; i < r; i++){
        int x;
        scanf("%d", &x);

        unordered_array_set_insert(&set1, x);
    }

    for (int i = 0; i < n - 1; i++){
        scanf("%d", &r);

        unordered_array_set set2 = unordered_array_set_create(r);

        for (int j = 0; j < r; j++){
            int x;
            scanf("%d", &x);

            unordered_array_set_insert(&set2, x);
        }

        set1 = unordered_array_set_intersection(set1, set2);
    }

    unordered_array_set_print(set1);
}