#include"view_line.h"

// time : O(1)
// space: O(1)
int32_t	f_rgba_to_int32(unsigned char r,
	unsigned char g, unsigned char b, unsigned char a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

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
// space: O(1)
void	color_background_mlx(mlx_image_t *dst, int32_t color)
{
	int32_t	i;

	i = 0;
	while (dst != NULL && i < (int32_t)(dst->width * dst->height))
	{
		mlx_put_pixel(dst, i % (int32_t)dst->width, i / (int32_t)dst->width, color);
		i += 1;
	}
}

// time : O(?)
// space: O(?)
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
