#include<stdio.h>
#include<stdlib.h>

// Structure to represent a sparse matrix element
struct Element{
    int row;
    int col;
    int value;
};

// Structure to represent a sparse matrix
struct SparseMatrix{
    int no_rows;
    int no_cols;
    int num_elements;
    struct Element *data;
}; 

// Function to create a sparse matrix from user input
void CreateSparseMatrix(struct SparseMatrix *S) {
    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &S->no_rows, &S->no_cols);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &S->num_elements);
    S->data = (struct Element *)malloc(S->num_elements * sizeof(struct Element));
    printf("Enter non-zero elements (row, column, value):\n");
    for (int i = 0; i < S->num_elements; i++) {
        scanf("%d %d %d", &S->data[i].row, &S->data[i].col, &S->data[i].value);
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(struct SparseMatrix *S) {
    printf("Sparse Matrix:\n");
    printf("Rows: %d, Columns: %d\n", S->no_rows, S->no_cols);
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < S->num_elements; i++) {
        printf("%d\t%d\t%d\n", S->data[i].row, S->data[i].col, S->data[i].value);
    }
}

// Function to transpose a sparse matrix
void TransposeSparseMatrix(struct SparseMatrix *S) {
    struct SparseMatrix *transposed;
    transposed->no_rows = S->no_cols;
    transposed->no_cols = S->no_rows;
    transposed->num_elements = S->num_elements;
    transposed->data = (struct Element *)malloc(transposed->num_elements * sizeof(struct Element));
    int *count = (int *)calloc(S->no_cols, sizeof(int));
    for (int i = 0; i < S->num_elements; i++) {
        count[S->data[i].col]++;
    }
    int *index = (int *)calloc(S->no_cols, sizeof(int));
    index[0] = 0;
    for (int i = 1; i < S->no_cols; i++) {
        index[i] = index[i - 1] + count[i - 1];
    }
    for (int i = 0; i < S->num_elements; i++) {
        int j = S->data[i].col;
        transposed->data[index[j]].row = S->data[i].col;
    }
    displaySparseMatrix(transposed);
}

// Function to add two sparse matrices
void AddSparseMatrix(struct SparseMatrix *S1, struct SparseMatrix *S2) {
    struct SparseMatrix *result;
    result->no_rows = S1->no_rows;
    result->no_cols = S1->no_cols;
    result->num_elements = S1->num_elements + S2->num_elements;
    result->data = (struct Element *)malloc(result->num_elements * sizeof(struct Element));
    int i = 0, j = 0, k = 0;
    while (i < S1->num_elements && j < S2->num_elements) {
        if (S1->data[i].row < S2->data[j].row) {
            result->data[k++] = S1->data[i++];
        } else if (S1->data[i].row > S2->data[j].row) {
            result->data[k++] = S2->data[j++];
        } else {
            if (S1->data[i].col < S2->data[j].col) {
                result->data[k++] = S1->data[i++];
            } else if (S1->data[i].col > S2->data[j].col) {
                result->data[k++] = S2->data[j++];
            } else {
                result->data[k].row = S1->data[i].row;
                result->data[k].col = S1->data[i].col;
                result->data[k].value = S1->data[i].value + S2->data[j].value;
                k++;
                i++;
                j++;
            }
        }
    }
    while (i < S1->num_elements) {
        result->data[k++] = S1->data[i++];
    }
    while (j < S2->num_elements) {
        result->data[k++] = S2->data[j++];
    }
    result->num_elements = k;
    displaySparseMatrix(result);
}

// Function to multiply two sparse matrices
void MultiplySparseMatrix(struct SparseMatrix *S1, struct SparseMatrix *S2) {
    struct SparseMatrix *result;
    result->no_rows = S1->no_rows;
    result->no_cols = S2->no_cols;
    result->num_elements = 0;
    result->data = (struct Element *)malloc(result->num_elements * sizeof(struct Element));
    for (int i = 0; i < S1->num_elements; i++) {
        for (int j = 0; j < S2->num_elements; j++) {
            if (S1->data[i].col == S2->data[j].row) {
                int value = 0;
                for (int k = 0; k < S1->num_elements; k++) {
                    if (S1->data[k].col == S1->data[i].col && S2->data[j].row == S2->data[k].row) {
                        value += S1->data[k].value * S2->data[k].value;
                    }
                }
                result->data[result->num_elements].row = S1->data[i].row;
                result->data[result->num_elements].col = S2->data[j].col;
                result->data[result->num_elements].value = value;
                result->num_elements++;
            }
        }
    }
    displaySparseMatrix(result);
}

void main(){
    struct SparseMatrix *matrix ;

    for(int i=0;i<2;i++){
        CreateSparseMatrix(matrix);
    }

    for(int i=0;i<2;i++){
        displaySparseMatrix(matrix);
    }

    int choice;
    printf("Enter Your Choice of operation on matrix : \n");
    printf("1. Addition\n2. Transpose\n3. Multiplication\n->");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            // Add two sparse matrices
            AddSparseMatrix(matrix, matrix);
            break;
        case 2:
            // Transpose a sparse matrix
            TransposeSparseMatrix(matrix);
            break;
        case 3:
            // Multiply two sparse matrices
            MultiplySparseMatrix(matrix, matrix);
            break;
        default:
            printf("Invalid choice\n");
    }
}