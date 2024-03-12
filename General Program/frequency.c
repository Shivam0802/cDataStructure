#include <stdio.h>

 void findFrequency(int arr[], int n) {
    int freq[n]; 
    int visited[n]; 

    for (int i = 0; i < n; i++) {
        freq[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }
        freq[i] = count;
    }
    printf("Element\tFrequency\n");
    for (int i = 0; i < n; i++) {
        if (freq[i] != 0)
            printf("%d\t%d\n", arr[i], freq[i]);
    }
}

void main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    findFrequency(arr, size);
}


