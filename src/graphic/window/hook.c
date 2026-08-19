#include"window.h"
#include<time.h>

// time : O(1)
// space: O(1)
bool	is_valid_key(mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_ESCAPE
		|| keydata.key == MLX_KEY_1
		|| keydata.key == MLX_KEY_2
		|| keydata.key == MLX_KEY_UP
		|| keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT
		|| keydata.key == MLX_KEY_RIGHT)
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
void	update_camera(mlx_key_data_t keydata, t_2d_camera *camera)
{
	if (keydata.key == MLX_KEY_UP)
		camera->offset.y -= 5;
	if (keydata.key == MLX_KEY_DOWN)
		camera->offset.y += 5;
	if (keydata.key == MLX_KEY_LEFT)
		camera->offset.x -= 5;
	if (keydata.key == MLX_KEY_RIGHT)
		camera->offset.x += 5;
	if (keydata.key == MLX_KEY_1 && camera->zoom < 3.0)
		camera->zoom *= 1.01;
	if (keydata.key == MLX_KEY_2 && camera->zoom > 0.2)
		camera->zoom /= 1.01;
}

// time : O(n)
// space: O(1)
void	redraw_img(mlx_key_data_t keydata, t_hook2d *view)
{
	t_line	rectangle;

	if (view != NULL && view->mlx != NULL
		&& view->img != NULL && view->rectangle != NULL)
	{
		rectangle = pan_zoom_line(*(view->camera), *(view->rectangle),
			view->img->width, view->img->height);
		draw_rectangle_mlx(view->img, rectangle,
			get_all_area(view->img->height, view->img->width).sub_area, view->background_color);
		update_camera(keydata, view->camera);
		rectangle = pan_zoom_line(*(view->camera), *(view->rectangle),
			view->img->width, view->img->height);
		draw_rectangle_mlx(view->img, rectangle,
			get_all_area(view->img->height, view->img->width).sub_area, view->color);
	}
}

// time : O(n)
// space: O(1)
void hook_pan_and_zoom(mlx_key_data_t keydata, void *param)
{
    t_hook2d		*view;
	static clock_t	before = 0;
	clock_t			after;

    view = (t_hook2d *)param;
	if (view != NULL && view->mlx != NULL
		&& view->img != NULL && view->rectangle != NULL
		&& is_valid_key(keydata) == true)
	{
		after = clock();
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(view->mlx);
		if (before != 0 && after - before < 10000)
			return;
		before = after;
		redraw_img(keydata, view);
	}
}
