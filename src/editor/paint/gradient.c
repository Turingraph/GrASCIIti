#include"paint.h"

// time : O(1)
// space: O(1)
unsigned char	get_rgba(e_rgba rgb_type, t_rgba *src)
{
	if (src == NULL)
		return (0);
	if (rgb_type == RED)
		return (src->r);
	if (rgb_type == GREEN)
		return (src->g);
	if (rgb_type == BLUE)
		return (src->b);
	if (rgb_type == ALPHA)
		return (src->a);
	return (0);
}

// time : O(1)
// space: O(1)
unsigned char	gradient_smooth(e_rgba rgb_type, t_gradient *gradient_input, int input_threshold)
{
	float	y;
	float	dx;
	float	dy;
	float	y1;
	float	y2;

	if (gradient_input->start_value == gradient_input->end_value)
		return (get_rgba(rgb_type, gradient_input->start_rgb));
	y1 = (float)(get_rgba(rgb_type, gradient_input->start_rgb));
	y2 = (float)(get_rgba(rgb_type, gradient_input->end_rgb));
	dx = float(gradient_input->end_value - gradient_input->start_value);
	dy = float(y2 - y1);
	y = (((float)(input_threshold - gradient_input->start_value)) / dx) * dy + y1;
	return ((unsigned char)f_interval(f_round(y), 0, 255));
}

// time : O(1)
// space: O(1)
int	get_gradient_input(t_table_fdf *src, e_7cell_channels mode, size_t row, size_t col)
{
	if (row > src->row || col > src->col)
		return (-2);
	if (mode == D7_RED && src->r != NULL && src->r[row] != NULL)
		return ((int)src->r[row][col]);
	if (mode == D7_GREEN && src->g != NULL && src->g[row] != NULL)
		return ((int)src->g[row][col]);
	if (mode == D7_BLUE && src->b != NULL && src->b[row] != NULL)
		return ((int)src->b[row][col]);
	if (mode == D7_ALPHA && src->a != NULL && src->a[row] != NULL)
		return ((int)src->a[row][col]);
	if (mode == D7_ROW)
		return ((int)row);
	if (mode == D7_COL)
		return ((int)col);
	if (mode == D7_HEIGHT && src->arr != NULL && src->arr[row] != NULL)
		return ((int)src->arr[row][col]);
	return (-1);
}

// time : O(1)
// space: O(1)
unsigned char	update_cell_color(unsigned char alpha, e_bool is_overwrite,
	unsigned char dst, unsigned char new_color)
{
	float	dc;

	if (is_overwrite == TRUE)
		return (new_color);
	dc = (float)dst - (float)new_color;
	if (dc < 0)
		dc *= -1;
	return ((unsigned char)f_interval(f_round((dc * alpha) / 255.0 + new_color), 0, 255));
}

// time : O(n)
// space: O(1)
void	color_cells_gradient(t_table_fdf *dst,
	t_gradient *gradient_input,
	e_bool is_overwrite,
	e_bool(*is_filtered_cell)(size_t row, size_t col, t_table_fdf *dst))
{
	size_t	i;
	size_t	j;
	int		threshold;

	i = 0;
	while (i < dst->row && is_rgbah_table_not_null(dst, 0) == TRUE)
	{
		j = 0;
		while (j < dst->col && is_rgbah_table_not_null(dst, i) == TRUE)
		{
			threshold = get_gradient_input(gradient_input->input_channel);
			if ((is_filtered_cell == NULL || is_filtered_cell(row, col, dst) == TRUE)
				&& gradient_input->start_value <= threshold && threshold <= gradient_input->end_value)
			{
				dst->r[i][j] = update_cell_color(dst->a[i][j], is_overwrite, dst->r[i][j],
					gradient_smooth(RED, gradient_input, threshold));
				dst->g[i][j] = update_cell_color(dst->a[i][j], is_overwrite, dst->g[i][j],
					gradient_smooth(GREEN, gradient_input, threshold));
				dst->b[i][j] = update_cell_color(dst->a[i][j], is_overwrite, dst->b[i][j],
					gradient_smooth(BLUE, gradient_input, threshold));
				if (is_overwrite == FALSE)
					dst->a[i][j] = gradient_smooth(ALPHA, gradient_input, threshold);
			}
			j += 1;
		}
		i += 1;
	}
}
