#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

int pivot(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = pivot(arr, low, high);
        QuickSort(arr, low, pi);
        QuickSort(arr, pi + 1, high);
    }
}

int readArray(const char *filename, int arr[], int n)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("Can't Open File: %s\n", filename);
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

    if (readArray("best_case100_ele.txt", arr, N))
    {
        start = clock();
        QuickSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time : %f ms\n", time_taken);
    }

    if (readArray("avg_case100_ele.txt", arr, N))
    {
        start = clock();
        QuickSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("\nAverage Case Time : %f ms\n", time_taken);
    }

    if (readArray("worst_case100_ele.txt", arr, N))
    {
        start = clock();
        QuickSort(arr, 0, N - 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("\nWorst Case Time : %f ms\n", time_taken);
    }
}