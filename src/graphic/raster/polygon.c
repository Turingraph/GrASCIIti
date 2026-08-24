/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:17:05 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 22:17:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"

// time : O(n)
// sapce: O(1)
void	draw_polygon_mlx(mlx_image_t *dst, const t_2d_polygon *polygon,
	t_ink32 ink, t_line boundary)
{
	size_t	i;
	t_line	line;

	i = 0;
	while (dst != NULL && polygon != NULL && i < polygon->length - 1)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[i + 1], boundary);
		draw_mlx_straight_line(dst, line, boundary, ink);
		i += 1;
	}
	if (dst != NULL && polygon != NULL
		&& i == polygon->length - 1 && polygon->is_loop == true)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[0], boundary);
		draw_mlx_straight_line(dst, line, boundary, ink);
	}
}

// time : O(n)
// sapce: O(1)
void	draw_islamic_tiling_mlx(mlx_image_t *dst, const t_2d_polygon *polygon,
	t_ink32 ink, t_2d_int tiling_area)
{
	size_t	i;
	size_t	j;
	t_line	tiling;

	i = 0;
	while (dst != NULL && polygon != NULL
		&& tiling_area.y > 0 && i < f_floor(dst->height / tiling_area.y) + 1)
	{
		j = 0;
		while (tiling_area.x > 0 && j < f_floor(dst->width / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			draw_polygon_mlx(dst, polygon, ink, tiling);
			j += 1;
		}
		i += 1;
	}
}
