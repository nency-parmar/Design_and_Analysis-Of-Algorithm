#include <stdio.h>
#define SIZE 100

int queue[SIZE];
int f = -1;
int r = -1;

void enqueue(int ele)
{
    if (r == SIZE - 1)
    {
        printf("Queue Overflow!!!\n");
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        r++;
        int top = SIZE - 1 - r;
        if (top < 0)
        {
            printf("Queue Overflow!!!\n");
            return;
        }
        queue[top] = ele;
    }
}

void dequeue()
{
    if (f == -1 || f > r)
    {
        printf("Queue Underflow!!!\n");
    }
    else
    {
        int top = SIZE - 1 - f;
        f++;
        if (f > r)
        {
            f = -1;
            r = -1;
        }
    }
}

void display()
{
    if (f == -1 || f > r)
    {
        printf("Queue is empty!!!\n");
    }
    else
    {
        for (int i = f; i <= r; i++)
        {
            int top = SIZE - 1 - i;
            printf("%d\n", queue[top]);
        }
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    printf("After dequeue:\n");
    display();
}