#include"math.h"

// time : O(n)
// space: O(1)
double	normal_distribution_function(double std, double means, double x)
{
	double	up;
	double	down;
	double	pi;

	pi = 3.141592653;
	if (std == 0)
		return (0);
	down = std * f_root_finding(2 * pi, 2);
	up = f_exp(-1 * f_pow(x - means, 2) / (2 * std * std));
	return (up / down);
}

// time : O(n)
// space: O(1)
double	f_sum(const double *vec_v, size_t dim)
{
	size_t	i;
	double	y;

	y = 0;
	i = 0;
	while (i < dim)
	{
		y += vec_v[i];
		i += 1;
	}
	return (y);
}
