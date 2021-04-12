#include<stdio.h>
struct fraction{
	int num;
	int den;
};
typedef struct fraction frac;

struct egyptian_fraction{
	int k;
	frac fractions[100];
	frac sum;
};
typedef struct egyptian_fraction egyptian_frac;

egyptian_frac input_one_fraction()
{
	egyptian_frac ef;
	scanf("%d", &ef.k);
	for(int i=0; i<ef.k ; i++)
	{
		ef.fractions[i].num=1;
scanf("%d", &ef.fractions[i].den);
	}
	return ef;
}

void input_n_fraction(int n, egyptian_frac aef[])

{
	for(int i=0; i<n ; i++)
	{
		aef[i] = input_one_fraction();
	}
}
int gcd(int num, int den)
{
	int i,div,min;
	if (num>den)
		min=den;
	else
		min=num;
	for(i=1;i<min;i++)
		if(num%i==0 && den%i==0)
			div=i;
	return div;
}


frac compute_one_fraction(egyptian_frac *ef)
{
	ef->sum.num = 0;
	ef->sum.den=1;
	int i;
	for(i=0;i< ef->k;i++)
	{
		ef->sum.num = (ef->sum.num * ef->fractions[i].den) + (ef->fractions[i].num* ef->sum.den);
		ef->sum.den = ef->sum.den * ef->fractions[i].den;
	}
	int div = gcd(ef->sum.num, ef->sum.den);

	ef->sum.num /=div;
	ef->sum.den /=div;
}
void compute_n_fraction( int n, egyptian_frac aef[n])
{
int i;
for(i=0;i<n;i++)
{
	compute_one_fraction(&aef[i]);
}

}



void output_one_fraction(egyptian_frac f)
{
	for(int i = 0; i<f.k -1; i++)
     printf("%d/%d = %d/%d", f.fractions[i].num, f.fractions[i].den, f.sum.num, f.sum.den);
}
void output_n_fraction( int n, egyptian_frac ef[])
{
	for(int i =0; i<n;i++)
		output_one_fraction(ef[i]);


}

int main(void)
{
printf("Enter n\n");
int n,i,j;
scanf("%d",&n);
egyptian_frac aef[n];
input_n_fraction(n, aef);
compute_n_fraction(n, aef);
output_n_fraction(n, aef);

	return 0;
}
