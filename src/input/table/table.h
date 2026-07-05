#ifndef TABLE_H
# define TABLE_H

#include <stdlib.h>
#include "../../input/load/load.h"
#include "../../utils/math/math.h"

// arr.c
void			copy_uchar_arr(unsigned char *dst, const unsigned char *src, size_t len, size_t scale_dim);
unsigned char	**init_2d_uchar_arr(size_t row, size_t col);
void			copy_int_arr(int *dst, const int *src, size_t len, size_t scale_dim);
int				**init_2d_int_arr(size_t row, size_t col);

// init.c
void			*free_table_fdf(t_table_fdf *src);
t_table_fdf		init_table_fdf(size_t row, size_t col, e_bool is_rgb);
t_table_fdf		load_table_fdf(const t_load_fdf_arr *src, e_bool is_rgb);

// scale.c
t_table_fdf		scale_dimension_fdf(const t_table_fdf *src, size_t scale_row, size_t scale_col);
void			scale_addition_fdf(t_table_fdf *src, int scale);
void			scale_hadamard_fdf(t_table_fdf *src, float scale);
void			scale_relu_fdf(t_table_fdf *src, int min, int max, int expect);
int				scale_positive_fdf(t_table_fdf *src, e_bool is_update, e_bool return_min);

// shade.c
void			write_table_ascii_cheche01(int fd, const t_table_fdf *src, e_5cell_channels channel);
void			write_table_ascii_standard(int fd, const t_table_fdf *src, e_5cell_channels channel);
void			write_table_ascii_chungaloider(int fd, const t_table_fdf *src, e_5cell_channels channel);

// type.c
unsigned char	**choose_rgb_channel(const t_table_fdf *src, e_rgba rgb_type,
					size_t row);
e_bool			is_rgbah_table_not_null(const t_table_fdf *src, size_t row);
t_complex		get_table_fdf_coordinate(size_t row, size_t col,
					const t_table_fdf *dst);
e_bool			is_default_rgba(const unsigned char **r,
					const unsigned char **g,
					const unsigned char **b, const unsigned char **a);

// utils.c
void			set_table_fdf_origin(t_table_fdf *dst, e_axis direction, size_t ith_position, size_t max_position);
t_table_fdf		open_table_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*one_line)(char *line), e_bool is_rgb);

// write.c
void			write_table_fdf(int fd, const t_table_fdf *src, size_t digits, e_write_style mode);
void			write_table_ascii(int fd, const t_table_fdf *src, e_5cell_channels channel, const char *dict);

#endif
