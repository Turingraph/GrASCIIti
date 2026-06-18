#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	triangle_fdf_rgb(t_table_fdf src, t_triangle *dst, size_t row, size_t col)
{
	float	drgb;

	drgb = (float)((int)src.r[row][col] + (int)src.r[row + 1][col] + (int)src.r[row][col + 1] + (int)src.r[row + 1][col + 1]) / 4;
	dst->r = (unsigned char)f_round(f_interval(drgb, 0, 255));
	drgb = (float)((int)src.g[row][col] + (int)src.g[row + 1][col] + (int)src.g[row][col + 1] + (int)src.g[row + 1][col + 1]) / 4;
	dst->g = (unsigned char)f_round(f_interval(drgb, 0, 255));
	drgb = (float)((int)src.b[row][col] + (int)src.b[row + 1][col] + (int)src.b[row][col + 1] + (int)src.b[row + 1][col + 1]) / 4;
	dst->b = (unsigned char)f_round(f_interval(drgb, 0, 255));
	drgb = (float)((int)src.a[row][col] + (int)src.a[row + 1][col] + (int)src.a[row][col + 1] + (int)src.a[row + 1][col + 1]) / 4;
	dst->a = (unsigned char)f_round(f_interval(drgb, 0, 255));
}

// time : O(1)
// space: O(1)
t_triangle	f_fdf_triangle(t_table_fdf src, size_t row, size_t col, char mode)
{
	t_triangle	dst;

	dst = init_triangle();
	triangle_fdf_rgb(src, &dst, row, col);
	if (mode == 1 || mode == 2)
	{
		update_3d_vector(dst.p1, col, row, src.arr[row][col]);
		update_3d_vector(dst.p2, col, row + 1, src.arr[row + 1][col]);
		if (mode == 2)
			update_3d_vector(dst.p2, col + 1, row, src.arr[row][col + 1]);
		update_3d_vector(dst.p3, col + 1, row + 1, src.arr[row + 1][col + 1]);
		return (dst);
	}
	update_3d_vector(dst.p1, col, row + 1, src.arr[row + 1][col]);
	update_3d_vector(dst.p2, col, row, src.arr[row][col]);
	if (mode == 4)
		update_3d_vector(dst.p2, col + 1, row + 1, src.arr[row + 1][col + 1]);
	update_3d_vector(dst.p3, col + 1, row, src.arr[row][col + 1]);
	return (dst);
}

// time : O(1)
// space: O(1)
int	count_2_fdf_triangles(t_table_fdf src, size_t row, size_t col, char *mode)
{
	int		y;

	y = 0;
	if (src.row < 2 || src.col < 2 || src.row <= row + 1 || src.col <= col + 1)
		return (-1);
	if (src.arr[row][col] > 0)
		y += 1;
	if (src.arr[row + 1][col] > 0)
		y += 1;
	if (src.arr[row + 1][col + 1] > 0)
		y += 1;
	if (src.arr[row][col + 1] > 0)
		y += 1;
	if (y == 3 && src.arr[row][col + 1] <= 0)
		*mode = 1;
	if (y == 3 && src.arr[row + 1][col] <= 0)
		*mode = 2;
	if (y == 3 && src.arr[row + 1][col + 1] <= 0)
		*mode = 3;
	if (y == 3 && src.arr[row][col] <= 0)
		*mode = 4;
	if (y >= 3)
		return (y / 2);
	return (0);
}

// time : O(1)
// space: O(1)
float	test_2_fdf_triangles(t_table_fdf src, size_t row, size_t col)
{
	float		y;
	float		*target;
	t_triangle	triangle;

	if (src.row < 2 || src.col < 2 || src.row <= row + 1 || src.col <= col + 1)
		return (0);
	target = create_3d_vector(col + 1, row, src.arr[row][col + 1]);
	if (target == NULL)
		return (0);
	triangle = f_fdf_triangle(src, row, col, 1);
	scale_vec(triangle.p2, -1.0, 3);
	vec_add(triangle.p1, triangle.p2, 3);
	vec_add(triangle.p3, triangle.p2, 3);
	cross_product_3d(triangle.p1, triangle.p3);
	y = scale_projection(triangle.p1, target, 3);
	free(target);
	free_triangle(triangle);
	return (y);
}

// time : O(1)
// space: O(1)
t_triangle_arr	f_fdf_face(t_table_fdf src, size_t row, size_t col, char prism)
{
	t_triangle_arr	dst;
	char			mode;

	mode = 0;
	dst = init_triangle_arr(2);
	if (row + 1 >= src.row || col + 1 >= src.col)
		return (dst);
	dst.length += count_2_fdf_triangles(src, row, col, &mode);
	if (dst.length == 2 || prism == 0)
	{
		dst.length = 2;
		if (test_2_fdf_triangles(src, row, col) > 0)
		{
			dst.arr[0] = f_fdf_triangle(src, row, col, 3);
			dst.arr[1] = f_fdf_triangle(src, row, col, 4);
			return (dst);
		}
		dst.arr[0] = f_fdf_triangle(src, row, col, 1);
		dst.arr[1] = f_fdf_triangle(src, row, col, 2);
		return (dst);
	}
	if (dst.length == 1)
		dst.arr[0] = f_fdf_triangle(src, row, col, mode);
	return (dst);
}
