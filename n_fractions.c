//WAP to find the sum of n fractions.

#include<stdio.h>
struct frac{
int num;
int den;
};
typedef struct frac fraction;

fraction input()
{
	fraction f;
	printf("Enter the numerator\n");
scanf("%d", &f.num);
printf("Enter the denominator\n");
scanf("%d",&f.den);

return f;
}

int gcd(int num, int den)
{
if(num==0)
return den;
return gcd(den%num,num);
}
fraction lowest_term(fraction f)
{
int val = gcd(f.num,f.den);
f.num/=val;
f.den/=val;

return f;
}

fraction addition(fraction f1, fraction f2)
{
fraction res;
res.num = (f1.num*f2.den)+(f2.num*f1.den);
res.den = f1.den * f2.den;

return res;
}

fraction compute_total(fraction f_arr[], int n)
{
	fraction total;
	total.num = 0;
	total.den = 1;	
	int i;
	for(i=0;i<n;i++)
		total = addition(total,f_arr[i]);
	
total = lowest_term(total);

return total;
}

void output(fraction res)
{
	printf("The given fractions add up to %d/%d\n",res.num, res.den);
}

int main(void)
{
	fraction f_arr[100], res;
	int n;
	printf("Enter the no. of fractions\n");
	scanf("%d",&n);
	fraction p;
	if (n==1)
	{
		output(input());
		return 0;
	}

	for(int i =0; i<n;i++)
		f_arr[i]= input();
 	
	
	res = compute_total(f_arr, n);
	output(res);
	return 0;
}
	

	
