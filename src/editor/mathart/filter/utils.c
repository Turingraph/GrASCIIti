#include"filter.h"

// time : O(1)
// space: O(1)
e_bool	is_colored_cell(size_t row, size_t col, t_table_fdf *dst)
{
	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	if (choose_rgb_channel(dst, RED, row) != NULL && dst->r[row][col] > 0)
		return (TRUE);
	if (choose_rgb_channel(dst, GREEN, row) != NULL && dst->g[row][col] > 0)
		return (TRUE);
	if (choose_rgb_channel(dst, BLUE, row) != NULL && dst->b[row][col] > 0)
		return (TRUE);
	if (choose_rgb_channel(dst, ALPHA, row) != NULL && dst->a[row][col] > 0)
		return (TRUE);
	return (FALSE);
}

// time : O(1)
// space: O(1)
e_bool	is_positive_cell(size_t row, size_t col, t_table_fdf *dst)
{
	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	if (dst->arr != NULL && dst->arr[row] != NULL && dst->arr[row][col] > 0)
		return (TRUE);
	return (FALSE);
}

// time : O(1)
// space: O(1)
e_bool	is_chess_cell(size_t row, size_t col, t_table_fdf *dst)
{
	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	if ((row + col) % 2 == 1)
		return (TRUE);
	return (FALSE);
}

// time : O(1)
// space: O(1)
e_bool	is_conformal_x_func(size_t row, size_t col,
	t_table_fdf *dst, t_complex (*complex_func)(t_complex a))
{
	t_complex	y;
	int			conjugate;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	y = get_table_fdf_coordinate(row, col, dst);
	y = complex_func(y);
	conjugate = (int)f_round(y.re * y.re - y.im * y.im);
	if (conjugate % 2 == 0)
		return (FALSE);
	return (TRUE);
}

// time : O(1)
// space: O(1)
e_bool	is_conformal_func(size_t row, size_t col,
	t_table_fdf *dst, t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	y = get_table_fdf_coordinate(row, col, dst);
	y = complex_func(y);
	if (f_round(complex_magnitude(y, 0)) % 2 == 1)
		return (TRUE);
	return (FALSE);
}

