#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void BubbleSort(int arr[], int n)
{
    int i, j, temp;
    int swapped = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; i++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        if (swapped == 0)
            break;
    }
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    if (readArray("best_case100_ele.txt", arr, N))
    {
        start = clock();
        BubbleSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time : %f ms\n", time_taken);
    }

    if (readArray("avg_case100_ele.txt", arr, N))
    {
        start = clock();
        BubbleSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Average Case Time : %f ms\n", time_taken);
    }

    if (readArray("worst_case100_ele.txt", arr, N))
    {
        start = clock();
        BubbleSort(arr, N);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time : %f ms\n", time_taken);
    }
}