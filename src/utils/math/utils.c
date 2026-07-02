#include"math.h"

/*
You can use Laylor series to approximate Trigonometry function.
https://blog.devgenius.io/the-magic-behind-trigonometric-functions-using-taylor-series-in-programming-f4cae34d3729
*/

// time : O(n)
// space: O(1)
double	f_sin(double x, size_t accuracy)
{
	size_t	i;
	double	y;
	double	div;
	double	term;
	double	pi;

	pi = 3.141592653;
	x = x - f_floor(x / (2 * pi)) * 2 * pi;
	term = x;
	div = 1;
	y = 0;
	i = 0;
	while (i < accuracy)
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
double	f_cos(double x, size_t accuracy)
{
	size_t	i;
	double	y;
	double	div;
	double	term;
	double	pi;

	pi = 3.141592653;
	x = x - f_floor(x / (2 * pi)) * 2 * pi;
	term = x * x;
	div = 2;
	y = 1;
	i = 1;
	while (i < accuracy)
	{
		if (i % 2 == 0)
			y += term / div;
		else
			y -= term / div;
		i += 1;
		div *= ((double)i * 2) * ((double)i * 2 - 1);
		term *= x * x;
	}
	return (y);
}

// time : O(???) but might be O(log(n)), this is an open problem!
// space: O(1)
size_t	collatz_max_point(size_t x)
{
	size_t	max;
	size_t	limit;

	max = 0;
	if (max < x)
		max = x;
	limit = 0;
	while (limit < 10000 && x > 1)
	{
		if (max < x)
			max = x;
		if (x % 2 == 0)
			x /= 2;
		else
			x = 3 * x + 1;
		limit += 1;
	}
	return (max);
}

// time : O(log(n))
// space: O(1)
size_t	binary_search_count(size_t min_input, size_t max_input)
{
	size_t	min;
	size_t	mid;
	size_t	count;

	if (min_input > max_input)
	{
		min = min_input;
		min_input = max_input;
		max_input = min;
	}
	count = 0;
	min = 0;
	mid = (min + max_input) / 2;
	while (mid != min_input && min < max)
	{
		mid = (min + max_input) / 2;
		if (min_input < mid)
			max = mid;
		else
			min = mid + 1;
		count += 1;
	}
	return (count);
}

