#ifndef MATH_H
# define MATH_H

#include <stdlib.h>

// as_int.c
float	f_floor(float num);
float	f_round(float num);
float	f_interval(float num, float min, float max);
float	f_max(float a, float b);

// math.c
double	f_sum(double *vector, size_t dim);
double	f_pow(double x, size_t a);
double	newton_method(double x, size_t a, size_t accuracy);
double	f_exp(double x, size_t accuracy);
double	normal_distribution_function(double std, double means, double x);

// prime.c
size_t	next_prism(size_t num);
char	is_prime(size_t num);

/*
// trig.c
double	sin(double x, size_t accuracy);
double	cos(double x, size_t accuracy);
double	log(double x, size_t accuracy);
*/

#endif
