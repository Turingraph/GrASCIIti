#ifndef GENERATOR_H
# define GENERATOR_H

# include "../../../utils/type/type.h"
# include "../../../utils/libft/libft.h"
# include "../../../utils/math/math.h"

/*
I will finish this folder after submit fdf42 project.
*/

/*
List of unfinished function that I will implement after submit fdf42.
1.	gen_conformal_x_log
2.	gen_conformal_log
3.	every functions from derivertive.c
4.	gen_fourier_heat
*/

// conformal_x.c
int	gen_conformal_x_square(size_t row, size_t col, t_table_fdf *dst);
int	gen_conformal_x_cube(size_t row, size_t col, t_table_fdf *dst);
int	gen_conformal_x_sin(size_t row, size_t col, t_table_fdf *dst);
int	gen_conformal_x_log(size_t row, size_t col, t_table_fdf *dst);
int	gen_conformal_x_reciprocal(size_t row, size_t col, t_table_fdf *dst);

// conformal.c
int	gen_conformal_square(size_t row, size_t col, t_table_fdf *dst);
int	gen_conformal_cube(size_t row, size_t col, t_table_fdf *dst);
int	gen_conformal_sin(size_t row, size_t col, t_table_fdf *dst);
int	gen_conformal_log(size_t row, size_t col, t_table_fdf *dst);
int	gen_conformal_reciprocal(size_t row, size_t col, t_table_fdf *dst);

// discrete_math.c
int	gen_collatz_coloring(size_t row, size_t col, t_table_fdf *dst);
int	gen_collatz_x_coloring(size_t row, size_t col, t_table_fdf *dst);
int	gen_binary_search_coloring(size_t row, size_t col, t_table_fdf *dst);
int	gen_binary_search_x_coloring(size_t row, size_t col, t_table_fdf *dst);

// utils.c
int	gen_conformal_x_func(size_t row, size_t col,
	t_table_fdf *dst, t_complex (*complex_func)(t_complex a));
int	gen_conformal_func(size_t row, size_t col,
	t_table_fdf *dst, t_complex (*complex_func)(t_complex a));
int	gen_fourier_heat(size_t row, size_t col, t_table_fdf *dst);
int	gen_gaussian_bell_curve(size_t row, size_t col, t_table_fdf *dst);

#endif
