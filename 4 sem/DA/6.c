#include <stdio.h>
#include <stdlib.h>

void read(int b[100], int n){
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
}

void display(int b[100], int n){
    printf("The elements: ");
    for(int i = 0; i < n; i++)
        printf("%d ", b[i]);
}

void merge(int b[100], int l, int m, int h){
    int i, j, k, c[100];
    i = l;
    j = m + 1;
    k = l;
    while(i <= m && j <= h){
        if(b[i] < b[j]){
            c[k] = b[i];
            k++;
            i++;
        }
        else{
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while(i <= m){
        c[k] = b[i];
        k++;
        i++;
    }
    while(j <= h){
        c[k] = b[j];
        k++;
        j++;
    }
    for(int i = l; i <= h; i++)
        b[i] = c[i];
}

void merge_sort(int b[100], int l, int h){
    int mid;
    if(l < h){
        mid = (l + h)/2;
        merge_sort(b, l, mid);
        merge_sort(b, mid + 1, h);
        merge(b, l, mid, h);
    }
}

int main()
{
    int a[100], l, h, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    read(a, n);
    merge_sort(a, 0, n - 1);
    printf("After sorting: ");
    display(a, n);
    return 0;
}