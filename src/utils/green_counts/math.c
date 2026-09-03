/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:28 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 14:42:28 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// time : O(1)
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

// Newton method approximates x ^ (1 / a) where a >= 1
// x_(n+1) = x_n - f(x_n) / f'(x_n)
// where f(x) = x^a - c, such that x^a = f(x) + c, x^a = c
// time : O(1)
// space: O(1)
double	f_root_finding(double x, size_t a)
{
	double	y;
	double	err;
	size_t	i;

	if (a == 0 || x == 0)
		return (0);
	y = x;
	i = 0;
	err = (f_pow(y, a) - x) / ((double)a * f_pow(y, a - 1));
	while (f_abs(err) > 1e-8 && i < 64)
	{
		y -= err;
		err = (f_pow(y, a) - x) / ((double)a * f_pow(y, a - 1));
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

Note that ChatGPT recommended me to remove accuracy argument
and truncate the Taylor series based on acceptable error rate.
You can also use Taylor inequality to approximate the error more accurately
but this approach is more difficult to implement and debug.

Reference
1.	https://youtu.be/eX1hvWxmJVE?si=9jQUq-r2TJ8hPvIb
2.	https://mathworld.wolfram.com/TaylorSeries.html
3.	https://youtu.be/Cqi-b3nQdKM?si=qxGl29v81BEl0xbz
*/

// time : O(1)
// space: O(1)
double	f_exp(double x)
{
	double	y;
	double	term;
	double	div;
	size_t	i;

	div = 1;
	term = x;
	y = 1;
	i = 1;
	while (div != 0 && f_abs(term / div) > 1e-8 && i < 64)
	{
		y += term / div;
		term *= x;
		i += 1;
		div *= (double)i;
	}
	return (y);
}

/*
You can use Laylor series to approximate Trigonometry function.
https://blog.devgenius.io/
the-magic-behind-trigonometric-functions-using-
taylor-series-in-programming-f4cae34d3729
*/

/*
// time : O(1)
// space: O(1)
double	f_sin(double x)
{
	return (sin(x));
}

// time : O(1)
// space: O(1)
double	f_cos(double x)
{
	return (cos(x));
}
*/

double	f_sin(double x)
{
	double	y;
	double	div;
	double	term;
	double	pi;
	size_t	i;

	i = 0;
	pi = 3.141592653;
	x = x - f_floor(x / (2 * pi)) * 2 * pi;
	term = x;
	div = 1;
	y = 0;
	while (div != 0 && f_abs(term / div) > 1e-8 && i < 64)
	{
		if (i % 2 == 0)
			y += term / div;
		else
			y -= term / div;
		i += 1;
		div *= ((double)i * 2) * ((double)i * 2 + 1);
		term *= x * x;
	}
	return (y);
}

// time : O(n)
// space: O(1)
double	f_cos(double x)
{
	return (f_sin(x + 3.141592653 / 2.0));
}
