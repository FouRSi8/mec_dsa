#include <stdio.h>

void computeAv(int A[][3], int v[], int result[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        result[i] = 0;
        for (j = 0; j < n; j++) {
            result[i] += A[i][j] * v[j];
        }
    }
}

int main() {
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int v[3] = {1, 2, 3};
    int result[3];
    int n = 3;

    computeAv(A, v, result, n);

    printf("A.v = [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("]\n");

    return 0;
}

