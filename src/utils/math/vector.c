#include"math.h"

// time : O(n)
// space: O(1)
void	vec_add(double *update_v, double *vec_u, size_t dim)
{
	size_t	i;

	i = 0;
	while (i < dim && update_v != NULL)
	{
		update_v[i] += vec_u[i];
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	scale_vec(double *update_v, double s, size_t dim)
{
	size_t	i;

	i = 0;
	while (i < dim && update_v != NULL)
	{
		update_v[i] *= s;
		i += 1;
	}
}

// time : O(n)
// space: O(1)
double	dot_product(double *vec_v, double *vec_u, size_t dim)
{
	double	y;
	size_t	i;

	if (vec_u == NULL || vec_v == NULL)
		return (0);
	y = 0;
	i = 0;
	while (i < dim)
	{
		y += (vec_v[i] * vec_u[i]);
		i += 1;
	}
	return (y);
}

// time : O(n^2)
// space: O(n)
char	matrix_times_vec(double **matrix, double *update_v, size_t dim)
{
	double	*temp;
	size_t	i;

	temp = malloc(sizeof(double) * dim);
	if (temp == NULL)
		return (0);
	i = 0;
	while (i < dim)
	{
		temp[i] = update_v[i];
		i += 1;
	}
	i = 0;
	while (i < dim)
	{
		update_v[i] = dot_product(temp, matrix[i], dim);
		i += 1;
	}
	free(temp);
	return (1);
}
