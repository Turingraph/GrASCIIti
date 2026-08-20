#include"window.h"
#include<time.h>

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition_unit(t_hook2d *arg, int ix, int iy)
{
	t_line	line;
	t_line	zoom_offset;

	if (is_2dhook_valid((const t_hook2d *)arg) == true && ix > -1 && iy > -1)
	{
		zoom_offset = pan_zoom_line(*(arg->camera), arg->tiles.offset,
			arg->img->width, arg->img->height);
		line.p1.x = ix * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.x;
		line.p1.y = iy * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.y;
		line.p2.x = (ix + 1) * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.x;
		line.p2.y = iy * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.y;
		draw_mlx_straight_line(arg->img, line,
			get_all_area(arg->img->height, arg->img->width).sub_area, arg->ink);
		line.p2.x = ix * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.x;
		line.p2.y = (iy + 1) * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.y;
		draw_mlx_straight_line(arg->img, line,
			get_all_area(arg->img->height, arg->img->width).sub_area, arg->ink);
		line.p1.x = (ix + 1) * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.x;
		line.p1.y = iy * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.y;
		line.p2.x = (ix + 1) * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.x;
		line.p2.y = (iy + 1) * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.y;
		draw_mlx_straight_line(arg->img, line,
			get_all_area(arg->img->height, arg->img->width).sub_area, arg->ink);
		line.p1.x = ix * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.x;
		line.p1.y = (iy + 1) * arg->tiles.tile_size * arg->camera->zoom + zoom_offset.p1.y;
		draw_mlx_straight_line(arg->img, line,
			get_all_area(arg->img->height, arg->img->width).sub_area, arg->ink);
	}
}

// time : O(n)
// space: O(1)
void	picture_at_an_exhibition(t_hook2d *arg)
{
	t_line	interier_tiles;
	int		iy;
	int		ix;

	if (is_2dhook_valid((const t_hook2d *)arg) == true)
	{
		interier_tiles.p1 = get_interier_tiles_p1(
			arg->tiles, *(arg->camera), arg->img->width, arg->img->height);
		interier_tiles.p2 = get_interier_tiles_p2(
			arg->tiles, *(arg->camera), arg->img->width, arg->img->height);
		write_line(arg->tiles.offset);
		write_line(interier_tiles);
		iy = interier_tiles.p1.y;
		while (iy < interier_tiles.p2.y)
		{
			ix = interier_tiles.p1.x;
			while (ix < interier_tiles.p2.x)
			{
				picture_at_an_exhibition_unit(arg, ix, iy);
				ix += 1;
			}
			iy += 1;
		}
	}
}

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
	if (keydata.key == MLX_KEY_1 && camera->zoom < 3.0)
		camera->zoom *= 1.01;
	if (keydata.key == MLX_KEY_2 && camera->zoom > 0.2)
		camera->zoom /= 1.01;
}

// time : O(n)
// space: O(1)
void hook_pan_and_zoom(mlx_key_data_t keydata, void *param)
{
    t_hook2d		*view;
	static clock_t	before = 0;
	clock_t			after;

    view = (t_hook2d *)param;
	if (is_2dhook_valid((const t_hook2d *)view) == true
		&& is_valid_key(keydata) == true)
	{
		after = clock();
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(view->mlx);
		if (before != 0 && after - before < 10000)
			return;
		before = after;
		picture_at_an_exhibition(view);
		update_camera(keydata, view->camera);
		picture_at_an_exhibition(view);
	}
}
