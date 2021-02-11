//Write a program to add two user input numbers using 4 functions.
#include<stdio.h>
void inp();
void calculate(int n1,int n2);
void show(int n1,int n2, int s);
void main()
{
    inp();
}
void inp()
{
    printf("Enter two numbers\n");
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    calculate(n1,n2);
}
void calculate(int n1, int n2)
{
    int sum;
    sum = n1+n2;
    show(n1,n2,sum);
}
void show(int n1,int n2, int s)
{
    printf("The sum of %d and %d is %d",n1,n2,s);
}
