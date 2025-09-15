#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

void BinarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
        {
            printf("Element found at %d\n", mid);
            return;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            printf("Element not found\n");
            return;
        }
    }
}

int readArray(const char *filename, int arr[], int n)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("Can't Open File : %s\n", filename);
        return 0; // return 0 to indicate failure
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &arr[i]);
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
        BinarySearch(arr, N, 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time : %f ms\n", time_taken);
    }

    if (readArray("avg_case100000_ele.txt", arr, N))
    {
        start = clock();
        BinarySearch(arr, N, 50000);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Avg Case Time : %f ms\n", time_taken);
    }

    if (readArray("worst_case100000_ele.txt", arr, N))
    {
        start = clock();
        BinarySearch(arr, N, 100000);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time : %f ms\n", time_taken);
    }
    return 0;
}