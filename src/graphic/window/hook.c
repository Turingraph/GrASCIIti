#include<time.h>
#include"window.h"

// time : O(1)
// space: O(1)
void	hook_pan(mlx_key_data_t keydata, t_2d_camera *camera)
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
}

// time : O(n)
// space: O(1)
void	hook_rotate(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	t_matrix	transform;
	char		axis;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| (keydata.key != MLX_KEY_1
			&& keydata.key == MLX_KEY_2
			&& keydata.key == MLX_KEY_3))
		return ;
	axis = 0;
	if (keydata.key == MLX_KEY_2)
		axis = 1;
	if (keydata.key == MLX_KEY_3)
		axis = 2;
	transform = init_3d_rotate_matrix(3.141592653 / 12.0, axis);
	if (transform.arr == NULL)
		return ;
	linear_map_3d_all(hook->master_piece.still_life, transform);
	matrix_3d_product(transform, &(hook->master_piece.still_life->matrix));
	free(transform.arr);
}

// time : O(n)
// space: O(1)
void	hook_zoom(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	float		scale;
	t_matrix	transform;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| (keydata.key != MLX_KEY_0 && keydata.key != MLX_KEY_9)
		|| (keydata.key == MLX_KEY_0 && hook->camera->zoom / 1.01 < 0.2)
		|| (keydata.key == MLX_KEY_9 && hook->camera->zoom * 1.01 > 0.2))
		return ;
	scale = 1.01;
	if (keydata.key == MLX_KEY_0)
		scale = 1.0 / 1.01;
	transform = init_3d_zoom_matrix(scale);
	if (transform.arr == NULL)
		return ;
	hook->camera->zoom *= scale;
	linear_map_3d_all(hook->master_piece.still_life, transform);
	matrix_3d_product(transform, &(hook->master_piece.still_life->matrix));
	free(transform.arr);
}

// time : O(n)
// space: O(1)
void	hook_home(mlx_key_data_t keydata,
	t_2d_hook *hook)
{
	t_matrix	undo;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| keydata.key != MLX_KEY_Q)
		return ;
	undo = init_inverse_3d_matrix(hook->master_piece.still_life->matrix);
	if (undo.arr == NULL)
		return ;
	hook->camera->offset.x = 0.0;
	hook->camera->offset.y = 0.0;
	hook->camera->zoom = 1.0;
	matrix_3d_product(undo, &(hook->master_piece.still_life->matrix));
	linear_map_3d_all(hook->master_piece.still_life, undo);
	free(undo.arr);
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
		draw_fdf_mlx_y(hook, false);
		draw_fdf_mlx_x(hook, false);
		draw_motif_mlx(hook, true);
		hook_rotate(keydata, hook);
		hook_zoom(keydata, hook);
		hook_pan(keydata, hook->camera);
		hook_home(keydata, hook);
		draw_fdf_mlx_y(hook, true);
		draw_fdf_mlx_x(hook, true);
	}
}
