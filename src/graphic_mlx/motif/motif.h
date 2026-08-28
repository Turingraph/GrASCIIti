#ifndef MOTIF_H
# define MOTIF_H

# include "../raster/raster_private.h"

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

// public.c

void	view_motif(t_motif_arr *src, int32_t background_color, size_t resolution);

#endif
