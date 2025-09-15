#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #define N 100000

void Merge(int arr[], int low, int mid, int high)
{
    int h = low;
    int i = 0;
    int j = mid + 1;
    int b[high - low + 1];
    while (h <= mid && j <= high)
    {
        if (arr[h] <= arr[j])
        {s
            b[i] = arr[h];
            h++;
        }
        else
        {
            b[i] = arr[j];
            j++;
        }
        i++;
    }
    if (h > mid)
    {
        for (int k = j; k <= high; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            b[i] = arr[k];
            i++;
        }
    }
    for (int k = 0; k < i; k++)
    {
        arr[low + k] = b[k];
    }
}

void MergeSort(int arr[], int low, int high)
{
    int mid = 0;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

// int readArray(const char *filename, int arr[], int n)
// {
//     FILE *f = fopen(filename, "r");
//     if (!f)
//     {
//         printf("Can't Open File : %s\n", filename);
//         return 0;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         fscanf(f, "%d ", &arr[i]);
//     }
//     fclose(f);
//     return 1;
// }

int main()
{
    // int arr[N];
    // clock_t start, end;
    // double time_taken;

    int arr1[] = [ 4, 3, 5, 2, 86, 34, 65, 76, 43 ];
    MergeSort(arr1, 0, 8);

    // if (readArray("best_case100000_ele.txt", arr, N))
    // {
    //     start = clock();
    //     MergeSort(arr, 0, N);
    //     end = clock();
    //     time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    //     printf("Best Case Time : %f ms\n", time_taken);
    // }

    // if (readArray("avg_case100000_ele.txt", arr, N))
    // {
    //     start = clock();
    //     MergeSort(arr, 0, N);
    //     end = clock();
    //     time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    //     printf("\nAverage Case Time : %f ms\n", time_taken);
    // }

    // if (readArray("worst_case100000_ele.txt", arr, N))
    // {
    //     start = clock();
    //     MergeSort(arr, 0, N);
    //     end = clock();
    //     time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    //     printf("\nWorst Case Time : %f ms\n", time_taken);
    // }
}