/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/31 16:07:53 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 18:24:30 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "motif_private.h"

// time : O(1)
// space: O(1)
bool	is_islamic_art_valid(const t_islamic_art *src)
{
	if (src == NULL || src->motif == NULL
		|| src->motif->arr == NULL || src->motif->length == 0
		|| src->tiles.tile_counts.x * src->tiles.tile_counts.y == 0
		|| src->tiles.tile_size == 0)
		return (false);
	return (true);
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
t_line	init_first_line(t_line src, t_line boundary)
{
	t_line	dst;
	int		offset;

	offset = boundary.p1.x;
	dst.p1.x = src.p1.x + offset;
	dst.p2.x = src.p2.x + offset;
	offset = boundary.p1.y;
	dst.p1.y = src.p1.y + offset;
	dst.p2.y = src.p2.y + offset;
	return (dst);
}

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
	int		output;

	dst = f_interval(src, 0, 1);
	output = (int)f_floor(dst * (boundary.p2.x - boundary.p1.x));
	if (mode == 1)
		output = (int)f_floor(dst * (boundary.p2.y - boundary.p1.y));
	return (output);
}

/**
 * Convert two normalized complex-plane points into a 2D integer line
 * within the specified boundary. The real component is mapped to the
 * x dimension and the imaginary component to the y dimension. The
 * resulting coordinates are translated by the boundary origin.
 *
 * time/space: O(1) / O(1)
 *
 * status: internal helper
 *
 * @param point_1 first normalized complex point
 * @param point_2 second normalized complex point
 * @param boundary target rectangular boundary
 * @return integer line mapped to the boundary
 */
t_line	init_float_line(t_complex point_1, t_complex point_2,
	t_line boundary)
{
	t_line	dst;

	dst.p1.x = float_to_2d_int(point_1.re, boundary, 0) + boundary.p1.x;
	dst.p1.y = float_to_2d_int(point_1.im, boundary, 1) + boundary.p1.y;
	dst.p2.x = float_to_2d_int(point_2.re, boundary, 0) + boundary.p1.x;
	dst.p2.y = float_to_2d_int(point_2.im, boundary, 1) + boundary.p1.y;
	return (dst);
}
