#ifndef CONVOLUTION_H
# define CONVOLUTION_H

#include "../table/table.h"

// kernel.c
double		**blur_kernel(size_t col, size_t row, double scale);
double		**gaussian_kernel(size_t col, size_t row);
t_table_fdf	*convolute_hight(t_table_fdf *src, size_t col, size_t row, double **kernel);
t_table_fdf	*convolute_rgb(t_table_fdf *src, size_t col, size_t row, double **kernel);

#endif