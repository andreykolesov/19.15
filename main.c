#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>

void test_inputMatrix() {
    matrix m = getMemMatrix(2, 2);

    inputMatrix(&m);

    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 2);
    assert(m.values[1][0] == 3);
    assert(m.values[1][1] == 4);

    freeMemMatrix(&m);
}

void test_inputMatrices() {
    matrix *ms = getMemArrayOfMatrices(2, 2, 2);

    inputMatrices(ms, 2);

    assert(ms[0].values[0][0] == 1);
    assert(ms[0].values[0][1] == 2);
    assert(ms[0].values[1][0] == 3);
    assert(ms[0].values[1][1] == 4);

    assert(ms[1].values[0][0] == 5);
    assert(ms[1].values[0][1] == 6);
    assert(ms[1].values[1][0] == 7);
    assert(ms[1].values[1][1] == 8);

    freeMemMatrices(ms, 2);
}

void test_input() {
    test_inputMatrix();
    test_inputMatrices();
}

void test_outputMatrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    outputMatrix(m);

    freeMemMatrix(&m);
}

void test_outputMatrices() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    matrix *ms = createArrayOfMatrixFromArray(a, 2, 2, 2);

    outputMatrices(ms, 2);

    freeMemMatrices(ms, 2);
}

void test_output(){
    test_outputMatrix();
    test_outputMatrices();
}

void test_swapRows_1(){
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    swapRows(m, 0, 1);

    assert (m.values[0][0] == 3);
    assert (m.values[0][1] == 4);
    assert (m.values[1][0] == 1);
    assert (m.values[1][1] == 2);

    freeMemMatrix(&m);
}

void test_swapRows_2(){
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 3, 2);

    swapRows(m, 0, 2);

    assert (m.values[0][0] == 5);
    assert (m.values[0][1] == 6);
    assert (m.values[1][0] == 3);
    assert (m.values[1][1] == 4);
    assert (m.values[2][0] == 1);
    assert (m.values[2][1] == 2);

    freeMemMatrix(&m);
}

void test_swapRows(){
    test_swapRows_1();
    test_swapRows_2();
}

void test_swapColumns_1(){
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4}, 2, 2);

    swapColumns(m, 0, 1);

    assert (m.values[0][0] == 2);
    assert (m.values[0][1] == 1);
    assert (m.values[1][0] == 4);
    assert (m.values[1][1] == 3);

    freeMemMatrix(&m);
}

void test_swapColumns_2(){
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 2, 3);

    swapColumns(m, 1, 2);

    assert (m.values[0][0] == 1);
    assert (m.values[0][1] == 3);
    assert (m.values[0][2] == 2);
    assert (m.values[1][0] == 4);
    assert (m.values[1][1] == 6);
    assert (m.values[1][2] == 5);

    freeMemMatrix(&m);
}

void test_swapColumns(){
    test_swapColumns_1();
    test_swapColumns_2();
}

int getSum(int *a, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int max(int *a, int n) {
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void test_insertionSortRowsMatrixByRowCriteria_1() {
    matrix m = createMatrixFromArray((int[]) {9, 8, 7, 6, 5, 4, 3, 2, 1}, 3, 3);

    insertionSortRowsMatrixByRowCriteria(m, getSum);

    assert (m.values[0][0] == 3);
    assert (m.values[0][1] == 2);
    assert (m.values[0][2] == 1);
    assert (m.values[1][0] == 6);
    assert (m.values[1][1] == 5);
    assert (m.values[1][2] == 4);
    assert (m.values[2][0] == 9);
    assert (m.values[2][1] == 8);
    assert (m.values[2][2] == 7);

    freeMemMatrix(&m);
}

void test_insertionSortRowsMatrixByRowCriteria_2() {
    matrix m = createMatrixFromArray((int[]) {9, 1, 6, 7, 2, 5, 8, 3, 4}, 3, 3);

    insertionSortRowsMatrixByRowCriteria(m, max);

    assert(m.values[0][0] == 7);
    assert(m.values[0][1] == 2);
    assert(m.values[0][2] == 5);
    assert(m.values[1][0] == 8);
    assert(m.values[1][1] == 3);
    assert(m.values[1][2] == 4);
    assert(m.values[2][0] == 9);
    assert(m.values[2][1] == 1);
    assert(m.values[2][2] == 6);

    freeMemMatrix(&m);
}

void test_insertionSortRowsMatrixByRowCriteria(){
    test_insertionSortRowsMatrixByRowCriteria_1();
    test_insertionSortRowsMatrixByRowCriteria_2();
}

void test_selectionSortColsMatrixByColCriteria_1(){
    matrix m = createMatrixFromArray((int[]) {9, 1, 6, 7, 2, 5, 8, 3, 4}, 3, 3);

    selectionSortColsMatrixByColCriteria(m, getSum);

    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 6);
    assert(m.values[0][2] == 9);
    assert(m.values[1][0] == 2);
    assert(m.values[1][1] == 5);
    assert(m.values[1][2] == 7);
    assert(m.values[2][0] == 3);
    assert(m.values[2][1] == 4);
    assert(m.values[2][2] == 8);

    freeMemMatrix(&m);
}

void test_selectionSortColsMatrixByColCriteria_2(){
    matrix m = createMatrixFromArray((int[]) {1, 9, 6, 2, 7, 5, 3, 8, 4}, 3, 3);

    selectionSortColsMatrixByColCriteria(m, max);

    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 6);
    assert(m.values[0][2] == 9);
    assert(m.values[1][0] == 2);
    assert(m.values[1][1] == 5);
    assert(m.values[1][2] == 7);
    assert(m.values[2][0] == 3);
    assert(m.values[2][1] == 4);
    assert(m.values[2][2] == 8);

    freeMemMatrix(&m);
}

