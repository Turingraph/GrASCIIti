#include "display_private.h"

// time : O(n)
// space: O(1)
void	proj_euler_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_EULER)
		return ;
	proj_picasso_fdf(hook, is_draw, thickness);
	proj_kusama_fdf(hook, is_draw, thickness * 3 / 2);
}

// time : O(n)
// space: O(1)
void	proj_poincare_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_POINCARE)
		return ;
	proj_kusama_fdf(hook, is_draw, thickness);
	if (is_draw == true)
		proj_kusama_fdf(hook, false, thickness * 4 / 5);
}

// time : O(n)
// space: O(1)
void	proj_dijkstra_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_DIJKSTRA)
		return ;
	proj_picasso_fdf(hook, is_draw, thickness);
	proj_kusama_fdf(hook, is_draw, thickness * 3 / 2);
	if (is_draw == true)
		proj_kusama_fdf(hook, false, thickness * 4 / 5);
}

// time : O(n)
// space: O(1)
void	proj_warhol_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_WARHOL)
		return ;
	draw_toby_fox_fdf(hook, is_draw);
	if (is_draw == true)
		proj_picasso_fdf(hook, false, thickness);
}

// time : O(n)
// space: O(1)
void	proj_araki_fdf(t_2d_hook *hook, bool is_draw)
{
	size_t	thickness;

	thickness = hook->master_piece.artstyle.line_thickness;
	if (hook->master_piece.artstyle.artists != E_ARAKI)
		return ;
	draw_toby_fox_fdf(hook, is_draw);
	if (is_draw == true)
	{
		proj_picasso_fdf(hook, false, thickness);
		proj_kusama_fdf(hook, false, thickness * 3 / 2);
		proj_kusama_fdf(hook, true, thickness * 4 / 5);
	}
}
