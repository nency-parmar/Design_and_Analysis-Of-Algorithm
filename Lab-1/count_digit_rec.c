#include <stdio.h>
int digit(int n);
int main() {
    int n, count;
    printf("Enter a Number: ");
    scanf("%d", &n);
    if(n == 0)
    {
        count = 1;
    }
    else
    {
        count = digit(n);
    }
    printf("Number of digits: %d\n", count);
    return 0;
}
int digit(int n) 
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return 1 + digit(n / 10);
    }
}