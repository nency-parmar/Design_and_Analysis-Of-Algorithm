#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack Overflow!!!\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Emptyy!!!\n");
    }
    else
    {
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty!!!\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    printf("------------------\n");
    pop();
    display();
}
