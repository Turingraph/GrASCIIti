#include"fdf.h"

// https://en.wikipedia.org/wiki/Rotation_matrix

// time : O(1)
// space: O(1)
float	init_3d_rotate_matrix_unit(float delta, char code)
{
	float	dst;

	dst = 0.0;
	if (code == '1')
		dst = 1.0;
	if (code == 'C')
		dst = f_cos(delta);
	if (code == 'c')
		dst = -1.0 * f_cos(delta);
	if (code == 'S')
		dst = f_sin(delta);
	if (code == 's')
		dst = -1.0 * f_sin(delta);
	return (dst);
}

// time : O(1)
// space: O(1)
t_matrix	init_3d_rotate_matrix_loop(float delta, const char *code)
{
	t_matrix	dst;
	size_t		i;

	dst.col = 0;
	dst.row = 0;
	dst.arr = malloc(sizeof(float) * 9);
	if (dst.arr == NULL || code == 0)
	{
		free(dst.arr);
		dst.arr = NULL;
		return (dst);
	}
	dst.col = 3;
	dst.row = 3;
	i = 0;
	while (i < 9)
	{
		dst.arr[i] = init_3d_rotate_matrix_unit(
				delta, code[i]);
		i += 1;
	}
	return (dst);
}

// time : O(1)
// space: O(1)
t_matrix	init_3d_rotate_matrix(float delta, char axis)
{
	char		*axis_x;
	char		*axis_y;
	char		*axis_z;
	t_matrix	dst;

	axis_x = "1000Cs0SC";
	axis_y = "C0S010s0C";
	axis_z = "Cs0SC0001";
	if (axis == 0)
		dst = init_3d_rotate_matrix_loop(delta, axis_x);
	else if (axis == 1)
		dst = init_3d_rotate_matrix_loop(delta, axis_y);
	else
		dst = init_3d_rotate_matrix_loop(delta, axis_z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_matrix	init_3d_zoom_matrix(float zoom)
{
	char		*items;
	t_matrix	dst;
	size_t		i;

	items = "100010001";
	dst = init_3d_rotate_matrix_loop(zoom, items);
	i = 0;
	while (dst.arr != NULL && i < 9)
	{
		dst.arr[i] *= zoom;
		i += 1;
	}
	return (dst);
}

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
	det = matrix_det(src);
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

