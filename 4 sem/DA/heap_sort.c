#include <stdio.h>
#include <stdlib.h>

// Forward declarations
void heapify(int arr[], int n, int i);
void swap(int *a, int *b);
void printarray(int arr[], int n);

void heapsort(int arr[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        printf("\n");
        printarray(arr,i);
        heapify(arr, i, 0);
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

int main()
{
    int arr[20], n;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapsort(arr, n);

    printf("Sorted array is:\n");
    printarray(arr, n);

    return 0;
}
