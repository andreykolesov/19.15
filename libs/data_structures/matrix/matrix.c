#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);

    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);

    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);

    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);

    free(ms);
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; i < m->nCols; i++)
            scanf("%d", &(m->values[i][j]));
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; i < m.nCols; i++)
            printf("%d", m.values[i][j]);

        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);

        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    assert (i1 >= 0 && i1 < m.nRows);
    assert (i2 >= 0 && i2 < m.nRows);

    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    assert (j1 >= 0 && j1 < m.nCols);
    assert (j2 >= 0 && j2 < m.nCols);

    for (int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = temp;
    }
}

int getSum(int *a, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*getSum)(int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; i++)
        a[i] = getSum(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            m.values[j + 1] = m.values[j];
            j--;
        }

        a[j + 1] = key;
        swapRows(m, j + 1, i);
    }
}

void selectionSortColsMatrixByColCriteria(matrix m, int (*getSum)(int *, int)) {
    int *col_values = (int *) malloc(sizeof(int) * m.nCols);

    for (int i = 0; i < m.nCols; i++) {
        int *cols = (int *) malloc(sizeof(int) * m.nRows);

        for (int j = 0; j < m.nRows; j++) {
            cols[j] = m.values[j][i];
        }

        col_values[i] = getSum(cols, m.nRows);
    }

    for (int i = 0; i < m.nCols - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < m.nCols; j++) {
            if (col_values[j] < col_values[min_index])
                min_index = j;
        }

        swapColumns(m, min_index, i);
        int temp = col_values[min_index];
        col_values[min_index] = col_values[i];
        col_values[i] = temp;
    }
}


