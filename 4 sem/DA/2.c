#include <stdio.h>
#include <stdlib.h>

void read(int b[100], int n)
{
    int i;
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);
}

void display(int b[100], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d\t", b[i]);
}

void sort(int b[100], int n)
{
    int i, j, t, min, swap=0, comp=0;
    for(i=0; i<n; i++)
    {
        min=i;
        for(j=i+1; j<n; j++)
        {
            comp++;
            if(b[j] < b[min])
            {
                min=j;
            }
        }
        t = b[i];
        b[i] = b[min];
        b[min] = t;
        swap++;
    }
    printf("\nNo of swaps: %d \nNo of comparisons: %d", swap, comp);
}

int main()
{
    int n, a[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    read(a, n);
    printf("Elements are: ");
    display(a, n);
    sort(a, n);
    printf("\nSorted array: ");
    display(a, n);
    return 0;
}