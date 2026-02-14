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
    int i, j, t, swap=0, comp=0, flag=0;
    for(i=0; i<n-1; i++)
    {
        flag=0;
        for(j=0; j<n-i-1; j++)
        {
            if(b[j] > b[j+1])
            {
                t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
                swap++;
                flag=1;
            }
            comp++;
        }
        if(flag==0)
        {
            break;
        }
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