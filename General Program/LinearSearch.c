#include<stdio.h>
#include<stdlib.h>

void LinearSearch(int arr[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Element found at index %d\n", i+1);
            return;
        }
    }
    printf("Element not found\n");
}

void main() {
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    LinearSearch(arr, size, target);
}

