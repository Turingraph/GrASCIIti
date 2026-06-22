#include"math.h"

// https://stackoverflow.com/questions/41856771/
// write-your-own-implementation-of-maths-floor-function-c

// time : O(1)
// space: O(1)
float	f_floor(float num)
{
    long long	n;
    float		d;

	if (num > 2147483647.0)
		return (2147483647.0);
	if (num < -2147483648.0)
		return (-2147483648.0);
	n = (long long)num;
	d = (float)n;
	return (d);
}

// time : O(1)
// space: O(1)
float	f_round(float num)
{
	float	floor;

	floor = f_floor(num);
	if (num > 2147483647.0)
		return (2147483647.0);
	if (num < -2147483648.0)
		return (-2147483648.0);
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