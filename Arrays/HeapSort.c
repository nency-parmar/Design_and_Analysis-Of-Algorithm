#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void heapify(int arr[], int n, int i)
{
    int max = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[max])
    {
        max = l;
    }
    if (r < n && arr[r] > arr[max])
    {
        max = r;
    }
    if (max != i)
    {
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int readArray(const char *filename, int arr[], int n)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("Can't Open File : %s\n", filename);
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d ", &arr[i]);
    }
    fclose(f);
    return 1;
}

int main()
{
    int arr[N];
    clock_t start, end;
    double time_taken;

    if (readArray("best_case100000_ele.txt", arr, N))
    {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time : %f ms\n", time_taken);
    }

    if (readArray("avg_case100000_ele.txt", arr, N))
    {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("\nAverage Case Time : %f ms\n", time_taken);
    }

    if (readArray("worst_case100000_ele.txt", arr, N))
    {
        start = clock();
        heapSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("\nWorst Case Time : %f ms\n", time_taken);
    }
}