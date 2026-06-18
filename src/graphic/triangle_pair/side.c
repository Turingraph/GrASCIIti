#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	f_fdf_side_x(t_table_fdf src, t_triangle_arr *dst, size_t row, size_t col)
{
	if (dst->capacity > 1 && col + 1 < src.col && row < src.row)
	{
		update_3d_vector(dst->arr[0].p1, col, row, src.arr[row][col]);
		update_3d_vector(dst->arr[0].p2, col + 1, row, src.arr[row][col + 1]);
		update_3d_vector(dst->arr[0].p3, col + 1, row, 0);
		update_3d_vector(dst->arr[1].p1, col, row, src.arr[row][col]);
		update_3d_vector(dst->arr[1].p2, col, row, 0);
		update_3d_vector(dst->arr[1].p3, col + 1, row, 0);
		dst->arr[0].r = (unsigned char)f_interval(f_round((src.r[row][col] + src.r[row][col + 1]) / 2), 0, 255);
		dst->arr[0].g = (unsigned char)f_interval(f_round((src.g[row][col] + src.g[row][col + 1]) / 2), 0, 255);
		dst->arr[0].b = (unsigned char)f_interval(f_round((src.b[row][col] + src.b[row][col + 1]) / 2), 0, 255);
		dst->arr[0].a = (unsigned char)f_interval(f_round((src.a[row][col] + src.a[row][col + 1]) / 2), 0, 255);
		dst->arr[1].r = (unsigned char)f_interval(f_round((src.r[row][col] + src.r[row][col + 1]) / 2), 0, 255);
		dst->arr[1].g = (unsigned char)f_interval(f_round((src.g[row][col] + src.g[row][col + 1]) / 2), 0, 255);
		dst->arr[1].b = (unsigned char)f_interval(f_round((src.b[row][col] + src.b[row][col + 1]) / 2), 0, 255);
		dst->arr[1].a = (unsigned char)f_interval(f_round((src.a[row][col] + src.a[row][col + 1]) / 2), 0, 255);
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
void	f_fdf_side_y(t_table_fdf src, t_triangle_arr *dst, size_t row, size_t col)
{
	if (dst->capacity > 1 && col < src.col && row + 1 < src.row)
	{
		update_3d_vector(dst->arr[0].p1, col, row, src.arr[row][col]);
		update_3d_vector(dst->arr[0].p2, col, row + 1, src.arr[row + 1][col]);
		update_3d_vector(dst->arr[0].p3, col, row + 1, 0);
		update_3d_vector(dst->arr[1].p1, col, row, src.arr[row][col]);
		update_3d_vector(dst->arr[1].p2, col, row, 0);
		update_3d_vector(dst->arr[1].p3, col, row + 1, 0);
		dst->arr[0].r = (unsigned char)f_interval(f_round((src.r[row][col] + src.r[row + 1][col]) / 2), 0, 255);
		dst->arr[0].g = (unsigned char)f_interval(f_round((src.g[row][col] + src.g[row + 1][col]) / 2), 0, 255);
		dst->arr[0].b = (unsigned char)f_interval(f_round((src.b[row][col] + src.b[row + 1][col]) / 2), 0, 255);
		dst->arr[0].a = (unsigned char)f_interval(f_round((src.a[row][col] + src.a[row + 1][col]) / 2), 0, 255);
		dst->arr[1].r = (unsigned char)f_interval(f_round((src.r[row][col] + src.r[row + 1][col]) / 2), 0, 255);
		dst->arr[1].g = (unsigned char)f_interval(f_round((src.g[row][col] + src.g[row + 1][col]) / 2), 0, 255);
		dst->arr[1].b = (unsigned char)f_interval(f_round((src.b[row][col] + src.b[row + 1][col]) / 2), 0, 255);
		dst->arr[1].a = (unsigned char)f_interval(f_round((src.a[row][col] + src.a[row + 1][col]) / 2), 0, 255);
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
void	f_fdf_side_l(t_table_fdf src, t_triangle_arr *dst, size_t row, size_t col)
{
	if (dst->capacity > 1 && col + 1 < src.col && row + 1 < src.row)
	{
		update_3d_vector(dst->arr[0].p1, (float)col, (float)row, (float)src.arr[row][col]);
		update_3d_vector(dst->arr[0].p2, (float)(col + 1), (float)(row + 1), (float)src.arr[row + 1][col + 1]);
		update_3d_vector(dst->arr[0].p3, (float)(col + 1), (float)(row + 1), 0.0);
		update_3d_vector(dst->arr[1].p1, (float)col, (float)row, (float)src.arr[row][col]);
		update_3d_vector(dst->arr[1].p2, (float)col, (float)row, 0.0);
		update_3d_vector(dst->arr[1].p3, (float)(col + 1), (float)(row + 1), 0);
		dst->arr[0].r = (unsigned char)f_interval(f_round((src.r[row][col] + src.r[row + 1][col + 1]) / 2), 0, 255);
		dst->arr[0].g = (unsigned char)f_interval(f_round((src.g[row][col] + src.g[row + 1][col + 1]) / 2), 0, 255);
		dst->arr[0].b = (unsigned char)f_interval(f_round((src.b[row][col] + src.b[row + 1][col + 1]) / 2), 0, 255);
		dst->arr[0].a = (unsigned char)f_interval(f_round((src.a[row][col] + src.a[row + 1][col + 1]) / 2), 0, 255);
		dst->arr[1].r = (unsigned char)f_interval(f_round((src.r[row][col] + src.r[row + 1][col + 1]) / 2), 0, 255);
		dst->arr[1].g = (unsigned char)f_interval(f_round((src.g[row][col] + src.g[row + 1][col + 1]) / 2), 0, 255);
		dst->arr[1].b = (unsigned char)f_interval(f_round((src.b[row][col] + src.b[row + 1][col + 1]) / 2), 0, 255);
		dst->arr[1].a = (unsigned char)f_interval(f_round((src.a[row][col] + src.a[row + 1][col + 1]) / 2), 0, 255);
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
void	f_fdf_side_r(t_table_fdf src, t_triangle_arr *dst, size_t row, size_t col)
{
	if (dst->capacity > 1 && col + 1 < src.col && row + 1 < src.row)
	{
		update_3d_vector(dst->arr[0].p1, (float)col, (float)(row + 1), (float)src.arr[row + 1][col]);
		update_3d_vector(dst->arr[0].p2, (float)(col + 1), (float)row, (float)src.arr[row][col + 1]);
		update_3d_vector(dst->arr[0].p3, (float)(col + 1), (float)row, 0.0);
		update_3d_vector(dst->arr[1].p1, (float)col, (float)(row + 1), (float)src.arr[row + 1][col]);
		update_3d_vector(dst->arr[1].p2, (float)col, (float)(row + 1), 0.0);
		update_3d_vector(dst->arr[1].p3, (float)col + 1, (float)row, 0.0);
		dst->arr[0].r = (unsigned char)f_interval(f_round((src.r[row][col + 1] + src.r[row + 1][col]) / 2), 0, 255);
		dst->arr[0].g = (unsigned char)f_interval(f_round((src.g[row][col + 1] + src.g[row + 1][col]) / 2), 0, 255);
		dst->arr[0].b = (unsigned char)f_interval(f_round((src.b[row][col + 1] + src.b[row + 1][col]) / 2), 0, 255);
		dst->arr[0].a = (unsigned char)f_interval(f_round((src.a[row][col + 1] + src.a[row + 1][col]) / 2), 0, 255);
		dst->arr[1].r = (unsigned char)f_interval(f_round((src.r[row][col + 1] + src.r[row + 1][col]) / 2), 0, 255);
		dst->arr[1].g = (unsigned char)f_interval(f_round((src.g[row][col + 1] + src.g[row + 1][col]) / 2), 0, 255);
		dst->arr[1].b = (unsigned char)f_interval(f_round((src.b[row][col + 1] + src.b[row + 1][col]) / 2), 0, 255);
		dst->arr[1].a = (unsigned char)f_interval(f_round((src.a[row][col + 1] + src.a[row + 1][col]) / 2), 0, 255);
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
t_triangle_arr	f_fdf_side(t_table_fdf src, size_t row, size_t col, char axis)
{
	t_triangle_arr	dst;

	axis = fdf_side_detection(src, row, col, axis);
	dst = init_triangle_arr(2);
	if (dst.arr == NULL)
		return (dst);
	dst.arr[0] = init_triangle();
	dst.arr[1] = init_triangle();
	if (axis == 'n')
		return (dst);
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
