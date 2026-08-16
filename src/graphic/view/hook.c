#include "view.h"

// time : O(n)
// space: O(1)
void hook_pan(mlx_key_data_t keydata, void *param)
{
    t_view *view;

    view = (t_view *)param;
	if (view != NULL && view->mlx != NULL
		&& view->img != NULL
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(view->mlx);
		if (keydata.key == MLX_KEY_UP && view->img->instances[0].y > 0)
			view->img->instances[0].y -= 5;
		if (keydata.key == MLX_KEY_DOWN
			&& (int)view->img->instances[0].y < 810 - (int)view->img->height)
			view->img->instances[0].y += 5;
		if (keydata.key == MLX_KEY_LEFT && view->img->instances[0].x > 0)
			view->img->instances[0].x -= 5;
		if (keydata.key == MLX_KEY_RIGHT
			&& (int)view->img->instances[0].x < 1440 - (int)view->img->width)
			view->img->instances[0].x += 5;
	}
}
