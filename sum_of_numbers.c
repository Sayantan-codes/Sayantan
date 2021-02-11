//Write a program to find the sum of n different numbers using 4 functions
#include<stdio.h>
#include<math.h>
void main()
{
    int n; printf("Enter the number of no.s\n");
    scanf("%d",&n);
    int s=0,x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        s+=x;
    }
    printf("Required sum is %d ",s);
}

