#ifndef MATH_H
# define MATH_H

#include <stdlib.h>

// as_int.c
double	f_floor(double num);
double	f_round(double num);
double	f_interval(double num, double min, double max);

// euclid.c
double	euclid_distance(double *vec_v, double *vec_0, size_t dim, char square);
double	cos_between_2_vectors(double *vec_v, double *vec_u, size_t dim);
void	vector_projection(double *vec_v, double *vec_u, size_t dim);
double	scale_projection(double *vec_v, double *vec_u, size_t dim);

// math.c
double	f_sum(double *vector, size_t dim);
double	f_pow(double x, size_t a);
double	newton_method(double x, size_t a, size_t accuracy);
double	f_exp(double x, size_t accuracy);

// three_dim.c
void	cross_product_3d(double *update_v, double *vec_u);
void	update_3d_vector(double *dst, double x, double y, double z);
double	*create_3d_vector(double x, double y, double z);

// vector.c
void	vec_add(double *update_v, double *vec_u, size_t dim);
void	scale_vec(double *update_v, double s, size_t dim);
double	dot_product(double *vec_v, double *vec_u, size_t dim);
char	matrix_times_vec(double **matrix, double *update_v, size_t dim);

/*
// trig.c
double	sin(double x, size_t accuracy);
double	cos(double x, size_t accuracy);
double	log(double x, size_t accuracy);
*/

#endif
