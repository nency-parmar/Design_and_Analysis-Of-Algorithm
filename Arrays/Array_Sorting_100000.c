#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

void w_best_case()
{
    FILE *f = fopen("best_case100000_ele.txt", "w");
    for (int i = 0; i <= N; i++)
    {
        fprintf(f, "%d , ", i);
    }
    fclose(f);
}

void w_worst_case()
{
    FILE *f = fopen("worst_case100000_ele.txt", "w");
    for (int i = N; i >= 1; i--)
    {
        fprintf(f, "%d , ", i);
    }
    fclose(f);
}

void w_avg_case()
{
    int arr[N];
    int temp;

    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    srand(time(NULL));
    for (int i = N - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    FILE *f = fopen("avg_case100000_ele.txt", "w");
    for (int i = 0; i < N; i++)
    {
        fprintf(f, "%d , ", arr[i]);
    }
    fclose(f);
}

int main()
{
    w_best_case();
    w_worst_case();
    w_avg_case();
}