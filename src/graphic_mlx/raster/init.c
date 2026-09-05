/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:29:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 18:31:04 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster_private.h"

// time : O(1)
// space: O(1)
int	init_swap_bresenham_y(t_line *line,
	int *delta_x, int *delta_y)
{
	int	y;

	y = 1;
	if (line != NULL && delta_x != NULL && delta_y != NULL
		&& f_abs_int(line->p2.x - line->p1.x) < f_abs_int(line->p2.y - line->p1.y))
	{
		*delta_y = line->p2.x - line->p1.x;
		*delta_x = line->p2.y - line->p1.y;
		if (*delta_x < 0)
		{
			*delta_y = line->p1.x - line->p2.x;
			*delta_x = line->p1.y - line->p2.y;
			y = 2;
		}
		if (*delta_y < 0)
		{
			*delta_y += 1;
			return (y * -1);
		}
		return (y);
	}
	return (0);
}

// time : O(1)
// space: O(1)
int	init_swap_bresenham_x(t_line *line,
	int *delta_x, int *delta_y)
{
	int	y;

	y = 1;
	if (line != NULL && delta_x != NULL && delta_y != NULL
		&& f_abs_int(line->p2.x - line->p1.x) >= f_abs_int(line->p2.y - line->p1.y))
	{
		*delta_x = line->p2.x - line->p1.x;
		*delta_y = line->p2.y - line->p1.y;
		if (*delta_x < 0)
		{
			*delta_x = line->p1.x - line->p2.x;
			*delta_y = line->p1.y - line->p2.y;
			y = 2;
		}
		if (*delta_y < 0)
		{
			*delta_y += 1;
			return (y * -1);
		}
		return (y);
	}
	return (0);
}

/**
 * Define the rectangular sub-area within the full table boundary.
 * 
 * The returned boundary stores the full table dimensions in all_area and
 * clamps sub_area to the valid range [0, col] x [0, row]. The sub-area
 * endpoints are reordered when necessary so that p1 represents the
 * minimum corner and p2 represents the maximum corner.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: internal helper
 * 
 * @param sub_area requested rectangular sub-area
 * @param row number of rows in the full table
 * @param col number of columns in the full table
 * @return normalized and clamped table boundary
 */
t_boundary	init_rectangle_boundary(t_line sub_area, size_t row, size_t col)
{
	int			temp;
	t_boundary	dst;

	dst.all_area.x = (int)col;
	dst.all_area.y = (int)row;
	dst.sub_area.p1.x = (int)f_interval(sub_area.p1.x, 0, col);
	dst.sub_area.p1.y = (int)f_interval(sub_area.p1.y, 0, row);
	dst.sub_area.p2.x = (int)f_interval(sub_area.p2.x, 0, col);
	dst.sub_area.p2.y = (int)f_interval(sub_area.p2.y, 0, row);
	if (dst.sub_area.p1.x > dst.sub_area.p2.x)
	{
		temp = dst.sub_area.p1.x;
		dst.sub_area.p1.x = dst.sub_area.p2.x;
		dst.sub_area.p2.x = temp;
	}
	if (dst.sub_area.p1.y > dst.sub_area.p2.y)
	{
		temp = dst.sub_area.p1.y;
		dst.sub_area.p1.y = dst.sub_area.p2.y;
		dst.sub_area.p2.y = temp;
	}
	return (dst);
}

/**
 * Translate a line into a rectangular sub-area.
 * Each coordinate of src is interpreted relative to the origin of the
 * sub-area. The coordinate is first clamped to the corresponding sub-area
 * dimension, then translated by the sub-area origin so that the complete
 * line remains within the requested region of the full table.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: internal helper
 * 
 * issue: It truncate the line (that outside the boundary) incorrectly.
 * 
 * @param src source line in sub-area-relative coordinates
 * @param boundary full table and target sub-area boundary
 * @return translated and clamped line
 */
t_line	init_first_line(t_line src, t_boundary boundary)
{
	t_line	dst;
	int		offset;

	offset = boundary.sub_area.p1.x;
	dst.p1.x = src.p1.x + offset;
	dst.p2.x = src.p2.x + offset;
	offset = boundary.sub_area.p1.y;
	dst.p1.y = src.p1.y + offset;
	dst.p2.y = src.p2.y + offset;
	return (dst);
}

/**
 * Translate a line into a rectangular sub-area.
 * Each coordinate of src is interpreted relative to the origin of the
 * sub-area. The coordinate is first clamped to the corresponding sub-area
 * dimension, then translated by the sub-area origin so that the complete
 * line remains within the requested region of the full table.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: internal helper
 * 
 * issue: It truncate the line (that outside the boundary) incorrectly.
 * 
 * @param src source line in sub-area-relative coordinates
 * @param boundary full table and target sub-area boundary
 * @return translated and clamped line
 */
// t_line	init_first_line(t_line src, t_boundary boundary)
// {
// 	t_line	dst;
// 	int		offset;

// 	offset = boundary.sub_area.p1.x;
// 	dst.p1.x = (int)f_interval(src.p1.x, 0,
// 			boundary.sub_area.p2.x - boundary.sub_area.p1.x) + offset;
// 	dst.p2.x = (int)f_interval(src.p2.x, 0,
// 			boundary.sub_area.p2.x - boundary.sub_area.p1.x) + offset;
// 	offset = boundary.sub_area.p1.y;
// 	dst.p1.y = (int)f_interval(src.p1.y, 0,
// 			boundary.sub_area.p2.y - boundary.sub_area.p1.y) + offset;
// 	dst.p2.y = (int)f_interval(src.p2.y, 0,
// 			boundary.sub_area.p2.y - boundary.sub_area.p1.y) + offset;
// 	return (dst);
// }

/**
 * Convert a normalized floating-point coordinate to a 2D integer coordinate.
 * 
 * The source value is clamped to [0, 1] and scaled to the size of the
 * selected boundary dimension. Mode 1 selects the y dimension; any other
 * mode selects the x dimension.
 * 
 * The returned coordinate is relative to the boundary origin. This allows
 * the caller to apply the boundary offset separately and prevents the
 * boundary origin from being added more than once.
 * 
 * time/space: O(1) / O(1)
 * 
 * status: internal helper
 * 
 * @param src normalized coordinate to convert
 * @param boundary target rectangular boundary
 * @param mode 1 for y dimension, otherwise x dimension
 * @return converted integer coordinate relative to the boundary origin
 */
int	float_to_2d_int(float src, t_line boundary, char mode)
{
	float	dst;

	dst = f_interval(src, 0, 1);
	if (mode == 1)
		return ((int)f_floor(dst * (boundary.p2.y - 1 - boundary.p1.y)));
	return ((int)f_floor(dst * (boundary.p2.x - 1 - boundary.p1.x)));
}
