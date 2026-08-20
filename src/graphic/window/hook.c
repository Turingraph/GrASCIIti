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
	if (keydata.key == MLX_KEY_1 && camera->zoom * 1.01 < 3.0)
		camera->zoom *= 1.01;
	if (keydata.key == MLX_KEY_2 && camera->zoom / 1.01 > 0.2)
		camera->zoom /= 1.01;
}

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition_horizontal(t_2d_hook *hook,
	t_line interier_tile)
{
	int		iy;
	t_line	line;
	t_line	all_area;

	if (is_2dhook_valid(hook) == false)
		return ;
	all_area = get_all_area(
		hook->img->height,
		hook->img->width
	).sub_area;
	iy = interier_tile.p1.y;
	while (iy <= interier_tile.p2.y)
	{
		line.p1 = get_ith_tile_screen(hook->tiles,
			*(hook->camera), interier_tile.p1.x, iy);
		line.p2 = get_ith_tile_screen(hook->tiles,
			*(hook->camera), interier_tile.p2.x, iy);
		draw_mlx_straight_line(hook->img, line, all_area, hook->ink);
		iy += 1;
	}
}

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition_vertical(t_2d_hook *hook,
	t_line interier_tile)
{
	int		ix;
	t_line	line;
	t_line	all_area;

	if (is_2dhook_valid(hook) == false)
		return ;
	all_area = get_all_area(
		hook->img->height,
		hook->img->width
	).sub_area;
	ix = interier_tile.p1.x;
	while (ix <= interier_tile.p2.x)
	{
		line.p1 = get_ith_tile_screen(hook->tiles,
			*(hook->camera), ix, interier_tile.p1.y);
		line.p2 = get_ith_tile_screen(hook->tiles,
			*(hook->camera), ix, interier_tile.p2.y);
		draw_mlx_straight_line(hook->img, line, all_area, hook->ink);
		ix += 1;
	}
}

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition(t_2d_hook *hook, bool is_draw)
{
	t_line	interier_tile;
	int32_t	ink;

	if (is_2dhook_valid(hook) == false)
		return ;
	interier_tile.p1 = get_first_interier_tile(hook->tiles, *(hook->camera),
		hook->img->width, hook->img->height);
	interier_tile.p2 = get_last_interier_tile(hook->tiles, *(hook->camera),
		hook->img->width, hook->img->height);
	if (interier_tile.p1.x < 0 || interier_tile.p1.y < 0
		|| interier_tile.p2.x < 0 || interier_tile.p2.y < 0)
		return ;
	ink = hook->ink.color;
	if (is_draw == false)
		hook->ink.color = hook->background;
	picture_at_an_exhibition_horizontal(hook, interier_tile);
	picture_at_an_exhibition_vertical(hook, interier_tile);
	hook->ink.color = ink;
}

// time : O(n)
// space: O(1)
void hook_pan_and_zoom(mlx_key_data_t keydata, void *param)
{
    t_2d_hook		*hook;
	static clock_t	before = 0;
	clock_t			after;

    hook = (t_2d_hook *)param;
	if (is_2dhook_valid((const t_2d_hook *)hook) == true
		&& is_valid_key(keydata) == true)
	{
		after = clock();
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(hook->mlx);
		if (before != 0 && after - before < 1000)
			return;
		before = after;
		picture_at_an_exhibition(hook, false);
		update_camera(keydata, hook->camera);
		picture_at_an_exhibition(hook, true);
	}
}
