/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:28 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 17:54:40 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// time : O(1)
// space: O(1)
float	f_pow(float x, size_t a)
{
	size_t	i;
	float	y;

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
float	f_root_finding(float x, size_t a)
{
	float	y;
	float	err;
	size_t	i;

	if (a == 0 || x == 0)
		return (0);
	y = x;
	i = 0;
	err = (f_pow(y, a) - x) / ((float)a * f_pow(y, a - 1));
	while (f_abs(err) > 1e-4 && i < 8)
	{
		y -= err;
		err = (f_pow(y, a) - x) / ((float)a * f_pow(y, a - 1));
		i += 1;
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
float	f_sin(float x)
{
	return (sin(x));
}

// time : O(1)
// space: O(1)
float	f_cos(float x)
{
	return (cos(x));
}
*/

float	f_sin(float x)
{
	float	y;
	float	div;
	float	term;
	float	pi2;
	size_t	i;

	i = 0;
	pi2 = 6.283;
	x = x - f_floor(x / pi2) * pi2;
	if (x < 1.0 && x > -1.0)
		return (x);
	term = x;
	div = 1;
	y = 0;
	while (div != 0 && f_abs(term / div) > 1e-4 && i < 8)
	{
		if (i % 2 == 0)
			y += term / div;
		else
			y -= term / div;
		i += 1;
		div *= ((float)i * 2) * ((float)i * 2 + 1);
		term *= x * x;
	}
	return (y);
}

// time : O(n)
// space: O(1)
float	f_cos(float x)
{
	return (f_sin(x + 3.1415 / 2.0));
}
