#ifndef MATH_H
# define MATH_H

# include <stdlib.h>
# include "../type/type.h"

// as_int.c
float	f_floor(float num);
float	f_round(float num);
float	f_interval(float num, float min, float max);
float	f_max(float a, float b);
float	f_min(float a, float b);

// complex_trig.c
t_complex	complex_exp(t_complex a);
t_complex	complex_sin(t_complex a);
t_complex	complex_cos(t_complex a);

// complex.c
t_complex	complex_multiplication(t_complex a, t_complex b);
t_complex	complex_square(t_complex a);
t_complex	complex_cube(t_complex a);
t_complex	complex_reciprocal(t_complex a);
double		complex_magnitude(t_complex a, char is_square);

// math.c
double	f_pow(double x, size_t a);
double	f_root_finding(double x, size_t a);
double	f_exp(double x);
double	f_sin(double x);
double	f_cos(double x);

// stat.c
double	normal_distribution_function(double std, double means, double x);
double	f_sum(const double *vec_v, size_t dim);

// utils.c
size_t	collatz_max_point(size_t x);
size_t	binary_search_count(size_t min_input, size_t max_input);
double	f_abs(double x);

#endif
