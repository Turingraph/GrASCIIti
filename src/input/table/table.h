#ifndef TABLE_H
# define TABLE_H

#include <stdlib.h>
#include "../../input/load/load.h"
#include "../../utils/math/math.h"

typedef enum e_5cell_channels e_5cell_channels;

enum e_5cell_channels
{
	D5_RED,
	D5_GREEN,
	D5_BLUE,
	D5_ALPHA,
	D5_HEIGHT
};

// init.c
void			*free_table_fdf(t_table_fdf *src);
t_table_fdf		init_table_fdf(size_t row, size_t col, bool is_rgba);
t_table_fdf		load_table_fdf(const t_load_fdf_arr *src, bool is_rgba);

// scale.c
t_table_fdf		scale_dimension_fdf(const t_table_fdf *src, size_t scale_row, size_t scale_col);
void			scale_multiplication_fdf(t_table_fdf *dst, float scale, e_5cell_channels channels);
void			scale_addition_fdf(t_table_fdf *dst, int input, e_5cell_channels channels);
int				get_minmax_from_table_fdf(t_table_fdf *dst, bool is_max, e_5cell_channels channels);
void			scale_positive_fdf(t_table_fdf *dst);

// shade.c
void			write_table_ascii_cheche01(int fd, const t_table_fdf *src, e_5cell_channels channel);
void			write_table_ascii_standard(int fd, const t_table_fdf *src, e_5cell_channels channel);
void			write_table_ascii_chungaloider(int fd, const t_table_fdf *src, e_5cell_channels channel);

// utils.c
void			set_table_fdf_origin(t_table_fdf *dst, size_t direction, size_t ith_position, size_t max_position);
t_table_fdf		open_table_fdf_file(const char *file_name, const char *dir,
					t_load_fdf (*one_line)(const char *line), bool is_rgba);
t_complex		get_table_fdf_coordinate(const t_table_fdf *dst, size_t index);
unsigned char	*get_rgba_of_table_fdf(const t_table_fdf *src, e_rgba rgba_type);

// write.c
void			write_table_fdf(int fd, const t_table_fdf *src, size_t digits, e_write_style mode);
void			write_table_ascii(int fd, const t_table_fdf *src, e_5cell_channels channel, const char *dict);

#endif
