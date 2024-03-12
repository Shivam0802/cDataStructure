#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } 
        else if (arr[mid] < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void bubbleSort(int arr[], int size) {
    int i, j;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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
    
    int arr1[size];
    bubbleSort(arr, size);
    printf("Sorted array: \n");
    for (int i=0; i < size; i++) {
        for (int i = 0; i < size; i++) {
            arr1[i] = arr[i];
        }
        printf("%d ", arr1[i]);
    }
    int index = binarySearch(arr1, size, target);

    if (index != -1) {
        printf("\nElement found at index %d",index);
    } else {
        printf("\nElement not found");
    }
}


