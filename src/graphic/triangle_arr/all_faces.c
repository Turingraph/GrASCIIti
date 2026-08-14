#include"triangle_arr.h"

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_faces(const t_table_fdf *src, e_3d_shape shape)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;

	if (src == NULL || src->arr == NULL)
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(
			2 * (src->row - 1) * (src->col - 1), src->row, src->col);
	if (dst.arr == NULL || src->arr == NULL)
		return (dst);
	i = 0;
	while (i < src->row - 1)
	{
		j = 0;
		while (j < src->col - 1)
		{
			item = f_fdf_face(src, i * src->col + j, shape);
			j += concat_triangle_arr(&dst, &item);
		}
		i += 1;
	}
	item = copy_triangle_arr(&dst, dst.length);
	return (item);
}

// time : O(1)
// space: O(1)
size_t	getdim(size_t row, size_t col, e_edge mode, char state)
{
	if (mode == EDGE_X && state == 'r')
		return (row);
	if (mode == EDGE_X && state == 'c')
		return (col - 1);
	if (mode == EDGE_X && state == 'x')
		return (row * (col - 1));
	if (mode == EDGE_Y && state == 'r')
		return (row - 1);
	if (mode == EDGE_Y && state == 'c')
		return (col);
	if (mode == EDGE_Y && state == 'x')
		return (col * (row - 1));
	return (0);
}

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_edge_xy(
	const t_table_fdf *src, e_edge mode, bool is_voxel)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;

	if (src == NULL || (mode != EDGE_X && mode != EDGE_Y))
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(2 * getdim(src->row, src->col, mode, 'x'),
			getdim(src->row, src->col, mode, 'r'),
			getdim(src->row, src->col, mode, 'c'));
	if (dst.arr == NULL || src->arr == NULL)
		return (dst);
	i = 0;
	while (i < getdim(src->row, src->col, mode, 'r'))
	{
		j = 0;
		while (j < getdim(src->row, src->col, mode, 'c'))
		{
			item = f_fdf_edge(src, i * src->col + j, mode, is_voxel);
			j += concat_triangle_arr(&dst, &item);
		}
		i += 1;
	}
	item = copy_triangle_arr(&dst, dst.length);
	return (item);
}

// time : O(n)
// space: O(n)
t_triangle_arr	all_triangle_edge_lr(const t_table_fdf *src, e_edge mode)
{
	size_t			i;
	size_t			j;
	t_triangle_arr	dst;
	t_triangle_arr	item;
	bool			is_voxel;

	is_voxel = false;
	if (src == NULL || src->row <= 1 || src->col <= 1 || src->arr == NULL
		|| (mode != EDGE_DIAGONAL_LEFT && mode != EDGE_DIAGONAL_RIGHT))
		return (init_triangle_arr(0, 0, 0));
	dst = init_triangle_arr(2 * (src->row - 1) * (src->col - 1),
			src->row - 1, src->col - 1);
	i = 0;
	while (i < src->row - 1 && dst.arr != NULL)
	{
		j = 0;
		while (j < src->col - 1)
		{
			item = f_fdf_edge(src, i * src->col + j, mode, is_voxel);
			j += concat_triangle_arr(&dst, &item);
		}
		i += 1;
	}
	item = copy_triangle_arr(&dst, dst.length);
	return (item);
}

