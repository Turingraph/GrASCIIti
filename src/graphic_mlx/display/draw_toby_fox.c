#include "display_private.h"

// time : O(1)
// space: O(1)
static void	draw_toby_fox_fdf_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line		line;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, 0);
	line.p1 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0));
	line.p2 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 3),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 3));
	draw_rectangle_fdf(line, ink.color, *hook->camera, hook->img);
}

// time : O(n)
// space: O(1)
void	draw_toby_fox_fdf(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (1 < src.row && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			draw_toby_fox_fdf_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(1)
// space: O(1)
static void	draw_tuyoki_fdf_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line		line;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, 0);
	line.p1 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 1),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 1));
	line.p2 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 2),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 2));
	draw_rectangle_fdf(line, ink.color, *hook->camera, hook->img);
}

// time : O(n)
// space: O(1)
void	draw_tuyoki_fdf(t_2d_hook *hook, bool is_draw)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (1 < src.row && ixiy.x < (int)src.col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.row - 1)
		{
			draw_tuyoki_fdf_unit(hook, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}
