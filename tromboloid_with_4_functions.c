#include<stdio.h>
void inp();
void calculate(float h, float d, float b);
void show(float v);
void main()
{
    inp();
}
void inp()
{
    printf("Enter h,d and b respectively\n");
    float h,b,d;
    scanf("%f%f%f",&h,&d,&b);
    calculate(h,b,d);
}
void calculate(float h, float d, float b)
{
    float vol = (0.333)*((h*d*b)+(d/b));
    show(vol);
}
void show(float v)
{
    printf("The volume is %f",v);
}
