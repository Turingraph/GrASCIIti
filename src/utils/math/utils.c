#include"math.h"

/*
// the larger large_num the better the approximation.
// https://math.stackexchange.com/questions/977586/is-there-an-approximation-to-the-natural-log-function-at-large-values
// time : O(n)
// space: O(1)
double	natural_log(double x, double large_num, size_t accuracy)
{
	return (large_num * newton_method(x, large_num, accuracy) - large_num);
}
*/

// time : O(1)
// space: O(1)
double	f_abs(double x)
{
	if (x < 0)
		return (-1 * x);
	return (x);
}

// time : O(1)
// space: O(1)
float	f_max3(float a, float b, float c)
{
	if (a >= b && a >= c)
		return (a);
	if (b >= a && b >= c)
		return (b);
	if (c >= a && c >= b)
		return (c);
	return (b);
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
	size_t	max;
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
	max = max_input;
	while (mid != min_input && min < max)
	{
		mid = (min + max) / 2;
		if (min_input < mid)
			max = mid;
		else
			min = mid + 1;
		count += 1;
	}
	return (count);
}
