#include <stdio.h>
int power(int x, int y);
int main()
{
    int a;
    printf("Enter a Number: ");
    scanf("%d", &a);
    int b;
    printf("Enter a Power: ");
    scanf("%d", &b);
    int ans;
    ans = power(a, b);
    printf("%d", ans);
}

int power(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, y - 1);
    }
}