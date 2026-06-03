#ifndef MATH_H
# define MATH_H

#include <stdlib.h>

// as_int.c
double	f_floor(double num);
double	f_round(double num);
double	f_interval(double num, double min, double max);

// math.c
double	f_sum(double *vector, size_t dim);
double	f_pow(double x, size_t a);
double	newton_method(double x, size_t a, size_t accuracy);
double	f_exp(double x, size_t accuracy);

/*
// trig.c
double	sin(double x, size_t accuracy);
double	cos(double x, size_t accuracy);
double	log(double x, size_t accuracy);
*/

#endif
