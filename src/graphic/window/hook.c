#include"window.h"

// time : O(1)
// space: O(1)
void	update_camera(mlx_key_data_t keydata, t_2d_camera *camera)
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
