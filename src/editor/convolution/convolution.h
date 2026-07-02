#ifndef CONVOLUTION_H
# define CONVOLUTION_H

# include "../../input/table/table.h"

typedef struct t_table_rgba t_table_rgba;

struct t_table_rgba
{
	size_t			row;
	size_t			col;
	unsigned char	**arr;
};

// convolution.c
t_table_fdf	convolution_hight(const t_table_fdf *src, double **kernel, size_t half_dim);
t_table_fdf	convolution_rgb(const t_table_fdf *src, double **kernel, size_t half_dim, e_rgba rgb_type);

// kernel.c
double		**blur_kernel_2d(size_t dim, double scale);
double		*gaussian_kernel_1d(size_t half_dim);
double		**outer_product_kernel(const double *vec_v, const double *vec_u, size_t dim);

// src_kernel.c
void		row_of_src_kernel_int(const int *src, double *dst, size_t col, size_t max_col);
double		**src_kernel_int(const t_table_fdf *src, size_t row, size_t col, size_t half_dim);
double		**src_kernel_char(const t_table_rgba *src, size_t row, size_t col, size_t half_dim);

#endif
