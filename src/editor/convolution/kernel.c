#include"convolution.h"

// https://stackoverflow.com/questions/1696113/
// how-do-i-gaussian-blur-an-image-without-using-any-in-built-gaussian-functions

double	normal_distribution_function(double std, double means, double x)
{
	size_t	ac;
	double	up;
	double	down;
	double	pi;

	pi = 3.141592653;
	ac = 24;
	if (std == 0)
		return (0);
	down = std * newton_method(2 * pi, 2, ac);
	up = f_exp(-1 * f_pow(x - means, 2) / (2 * std * std), ac);
	return (up / down);
}

// time : O(n)
// space: O(n)
double	*gaussian_kernel_1d(size_t half_dim)
{
	size_t	i;
	double	*kernel;
	double	sum;

	kernel = malloc_talk(sizeof(double) * (2 * half_dim + 1),
		"convolution/kernel.c/gaussian_kernel\n");
	if (kernel == NULL)
		return (NULL);
	i = 0;
	while (i <= half_dim)
	{
		kernel[half_dim - i] = normal_distribution_function(1, 0, (-1.0) * (double)(i));
		kernel[half_dim + i] = normal_distribution_function(1, 0, (double)(i));
		i += 1;
	}
	sum = f_sum(kernel, 2 * half_dim + 1);
	i = 0;
	while (i < 2 * half_dim + 1 && sum != 0)
	{
		kernel[i] /= sum;
		i += 1;
	}
	return (kernel);
}

// time : O(n^2)
// space: O(n^2)
double		**blur_kernel_2d(size_t dim, double scale)
{
	size_t	i;
	size_t	j;
	double	**dst;

	dst = (double **)malloc_talk(sizeof(double *) * dim, "convolution/kernel.c/blur_kernel\n");
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < dim)
	{
		dst[i] = (double *)malloc_talk(sizeof(double) * dim, "convolution/kernel.c/blur_kernel\n");
		if (dst[i] == NULL)
		{
			free_2d_arr((void **)dst, i);
			return (NULL);
		}
		j = 0;
		while (j < dim)
		{
			dst[i][j] = scale;
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n^2)
// space: O(n^2)
double	**outer_product_kernel(double *vec_v, double *vec_u, size_t dim)
{
	double	**kernel;
	size_t	i;
	size_t	j;

	kernel = blur_kernel_2d(dim, 1);
	if (kernel == NULL)
		return (NULL);
	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			kernel[i][j] = vec_v[i] * vec_u[j];
			j += 1;
		}
		i += 1;
	}
	return (kernel);
}
