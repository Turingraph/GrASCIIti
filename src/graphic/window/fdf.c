/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:32:53 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 22:41:42 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

// time : O(1)
// space: O(1)
t_ink32	get_hook_ink(t_2d_hook *hook, bool is_draw, t_2d_int ixiy)
{
	t_ink32		ink;
	t_table_fdf	*table;

	table = hook->master_piece.still_life->src;
	ink = hook->master_piece.drawing_style;
	ink.color = get_table_rgba_int32((const t_table_fdf *)table,
			ixiy.y * table->col + ixiy.x);
	if (is_draw == false)
		ink.color = hook->master_piece.background.color;
	return (ink);
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_unit_circle(t_2d_int point,
	t_ink32 ink, t_2d_camera camera, mlx_image_t *img)
{
	t_circle	circle;
	t_boundary	boundary;

	if (is_circle_in_screen(camera, point, ink.thickness) == true
		&& ink.type != E_RECTANGLE)
	{
		boundary = get_all_area(img->height, img->width);
		circle.radius = ink.thickness;
		circle.x = point.x;
		circle.y = point.y;
		midpoint_circle_mlx(img, ink.color, circle, boundary);
	}
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_unit(t_line line, t_ink32 ink,
	t_2d_camera camera, mlx_image_t *img)
{
	t_line		rectangle_boundary;

	rectangle_boundary.p1 = camera.offset;
	rectangle_boundary.p2 = camera.window_size;
	if ((is_line_in_screen(camera, line.p1) == true
			|| is_line_in_screen(camera, line.p2) == true)
		&& ink.type == E_RECTANGLE)
		draw_rectangle_mlx(img, line, rectangle_boundary, ink.color);
	else if ((is_line_in_screen(camera, line.p1) == true
			|| is_line_in_screen(camera, line.p2) == true)
		&& ink.type == E_LINE)
		draw_mlx_straight_line(img, line, rectangle_boundary, ink);
	else
	{
		draw_fdf_mlx_unit_circle(line.p1, ink, camera, img);
		draw_fdf_mlx_unit_circle(line.p2, ink, camera, img);
	}
}
