#include"window.h"
#include<time.h>

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

// time : O(n)
// space: O(1)
void	hook_pan_motif(mlx_key_data_t keydata, void *param)
{
	t_2d_hook		*hook;
	static clock_t	before = 0;
	clock_t			after;

	hook = (t_2d_hook *)param;
	if ((is_2dhook_valid((const t_2d_hook *)hook, E_STILL_LIFE) == true
			|| is_2dhook_valid((const t_2d_hook *)hook, E_MOTIF) == true)
		&& is_valid_key(keydata) == true)
	{
		after = clock();
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(hook->mlx);
		if (before != 0 && after - before < 1000)
			return ;
		before = after;
		draw_motif_mlx(hook, false);
		update_camera(keydata, hook->camera);
		draw_motif_mlx(hook, true);
	}
}
