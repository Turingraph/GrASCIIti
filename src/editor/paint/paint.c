#include"paint.h"

// time : O(n)
// space: O(1)
void	fill_cells_height(
	t_table_fdf *dst,
	int height,
	e_bool is_overwrite,
	e_bool(*is_filtered_cell)(size_t row, size_t col, t_table_fdf *dst))
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dst->row && dst->arr != NULL)
	{
		j = 0;
		while (j < dst->col && dst->arr[i] != NULL)
		{
			if ((is_filtered_cell == NULL || is_filtered_cell(i, j, dst) == TRUE)
				&& ((is_overwrite == FALSE && dst->arr[i][j] <= 0) || is_overwrite == TRUE))
				dst->arr[i][j] = height;
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	fill_cells_color(
	t_table_fdf *dst,
	unsigned char input_value,
	e_rgba rgb_type,
	e_bool(*is_filtered_cell)(size_t row, size_t col, t_table_fdf *dst))
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dst->row && choose_5cell_channel(dst, channel, 0) != NULL)
	{
		j = 0;
		while (j < dst->col && choose_5cell_channel(dst, channel, i) != NULL)
		{
			if (is_filtered_cell == NULL || is_filtered_cell(i, j, dst) == TRUE)
				choose_rgb_channel(dst, channel, i)[i][j] = input_value;
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	generate_cells_color(
	t_table_fdf *dst,
	e_5cell_channels channel,
	e_bool(*is_filtered_cell)(size_t row, size_t col, t_table_fdf *dst),
	int(*gen_color)(size_t row, size_t col, t_table_fdf *dst))
{
	size_t	i;
	size_t	j;
	int		height;

	i = 0;
	while (i < dst->row && dst->arr != NULL)
	{
		j = 0;
		while (j < dst->col && dst->arr[i] != NULL)
		{
			if (is_filtered_cell == NULL || is_filtered_cell(i, j, dst) == TRUE)
			{
				height = gen_color(i, j, dst);
				if (channel == D5_HEIGHT)
					dst->arr[i][j] = height;
				if (channel == D5_RED)
					dst->r[i][j] = (unsigned char)(height % 256);
				if (channel == D5_GREEN)
					dst->g[i][j] = (unsigned char)(height % 256);
				if (channel == D5_BLUE)
					dst->b[i][j] = (unsigned char)(height % 256);
				if (channel == D5_ALPHA)
					dst->a[i][j] = (unsigned char)(height % 256);
			}
			j += 1;
		}
		i += 1;
	}
}
