#include"fdf_private.h"

// time : O(1)
// space: O(1)
bool	is_2dhook_valid(const t_2d_hook *src)
{
	if (src == NULL
		|| src->camera == NULL
		|| src->img == NULL
		|| src->mlx == NULL
		|| is_fdf_valid(src->master_piece.calligraphy) == false)
		return (false);
	return (true);
}

// time : O(1)
// space: O(1)
bool	is_valid_key(mlx_key_data_t keydata)
{
	if ((keydata.action == MLX_PRESS
		|| keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_ESCAPE
		|| keydata.key == MLX_KEY_UP
		|| keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT
		|| keydata.key == MLX_KEY_RIGHT
		|| keydata.key == MLX_KEY_1
		|| keydata.key == MLX_KEY_2
		|| keydata.key == MLX_KEY_3
		|| keydata.key == MLX_KEY_9
		|| keydata.key == MLX_KEY_0
		|| keydata.key == MLX_KEY_Q))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_valid_pan_key(mlx_key_data_t keydata)
{
	if ((keydata.action == MLX_PRESS
		|| keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_UP
		|| keydata.key == MLX_KEY_DOWN
		|| keydata.key == MLX_KEY_LEFT
		|| keydata.key == MLX_KEY_RIGHT))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_valid_rotate_key(mlx_key_data_t keydata)
{
	if ((keydata.action == MLX_PRESS
		|| keydata.action == MLX_REPEAT)
		&& (keydata.key == MLX_KEY_1
		|| keydata.key == MLX_KEY_2
		|| keydata.key == MLX_KEY_3))
		return (true);
	return (false);
}

// time : O(1)
// space: O(1)
bool	is_valid_zoom_key(mlx_key_data_t keydata, float zoom)
{
	if ((keydata.action == MLX_PRESS
		|| keydata.action == MLX_REPEAT)
		&& ((keydata.key == MLX_KEY_9 && zoom * 1.01 < 2.0)
		|| (keydata.key == MLX_KEY_0 && zoom / 1.01 > 0.2)))
		return (true);
	return (false);
}

