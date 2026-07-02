#include"triangle_arr.h"

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_faces(t_table_fdf src, char prism)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;

	dst = init_triangle_arr(2 * (src.row - 1) * (src.col - 1));
	if (dst.arr == NULL || src.arr == NULL)
		return (dst);
	i = 0;
	while (i < src.row - 1)
	{
		j = 0;
		while (j < src.col - 1)
		{
			item = f_fdf_face(src, i, j, prism);
			concat_triangle_arr(&dst, &item);
			j += 1;
		}
		i += 1;
	}
	item = copy_triangle_arr(&dst, dst.length);
	return (item);
}

// time : O(1)
// space: O(1)
size_t	getdim(size_t row, size_t col, char axis, char state)
{
	if (axis == 'x' && state == 'r')
		return (row);
	if (axis == 'x' && state == 'c')
		return (col - 1);
	if (axis == 'x' && state == 'x')
		return (row * (col - 1));
	if (axis == 'y' && state == 'r')
		return (row - 1);
	if (axis == 'y' && state == 'c')
		return (col);
	if (axis == 'y' && state == 'x')
		return (col * (row - 1));
	return (0);
}

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_side_xy(t_table_fdf src, char axis)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;

	dst = init_triangle_arr(2 * getdim(src.row, src.col, axis, 'x'));
	if (dst.arr == NULL)
		return (dst);
	if (dst.arr == NULL || src.arr == NULL || (axis != 'x' && axis != 'y'))
		return (dst);
	i = 0;
	while (i < getdim(src.row, src.col, axis, 'r'))
	{
		j = 0;
		while (j < getdim(src.row, src.col, axis, 'c'))
		{
			item = f_fdf_side(src, i, j, axis);
			concat_triangle_arr(&dst, &item);
			j += 1;
		}
		i += 1;
	}
	item = copy_triangle_arr(&dst, dst.length);
	return (item);
}

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_side_lr(t_table_fdf src, char axis)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;

	dst = init_triangle_arr(2 * (src.row - 1) * (src.col - 1));
	if (dst.arr == NULL || src.arr == NULL || (axis != 'l' && axis != 'r'))
		return (dst);
	i = 0;
	while (i < src.row - 1)
	{
		j = 0;
		while (j < src.col - 1)
		{
			item = f_fdf_side(src, i, j, axis);
			concat_triangle_arr(&dst, &item);
			j += 1;
		}
		i += 1;
	}
	item = copy_triangle_arr(&dst, dst.length);
	return (item);
}

