#include <stdio.h>
#include <stdlib.h>

void read(int b[100], int n)
{
    int i;
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);
}

void Search(int b[100], int n, int key)
{
    int low=0, high=n-1, mid, comp=0;
    while(low <= high)
    {
        mid = (low + high) / 2;
        comp++;
        if(b[mid] == key)
        {
            printf("Element %d found at %d", key, mid+1);
            printf("\nNo of comparisons: %d", comp);
            return;
        }
        else if(b[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("Element not found");
    printf("\nNo of comparisons: %d", comp);
}

int main()
{
    int n, a[100], key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    read(a, n);
    printf("Enter the key element: ");
    scanf("%d", &key);
    Search(a, n, key);
    return 0;
}
