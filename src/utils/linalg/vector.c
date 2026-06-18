#include"linalg.h"

// time : O(n)
// space: O(1)
void	vec_add(float *update_v, float *vec_u, size_t dim)
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
void	scale_vec(float *update_v, float s, size_t dim)
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
float	dot_product(float *vec_v, float *vec_u, size_t dim)
{
	float	y;
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
char	matrix_times_vec(float **matrix, float *update_v, size_t dim)
{
	float	*temp;
	size_t	i;

	temp = malloc(sizeof(float) * dim);
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
