//Write a program to find the volume of a tromboloid using one function
#include<stdio.h>
void main()
{
    float h,d,b;
    printf("enter parameters h,d,b respectively\n");
    scanf("%f%f%f",&h,&d,&b);
    float vol; //1/3 of ((h x d x b) + ( d divided by b)).
    vol = (0.333)*((h*d*b)+(d/b));
    printf("The volume is %f",vol);
}
