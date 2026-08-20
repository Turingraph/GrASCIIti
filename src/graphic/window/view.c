#include"window.h"

// 1920 * (3 / 4) = 1440
// 1080 * (3 / 4) = 810
// time : O(n)
// space: O(n)
int	view_rectangle(size_t resolution, t_ink32 ink, int32_t background)
{
	t_tile_format	tiles;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_2d_hook	hook;
	t_2d_camera	camera = {.offset = {.x = 0, .y = 0}, .zoom = 1.0};

	tiles = init_tile_format(1440, 810, (size_t)f_interval(resolution, 0, 10));
	mlx = mlx_init(1440, 810, "Subset at 4:42pm", true);
	img = handle_mlx_error(mlx, 1440, 810);
	if (img == NULL)
		return (-1);
	color_background_mlx(img, background);
	hook.img = img;
	hook.mlx = mlx;
	hook.camera = &camera;
	hook.background = background;
	hook.tiles = tiles;
	hook.ink = ink;
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
