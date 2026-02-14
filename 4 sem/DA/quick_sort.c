#include <stdio.h>
#include <stdlib.h>

int a[100];

void read(int n) {
    int i;
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display(int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

int partition(int low, int high) {
    int p = a[low], i = low, j = high + 1, temp;
    do {
        do {
            i++;
        } while (p >= a[i] && i < high);

        do {
            j--;
        } while (p < a[j]);

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}

void quicksort(int low, int high) {
    if (low < high) {
        int k = partition(low, high);
        quicksort(low, k - 1);
        quicksort(k + 1, high);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    read(n);
    printf("Elements are: ");
    display(n);
    quicksort(0, n - 1);
    printf("\nSorted array: ");
    display(n);
    return 0;
}
