#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	f_fdf_side_x(const t_table_fdf *src, t_triangle_arr *dst, size_t row, size_t col)
{
	if (dst->capacity > 1 && col + 1 < src->col && row < src->row)
	{
		update_3d_vector(dst->arr[0].p1, col, row, src->arr[row][col]);
		update_3d_vector(dst->arr[0].p2, col + 1, row, src->arr[row][col + 1]);
		update_3d_vector(dst->arr[0].p3, col + 1, row, 0);
		update_3d_vector(dst->arr[1].p1, col, row, src->arr[row][col]);
		update_3d_vector(dst->arr[1].p2, col, row, 0);
		update_3d_vector(dst->arr[1].p3, col + 1, row, 0);
		dst->arr[0].r = triangle_side_rgb(src->r, row, col, 'x');
		dst->arr[1].r = triangle_side_rgb(src->r, row, col, 'x');
		dst->arr[0].g = triangle_side_rgb(src->g, row, col, 'x');
		dst->arr[1].g = triangle_side_rgb(src->g, row, col, 'x');
		dst->arr[0].b = triangle_side_rgb(src->b, row, col, 'x');
		dst->arr[1].b = triangle_side_rgb(src->b, row, col, 'x');
		dst->arr[0].a = triangle_side_rgb(src->a, row, col, 'x');
		dst->arr[1].a = triangle_side_rgb(src->a, row, col, 'x');
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
void	f_fdf_side_y(const t_table_fdf *src, t_triangle_arr *dst, size_t row, size_t col)
{
	if (dst->capacity > 1 && col < src->col && row + 1 < src->row)
	{
		update_3d_vector(dst->arr[0].p1, col, row, src->arr[row][col]);
		update_3d_vector(dst->arr[0].p2, col, row + 1, src->arr[row + 1][col]);
		update_3d_vector(dst->arr[0].p3, col, row + 1, 0);
		update_3d_vector(dst->arr[1].p1, col, row, src->arr[row][col]);
		update_3d_vector(dst->arr[1].p2, col, row, 0);
		update_3d_vector(dst->arr[1].p3, col, row + 1, 0);
		dst->arr[0].r = triangle_side_rgb(src->r, row, col, 'y');
		dst->arr[1].r = triangle_side_rgb(src->r, row, col, 'y');
		dst->arr[0].g = triangle_side_rgb(src->g, row, col, 'y');
		dst->arr[1].g = triangle_side_rgb(src->g, row, col, 'y');
		dst->arr[0].b = triangle_side_rgb(src->b, row, col, 'y');
		dst->arr[1].b = triangle_side_rgb(src->b, row, col, 'y');
		dst->arr[0].a = triangle_side_rgb(src->a, row, col, 'y');
		dst->arr[1].a = triangle_side_rgb(src->a, row, col, 'y');
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
void	f_fdf_side_l(const t_table_fdf *src, t_triangle_arr *dst, size_t row, size_t col)
{
	if (dst->capacity > 1 && col + 1 < src->col && row + 1 < src->row)
	{
		update_3d_vector(dst->arr[0].p1, (float)col, (float)row, (float)src->arr[row][col]);
		update_3d_vector(dst->arr[0].p2, (float)(col + 1), (float)(row + 1), (float)src->arr[row + 1][col + 1]);
		update_3d_vector(dst->arr[0].p3, (float)(col + 1), (float)(row + 1), 0.0);
		update_3d_vector(dst->arr[1].p1, (float)col, (float)row, (float)src->arr[row][col]);
		update_3d_vector(dst->arr[1].p2, (float)col, (float)row, 0.0);
		update_3d_vector(dst->arr[1].p3, (float)(col + 1), (float)(row + 1), 0);
		dst->arr[0].r = triangle_side_rgb(src->r, row, col, 'l');
		dst->arr[1].r = triangle_side_rgb(src->r, row, col, 'l');
		dst->arr[0].g = triangle_side_rgb(src->g, row, col, 'l');
		dst->arr[1].g = triangle_side_rgb(src->g, row, col, 'l');
		dst->arr[0].b = triangle_side_rgb(src->b, row, col, 'l');
		dst->arr[1].b = triangle_side_rgb(src->b, row, col, 'l');
		dst->arr[0].a = triangle_side_rgb(src->a, row, col, 'l');
		dst->arr[1].a = triangle_side_rgb(src->a, row, col, 'l');
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
void	f_fdf_side_r(const t_table_fdf *src, t_triangle_arr *dst, size_t row, size_t col)
{
	if (dst->capacity > 1 && col + 1 < src->col && row + 1 < src->row)
	{
		update_3d_vector(dst->arr[0].p1, (float)col, (float)(row + 1), (float)src->arr[row + 1][col]);
		update_3d_vector(dst->arr[0].p2, (float)(col + 1), (float)row, (float)src->arr[row][col + 1]);
		update_3d_vector(dst->arr[0].p3, (float)(col + 1), (float)row, 0.0);
		update_3d_vector(dst->arr[1].p1, (float)col, (float)(row + 1), (float)src->arr[row + 1][col]);
		update_3d_vector(dst->arr[1].p2, (float)col, (float)(row + 1), 0.0);
		update_3d_vector(dst->arr[1].p3, (float)col + 1, (float)row, 0.0);
		dst->arr[0].r = triangle_side_rgb(src->r, row, col, 'r');
		dst->arr[1].r = triangle_side_rgb(src->r, row, col, 'r');
		dst->arr[0].g = triangle_side_rgb(src->g, row, col, 'r');
		dst->arr[1].g = triangle_side_rgb(src->g, row, col, 'r');
		dst->arr[0].b = triangle_side_rgb(src->b, row, col, 'r');
		dst->arr[1].b = triangle_side_rgb(src->b, row, col, 'r');
		dst->arr[0].a = triangle_side_rgb(src->a, row, col, 'r');
		dst->arr[1].a = triangle_side_rgb(src->a, row, col, 'r');
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
t_triangle_arr	f_fdf_side(const t_table_fdf *src, size_t row, size_t col, char axis)
{
	t_triangle_arr	dst;

	axis = fdf_side_detection(src, row, col, axis);
	dst = init_triangle_arr(2);
	if (dst.arr == NULL)
		return (dst);
	dst.arr[0] = init_triangle();
	dst.arr[1] = init_triangle();
	if (axis == 'n')
	{
		free_triangle_arr(&dst);
		return (dst);
	}
	if (axis == 'x')
		f_fdf_side_x(src, &dst, row, col);
	if (axis == 'y')
		f_fdf_side_y(src, &dst, row, col);
	if (axis == 'l')
		f_fdf_side_l(src, &dst, row, col);
	if (axis == 'r')
		f_fdf_side_r(src, &dst, row, col);
	return (dst);
}
