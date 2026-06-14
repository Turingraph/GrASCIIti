#include"math.h"

// time : O(n)
// space: O(1)
double	euclid_distance(double *vec_v, double *vec_0, size_t dim, char square)
{
	double	y;
	size_t	i;

	y = 0;
	i = 0;
	while (i < dim)
	{
		if (vec_0 != NULL)
			y += (vec_v[i] - vec_0[i]) * (vec_v[i] - vec_0[i]);
		else
			y += vec_v[i] * vec_v[i];
		i += 1;
	}
	if (square == 1)
		return (y);
	return (newton_method(y, 2, 12));
}

// time : O(n)
// space: O(1)
double	cos_between_2_vectors(double *vec_v, double *vec_u, size_t dim)
{
	double	div;

	div = euclid_distance(vec_v, vec_u, dim, 0);
	if (div == 0)
		return (0);
	return (dot_product(vec_v, vec_u, dim) / div);
}

// time : O(n)
// space: O(n)
void	vector_projection(double *update_v, double *vec_u, size_t dim)
{
	double	div;
	double	scale;

	div = euclid_distance(update_v, NULL, dim, 1);
	if (div != 0)
	{
		scale = dot_product(update_v, vec_u, dim) / div;
		scale_vec(update_v, scale, dim);
	}
}

// time : O(n)
// space: O(1)
double	scale_projection(double *vec_v, double *vec_u, size_t dim)
{
	double	div;
	double	scale;

	div = euclid_distance(vec_v, NULL, dim, 0);
	if (div == 0)
		return (0);
	scale = dot_product(vec_v, vec_u, dim) / div;
	return (scale);
}
