#include <stdio.h>
int sum(int n);
int main() 
{
    int n;
    int ans = 0;
    printf("Enter a Number: ");
    scanf("%d", &n);
    ans = sum(n);
    printf("Sum of %d is : %d\n", n, ans);
    return 0;
}

int sum(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return sum(n - 1) + n;
}