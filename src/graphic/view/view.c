#include"view.h"

// time : O(n)
// space: O(1)
mlx_image_t	*handle_mlx_error(mlx_t *mlx)
{
	mlx_image_t	*dst;

	if (mlx == NULL)
		return (NULL);
	dst = mlx_new_image(mlx, 1440, 810);
	if (dst == NULL)
	{
		mlx_terminate(mlx);
		return(NULL);
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	view_islamic_tiling_loop(mlx_image_t *dst,
	const t_islamic_arr *src)
{
	size_t	i;

	i = 0;
	while (dst != NULL && src != NULL
		&& src->arr != NULL && i < src->length)
	{
		if (src->arr[i].ink.type == E_LINE)
			draw_square_tiling_mlx(dst,
				(const t_2d_polygon *)&(src->arr[i].polygon),
				src->arr[i].ink, src->arr[i].tiling);
		if (src->arr[i].ink.type == E_RECTANGLE)
			draw_mondrian_tiling_fmlx(dst,
				(const t_2d_polygon *)&(src->arr[i].polygon),
				src->arr[i].ink.color, src->arr[i].tiling);
		if (src->arr[i].ink.type == E_CIRCLE)
			draw_kusama_tiling_fmlx(dst,
				(const t_2d_polygon *)&(src->arr[i].polygon),
				src->arr[i].ink, src->arr[i].tiling);
		i += 1;
	}
}

// time : O(n)
// space: O(n)
int	view_islamic_tiling(const t_islamic_arr *src, int32_t background_color)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (src != NULL && src->arr != NULL && src->length > 0)
	{
		mlx = mlx_init(1440, 810, "Subset at 4:42pm", true);
		img = handle_mlx_error(mlx);
		if (img == NULL)
			return (-1);
		color_background_mlx(img, background_color);
		view_islamic_tiling_loop(img, src);
		if (-1 == mlx_image_to_window(mlx, img,
			(1440 - img->width) / 2,
			(810 - img->height) / 2))
		{
			mlx_terminate(mlx);
			return(-1);
		}
		mlx_loop(mlx);
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
	}
	return (1);
}

// time : O(n)
// space: O(n)
int	view_pixel_art(const t_table_fdf *src, int32_t background_color)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (src != NULL && src->row * src->col > 0)
	{
		mlx = mlx_init(1440, 810, "Subset at 4:42pm", true);
		img = handle_mlx_error(mlx);
		if (img == NULL)
			return (-1);
		color_background_mlx(img, background_color);
		draw_pixel_art(img, src);
		if (-1 == mlx_image_to_window(mlx, img,
			(1440 - img->width) / 2,
			(810 - img->height) / 2))
		{
			mlx_terminate(mlx);
			return(-1);
		}
		mlx_loop(mlx);
		mlx_delete_image(mlx, img);
		mlx_terminate(mlx);
	}
	return (1);
}
