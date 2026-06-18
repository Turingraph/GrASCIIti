#include"math.h"

// time : O(n)
// space: O(1)
double	f_sum(double *vector, size_t dim)
{
	size_t	i;
	double	y;

	y = 0;
	i = 0;
	while (i < dim)
	{
		y += vector[i];
		i += 1;
	}
	return (y);
}

// time : O(n)
// space: O(1)
double	f_pow(double x, size_t a)
{
	size_t	i;
	double	y;

	y = 1;
	i = 0;
	while (i < a)
	{
		y *= x;
		i += 1;
	}
	return (y);
}

// https://youtu.be/-RdOwhmqP5s?si=HZMppRY9tGm3OjL-

// approximate x ^ (1 / a) where a >= 1
// x_(n+1) = x_n - f(x_n) / f'(x_n)
// time : O(n)
// space: O(1)
double	newton_method(double x, size_t a, size_t accuracy)
{
	size_t	i;
	double	y;

	y = 1 / (double)a;
	i = 0;
	while (i < accuracy)
	{
		y = y - (f_pow(y, a) - x)/((double)a * y);
		i += 1;
	}
	return (y);
}

/*
This function approximate e^x

e constant = 2.718
*	e = 1/1! + 1/2! + ... + 1/n!
*	d/dx[e^x] = e^x
*	a^0 = 1

Taylor Series
*	taylor(f) = f(a) + (x-a)f'(a) + (x-a)^2f''(a)/2! + ... + (x-a)^nf^n(a)/n!
*	maclaurin(f) = f(0) + xf'(0) + x^2f''(0)/2! + ... + x^nf^n(0)/n!

Then
*	maclaurin(e^x) = 1 + x/1 + x^2/2! + ... + x^n/n!

Therefore, we can approximate e^x as 1 + x/1 + x^2/2! + ... + x^n/n!

Reference
1.	https://youtu.be/eX1hvWxmJVE?si=9jQUq-r2TJ8hPvIb
2.	https://mathworld.wolfram.com/TaylorSeries.html
*/

// time : O(n)
// space: O(1)
double	f_exp(double x, size_t accuracy)
{
	size_t	i;
	double	y;
	double	term;
	double	div;

	div = 1;
	term = x;
	y = 1;
	i = 0;
	while (i < accuracy)
	{
		y += term / div;
		i += 1;
		term *= x;
		div *= (double)i;
	}
	return (y);
}

// time : O(n)
// space: O(1)
double	normal_distribution_function(double std, double means, double x)
{
	size_t	ac;
	double	up;
	double	down;
	double	pi;

	pi = 3.141592653;
	ac = 24;
	if (std == 0)
		return (0);
	down = std * newton_method(2 * pi, 2, ac);
	up = f_exp(-1 * f_pow(x - means, 2) / (2 * std * std), ac);
	return (up / down);
}
