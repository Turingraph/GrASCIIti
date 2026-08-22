#include"window.h"

/*
I remove check-up to speed the program, even if it risk miss used.
*/

// time : O(1)
// space: O(1)
t_ink32	get_hook_ink(t_2d_hook *hook, bool is_draw, t_2d_int ixiy)
{
	t_ink32		ink;
	t_table_fdf	*table;

	table = hook->master_piece.still_life->src;
	ink = hook->master_piece.drawing_style;
	ink.color = get_table_rgba_int32(
		(const t_table_fdf *)table, ixiy.y * table->col + ixiy.x);
	if (is_draw == false && ink.color == 0)
		ink.color = hook->master_piece.drawing_style.color;
	else if (is_draw == true)
		ink.color = hook->master_piece.background.color;
	return (ink);
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_x_unit(t_2d_hook *hook, t_line boundary,
	bool is_draw, t_2d_int ixiy)
{
	t_2d_polygon	dst;
	t_ink32			ink;
	t_complex		arr[2];

	ink = get_hook_ink(hook, is_draw, ixiy);
	dst.length = 2;
	dst.is_loop = false;
	arr[0].re = hook->master_piece.still_life->pos_x[
			ixiy.y * hook->master_piece.still_life->src->col + ixiy.x];
	arr[0].im = hook->master_piece.still_life->pos_y[
			ixiy.y * hook->master_piece.still_life->src->col + ixiy.x];
	arr[1].re = hook->master_piece.still_life->pos_x[
			(ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x];
	arr[1].im = hook->master_piece.still_life->pos_y[
			(ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x];
	arr[0].re /= hook->master_piece.still_life->width;
	arr[0].im /= hook->master_piece.still_life->width;
	arr[1].re /= hook->master_piece.still_life->width;
	arr[1].im /= hook->master_piece.still_life->width;
	dst.arr = arr;
	if (ink.type == E_LINE)
		draw_polygon_mlx(hook->img, &dst, ink, boundary);
	else if (ink.type == E_CIRCLE)
		draw_kusama_mlx(hook->img, &dst, ink, boundary);
	else if (ink.type == E_RECTANGLE)
		draw_mondrian_mlx(hook->img, &dst, ink.color, boundary);
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_y_unit(t_2d_hook *hook, t_line boundary,
	bool is_draw, t_2d_int ixiy)
{
	t_2d_polygon	dst;
	t_ink32			ink;
	t_complex		arr[2];

	ink = get_hook_ink(hook, is_draw, ixiy);
	dst.length = 2;
	dst.is_loop = false;
	arr[0].re = hook->master_piece.still_life->pos_x[
			ixiy.y * hook->master_piece.still_life->src->col + ixiy.x];
	arr[0].im = hook->master_piece.still_life->pos_y[
			ixiy.y * hook->master_piece.still_life->src->col + ixiy.x];
	arr[1].re = hook->master_piece.still_life->pos_x[
			ixiy.y * hook->master_piece.still_life->src->col + ixiy.x + 1];
	arr[1].im = hook->master_piece.still_life->pos_y[
			ixiy.y * hook->master_piece.still_life->src->col + ixiy.x + 1];
	arr[0].re /= hook->master_piece.still_life->width;
	arr[0].im /= hook->master_piece.still_life->width;
	arr[1].re /= hook->master_piece.still_life->width;
	arr[1].im /= hook->master_piece.still_life->width;
	dst.arr = arr;
	if (ink.type == E_LINE)
		draw_polygon_mlx(hook->img, &dst, ink, boundary);
	else if (ink.type == E_CIRCLE)
		draw_kusama_mlx(hook->img, &dst, ink, boundary);
	else if (ink.type == E_RECTANGLE)
		draw_mondrian_mlx(hook->img, &dst, ink.color, boundary);
}

/*
graphic/window/fdf.c: In function ‘draw_fdf_mlx_y_unit’:
graphic/window/fdf.c:63:19: error: ‘arr’ is used uninitialized [-Werror=uninitialized]
   63 |         arr[0].re = hook->master_piece.still_life->pos_x[
      |         ~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   64 |                         ixiy.y * hook->master_piece.still_life->src->col + ixiy.x];
      |                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
graphic/window/fdf.c:58:34: note: ‘arr’ was declared here
   58 |         t_complex               *arr;
*/

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_x(t_2d_hook *hook, bool is_draw)
{
	t_line		boundary;
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false)
		return ;
	boundary.p1 = world_to_screen_2d(*(hook->camera),
		hook->master_piece.tiles.offset.p1);
	boundary.p2 = world_to_screen_2d(*(hook->camera),
		hook->master_piece.tiles.offset.p2);
	src = *hook->master_piece.still_life;
	ixiy.x = 0;
	while (ixiy.x < (int)src.src->col)
	{
		ixiy.y = 0;
		while (0 < src.src->row && ixiy.y < (int)src.src->row - 1)
		{
			draw_fdf_mlx_x_unit(hook, boundary, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_fdf_mlx_y(t_2d_hook *hook, bool is_draw)
{
	t_line		boundary;
	t_2d_int	ixiy;
	t_fdf		src;

	if (is_2dhook_valid(hook, E_STILL_LIFE) == false)
		return ;
	boundary.p1 = world_to_screen_2d(*(hook->camera),
		hook->master_piece.tiles.offset.p1);
	boundary.p2 = world_to_screen_2d(*(hook->camera),
		hook->master_piece.tiles.offset.p2);
	src = *hook->master_piece.still_life;
	ixiy.x = 0;
	while (ixiy.x < (int)src.src->col - 1)
	{
		ixiy.y = 0;
		while (0 < src.src->row && ixiy.y < (int)src.src->row)
		{
			draw_fdf_mlx_y_unit(hook, boundary, is_draw, ixiy);
			ixiy.y += 1;
		}
		ixiy.x += 1;
	}
}
