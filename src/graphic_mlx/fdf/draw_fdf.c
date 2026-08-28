#include"fdf_private.h"

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_x(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| hook->master_piece.drawing_style.type == E_PIXEL_ART)
		return ;
	src = *hook->master_piece.still_life;
	ixiy.x = 0;
	while (0 < src.src->col && ixiy.x < (int)src.src->col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.src->row)
		{
			draw_fdf_mlx_x_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		// write(1, "\n", 1);
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_y(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| hook->master_piece.drawing_style.type == E_PIXEL_ART)
		return ;
	src = *hook->master_piece.still_life;
	ixiy.x = 0;
	while (ixiy.x < (int)src.src->col)
	{
		ixiy.y = 0;
		while (0 < src.src->row && ixiy.y < (int)src.src->row - 1)
		{
			draw_fdf_mlx_y_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_pixel_art_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line	line;
	t_ink32	ink;

	ink = get_hook_ink(hook, is_draw, ixiy);
	ink.type = E_RECTANGLE;
	line.p1 = world_3d_to_screen_2d(*hook->camera,
		hook->master_piece.still_life->pos_x[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x],
		hook->master_piece.still_life->pos_y[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x]);
	line.p2 = world_3d_to_screen_2d(*hook->camera,
		hook->master_piece.still_life->pos_x[(ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x + 1],
		hook->master_piece.still_life->pos_y[(ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x + 1]);
	draw_fdf_mlx_unit(line, ink, *(hook->camera), hook->img);
}

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_pixel_art(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false
		|| hook->master_piece.drawing_style.type != E_PIXEL_ART)
		return ;
	src = *hook->master_piece.still_life;
	ixiy.x = 0;
	while (0 < src.src->col && ixiy.x < (int)src.src->col - 1)
	{
		ixiy.y = 0;
		while (0 < src.src->row && ixiy.y < (int)src.src->row - 1)
		{
			draw_fdf_mlx_pixel_art_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

/**
 * Draw or erase an FDF object on an MLX image.
 *
 * The FDF is rendered using the current 2D camera and drawing style stored
 * in the supplied hook. Normal FDF rendering draws horizontal and vertical
 * edges between adjacent points. When the drawing style is E_PIXEL_ART,
 * each FDF cell is rendered as a filled rectangle instead.
 *
 * When is_draw is true, the color stored in each FDF cell is used when
 * available. When is_draw is false, the FDF is drawn using the background
 * color, allowing the previous rendering to be erased before updating
 * the object.
 *
 * The hook must contain a valid MLX image, camera, and FDF object.
 *
 * time/space: O(n) / O(1)
 *
 * status: internal helper
 *
 * @param hook FDF view context containing the image, camera, and FDF object
 * @param is_draw true to draw the FDF, false to erase it
 */
void	draw_fdf_mlx(t_2d_hook *hook, bool is_draw)
{
	draw_fdf_mlx_y(hook, is_draw);
	draw_fdf_mlx_x(hook, is_draw);
	draw_fdf_mlx_pixel_art(hook, is_draw);
}
