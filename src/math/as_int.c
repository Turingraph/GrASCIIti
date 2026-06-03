#include"math.h"

// https://stackoverflow.com/questions/41856771/
// write-your-own-implementation-of-maths-floor-function-c

// time : O(1)
// space: O(1)
double	f_floor(double num)
{
    long long	n;
    double		d;

	n = (long long)num;
	d = (double)n;
	if (num >= 2147483647 || num <= -2147483648 || num != num)
        return (num);
    if (d == num || num >= 0)
        return (d);
    return (d - 1);
}

// time : O(1)
// space: O(1)
double	f_round(double num)
{
    double	floor;

	floor = f_floor(num);
	if (num >= 2147483647 || num <= -2147483648 || num != num)
        return (num);
    if (num - floor < floor + 1 - num)
		return (floor);
	return (floor + 1);
}

// time : O(1)
// space: O(1)
double	f_interval(double num, double min, double max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}