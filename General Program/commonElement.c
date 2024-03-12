#include <stdio.h>

int removeDuplicates(int arr[], int size)
{
    if (size == 0 || size == 1)
        return size;
 
    int temp[size];

    int j = 0;

    for (int i = 0; i < size - 1; i++){
        if (arr[i] != arr[i + 1]){
            temp[j++] = arr[i];
        }
    }

    temp[j++] = arr[size - 1];

    for (int i = 0; i < j; i++){
        arr[i] = temp[i];
    }

    return j;
}

void findCommonElements(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            i++;
        } 
        else if (arr1[i] > arr2[j]) {
            j++;
        } 
        else {
            printf("%d ", arr1[i]);
            while (i < m && arr1[i] == arr1[i + 1]) {
                i++;
            }
            while (j < n && arr2[j] == arr2[j + 1]) {
                j++;
            }
            i++;
            j++;
        }
    }
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

int main() {
    int m;
    printf("Enter the size of the first array: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter the elements of the first array:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
    }

    int n;
    printf("Enter the size of the second array: ");
    scanf("%d", &n);

    int arr2[n];
    printf("Enter the elements of the second array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    int temp1[m];
    bubbleSort(arr1, m);
    printf("\nArray 1 after sorting: ");
    for(int i = 0; i < m; i++){
        temp1[i] = arr1[i];
        printf("%d ", temp1[i]);
    }
    m = removeDuplicates(temp1, m);
    printf("\nArray 1 after removing duplicates: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", temp1[i]);
    }

    printf("\n");
    int temp2[n];
    bubbleSort(arr2, n);
    printf("\nArray 2 after sorting: ");
    for(int i = 0; i < n; i++){
        temp2[i] = arr2[i];
        printf("%d ", temp2[i]);
    }
    n = removeDuplicates(temp2, n);
    printf("\nArray 2 after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", temp2[i]);
    }

    printf("\nCommon elements: ");
    findCommonElements(temp1, m, temp2, n);

    return 0;
}


