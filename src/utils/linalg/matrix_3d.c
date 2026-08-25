#include "linalg.h"

// https://www.storyofmathematics.com/inverse-of-a-3x3-matrix/

// time : O(1)
// space: O(1)
t_matrix	init_inverse_3d_matrix(t_matrix src)
{
	float		det;
	float		*a;
	t_matrix	dst;

	dst.arr = NULL;
	dst.col = 0;
	dst.row = 0;
	a = src.arr;
	det = matrix_det_3d(src);
	if (a == NULL || (det < 1e-6f && det > -1e-6f))
		return (dst);
	dst.arr = malloc(sizeof(float) * 9);
	if (dst.arr == NULL)
		return (dst);
	dst.arr[0] = (a[4] * a[8] - a[5] * a[7]) / det;
	dst.arr[1] = -1 * (a[1] * a[8] - a[2] * a[7]) / det;
	dst.arr[2] = (a[5] * a[1] - a[2] * a[4]) / det;
	dst.arr[3] = -1 * (a[3] * a[8] - a[5] * a[6]) / det;
	dst.arr[4] = (a[0] * a[8] - a[2] * a[6]) / det;
	dst.arr[5] = -1 * (a[0] * a[5] - a[2] * a[3]) / det;
	dst.arr[6] = (a[3] * a[7] - a[4] * a[6]) / det;
	dst.arr[7] = -1 * (a[0] * a[7] - a[1] * a[6]) / det;
	dst.arr[8] = (a[0] * a[4] - a[1] * a[3]) / det;
	return (dst);
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
	c[0] = a[0] * b[0] + a[3] * b[1] + a[6] * b[2];
	c[1] = a[1] * b[0] + a[4] * b[1] + a[7] * b[2];
	c[2] = a[2] * b[0] + a[5] * b[1] + a[8] * b[2];
	c[3] = a[0] * b[3] + a[3] * b[4] + a[6] * b[5];
	c[4] = a[1] * b[3] + a[4] * b[4] + a[7] * b[5];
	c[5] = a[2] * b[3] + a[5] * b[4] + a[8] * b[5];
	c[6] = a[0] * b[6] + a[3] * b[7] + a[6] * b[8];
	c[7] = a[1] * b[6] + a[4] * b[7] + a[7] * b[8];
	c[8] = a[2] * b[6] + a[5] * b[7] + a[8] * b[8];
	i = 0;
	while (i < 9)
	{
		dst->arr[i] = c[i];
		i += 1;
	}
}

// time : O(1)
// space: O(1)
float	matrix_det_3d(t_matrix src)
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

// time : O(1)
// space: O(1)
t_matrix	init_3d_zoom_matrix(float zoom)
{
	t_matrix	dst;

	dst.arr = malloc(sizeof(float) * 9);
	dst.col = 0;
	dst.row = 0;
	if (dst.arr == NULL)
		return (dst);
	dst.col = 3;
	dst.row = 3;
	dst.arr[0] = zoom;
	dst.arr[1] = 0.0;
	dst.arr[2] = 0.0;
	dst.arr[3] = 0.0;
	dst.arr[4] = zoom;
	dst.arr[5] = 0.0;
	dst.arr[6] = 0.0;
	dst.arr[7] = 0.0;
	dst.arr[8] = zoom;
	return (dst);
}
