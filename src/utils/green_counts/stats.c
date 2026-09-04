/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:29:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 17:54:44 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

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
float	f_exp(float x)
{
	float	y;
	float	term;
	float	div;
	size_t	i;

	div = 1;
	term = x;
	y = 1;
	i = 1;
	while (div != 0 && f_abs(term / div) > 1e-4 && i < 8)
	{
		y += term / div;
		term *= x;
		i += 1;
		div *= (float)i;
	}
	return (y);
}

// time : O(n)
// space: O(1)
float	normal_distribution_function(float std, float means, float x)
{
	float	up;
	float	down;
	float	pi;

	pi = 3.1415;
	if (std == 0)
		return (0);
	down = std * f_root_finding(2 * pi, 2);
	up = f_exp(-1 * f_pow(x - means, 2) / (2 * std * std));
	return (up / down);
}

// https://www.khanacademy.org/math/statistics-probability/
// summarizing-quantitative-data/variance-standard-deviation-population/
// a/calculating-standard-deviation-step-by-step
// time : O(n)
// space: O(1)
float	f_std(const float *vec_v, size_t dim)
{
	size_t	i;
	float	y;
	float	mu;

	mu = f_sum(vec_v, dim);
	if (dim > 0)
		mu /= (float)dim;
	y = 0;
	i = 0;
	while (i < dim && vec_v != NULL)
	{
		y += (vec_v[i] - mu) * (vec_v[i] - mu);
		i += 1;
	}
	if (dim > 0)
		y /= (float)dim;
	return (y);
}

// time : O(n)
// space: O(1)
float	f_sum(const float *vec_v, size_t dim)
{
	float	y;
	size_t	i;

	y = 0.0;
	if (vec_v == NULL)
		return (y);
	i = 0;
	while (i < dim)
	{
		y += vec_v[i];
		i += 1;
	}
	return (y);
}
