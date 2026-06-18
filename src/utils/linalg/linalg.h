#ifndef GEOMETRY_H
# define GEOMETRY_H

# include "stdlib.h"
# include "../math/math.h"

// euclid.c
float	euclid_distance(float *vec_v, float *vec_0, size_t dim, char square);
float	cos_between_2_vectors(float *vec_v, float *vec_u, size_t dim);
void	vector_projection(float *vec_v, float *vec_u, size_t dim);
float	scale_projection(float *vec_v, float *vec_u, size_t dim);

// three_dim.c
void	cross_product_3d(float *update_v, float *vec_u);
void	update_3d_vector(float *dst, float x, float y, float z);
float	*create_3d_vector(float x, float y, float z);

// vector.c
void	vec_add(float *update_v, float *vec_u, size_t dim);
void	scale_vec(float *update_v, float s, size_t dim);
float	dot_product(float *vec_v, float *vec_u, size_t dim);
char	matrix_times_vec(float **matrix, float *update_v, size_t dim);

#endif
