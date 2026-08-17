#ifndef PAINT2_H
# define PAINT2_H

# include "../../input/table/table.h"
# include <fcntl.h>

typedef enum e_7cell_channels e_7cell_channels;

enum e_7cell_channels
{
	D7_RED,
	D7_GREEN,
	D7_BLUE,
	D7_ALPHA,
	D7_ROW,
	D7_COL,
	D7_HEIGHT
};

typedef struct t_gradient t_gradient;

struct t_gradient
{
	t_rgba				rgba_start;
	t_rgba				rgba_end;
	e_7cell_channels	cell_channel;
	int					input_start;
	int					input_end;
};

// gradient.c
void	color_cells_gradient(t_table_fdf *dst,
	t_gradient gradient_input,
	bool is_overwrite,
	bool (*is_filtered_cell)(const t_table_fdf *dst, size_t index));

// outlier.c
void	print_outlier(void);

// paint.c
void	fill_cells_height(
	t_table_fdf *dst,
	int height,
	bool is_overwrite,
	bool (*is_filtered_cell)(const t_table_fdf *dst, size_t index));
void	fill_cells_color(
	t_table_fdf *dst,
	unsigned char input_value,
	e_rgba rgba_type,
	bool (*is_filtered_cell)(const t_table_fdf *dst, size_t index));
void	generate_cells_color(
	t_table_fdf *dst,
	e_rgba channel,
	bool (*is_filtered_cell)(const t_table_fdf *dst, size_t index),
	int(*gen_color)(const t_table_fdf *dst, size_t index));
bool	is_empty_space(const t_table_fdf *src, size_t index);
void	paint_table_background(t_table_fdf *dst, t_rgba color);

#endif
