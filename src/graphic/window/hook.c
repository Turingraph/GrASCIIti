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
void	picture_at_an_exhibition_unit(t_2d_hook *hook,
	bool is_draw, t_line tile)
{
	size_t	i;
	t_motif	*arr;
	t_ink32	ink;

	if (is_2dhook_valid(hook) == false
		|| hook->master_piece.motif == NULL
		|| hook->master_piece.motif->arr == NULL)
		return ;
	arr = hook->master_piece.motif->arr;
	i = 0;
	while (i < hook->master_piece.motif->length)
	{
		ink = arr[i].ink;
		if (is_draw == false)
			ink.color = hook->master_piece.background;
		if (ink.type == E_LINE)
			draw_polygon_mlx(hook->img, &(arr[i].polygon),
				ink, tile);
		else if (ink.type == E_CIRCLE)
			draw_kusama_mlx(hook->img, &(arr[i].polygon),
				ink, tile);
		else if (ink.type == E_RECTANGLE)
			draw_mondrian_mlx(hook->img, &(arr[i].polygon),
				ink.color, tile);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition_loop(t_2d_hook *hook,
	bool is_draw, t_line interier_tile)
{
	t_line	tile;
	int		ix;
	int		iy;

	if (is_2dhook_valid(hook) == false
		|| hook->master_piece.motif == NULL
		|| hook->master_piece.motif->arr == NULL)
		return ;
	iy = interier_tile.p1.y;
	while (iy < interier_tile.p2.y)
	{
		ix = interier_tile.p1.x;
		while (ix < interier_tile.p2.x)
		{
			tile.p1 = get_ith_tile_screen(hook->master_piece.tiles,
					*(hook->camera), ix, iy);
			tile.p2 = get_ith_tile_screen(hook->master_piece.tiles,
					*(hook->camera), ix + 1, iy + 1);
			picture_at_an_exhibition_unit(hook, is_draw, tile);
			ix += 1;
		}
		iy += 1;
	}
}

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition(t_2d_hook *hook, bool is_draw)
{
	t_line	interier_tile;

	if (is_2dhook_valid(hook) == false
		|| hook->master_piece.motif == NULL
		|| hook->master_piece.motif->arr == NULL)
		return ;
	interier_tile.p1 = get_first_interier_tile(hook->master_piece.tiles,
			*(hook->camera));
	interier_tile.p2 = get_last_interier_tile(hook->master_piece.tiles,
			*(hook->camera));
	if (interier_tile.p1.x < 0 || interier_tile.p1.y < 0
		|| interier_tile.p2.x < 0 || interier_tile.p2.y < 0)
		return ;
	picture_at_an_exhibition_loop(hook, is_draw, interier_tile);
}

// time : O(n)
// space: O(1)
void	hook_pan_and_zoom(mlx_key_data_t keydata, void *param)
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
			return ;
		before = after;
		picture_at_an_exhibition(hook, false);
		update_camera(keydata, hook->camera);
		picture_at_an_exhibition(hook, true);
	}
}
