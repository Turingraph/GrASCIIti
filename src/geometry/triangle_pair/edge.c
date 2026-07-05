#include"triangle_pair.h"

// time : O(1)
// space: O(1)
void	get_edge_indexing(size_t *row, size_t *col, e_edge mode)
{
	if (mode == EDGE_X || mode == EDGE_DIAGONAL_RIGHT)
		*col += 1;
	if (mode == EDGE_Y)
		*row += 1;
	if (mode == EDGE_DIAGONAL_LEFT)
	{
		*row += 1;
		*col += 1;
	}
}

// time : O(1)
// space: O(1)
void	init_edge_positions(t_triangle_arr *dst, size_t row, size_t col, e_edge mode)
{
	size_t	row_2;
	size_t	col_2;

	if (dst != NULL && dst->capacity > 1 && dst->arr != NULL)
	{
		row_2 = row;
		col_2 = col;
		get_edge_indexing(&row_2, &col_2, mode);
		if (mode == EDGE_DIAGONAL_RIGHT)
			row += 1;
		update_3d_vector(dst->arr[0].p1, (float)col, (float)row, 1.0);
		update_3d_vector(dst->arr[0].p2, (float)col, (float)row, 0);
		update_3d_vector(dst->arr[0].p3, (float)col_2, (float)row_2, 0);
		update_3d_vector(dst->arr[1].p1, (float)col, (float)row, 1.0);
		update_3d_vector(dst->arr[1].p2, (float)col_2, (float)row_2, 1.0);
		update_3d_vector(dst->arr[1].p3, (float)col_2, (float)row_2, 0);
		dst->length = 2;
	}
}

// time : O(1)
// space: O(1)
e_edge	fdf_edge_detection(const t_table_fdf *src, size_t row, size_t col, e_edge mode)
{
	if (row >= src->row || col >= src->col)
		return (EDGE_INVALID);
	if ((mode == EDGE_DIAGONAL_LEFT || mode == EDGE_DIAGONAL_RIGHT) && (row + 1 >= src->row || col + 1 >= src->col))
		return (EDGE_INVALID);
	if (mode == EDGE_X && row < src->row && col + 1 < src->col
		&& src->arr[row][col] > 0 && src->arr[row][col + 1] > 0 && ((row == 0)
		|| (row > 0 && src->arr[row - 1][col] <= 0 && src->arr[row - 1][col + 1] <= 0)
		|| (row < src->row - 1 && src->arr[row + 1][col] <= 0 && src->arr[row + 1][col + 1] <= 0)
		|| (row + 1 == src->row - 1)))
		return (EDGE_X);
	if (mode == EDGE_X && row + 1 < src->row && col < src->col
		&& src->arr[row][col] > 0 && src->arr[row + 1][col] > 0 && ((col == 0)
		|| (col > 0 && src->arr[row][col - 1] <= 0 && src->arr[row + 1][col - 1] <= 0)
		|| (col < src->col - 1 && src->arr[row][col + 1] <= 0 && src->arr[row + 1][col + 1] <= 0)
		|| (col + 1 == src->col - 1)))
		return (EDGE_X);
	if (mode == EDGE_DIAGONAL_LEFT && row + 1 < src->row && col + 1 < src->col
		&& src->arr[row][col] > 0 && src->arr[row + 1][col + 1] > 0
		&& (src->arr[row][col + 1] <= 0 || src->arr[row + 1][col] <= 0))
		return (EDGE_DIAGONAL_LEFT);
	if ((mode == EDGE_DIAGONAL_RIGHT && row + 1 < src->row && col + 1 < src->col
		&& src->arr[row + 1][col] > 0 && src->arr[row][col + 1] > 0)
		&& ((src->arr[row][col] <= 0 || src->arr[row + 1][col + 1] <= 0)))
		return (EDGE_DIAGONAL_RIGHT);
	return (EDGE_INVALID);
}

// time : O(1)
// space: O(1)
void	*f_fdf_edge_coloring(const t_table_fdf *src, size_t row, size_t col, t_triangle_arr *dst)
{
	if (src == NULL || row >= src->row || col >= src->col || dst == NULL
		|| src->r == NULL || src->r[row] == NULL
		|| src->g == NULL || src->g[row] == NULL
		|| src->b == NULL || src->b[row] == NULL
		|| src->a == NULL || src->a[row] == NULL)
		return (NULL);
	dst->arr[0].r = src->r[row][col];
	dst->arr[0].g = src->r[row][col];
	dst->arr[0].b = src->r[row][col];
	dst->arr[0].a = src->r[row][col];
	dst->arr[1].r = src->r[row][col];
	dst->arr[1].g = src->r[row][col];
	dst->arr[1].b = src->r[row][col];
	dst->arr[1].a = src->r[row][col];
	if (src->color_sampling == SAMPLE_AVERAGE
		|| src->color_sampling == SAMPLE_EDGE_AVERAGE)
	{
		edge_average_tri_coloring(src->r, dst, RED);
		edge_average_tri_coloring(src->g, dst, GREEN);
		edge_average_tri_coloring(src->b, dst, BLUE);
		edge_average_tri_coloring(src->a, dst, ALPHA);
	}
	return (NULL);
}

// time : O(1)
// space: O(1)
t_triangle_arr	f_fdf_edge(const t_table_fdf *src, size_t row, size_t col, e_edge mode)
{
	t_triangle_arr	dst;

	mode = fdf_edge_detection(src, row, col, mode);
	dst = init_triangle_arr(2, 0, 0);
	if (dst.arr == NULL)
		return (dst);
	dst.arr[0] = init_triangle();
	dst.arr[1] = init_triangle();
	if (mode == EDGE_INVALID)
	{
		free_triangle_arr(&dst);
		return (dst);
	}
	init_edge_positions(&dst, row, col, mode);
	if (dst.arr[0].p1[0] < src->col && dst.arr[0].p1[1] < src->row
		&& dst.arr[1].p2[0] < src->col && dst.arr[1].p2[1] < src->row)
	{
		dst.arr[0].p1[2] = src->arr[dst.arr[0].p1[1]][dst.arr[0].p1[0]];
		dst.arr[1].p1[2] = dst.arr[0].p1[2];
		dst.arr[1].p2[2] = src->arr[dst.arr[1].p2[1]][dst.arr[1].p2[0]];
	}
	f_fdf_edge_coloring(src, row, col, &dst);
	return (dst);
}
