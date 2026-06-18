#include"math.h"

// https://stackoverflow.com/questions/41856771/
// write-your-own-implementation-of-maths-floor-function-c

// time : O(1)
// space: O(1)
float	f_floor(float num)
{
    long long	n;
    float		d;

	n = (long long)num;
	d = (float)n;
	if (num >= 2147483647 || num <= -2147483648 || num != num)
        return (num);
    if (d == num || num >= 0)
        return (d);
    return (d - 1);
}

// time : O(1)
// space: O(1)
float	f_round(float num)
{
    float	floor;

	floor = f_floor(num);
	if (num >= 2147483647 || num <= -2147483648 || num != num)
        return (num);
    if (num - floor < floor + 1 - num)
		return (floor);
	return (floor + 1);
}

// time : O(1)
// space: O(1)
float	f_interval(float num, float min, float max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}