#include<stdio.h>
int fact(int n);
int main() 
{
    int n = 1;
    int ans = 1;
    printf("Enter a Number: ");
    scanf("%d", &n);
    ans = fact(n);
    printf("Factorial of %d is : %d\n", n, ans);
}

int fact(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fact(n-1) * n;
    }
}