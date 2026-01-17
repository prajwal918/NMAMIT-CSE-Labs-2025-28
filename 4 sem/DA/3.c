// bubblesort


#include <stdio.h>

#define MAX 100 // Maximum array size

// Function Prototypes
void read(int a[], int n);
void bubblesort(int a[], int n);
void display(int a[], int n);

int main()
{
    int a[MAX], n;

    // 1. Input the size of the array
    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    // Check if the user input fits in our array
    if (n > MAX || n < 1) {
        printf("Please enter a valid number between 1 and %d.\n", MAX);
        return 1; // Exit with error
    }

    // 2. Read the elements
    read(a, n);

    // 3. Sort the array
    printf("\nBefore sorting: ");
    display(a, n);

    bubblesort(a, n);

    printf("After sorting:  ");
    display(a, n);

    return 0;
}

// Function to read user input
void read(int a[], int n)
{
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

// Function to print the array
void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// The Bubble Sort Logic
void bubblesort(int a[], int n)
{
    int temp;
    
    // Outer loop: Controls the number of passes
    for(int i = 0; i < n - 1; i++)
    {
        // Inner loop: Compares adjacent elements
        // 'n - i - 1' ensures we don't re-check the already sorted elements at the end
        for(int j = 0; j < n - i - 1; j++)
        {
            // Swap if the left element is bigger than the right element
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}