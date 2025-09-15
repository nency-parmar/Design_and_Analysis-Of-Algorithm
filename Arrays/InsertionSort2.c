#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int read_array_from_file(const char *filename, int arr[])
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Failed to open file");
        return -1;
    }

    int i = 0;
    while (fscanf(file, "%d ,", &arr[i]) == 1 && i < N)
    {
        i++;
    }

    fclose(file);
    return i; // Return the number of elements read
}

int main()
{
    int arr[N];
    int n = read_array_from_file("avg_case100000_ele.txt", arr);

    if (n < 0)
    {
        return EXIT_FAILURE; // Error reading file
    }

    printf("Array before sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    InsertionSort(arr, n);

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}