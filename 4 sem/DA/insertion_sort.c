#include <stdio.h>

void insertion_sort(int a[], int n) {
    int i, j, item;
    for (i = 1; i < n; i++) {
        item = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > item) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = item;
    }
}

int main() {
    int a[100], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    insertion_sort(a, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}

