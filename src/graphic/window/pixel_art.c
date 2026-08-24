/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:40:33 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 22:40:43 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_pixel_art_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line	line;
	t_ink32	ink;
	float	*post_x;
	float	*post_y;
	int		next;

	next = (ixiy.y + 1) * hook->master_piece.still_life->src->col + ixiy.x + 1;
	post_x = hook->master_piece.still_life->pos_x;
	pos_y = hook->master_piece.still_life->pos_y;
	ink = get_hook_ink(hook, is_draw, ixiy);
	ink.type = E_RECTANGLE;
	line.p1 = world_to_screen_3d(*hook->camera,
			pos_x[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x],
			pos_y[ixiy.y * hook->master_piece.still_life->src->col + ixiy.x]);
	line.p2 = world_to_screen_3d(*hook->camera,
			pos_x[next], pos_y[next]);
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
