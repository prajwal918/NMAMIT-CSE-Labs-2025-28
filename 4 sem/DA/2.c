//selection sort


#include <stdio.h> // Corrected: Added stdio.h for printf/scanf

#define max 100

// Function Prototypes (Required in C if functions are defined after main)
void read(int a[], int n);
void display(int a[], int n);
void selectionSort(int a[], int n);

int main()
{
    int a[max], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    read(a, n);
    
    printf("\nBefore sorting:\n");
    display(a, n);
    
    selectionSort(a, n);
    
    printf("\nAfter sorting:\n");
    display(a, n);
    
    return 0;
}

void read(int a[], int n)
{
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n"); // Added newline for cleaner output
}

void selectionSort(int a[], int n)
{
    int temp, min, comp = 0, swap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            comp++;
            if (a[j] < a[min])
            {
                swap++; // Counts how often we find a NEW minimum
                min = j;
            }
        }
        // Swapping happens here
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("\nInternal Stats - Updates to min: %d, Comparisons: %d\n", swap, comp);
}