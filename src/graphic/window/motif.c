/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:48:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 22:53:56 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include <time.h>

// time : O(n)
// space: O(1)
void	draw_motif_mlx_unit(t_2d_hook *hook,
	bool is_draw, t_line tile)
{
	size_t	i;
	t_motif	*arr;
	t_ink32	ink;

	if (is_2dhook_valid(hook, E_MOTIF) == false)
		return ;
	arr = hook->master_piece.motif->arr;
	i = 0;
	while (i < hook->master_piece.motif->length)
	{
		ink = arr[i].ink;
		if (is_draw == false)
			ink.color = hook->master_piece.background.color;
		if (ink.type == E_LINE)
			draw_polygon_mlx(hook->img, &(arr[i].polygon), ink, tile);
		else if (ink.type == E_CIRCLE)
			draw_kusama_mlx(hook->img, &(arr[i].polygon), ink, tile);
		else if (ink.type == E_RECTANGLE)
			draw_mondrian_mlx(hook->img, &(arr[i].polygon), ink.color, tile);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_motif_mlx_loop(t_2d_hook *hook,
	bool is_draw, t_line interier_tile)
{
	t_line		tile;
	int			ix;
	int			iy;
	t_2d_camera	static_camera;

	if (is_2dhook_valid(hook, E_MOTIF) == false)
		return ;
	static_camera = get_static_camera(hook->camera->window_size);
	iy = interier_tile.p1.y;
	while (iy < interier_tile.p2.y)
	{
		ix = interier_tile.p1.x;
		while (ix < interier_tile.p2.x)
		{
			tile.p1 = get_ith_tile_screen(hook->master_piece.tiles,
					static_camera, ix, iy);
			tile.p2 = get_ith_tile_screen(hook->master_piece.tiles,
					static_camera, ix + 1, iy + 1);
			draw_motif_mlx_unit(hook, is_draw, tile);
			ix += 1;
		}
		iy += 1;
	}
}

// time : O(n)
// space: O(1)
void	draw_motif_mlx(t_2d_hook *hook, bool is_draw)
{
	t_line	interier_tile;

	if (is_2dhook_valid(hook, E_MOTIF) == false)
		return ;
	interier_tile.p1.x = 0;
	interier_tile.p1.y = 0;
	interier_tile.p2 = hook->master_piece.tiles.tile_counts;
	draw_motif_mlx_loop(hook, is_draw, interier_tile);
}
