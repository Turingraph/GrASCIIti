#include"filter.h"

// time : O(???) but might be O(log(n))
// space: O(1)
e_bool	is_collatz_coloring(size_t row, size_t col, t_table_fdf *dst)
{
	int		input;
	size_t	max;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	input = f_round(complex_magnitude(
		get_table_fdf_coordinate(row, col, dst), 0));
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input) / 7;
	if (max % 2 == 0)
		return (FALSE);
	return (TRUE);
}

// time : O(???) but might be O(log(n))
// space: O(1)
e_bool	is_collatz_x_coloring(size_t row, size_t col, t_table_fdf *dst)
{
	t_complex	cinput;
	int			input;
	size_t		max;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	cinput = get_table_fdf_coordinate(row, col, dst);
	input = f_round(cinput.re) * f_round(cinput.im);
	if (input < 0)
		input *= -1;
	max = collatz_max_point((size_t)input) / 7;
	if (max % 2 == 0)
		return (FALSE);
	return (TRUE);
}

// time : O(log(n))
// space: O(1)
e_bool	is_binary_search_coloring(size_t row, size_t col, t_table_fdf *dst)
{
	int		input;
	size_t	max;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	input = f_round(complex_magnitude(
		get_table_fdf_coordinate(row, col, dst), 0));
	if (input < 0)
		input *= -1;
	max = binary_search_count((size_t)input,
		(size_t)f_round(newton_method(dst->row * dst->row + dst->col * dst->col, 2, 12)));
	if (max % 2 == 0)
		return (FALSE);
	return (TRUE);
}

// time : O(log(n))
// space: O(1)
e_bool	is_binary_search_x_coloring(size_t row, size_t col, t_table_fdf *dst)
{
	t_complex	cinput;
	int			input;
	size_t		max;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	cinput = get_table_fdf_coordinate(row, col, dst);
	input = (int)f_round(cinput.re) * (int)f_round(cinput.im);
	if (input < 0)
		input *= -1;
	max = binary_search_count((size_t)input, dst->row * dst->col);
	if (max % 2 == 0)
		return (FALSE);
	return (TRUE);
}
