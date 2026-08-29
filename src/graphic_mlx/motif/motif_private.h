/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motif_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 17:14:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 17:34:01 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOTIF_PRIVATE_H
# define MOTIF_PRIVATE_H

# include "../raster/raster_private.h"

/**
 * 2D polygon represented by normalized coordinates.
 *
 * Each coordinate in arr must be within the range [0, 1]. The polygon
 * is scaled to the supplied drawing boundary when rendered, allowing
 * the same polygon to be reused across different areas and tile sizes.
 *
 * @param arr polygon vertices using normalized x and y coordinates
 * @param length number of vertices
 * @param is_loop connect the final vertex back to the first vertex
 */
typedef struct s_2d_polygon
{
	t_complex	*arr;
	size_t		length;
	bool		is_loop;
}	t_2d_polygon;

/**
 * Reusable 2D drawing motif composed of geometry and drawing properties.
 *
 * polygon provides the geometric data while ink describes how that geometry
 * should be rendered. A motif can therefore be reused with different
 * positions, transformations, or drawing operations.
 */
typedef struct s_motif
{
	t_2d_polygon	polygon;
	t_ink32			ink;
}	t_motif;

/**
 * Array of reusable 2D drawing motifs.
 *
 * A motif array represents a collection of independent drawing elements
 * that can be rendered together. It can be used to construct geometric or
 * line-based artwork such as Islamic patterns, Piet Mondrian-style
 * compositions, Kusama-inspired patterns, and other procedural drawings.
 */
typedef struct s_motif_arr
{
	t_motif	*arr;
	size_t	length;
}	t_motif_arr;


/**
 * A line represented by normalized 2D coordinates.
 *
 * The two endpoints are stored as complex numbers, where the real part
 * represents the X coordinate and the imaginary part represents the Y
 * coordinate. The coordinates are interpreted relative to a tile rather
 * than directly as screen pixels.
 *
 * This type is used by the motif renderer to describe reusable geometric
 * shapes that can be scaled and placed inside different tiles.
 * 
 * The scale features for manipulating motif will be implemented in the future.
 *
 * status: internal helper
 *
 * @param p1 first endpoint of the line
 * @param p2 second endpoint of the line
 */
typedef struct s_fline
{
	t_complex	p1;
	t_complex	p2;
}	t_fline;

/**
 * Describes how a motif is repeated across a 2D drawing area.
 *
 * The drawing area is divided into a rectangular grid of tiles. Motif
 * coordinates are interpreted relative to an individual tile and are
 * scaled according to tile_size before being placed on the drawing area.
 *
 * The offset allows the tile grid to begin at a position other than
 * the origin. This makes it possible to position a repeated motif
 * pattern without changing the motif itself.
 *
 * This type belongs to the motif renderer and is independent of FDF
 * data. It can therefore be used to build repeated geometric patterns
 * such as lines, circles, rectangles, Islamic geometric art, or other
 * tile-based drawings.
 *
 * status: internal helper
 *
 * @param tile_size size of each tile in the drawing area
 * @param tile_counts number of tiles along the X and Y axes
 * @param offset normalized coordinates describing the tile-grid offset
 */
typedef struct s_tile_format
{
	float		tile_size;
	t_2d_int	tile_counts;
	t_fline		offset;
}	t_tile_format;

/**
* Describes a tiled motif composition and its background.
*
* The motif array contains the geometric elements that are repeated
* across the tile format. The same composition can therefore be used
* to create Islamic geometric art, ornamental patterns, or other
* repeated line-based artwork.
*
* The tile format determines how the motif is positioned and repeated
* across the drawing area. The background color is used to fill the
* area behind the rendered motif.
*
* This type belongs to the motif renderer and does not depend on FDF
* data.
*
* status: internal helper
*
* @param motif collection of motifs used to build the composition
* @param tiles tiling configuration for repeating the motif
* @param background_color color rendered behind the motif
*/
typedef struct s_islamic_art
{
	t_motif_arr		*motif;
	t_tile_format	tiles;
}	t_islamic_art;

// draw.c

void			draw_motif_mlx(mlx_image_t *img, t_islamic_art *src);

// motif.c

void			draw_kusama_mlx(mlx_image_t *dst,
					const t_2d_polygon *polygon, t_ink32 ink, t_line boundary);
void			draw_polygon_mlx(mlx_image_t *dst, const t_2d_polygon *polygon,
					t_ink32 ink, t_line boundary);
void			draw_mondrian_mlx(mlx_image_t *dst,
					const t_2d_polygon *polygon, int32_t ink, t_line boundary);

// public.c

void			view_motif(t_motif_arr *src,
					int32_t background_color, size_t resolution);

// tile_format.c

t_fline			init_offset_tile_area(size_t width, size_t height,
					size_t resolution, size_t fixed_length);
t_tile_format	init_tile_format(size_t width,
					size_t height, size_t resolution);
t_2d_int		get_ith_tile_screen(t_tile_format tiles,
					int ix, int iy);

// tile.c

size_t			init_tile_size(size_t side_length, size_t resolution);
size_t			init_alltiles_count(size_t side_length,
					size_t resolution, size_t fixed_length);
size_t			init_alltiles_size(size_t side_length,
					size_t resolution, size_t fixed_length);
int				init_alltiles_offset(size_t side_length,
					size_t resolution, size_t fixed_length);

// utils.c

bool			is_islamic_art_valid(const t_islamic_art *src);

#endif
