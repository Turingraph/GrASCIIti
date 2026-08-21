#include"window.h"

// time : O(n)
// space: O(1)
mlx_image_t	*handle_mlx_error(mlx_t *mlx, size_t width, size_t height)
{
	mlx_image_t	*dst;

	if (mlx == NULL || width * height == 0)
		return (NULL);
	dst = mlx_new_image(mlx, width, height);
	if (dst == NULL)
	{
		mlx_terminate(mlx);
		return (NULL);
	}
	return (dst);
}

// 1920 * (3 / 4) = 1440
// 1080 * (3 / 4) = 810
// time : O(n)
// space: O(n)
int	view_master_piece(t_motif_arr *src, size_t resolution, int32_t background)
{
	t_tile_format	tiles;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_2d_hook	hook;
	t_2d_camera	camera;

	camera = init_2d_camera(1440, 810);
	tiles = init_tile_format(1440, 810, (size_t)f_interval(resolution, 0, 10));
	mlx = mlx_init(1440, 810, "Subset at 4:42pm", true);
	img = handle_mlx_error(mlx, 1440, 810);
	if (img == NULL)
		return (-1);
	color_background_mlx(img, background);
	hook.img = img;
	hook.mlx = mlx;
	hook.camera = &camera;
	hook.master_piece.motif = NULL;
	hook.master_piece.still_life = NULL;
	if (src != NULL)
		hook.master_piece.motif = src;
	hook.master_piece.background = background;
	hook.master_piece.tiles = tiles;
	picture_at_an_exhibition(&hook, true);
	if (-1 == mlx_image_to_window(mlx, img,
		(1440 - img->width) / 2,
		(810 - img->height) / 2))
	{
		mlx_terminate(mlx);
		return (-1);
	}
	mlx_key_hook(mlx, &hook_pan_and_zoom, &hook);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (1);
}
