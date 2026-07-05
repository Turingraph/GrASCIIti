#ifndef PAINT_H
# define PAINT_H

# include "../../input/table/table.h"
# include <fcntl.h>

/*
List of unfinished function that I will implement after submit fdf42.
1.	outlier.c
2.	thue_morse.c
*/

typedef struct t_gradient t_gradient;

struct t_gradient
{
	t_rgba				start_rgb;
	t_rgba				end_rgb;
	e_7cell_channels	cell_channel;
	int					start_value;
	int					end_value;
};

// gradient.c
void	color_cells_gradient(t_table_fdf *dst,
	t_gradient *gradient_input,
	e_bool is_overwrite,
	e_bool(*is_filtered_cell)(size_t row, size_t col, t_table_fdf *dst));

// outlier.c
void	print_outlier(void);

// paint.c
void	fill_cells_height(
	t_table_fdf *dst,
	int height,
	e_bool is_overwrite,
	e_bool(*is_filtered_cell)(size_t row, size_t col, t_table_fdf *dst));
void	generate_cells_color(
	t_table_fdf *dst,
	e_5cell_channels channel,
	e_bool(*is_filtered_cell)(size_t row, size_t col, t_table_fdf *dst),
	int(*gen_color)(size_t row, size_t col, t_table_fdf *dst));
void	fill_cells_color(
	t_table_fdf *dst,
	unsigned char input_value,
	e_rgba rgb_type,
	e_bool(*is_filtered_cell)(size_t row, size_t col, t_table_fdf *dst));

// thue_morse.c
void	print_thue_morse(void);

#endif
