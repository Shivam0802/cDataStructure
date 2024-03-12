#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a sparse matrix element
typedef struct {
    int row;
    int col;
    int value;
} Element;

// Structure to represent a sparse matrix
typedef struct {
    int rows;
    int cols;
    int num_elements;
    Element data[MAX_SIZE];
} SparseMatrix;

// Function to read a sparse matrix from user input
SparseMatrix readSparseMatrix() {
    SparseMatrix matrix;
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &matrix.rows, &matrix.cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &matrix.num_elements);
    printf("Enter non-zero elements (row, column, value):\n");
    for (int i = 0; i < matrix.num_elements; i++) {
        scanf("%d %d %d", &matrix.data[i].row, &matrix.data[i].col, &matrix.data[i].value);
    }
    return matrix;
}

// Function to display a sparse matrix
void displaySparseMatrix(SparseMatrix matrix) {
    printf("Sparse Matrix:\n");
    printf("Rows: %d, Columns: %d\n", matrix.rows, matrix.cols);
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < matrix.num_elements; i++) {
        printf("%d\t%d\t%d\n", matrix.data[i].row, matrix.data[i].col, matrix.data[i].value);
    }
}

// Function to transpose a sparse matrix
SparseMatrix transposeSparseMatrix(SparseMatrix matrix) {
    SparseMatrix transposed;
    transposed.rows = matrix.cols;
    transposed.cols = matrix.rows;
    transposed.num_elements = matrix.num_elements;
    for (int i = 0; i < matrix.num_elements; i++) {
        transposed.data[i].row = matrix.data[i].col;
        transposed.data[i].col = matrix.data[i].row;
        transposed.data[i].value = matrix.data[i].value;
    }
    return transposed;
}

// Function to add two sparse matrices
SparseMatrix addSparseMatrices(SparseMatrix matrix1, SparseMatrix matrix2) {
    SparseMatrix result;
    // Initialize result matrix dimensions
    result.rows = matrix1.rows;
    result.cols = matrix1.cols;
    // Initialize result matrix elements
    int index1 = 0, index2 = 0, index_result = 0;
    while (index1 < matrix1.num_elements && index2 < matrix2.num_elements) {
        // If the current element of matrix1 comes before the current element of matrix2
        if (matrix1.data[index1].row < matrix2.data[index2].row ||
            (matrix1.data[index1].row == matrix2.data[index2].row &&
             matrix1.data[index1].col < matrix2.data[index2].col)) {
            result.data[index_result++] = matrix1.data[index1++];
        }
        // If the current element of matrix2 comes before the current element of matrix1
        else if (matrix1.data[index1].row > matrix2.data[index2].row ||
                 (matrix1.data[index1].row == matrix2.data[index2].row &&
                  matrix1.data[index1].col > matrix2.data[index2].col)) {
            result.data[index_result++] = matrix2.data[index2++];
        }
        // If both elements are at the same position, add their values
        else {
            result.data[index_result].row = matrix1.data[index1].row;
            result.data[index_result].col = matrix1.data[index1].col;
            result.data[index_result].value = matrix1.data[index1].value + matrix2.data[index2].value;
            index1++;
            index2++;
            index_result++;
        }
    }
    // Copy the remaining elements from matrix1, if any
    while (index1 < matrix1.num_elements) {
        result.data[index_result++] = matrix1.data[index1++];
    }
    // Copy the remaining elements from matrix2, if any
    while (index2 < matrix2.num_elements) {
        result.data[index_result++] = matrix2.data[index2++];
    }
    result.num_elements = index_result;
    return result;
}

// Function to multiply two sparse matrices
SparseMatrix multiplySparseMatrices(SparseMatrix matrix1, SparseMatrix matrix2) {
    SparseMatrix result;
    // Initialize result matrix dimensions
    result.rows = matrix1.rows;
    result.cols = matrix2.cols;
    // Initialize result matrix elements
    result.num_elements = 0;
    for (int i = 0; i < matrix1.num_elements; i++) {
        for (int j = 0; j < matrix2.num_elements; j++) {
            if (matrix1.data[i].col == matrix2.data[j].row) {
                // Calculate value for result matrix
                int value = 0;
                for (int k = 0; k < matrix1.num_elements; k++) {
                    if (matrix1.data[k].col == matrix1.data[i].col && matrix2.data[j].row == matrix2.data[k].row) {
                        value += matrix1.data[k].value * matrix2.data[k].value;
                    }
                }
                // Insert non-zero element into result matrix
                result.data[result.num_elements].row = matrix1.data[i].row;
                result.data[result.num_elements].col = matrix2.data[j].col;
                result.data[result.num_elements].value = value;
                result.num_elements++;
            }
        }
    }
    return result;
}

int main() {
    SparseMatrix matrix1, matrix2, result;
    int choice;

    printf("Sparse Matrix Operations Menu:\n");
    printf("1. Transpose\n");
    printf("2. Addition\n");
    printf("3. Multiplication\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            matrix1 = readSparseMatrix();
            result = transposeSparseMatrix(matrix1);
            printf("Transposed Matrix:\n");
            displaySparseMatrix(result);
            break;
        case 2:
            matrix1 = readSparseMatrix();
            matrix2 = readSparseMatrix();
            result = addSparseMatrices(matrix1, matrix2);
            printf("Result of Addition:\n");
            displaySparseMatrix(result);
            break;
        case 3:
            matrix1 = readSparseMatrix();
            matrix2 = readSparseMatrix();
            result = multiplySparseMatrices(matrix1, matrix2);
            printf("Result of Multiplication:\n");
            displaySparseMatrix(result);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}
