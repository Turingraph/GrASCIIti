#include"generator.h"

// time : O(1)
// space: O(1)
int	gen_conformal_x_func(size_t row, size_t col,
	t_table_fdf *dst, t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	y = get_table_fdf_coordinate(row, col, dst);
	y = complex_func(y);
	return ((int)f_round(y.re * y.re - y.im * y.im));
}

// time : O(1)
// space: O(1)
int	gen_conformal_func(size_t row, size_t col,
	t_table_fdf *dst, t_complex (*complex_func)(t_complex a))
{
	t_complex	y;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	y = get_table_fdf_coordinate(row, col, dst);
	y = complex_func(y);
	return (f_round(complex_magnitude(y, 0)));
}

// I will implement this function after submit fdf42 coding project.
// This function will solve the heat equation of the 2D plate
// where the height of each cell is the heat at the given point.
// P.S. I'm not familiar with Fourier transform and heat equation,
// so I have to research about this a lot.
// time : O(???)
// space: O(???)
int	gen_fourier_heat(size_t row, size_t col, t_table_fdf *dst)
{
	return (gen_conformal_func(row, col, dst, complex_square));
}

// time : O(1)
// space: O(1)
int	gen_gaussian_bell_curve(size_t row, size_t col, t_table_fdf *dst)
{
	t_complex	y;

	if (row >= dst->row || col >= dst->col)
		return (FALSE);
	y = get_table_fdf_coordinate(row, col, dst);
	return (f_rount(f_exp(-1 * (y.re * y.re + y.im * y.im), 12)));
}