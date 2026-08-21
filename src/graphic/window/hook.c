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
void	picture_at_an_exhibition_horizontal(t_2d_hook *hook,
	t_line interier_tile, int32_t color)
{
	int		iy;
	t_line	line;
	t_line	all_area;
	t_ink32	ink;

	if (is_2dhook_valid(hook) == false)
		return ;
	ink.color = color;
	ink.thickness = 3;
	ink.type = E_LINE;
	all_area = get_all_area(
			hook->img->height,
			hook->img->width).sub_area;
	iy = interier_tile.p1.y;
	while (iy <= interier_tile.p2.y)
	{
		line.p1 = get_ith_tile_screen(hook->master_piece.tiles,
				*(hook->camera), interier_tile.p1.x, iy);
		line.p2 = get_ith_tile_screen(hook->master_piece.tiles,
				*(hook->camera), interier_tile.p2.x, iy);
		draw_mlx_straight_line(hook->img, line, all_area, ink);
		iy += 1;
	}
}

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition_vertical(t_2d_hook *hook,
	t_line interier_tile, int32_t color)
{
	int		ix;
	t_line	line;
	t_line	all_area;
	t_ink32	ink;

	if (is_2dhook_valid(hook) == false)
		return ;
	ink.color = color;
	ink.thickness = 3;
	ink.type = E_LINE;
	all_area = get_all_area(
			hook->img->height,
			hook->img->width).sub_area;
	ix = interier_tile.p1.x;
	while (ix <= interier_tile.p2.x)
	{
		line.p1 = get_ith_tile_screen(hook->master_piece.tiles,
				*(hook->camera), ix, interier_tile.p1.y);
		line.p2 = get_ith_tile_screen(hook->master_piece.tiles,
				*(hook->camera), ix, interier_tile.p2.y);
		draw_mlx_straight_line(hook->img, line, all_area, ink);
		ix += 1;
	}
}

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition(t_2d_hook *hook, bool is_draw)
{
	t_line		interier_tile;
	int32_t		ink;

	if (is_2dhook_valid(hook) == false)
		return ;
	interier_tile.p1 = get_first_interier_tile(hook->master_piece.tiles,
			*(hook->camera));
	interier_tile.p2 = get_last_interier_tile(hook->master_piece.tiles,
			*(hook->camera));
	if (interier_tile.p1.x < 0 || interier_tile.p1.y < 0
		|| interier_tile.p2.x < 0 || interier_tile.p2.y < 0)
		return ;
	ink = f_rgba_to_int32(155, 15, 100, 255);
	if (is_draw == false)
		ink = hook->master_piece.background;
	write_line(interier_tile);
	picture_at_an_exhibition_horizontal(hook, interier_tile, ink);
	picture_at_an_exhibition_vertical(hook, interier_tile, ink);
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
