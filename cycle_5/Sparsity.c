#include <stdio.h>
#include <stdlib.h>

struct Element {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int rows;
    int cols;
    int num_elements;
    struct Element *elements;
};

void create_sparse_matrix(struct SparseMatrix *matrix, int rows, int cols, int num_elements) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->num_elements = num_elements;
    matrix->elements = (struct Element*) malloc(num_elements * sizeof(struct Element));
}

void display_sparse_matrix(struct SparseMatrix matrix) {
    int i, j, k = 0;
    for (i = 0; i < matrix.rows; i++) {
        for (j = 0; j < matrix.cols; j++) {
            if (k < matrix.num_elements && matrix.elements[k].row == i && matrix.elements[k].col == j) {
                printf("%d ", matrix.elements[k].value);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

float calculate_sparsity(struct SparseMatrix matrix) {
    return (float) (matrix.rows * matrix.cols - matrix.num_elements) / (matrix.rows * matrix.cols);
}

int main() {
    struct SparseMatrix matrix;
    create_sparse_matrix(&matrix, 4, 4, 4);
    matrix.elements[0].row = 0;
    matrix.elements[0].col = 0;
    matrix.elements[0].value = 1;
    matrix.elements[1].row = 1;
    matrix.elements[1].col = 1;
    matrix.elements[1].value = 2;
    matrix.elements[2].row = 2;
    matrix.elements[2].col = 2;
    matrix.elements[2].value = 3;
    matrix.elements[3].row = 3;
    matrix.elements[3].col = 3;
    matrix.elements[3].value = 4;
    display_sparse_matrix(matrix);
    printf("Sparsity: %f\n", calculate_sparsity(matrix));
    return 0;
}

