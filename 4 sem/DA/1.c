#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[N];
    int i, index;
    clock_t start, end;
    double total_time;

    // Fill array with random numbers
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 10000;
    }

    printf("Linear Search Analysis (Size: 100000)\n");

    // CASE 1: BEST CASE (First Element)
    start = clock();
    index = linearSearch(arr, N, arr[0]);
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Best Case Time: %f seconds\n", total_time);

    // CASE 2: MEDIUM CASE (Last Element - arr[99999])
    start = clock();
    index = linearSearch(arr, N, arr[N - 1]);
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Medium Case Time: %f seconds\n", total_time);

    // CASE 3: WORST CASE (Not Found -10)
    start = clock();
    index = linearSearch(arr, N, -10);
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Worst Case Time: %f seconds\n", total_time);

    return 0;
}