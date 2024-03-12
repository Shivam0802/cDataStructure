#include <stdio.h>

void multiplyMatrices(int ROWS, int COLS, int Mat1[ROWS][COLS], int Mat2[ROWS][COLS], int Result[ROWS][COLS]) {
    int i, j, k;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            Result[i][j] = 0;
            for (k = 0; k < COLS; k++) {
                Result[i][j] += Mat1[i][k] * Mat2[k][j];
            }
        }
    }
}

void displayMatrix(int ROWS, int COLS, int matrix[ROWS][COLS]) {

    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int mat1[rows][cols];
    printf("Enter elements of matrix 1:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Matrix 1:\n");
    displayMatrix(rows, cols, mat1);

    int mat2[rows][cols];
    printf("Enter elements of matrix 2:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    printf("\nMatrix 2:\n");
    displayMatrix(rows, cols ,mat2);
   
    int result[rows][cols];

    multiplyMatrices(rows, cols, mat1, mat2, result);

    printf("\nResultant Matrix:\n");
    displayMatrix(rows, cols, result);
}




