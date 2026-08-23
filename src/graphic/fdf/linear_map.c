#include"fdf.h"


// time : O(n)
// space: O(1)
float	linear_map_3d(const t_fdf *src, t_matrix matrix, size_t i, char axis)
{
	float	output;
	float	*m;
	float	*x;
	float	*y;
	float	*z;

	if (is_fdf_valid(src) == false
		|| matrix.col * matrix.row != 9
		|| matrix.arr == NULL)
		return (0.0);
	m = matrix.arr;
	x = src->pos_x;
	y = src->pos_y;
	z = src->pos_z;
	output = x[i] * m[0] + y[i] * m[1] + z[i] * m[2];
	if (axis == 0)
		return (output);
	output = x[i] * m[3] + y[i] * m[4] + z[i] * m[5];
	if (axis == 1)
		return (output);
	output = x[i] * m[6] + y[i] * m[7] + z[i] * m[8];
	return (output);
}

// time : O(n)
// space: O(1)
void	linear_map_3d_all(t_fdf *src, t_matrix matrix)
{
	size_t	i;

	if (is_fdf_valid(src) == false
		|| matrix.col * matrix.row != 9
		|| matrix.arr == NULL)
		return ;
	i = 0;
	while (i < src->src->row * src->src->col)
	{
		src->pos_x[i] = linear_map_3d((const t_fdf *)src, matrix, i, 0);
		src->pos_y[i] = linear_map_3d((const t_fdf *)src, matrix, i, 1);
		src->pos_z[i] = linear_map_3d((const t_fdf *)src, matrix, i, 2);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	matrix_3d_product(t_matrix src, t_matrix *dst)
{
	float	c[9];
	float	*a;
	float	*b;
	size_t	i;

	if (src.arr == NULL || dst == NULL
		|| dst->arr == NULL || src.col * src.row < 9
		|| src.col * src.row != dst->col * dst->row)
		return ;
	a = src.arr;
	b = dst->arr;
	c[0] = a[0] * b[0] + a[1] * b[3] + a[2] * b[6];
	c[1] = a[3] * b[0] + a[4] * b[3] + a[5] * b[6];
	c[2] = a[6] * b[0] + a[7] * b[3] + a[8] * b[6];
	c[3] = a[0] * b[1] + a[1] * b[4] + a[2] * b[7];
	c[4] = a[3] * b[1] + a[4] * b[4] + a[5] * b[7];
	c[5] = a[6] * b[1] + a[7] * b[4] + a[8] * b[7];
	c[6] = a[0] * b[2] + a[1] * b[5] + a[2] * b[8];
	c[7] = a[3] * b[2] + a[4] * b[5] + a[5] * b[8];
	c[8] = a[6] * b[2] + a[7] * b[5] + a[8] * b[8];
	i = 0;
	while (i < 9)
	{
		dst->arr[i] = c[i];
		i += 1;
	}
}

// I will implement the general determanent later.
float	matrix_det(t_matrix src)
{
	float	*a;
	float	y;

	if (src.arr == NULL || src.col * src.row < 9)
		return (0.0);
	a = src.arr;
	y = a[0] * (a[4] * a[8] - a[5] * a[7]);
	y += -1 * a[1] * (a[3] * a[8] - a[5] * a[6]);
	y += a[2] * (a[3] * a[7] - a[4] * a[6]);
	return (y);
}
