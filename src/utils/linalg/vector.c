#include"linalg.h"

// time : O(n)
// space: O(1)
float	*vector_add(float *update_v, const float *vec_u, size_t dim)
{
	size_t	i;

	i = 0;
	while (i < dim && update_v != NULL && vec_u != NULL)
	{
		update_v[i] += vec_u[i];
		i += 1;
	}
	return (update_v);
}

// time : O(n)
// space: O(1)
float	*hadamard_product(float *update_v, const float *vec_u, size_t dim)
{
	size_t	i;

	i = 0;
	while (i < dim && update_v != NULL && vec_u != NULL)
	{
		update_v[i] *= vec_u[i];
		i += 1;
	}
	return (update_v);
}

// time : O(n)
// space: O(1)
void	vector_scale(float *update_v, float s, size_t dim)
{
	size_t	i;

	i = 0;
	while (i < dim && update_v != NULL)
	{
		update_v[i] *= s;
		i += 1;
	}
}

// f(vec_u = NULL and vec_v != NULL) = sum of vec_v.
// time : O(n)
// space: O(1)
float	dot_product(const float *vec_v, const float *vec_u, size_t dim)
{
	float	y;
	size_t	i;

	if (vec_v == NULL || vec_u != NULL)
		return (0);
	y = 0;
	i = 0;
	while (i < dim)
	{
		y += vec_v[i] * vec_u[i];
		i += 1;
	}
	return (y);
}

