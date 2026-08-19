#include"window.h"

// time : O(n)
// space: O(n)
int	view_rectangle(t_line rectangle,
	int32_t rectangle_color, int32_t background_color)
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_hook2d	var;
	t_line		boundary = {.p1 = {.x = 0, .y = 0}, .p2 = {.x = 1920, .y = 1080}};
	t_2d_camera	camera = {.offset = {.x = 0, .y = 0}, .zoom = 1.0};

	mlx = mlx_init(1920, 1080, "Subset at 4:42pm", true);
	img = handle_mlx_error(mlx);
	if (img == NULL)
		return (-1);
	color_background_mlx(img, background_color);
	draw_rectangle_mlx(img, rectangle, boundary, rectangle_color);
	if (-1 == mlx_image_to_window(mlx, img,
		(1920 - img->width) / 2,
		(1080 - img->height) / 2))
	{
		mlx_terminate(mlx);
		return(-1);
	}
	var.img = img;
	var.mlx = mlx;
	var.camera = &camera;
	var.rectangle = &rectangle;
	var.color = rectangle_color;
	var.background_color = background_color;
	mlx_key_hook(mlx, &hook_pan_and_zoom, &var);
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (1);
}
