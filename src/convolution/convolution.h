#ifndef CONVOLUTION_H
# define CONVOLUTION_H

#include "../table/table.h"
#include "../math/math.h"

// convolution.c
t_table_fdf	*convolution_hight(t_table_fdf *src, double **kernel, size_t half_dim);
t_table_fdf	*convolution_rgb(t_table_fdf *src, double **kernel, size_t half_dim, char rgb_type);

// kernel.c
double		**blur_kernel_2d(size_t dim, double scale);
double		*gaussian_kernel_1d(size_t half_dim);
double		**one_dim_to_two_dim(double *vec_v, double *vec_u, size_t half_dim);

// src_kernel.c
void		row_of_src_kernel_int(int *src, double *dst, size_t col, size_t max_col);
double		**src_kernel_int(t_table_fdf *src, size_t row, size_t col, size_t half_dim);
double		**src_kernel_char(t_table_char *src, size_t row, size_t col, size_t half_dim);

#endif
