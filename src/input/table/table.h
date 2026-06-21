#ifndef TABLE_H
# define TABLE_H

#include <stdlib.h>
#include "../../utils/libft/libft.h"
#include "../../utils/type/type.h"
#include "../../utils/math/math.h"

// arr.c
void			copy_int_arr(int *dst, int *src, size_t len, size_t scale_dim);
int				**init_2d_int_arr(size_t row, size_t col);

// init.c
void			*free_table_fdf(t_table_fdf *src);
t_table_fdf		init_table_fdf(size_t row, size_t col, e_bool is_rgb);
t_table_fdf		load_table_fdf(t_load_fdf_arr src, e_bool is_rgb);

// scale.c
t_table_fdf		scale_dimension_fdf(t_table_fdf src, size_t scale_row, size_t scale_col);
void			scale_addition_fdf(t_table_fdf *src, int scale);
void			scale_hadamard_fdf(t_table_fdf *src, float scale);
void			scale_relu_fdf(t_table_fdf *src, int min, int max, int expect);
size_t			scale_positive_fdf(t_table_fdf *src, e_bool is_update);

// write.c
void			write_table_fdf(int fd, t_table_fdf src, e_bool is_rgb, size_t digits);

#endif
