#include "display_private.h"

// time : O(1)
// space: O(1)
static void	proj_picassoy_fdf_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy, size_t thickness)
{
	t_line		line;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, thickness);
	line = init_proj_line_y(*hook->camera, hook->master_piece.fdf,
		ixiy, hook->master_piece.projection);
	draw_line_fdf(line, ink, *(hook->camera), hook->img);
}

// time : O(1)
// space: O(1)
static void	proj_picassox_fdf_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy, size_t thickness)
{
	t_line		line;
	t_ink32		ink;

	ink = get_hook_ink32(hook, is_draw, ixiy, thickness);
	line = init_proj_line_x(*hook->camera, hook->master_piece.fdf,
		ixiy, hook->master_piece.projection);
	draw_line_fdf(line, ink, *(hook->camera), hook->img);
}

// time : O(n)
// space: O(1)
static void	proj_picassox_fdf(t_2d_hook *hook, bool is_draw, size_t thickness)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (0 < src.src->row && ixiy.x < (int)src.src->col - 1)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.src->row)
		{
			proj_picassox_fdf_unit(hook, is_draw, ixiy, thickness);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
static void	proj_picassoy_fdf(t_2d_hook *hook, bool is_draw, size_t thickness)
{
	t_2d_int	ixiy;
	t_fdf		src;

	src = *hook->master_piece.fdf;
	ixiy.x = 0;
	while (1 < src.src->row && ixiy.x < (int)src.src->col)
	{
		ixiy.y = 0;
		while (ixiy.y < (int)src.src->row - 1)
		{
			proj_picassoy_fdf_unit(hook, is_draw, ixiy, thickness);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	proj_picasso_fdf(t_2d_hook *hook, bool is_draw, size_t thickness)
{
	proj_picassox_fdf(hook, is_draw, thickness);
	proj_picassoy_fdf(hook, is_draw, thickness);
}
