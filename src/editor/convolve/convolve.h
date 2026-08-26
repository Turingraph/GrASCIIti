#ifndef CONVOLVE_H
# define CONVOLVE_H

# include "../../input/table/table.h"
# include "../../utils/linalg/linalg.h"

// convolve_height.c
t_table_fdf	convolve_hight(const t_table_fdf *src, t_matrix kernel);;

// convolve_rgba.c
t_table_fdf	convolve_rgba(const t_table_fdf *src, t_matrix kernel, t_rgba target_channels);

// gauss.c
double	normal_distribution_function(double std, double means, double x);
float	f_std(const float *vec_v, size_t dim);

// kernel.c
float		*gaussian_kernel_1d(size_t half_dim, float std);
t_matrix	gaussian_kernel(size_t half_dim, float std_1, float std_2);

#endif
