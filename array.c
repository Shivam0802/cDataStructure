#include <stdio.h>

#define ROWS 3
#define COLS 3

void displayArray(int arr[ROWS][COLS]) {
    printf("Array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void initializeArray(int arr[ROWS][COLS]) {
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void transposeArray(int arr[ROWS][COLS]) {
    int temp;
    for (int i = 0; i < ROWS; i++) {
        for (int j = i + 1; j < COLS; j++) {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

void sumArray(int arr1[ROWS][COLS], int arr2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void differenceArray(int arr1[ROWS][COLS], int arr2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

void multiplyArray(int arr1[ROWS][COLS], int arr2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main() {
    int array1[ROWS][COLS];
    int array2[ROWS][COLS];
    int result[ROWS][COLS];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Initialize Array 1\n");
        printf("2. Initialize Array 2\n");
        printf("3. Display Array 1\n");
        printf("4. Display Array 2\n");
        printf("5. Transpose Array 1\n");
        printf("6. Transpose Array 2\n");
        printf("7. Sum of Arrays\n");
        printf("8. Difference of Arrays\n");
        printf("9. Multiply Arrays\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeArray(array1);
                break;
            case 2:
                initializeArray(array2);
                break;
            case 3:
                displayArray(array1);
                break;
            case 4:
                displayArray(array2);
                break;
            case 5:
                transposeArray(array1);
                break;
            case 6:
                transposeArray(array2);
                break;
            case 7:
                sumArray(array1, array2, result);
                displayArray(result);
                break;
            case 8:
                differenceArray(array1, array2, result);
                displayArray(result);
                break;
            case 9:
                multiplyArray(array1, array2, result);
                displayArray(result);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}