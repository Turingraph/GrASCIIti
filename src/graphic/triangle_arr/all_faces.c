#include"triangle_arr.h"

// time : O(n)
// space: O(n)
t_triangle_arr	*all_faces_triangles(t_table_fdf *src, char prism)
{
	t_triangle_arr	*dst;
	t_triangle_arr	*face;
	size_t			i;
	size_t			j;

	if (src->row < 2 || src->col < 2 || src->arr == NULL)
		return (NULL);
	dst = init_triangle_arr(2 * (src->row - 1) * (src->col - 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row - 1)
	{
		j = 0;
		while (j < src->col - 1)
		{
			face = f_fdf_face(src, i, j, prism);
			if (concat_triangle_arr(dst, face) == NULL)
				return (NULL);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	*all_sides_triangles_non_xy(t_table_fdf *src)
{
	t_triangle_arr	*dst;
	t_triangle_arr	*side;
	char			test;
	size_t			i;
	size_t			j;

	if (src->row < 2 || src->col < 2 || src->arr == NULL)
		return (NULL);
	dst = init_triangle_arr(2 * (src->row - 1) * (src->col - 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row - 1)
	{
		j = 0;
		while (j < src->col - 1)
		{
			side = NULL;
			test = fdf_side_detection(src, i, j, 'l');
			if (test != 'l')
				test = fdf_side_detection(src, i, j, 'r');
			if (test == 'l' || test == 'r')
				side = f_fdf_side(src, row, col, test);
			if (concat_triangle_arr(dst, side) == NULL)
				return (NULL);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	*all_sides_triangles_x(t_table_fdf *src)
{
	t_triangle_arr	*dst;
	t_triangle_arr	*side;
	size_t			i;
	size_t			j;

	if (src->row < 1 || src->col < 2 || src->arr == NULL)
		return (NULL);
	dst = init_triangle_arr(2 * src->row * (src->col - 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row)
	{
		j = 0;
		while (j < src->col - 1)
		{
			side = NULL;
			if (fdf_side_detection(src, i, j, 'x') == 'x')
				side = f_fdf_side(src, i, j, 'x');
			if (concat_triangle_arr(dst, side) == NULL)
				return (NULL);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	*all_sides_triangles_y(t_table_fdf *src)
{
	t_triangle_arr	*dst;
	t_triangle_arr	*side;
	size_t			i;
	size_t			j;

	if (src->row < 2 || src->col < 1 || src->arr == NULL)
		return (NULL);
	dst = init_triangle_arr(2 * (src->row - 1) * src->col);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row - 1)
	{
		j = 0;
		while (j < src->col)
		{
			side = NULL;
			if (fdf_side_detection(src, i, j, 'y') == 'y')
				side = f_fdf_side(src, i, j, 'y');
			if (concat_triangle_arr(dst, side) == NULL)
				return (NULL);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}
