#include <stdio.h>
#include <stdlib.h>
#define size 100

int Binary_Search(int arr[size], int n, int key, int high, int low) {
    if (low <= high) {
        int mid = (low + high) / 2;
        if (key == arr[mid])
            return mid;
        else if (key > arr[mid])
            return Binary_Search(arr, n, key, high, mid + 1);
        else
            return Binary_Search(arr, n, key, mid - 1, low);
    }
    return -1;
}

int main() {
    int arr[size], n, key;
    printf("Enter the size of the array \n");
    scanf("%d", &n);
    
    printf("Enter the array elements \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the key element to be searched \n");
    scanf("%d", &key);
    
    if (Binary_Search(arr, n, key, n - 1, 0) != -1) {
        printf("Key is found at %d", Binary_Search(arr, n, key, n - 1, 0) + 1);
    } else {
        printf("key not found");
    }
    return 0;
}