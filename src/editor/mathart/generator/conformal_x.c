#include "generator.h"

// time : O(1)
// space: O(1)
int	gen_conformal_x_square(size_t row, size_t col, t_table_fdf *dst)
{
	return (gen_conformal_x_func(row, col, dst, complex_square));
}

// time : O(1)
// space: O(1)
int	gen_conformal_x_cube(size_t row, size_t col, t_table_fdf *dst)
{
	return (gen_conformal_x_func(row, col, dst, complex_cube));
}

// time : O(1)
// space: O(1)
int	gen_conformal_x_sin(size_t row, size_t col, t_table_fdf *dst)
{
	return (gen_conformal_x_func(row, col, dst, complex_sin));
}

// time : O(1)
// space: O(1)
int	gen_conformal_x_reciprocal(size_t row, size_t col, t_table_fdf *dst)
{
	return (gen_conformal_x_func(row, col, dst, complex_reciprocal));
}

// I will implement this function after submit fdf42 coding project.
// time : O(1)
// space: O(1)
int	gen_conformal_x_log(size_t row, size_t col, t_table_fdf *dst)
{
	return (gen_conformal_x_func(row, col, dst, complex_square));
}

