#include"window.h"
#include<time.h>

// time : O(1)
// space: O(1)
void	update_camera_pan(mlx_key_data_t keydata, t_2d_camera *camera)
{
	if (camera == NULL || is_valid_key(keydata) == false)
		return ;
	if (keydata.key == MLX_KEY_UP)
		camera->offset.y -= 5;
	if (keydata.key == MLX_KEY_DOWN)
		camera->offset.y += 5;
	if (keydata.key == MLX_KEY_LEFT)
		camera->offset.x -= 5;
	if (keydata.key == MLX_KEY_RIGHT)
		camera->offset.x += 5;
	if (keydata.key == MLX_KEY_0)
	{
		camera->offset.x = 0;
		camera->offset.y = 0;
	}
}

// time : O(n)
// space: O(1)
void	hook_absolute_cinema_pan(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	if ((keydata.key != MLX_KEY_UP
			&& keydata.key != MLX_KEY_DOWN
			&& keydata.key != MLX_KEY_LEFT
			&& keydata.key != MLX_KEY_RIGHT
			&& keydata.key != MLX_KEY_0))
		return ;
	draw_fdf_mlx_y(hook, false);
	draw_fdf_mlx_x(hook, false);
	draw_motif_mlx(hook, true);
	update_camera_pan(keydata, hook->camera);
	draw_fdf_mlx_y(hook, true);
	draw_fdf_mlx_x(hook, true);
}

// time : O(n)
// space: O(1)
void	hook_absolute_cinema_rotate(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	char		axis;
	t_matrix	neo;

	axis = 4;
	if (keydata.key == MLX_KEY_1)
		axis = 0;
	if (keydata.key == MLX_KEY_2)
		axis = 1;
	if (keydata.key == MLX_KEY_3)
		axis = 2;
	if (axis < 4 && axis > -1)
	{
		neo = init_3d_rotate_matrix(3.141592653 / 12.0, axis);
		if (neo.arr == NULL)
			return ;
		draw_fdf_mlx_y(hook, false);
		draw_fdf_mlx_x(hook, false);
		draw_motif_mlx(hook, true);
		linear_map_3d_all(hook->master_piece.still_life, neo);
		draw_fdf_mlx_y(hook, true);
		draw_fdf_mlx_x(hook, true);
		free(neo.arr);
	}
}

// time : O(n)
// space: O(1)
void	hook_absolute_cinema(mlx_key_data_t keydata, void *param)
{
	t_2d_hook		*hook;
	static clock_t	before = 0;
	clock_t			after;

	hook = (t_2d_hook *)param;
	if (is_2dhook_valid((const t_2d_hook *)hook, E_STILL_LIFE) == true
		&& is_valid_key(keydata) == true)
	{
		after = clock();
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(hook->mlx);
		if (before != 0 && after - before < 1000)
			return ;
		before = after;
		hook_absolute_cinema_rotate(keydata, hook);
		hook_absolute_cinema_pan(keydata, hook);
	}
}

