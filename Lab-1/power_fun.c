#include<stdio.h>
int power(int n);
int main()
{
    int a,b;
    printf("Enter a Number: ");
    scanf("%d", &a);
    printf("Enter a Power: ");
    scanf("%d", &b);
    int i = 0, ans = 1;
    while (i<b)
    {
       ans = ans * i;
       i++;
    }
    printf("%d^%d is : %d",a,b,ans);
    return 0;
}