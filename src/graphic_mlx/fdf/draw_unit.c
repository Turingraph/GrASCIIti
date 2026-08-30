/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:52:29 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 16:55:33 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

// time : O(1)
// space: O(1)
t_ink32	get_hook_ink(t_2d_hook *hook, bool is_draw, t_2d_int ixiy)
{
	t_ink32		ink;
	t_table_fdf	*table;

	table = hook->master_piece.fdf->src;
	ink = hook->master_piece.drawing_style;
	ink.color = get_table_rgba_int32((const t_table_fdf *)table,
			ixiy.y * table->col + ixiy.x);
	if (is_draw == false)
		ink.color = hook->master_piece.background_color;
	else if (is_draw == true && ink.color == 0)
		ink.color = hook->master_piece.drawing_style.color;
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

	rectangle_boundary.p1.x = 0;
	rectangle_boundary.p1.y = 0;
	rectangle_boundary.p2 = camera.window_size;
	if (is_line_in_screen(camera, line) && ink.type == E_RECTANGLE)
		draw_rectangle_mlx(img, line, rectangle_boundary, ink.color);
	else if (is_line_in_screen(camera, line) && ink.type == E_LINE)
		draw_mlx_straight_line(img, line, rectangle_boundary, ink);
	else
	{
		draw_fdf_mlx_unit_circle(line.p1, ink, camera, img);
		draw_fdf_mlx_unit_circle(line.p2, ink, camera, img);
	}
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_y_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line	line;
	t_ink32	ink;

	ink = get_hook_ink(hook, is_draw, ixiy);
	line.p1 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0));
	line.p2 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 2),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 2));
	if (hook->master_piece.is_isometric == true)
	{
		line.p1 = world_3d_to_screen_isometric(*hook->camera,
				get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
				get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0),
				get_fdf_point(hook->master_piece.fdf, ixiy, 3, 0));
		line.p2 = world_3d_to_screen_isometric(*hook->camera,
				get_fdf_point(hook->master_piece.fdf, ixiy, 1, 2),
				get_fdf_point(hook->master_piece.fdf, ixiy, 2, 2),
				get_fdf_point(hook->master_piece.fdf, ixiy, 3, 2));
	}
	draw_fdf_mlx_unit(line, ink, *(hook->camera), hook->img);
}

// time : O(1)
// space: O(1)
void	draw_fdf_mlx_x_unit(t_2d_hook *hook,
	bool is_draw, t_2d_int ixiy)
{
	t_line	line;
	t_ink32	ink;

	ink = get_hook_ink(hook, is_draw, ixiy);
	line.p1 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0));
	line.p2 = world_3d_to_screen_2d(*hook->camera,
			get_fdf_point(hook->master_piece.fdf, ixiy, 1, 1),
			get_fdf_point(hook->master_piece.fdf, ixiy, 2, 1));
	if (hook->master_piece.is_isometric == true)
	{
		line.p1 = world_3d_to_screen_isometric(*hook->camera,
				get_fdf_point(hook->master_piece.fdf, ixiy, 1, 0),
				get_fdf_point(hook->master_piece.fdf, ixiy, 2, 0),
				get_fdf_point(hook->master_piece.fdf, ixiy, 3, 0));
		line.p2 = world_3d_to_screen_isometric(*hook->camera,
				get_fdf_point(hook->master_piece.fdf, ixiy, 1, 1),
				get_fdf_point(hook->master_piece.fdf, ixiy, 2, 1),
				get_fdf_point(hook->master_piece.fdf, ixiy, 3, 1));
	}
	draw_fdf_mlx_unit(line, ink, *(hook->camera), hook->img);
}
