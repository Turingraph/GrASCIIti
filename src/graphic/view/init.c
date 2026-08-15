#include"view.h"

// // time : O(1)
// // space: O(1)
size_t	get_window_dimension_fdf(size_t row, size_t col, char axis)
{
	size_t	window_size;

	window_size = 1080;
	if (row > window_size || col > window_size || row * col == 0)
		return (0);
	if (row == col || (row < col && axis == 0) || (row > col && axis == 1))
		return (window_size);
	if (row > col && axis == 0)
		return (col * (size_t)f_floor((float)window_size / (float)row));
	if (row < col && axis == 1)
		return (row * (size_t)f_floor((float)window_size / (float)col));
	return (0);
}

// time : O(n)
// space: O(1)
mlx_image_t	*solve_1st_mlx_error(mlx_t *mlx, t_table_fdf *table)
{
	mlx_image_t	*dst;

	if (mlx == NULL || table == NULL)
	{
		free_table_fdf(table);
		if (mlx != NULL)
			mlx_terminate(mlx);
		return (NULL);
	}
	dst = mlx_new_image(mlx, table->col, table->row);
	if (dst == NULL)
	{
		free_table_fdf(table);
		mlx_terminate(mlx);
		return(NULL);
	}
	return (dst);
}

// time : O(?)
// space: O(?)
int	maintain_view_table_fdf(t_table_fdf *window_table, size_t table_row, size_t table_col)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(1920, 1080, "Subset at 4:42pm", true);
	img = solve_1st_mlx_error(mlx, window_table);
	if (img == NULL)
		return (-1);
	paint_table_on_image(window_table, img);
	if (-1 == mlx_image_to_window(mlx, img,
		1920 / 2 - get_window_dimension_fdf(table_row, table_col, 0) / 2,
		1080 / 2 - get_window_dimension_fdf(table_row, table_col, 1) / 2))
	{
		mlx_terminate(mlx);
		return(-1);
	}
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	free_table_fdf(window_table);
	return (1);
}

// time : O(n)
// space: O(n)
void	view_table_fdf(const t_table_fdf *src)
{
	t_table_fdf	scale_src;

	if (src != NULL && src->row * src->col > 0)
	{
		scale_src = scale_window_dimension_fdf(src);
		maintain_view_table_fdf(&scale_src, src->row, src->col);
	}
}

// time : O(n)
// space: O(n)
int	view_convolve_table_fdf(const t_table_fdf *src,
	t_rgba target_channels, t_matrix kernel)
{
	t_table_fdf	scale_src;
	t_table_fdf	convolve_src;

	if (src != NULL && src->row * src->col > 0)
	{
		scale_src = scale_window_dimension_fdf(src);
		convolve_src = convolve_rgba(&scale_src, kernel, target_channels);
		free_table_fdf(&scale_src);
		maintain_view_table_fdf(&convolve_src, src->row, src->col);
	}
	return (1);
}
