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
void	view_master_piece(t_motif_arr *motif,
	t_ink32 drawing_style, t_background background)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_2d_hook		hook;
	t_2d_camera		camera;

	camera = init_2d_camera(1440, 810);
	mlx = mlx_init(1440, 810, "Subset at 4:42pm", true);
	img = handle_mlx_error(mlx, 1440, 810);
	hook.img = img;
	if (img == NULL || hook.img == NULL)
		return ;
	color_background_mlx(img, background.color);
	hook.mlx = mlx;
	hook.camera = &camera;
	hook.master_piece.still_life = NULL;
	hook.master_piece.motif = motif;
	hook.master_piece.tiles = init_tile_format(
		1440, 810, (size_t)f_interval(background.tiles_resolution, 0, 10));
	hook.master_piece.drawing_style = drawing_style;
	hook.master_piece.background = background;
	// draw_motif_mlx(&hook, true);
	if (-1 == mlx_image_to_window(mlx, img,
		(mlx->width - img->width) / 2,
		(mlx->height - img->height) / 2))
	{
		mlx_terminate(mlx);
		return  ;
	}
	// mlx_key_hook(mlx, &hook_pan_motif, &hook);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
}
