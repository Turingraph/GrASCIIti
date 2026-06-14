#include"math.h"

// time : O(1)
// space: O(1)
void	cross_product_3d(double *update_v, double *vec_u)
{
	double	dim_0;
	double	dim_1;
	double	dim_2;

	if (update_v != NULL && vec_u != NULL)
	{
		dim_0 = update_v[0];
		dim_1 = update_v[1];
		dim_2 = update_v[2];
		update_v[0] = dim_1 * vec_u[2] - dim_2 * vec_u[1];
		update_v[1] = (dim_0 * vec_u[2] - dim_2 * vec_u[0]) * -1.0;
		update_v[2] = dim_0 * vec_u[1] - dim_1 * vec_u[0];
	}
}

// time : O(1)
// space: O(1)
void	update_3d_vector(double *dst, double x, double y, double z)
{
	dst[0] = x;
	dst[1] = y;
	dst[2] = z;
}

// time : O(1)
// space: O(1)
double	*create_3d_vector(double x, double y, double z)
{
	double	*dst;

	dst = malloc(sizeof(double) * 3);
	if (dst == NULL)
		return (NULL);
	dst[0] = x;
	dst[1] = y;
	dst[2] = z;
	return (dst);
}
