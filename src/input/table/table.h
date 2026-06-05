#ifndef TABLE_H
# define TABLE_H

#include <stdlib.h>
#include "../../utils/libft/libft.h"
#include "../../utils/type/type.h"
#include "../../utils/math/math.h"

// arr.c
unsigned char	**init_null_char_arr(size_t row, size_t col);
int				**init_null_int_arr(size_t row, size_t col);

// convert.c
size_t			get_dim(t_llist_fdf *src, char dim);
void			*free_table_fdf(t_table_fdf *table);
t_table_fdf		*init_table_fdf(size_t row, size_t col);
t_table_fdf		*llist_to_table_fdf(t_llist_fdf *src);

// positive.c
long			min_and_max_fdf(t_table_fdf *table, char mode);
void			scale_relu_fdf(t_table_fdf *table, int min, int max, int expect);
void			scale_addition_fdf(t_table_fdf *table, int scale);
void			positive_table_fdf(t_table_fdf *table);

// save.c
void			write_table_fdf(int fd, t_table_fdf *table, char show_rgb, size_t n_digits);

// scale.c
t_table_fdf		*scale_dimension_fdf(t_table_fdf *src, size_t s_row, size_t s_col);
void			scale_hadamard_fdf(t_table_fdf *table, double scale);

#endif
