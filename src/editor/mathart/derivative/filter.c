#include"derivative.h"

/*
I will implement this function after submit fdf42 coding project.

Every function will return FALSE if the output <= 0, and TRUE if the output > 0.
It is implemented according to typical calculus 3 formulas.
*/

// time : O(1)
// space: O(1)
e_bool	is_evenodd_curl(size_t row, size_t col, t_table_fdf *dst)
{
	return (is_conformal_func(row, col, dst, complex_square));
}

// time : O(1)
// space: O(1)
e_bool	is_evenodd_divergence(size_t row, size_t col, t_table_fdf *dst)
{
	return (is_conformal_func(row, col, dst, complex_square));
}

// time : O(1)
// space: O(1)
e_bool	is_evenodd_gradient(size_t row, size_t col, t_table_fdf *dst)
{
	return (is_conformal_func(row, col, dst, complex_square));
}

// time : O(1)
// space: O(1)
e_bool	is_evenodd_partial_der(size_t row, size_t col, t_table_fdf *dst)
{
	return (is_conformal_func(row, col, dst, complex_square));
}

// time : O(1)
// space: O(1)
e_bool	is_evenodd_jacobian_det(size_t row, size_t col, t_table_fdf *dst)
{
	return (is_conformal_func(row, col, dst, complex_square));
}
