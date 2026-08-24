#include"green_counts.h"

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
float	f_sum(const float *vec_v, size_t dim)
{
	size_t	i;
	float	y;

	y = 0;
	i = 0;
	while (i < dim && vec_v != NULL)
	{
		y += vec_v[i];
		i += 1;
	}
	return (y);
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

/*
n% Percentile = group of A that have value Z greater than another
than n% of another A, for example this Pixel is brighter than
67% of all other pixels in an entire image.

You can find the percentile by taking the integral of the PDF
(probability density function) from negative infinity to your target value (for the right-hand value). 

Reference
*	https://youtu.be/3ORW40CshBM?si=UjzB17cq4-4EMGKD
*	https://math.stackexchange.com/questions/1460989/calculating-percentile-value-from-mean-and-standard-deviation-of-a-normal-distri
*/

