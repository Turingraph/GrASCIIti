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