void test_selectionSortColsMatrixByColCriteria(){
    test_selectionSortColsMatrixByColCriteria_1();
    test_selectionSortColsMatrixByColCriteria_2();
}

void test_isSquareMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);

    assert(isSquareMatrix(&m) == true);

    freeMemMatrix(&m);
}

void test_isSquareMatrix_2(){
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 3, 2);

    assert(isSquareMatrix(&m) == false);

    freeMemMatrix(&m);
}

void test_isSquareMatrix(){
    test_isSquareMatrix_1();
    test_isSquareMatrix_2();
}

void test_areTwoMatricesEqual_1() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);

    assert(areTwoMatricesEqual(&m1, &m2) == true);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual_2() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);
    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 3, 2);

    assert(areTwoMatricesEqual(&m1, &m2) == false);

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

void test_areTwoMatricesEqual(){
    test_areTwoMatricesEqual_1();
    test_areTwoMatricesEqual_2();
}

void test_isEMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 0, 1, 0, 0, 0, 1}, 3, 3);

    assert(isEMatrix(&m) == true);

    freeMemMatrix(&m);
}

void test_isEMatrix_2() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0, 0, 1, 0}, 3, 3);

    assert(isEMatrix(&m) == false);

    freeMemMatrix(&m);
}

void test_isEMatrix(){
    test_isEMatrix_1();
    test_isEMatrix_2();
}

void test_isSymmetricMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 2, 1, 2, 3, 2, 1}, 3, 3);

    assert(isSymmetricMatrix(&m) == true);

    freeMemMatrix(&m);
}

void test_isSymmetricMatrix_2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 2, 1, 2}, 3, 2);

    assert(isSymmetricMatrix(&m) == false);

    freeMemMatrix(&m);
}

void test_isSymmetricMatrix(){
    test_isSymmetricMatrix_1();
    test_isSymmetricMatrix_2();
}

void test_transposeSquareMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);

    transposeSquareMatrix(&m);

    matrix expected = createMatrixFromArray((int[]) {1, 4, 7, 2, 5, 8, 3, 6, 9}, 3, 3);

    assert(areTwoMatricesEqual(&m, &expected) == true);

    freeMemMatrix(&m);
    freeMemMatrix(&expected);
}

void test_transposeSquareMatrix_2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);

    transposeSquareMatrix(&m);

    matrix expected = createMatrixFromArray((int[]) {1, 4, 7, 2, 5, 8, 3, 6, 0}, 3, 3);

    assert(areTwoMatricesEqual(&m, &expected) == false);

    freeMemMatrix(&m);
    freeMemMatrix(&expected);
}

void test_transposeSquareMatrix(){
    test_transposeSquareMatrix_1();
    test_transposeSquareMatrix_2();
}

void test_transposeMatrix_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 2, 3);

    transposeMatrix(&m);

    matrix expected = createMatrixFromArray((int[]) {1, 4, 2, 5, 3, 6}, 3, 2);

    assert(areTwoMatricesEqual(&m, &expected) == true);

    freeMemMatrix(&m);
    freeMemMatrix(&expected);
}

void test_transposeMatrix_2() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3, 4, 5, 6}, 2, 3);

    transposeMatrix(&m);

    matrix expected = createMatrixFromArray((int[]) {1, 4, 2, 5, 3, 0}, 3, 2);

    assert(areTwoMatricesEqual(&m, &expected) == false);

    freeMemMatrix(&m);
    freeMemMatrix(&expected);
}

void test_transposeMatrix(){
    test_transposeMatrix_1();
    test_transposeMatrix_2();
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray((int[]) {9, 8, 7, 6, 5, 4, 3, 2, 1}, 3, 3);

    position pos = getMinValuePos(m);

    assert(pos.rowIndex == 2 && pos.colIndex == 2);

    freeMemMatrix(&m);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray((int []) {1, 2, 3, 4, 5, 6, 7, 8, 9}, 3, 3);

    position pos = getMaxValuePos(m);

    assert(pos.rowIndex == 2 && pos.colIndex == 2);

    freeMemMatrix(&m);
}

void test(){
    test_input();
    test_output();
    test_swapRows();
   test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_selectionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_transposeMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {
    test();

    return 0;
}