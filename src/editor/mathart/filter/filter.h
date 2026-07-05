#ifndef FILTER_H
# define FILTER_H

# include "../mathart.h"

/*
I will finish this folder after submit fdf42 project.

I calculate manually and use Wolfarm Alpha to calculate the derivative of z^3.
Here is the result.
*	note that z = x+yi, where i = root of -1.
*	d/dz[z^3] = 3z^2 = 3 * (x^2-y^2+2xyi) = 3x^2 - 3y^2 + 6xyi
*	d/dx[(x+yi)^3] = 3x^2 - 3y^2 + 6xyi = d/dz[z^3]
*	d/dy[(x+yi)^3] = 3x^2i - 3y^2i - 6xy = d/dz[z^3i]

It "feel" that there might be a conjecture/theorem
that d/dx[f(z)] = d/dz[f(z)] and d/dy[f(z)] = d/dy[f(z)i].

ChatGPT said that this is the result of Cauchy–Riemann equations.

Also ChatGPT recommend me to use ln(1 - |J|) if |J| produce too saturated color.
where J = jacobian matrix of the complex value function.

According to Wolfarm Website ( https://mathworld.wolfram.com/Cauchy-RiemannEquations.html )
*	0 = d/dx f(x + yi) + i * d/dy f(x + yi)
*	d/dx f(x + yi) = - i * d/dy f(x + yi)

This implies that generating the curl, gradient, partial derivative,
and determanent of Jacobian Matrix of basic functions
e.g. polynomial, trigonometry, log, exponential etc.
might not yield interesting artistic result (according to my subjective taste).

One interesting idea that ChatGPT recommend me is to apply those operation, use f_round,
and then mod by 2, in FILTER (because f_round() % 2 isn't linear operator).
*/

/*
List of unfinished function that I will implement after submit fdf42.
1.	is_conformal_x_log
2.	is_conformal_log
3.	every functions from derivertive.c
*/

// border.c
e_bool	is_in_prism_border(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_in_prism_terrain(size_t row, size_t col, t_table_fdf *dst);

// conformal_x.c
e_bool	is_conformal_x_square(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_x_cube(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_x_sin(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_x_reciprocal(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_x_log(size_t row, size_t col, t_table_fdf *dst);

// conformal.c
e_bool	is_conformal_square(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_cube(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_sin(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_log(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_reciprocal(size_t row, size_t col, t_table_fdf *dst);

// discrete_math.c
e_bool	is_collatz_coloring(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_collatz_x_coloring(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_binary_search_coloring(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_binary_search_x_coloring(size_t row, size_t col, t_table_fdf *dst);

// utils.c
e_bool	is_colored_cell(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_positive_cell(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_chess_cell(size_t row, size_t col, t_table_fdf *dst);
e_bool	is_conformal_x_func(size_t row, size_t col,
	t_table_fdf *dst, t_complex (*complex_func)(t_complex a));
e_bool	is_conformal_func(size_t row, size_t col,
	t_table_fdf *dst, t_complex (*complex_func)(t_complex a));

#endif
