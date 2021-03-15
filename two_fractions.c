//WAP to find the sum of two fractions.
#include<stdio.h>
struct st
{
  int num;
  int den;
};

typedef struct st fraction;
fraction input_frac ();
int gcd (int num, int den);
fraction lowest_term (fraction f, int div);
fraction addition (fraction f1, fraction f2);
void output (fraction f1, fraction f2, fraction res);

fraction
input_frac ()
{
  fraction f;
  printf ("Enter the numerator\n");
  scanf ("%d", &f.num);
  printf ("Enter the denominator\n");
  scanf ("%d", &f.den);
  return f;
}

int
gcd (int num, int den)
{
  if (num == 0)
    return den;
  return gcd (den % num, num);
  // for num>den the euclid's algorithm peforms k+1 recursive calls. The extra recursive call interchanges the num and den ensuring num<den.
}

fraction
lowest_term (fraction f, int div)
{
//gcd helps us to reduce the fraction to lowest terms.
  f.num = f.num / div;
  f.den = f.den / div;
  return f;
}

fraction
addition (fraction f1, fraction f2)
{
  fraction res;
  res.den = f1.den * f2.den;
  res.num = (f1.num * f2.den) + (f2.num * f1.den);
  int div = gcd (res.num, res.den);
  res = lowest_term (res, div);
  return res;
}

void
output (fraction f1, fraction f2, fraction res)
{
  printf ("The fractions %d/%d and %d/%d when added yield %d/%d\n", f1.num,
	  f1.den, f2.num, f2.den, res.num, res.den);
}

int
main (void)
{
  fraction a, b, c;
  a = input_frac ();
  b = input_frac ();
  c = addition (a, b);
  output (a, b, c);
  return 0;
}
