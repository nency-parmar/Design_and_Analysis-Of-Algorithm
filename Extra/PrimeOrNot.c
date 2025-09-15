#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 0;
    int count = 0;
    printf("Enter a Number : \n");
    scanf("%d",&a);
    if(a<2)
    {
        printf("Number is not Prime!!!");
        return 0;
    }
    for(int i=2; i <= a/2; i++)
    {
        if(a % i == 0)
        {
            count++;
        }
    }
    
    if(count == 2)
    {
        printf("Number is Prime!!!");
    }
    else{
        printf("Number is not Prime!!!");
    }
}