#include"linalg.h"

// time : O(1)
// space: O(1)
void	cross_product_3d(float *update_v, const float *vec_u)
{
	float	dim_0;
	float	dim_1;
	float	dim_2;

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
void	update_3d_vector(float *dst, float x, float y, float z)
{
	if (dst != NULL)
	{
		dst[0] = x;
		dst[1] = y;
		dst[2] = z;
	}
}

// time : O(1)
// space: O(1)
float	*create_3d_vector(float x, float y, float z)
{
	float	*dst;

	dst = malloc(sizeof(float) * 3);
	if (dst == NULL)
		return (NULL);
	dst[0] = x;
	dst[1] = y;
	dst[2] = z;
	return (dst);
}
