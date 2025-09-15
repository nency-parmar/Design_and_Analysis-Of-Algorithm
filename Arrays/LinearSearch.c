#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100

void linearsearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[n] == key)
        {
            printf("%d", i);
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
        linearsearch(arr, N, 1);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Best Case Time : %f ms\n", time_taken);
    }

    if (readArray("avg_case100_ele.txt", arr, N))
    {
        start = clock();
        linearsearch(arr, N, 50);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Avg Case Time : %f ms\n", time_taken);
    }

    if (readArray("worst_case100_ele.txt", arr, N))
    {
        start = clock();
        linearsearch(arr, N, 100);
        end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        printf("Worst Case Time : %f ms\n", time_taken);
    }
}