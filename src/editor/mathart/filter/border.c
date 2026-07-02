#include "filter.h"

// time : O(1)
// space: O(1)
int	count_2_fdf_triangles_bool(t_table_fdf *src, size_t row, size_t col)
{
	int		y;

	y = 0;
	if (src->row < 2 || src->col < 2 || src->row <= row + 1 || src->col <= col + 1)
		return (-1);
	if (src->arr[row][col] > 0)
		y += 1;
	if (src->arr[row + 1][col] > 0)
		y += 1;
	if (src->arr[row + 1][col + 1] > 0)
		y += 1;
	if (src->arr[row][col + 1] > 0)
		y += 1;
	if (y >= 3)
		return (y / 2);
	return (0);
}

// time : O(1)
// space: O(1)
e_bool	is_in_prism_border(size_t row, size_t col, t_table_fdf *dst)
{
	int	y;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	if (row == dst->row - 1)
		row -= 1;
	if (col == dst->col - 1)
		col -= 1;
	y = count_2_fdf_triangles_bool(dst, row, col);
	if (y == 1)
		return (TRUE);
	return (FALSE);
}

// time : O(1)
// space: O(1)
e_bool	is_in_prism_terrain(size_t row, size_t col, t_table_fdf *dst)
{
	int	y;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	if (row == dst->row - 1)
		row -= 1;
	if (col == dst->col - 1)
		col -= 1;
	y = count_2_fdf_triangles_bool(dst, row, col);
	if (y == 2)
		return (TRUE);
	return (FALSE);
}
