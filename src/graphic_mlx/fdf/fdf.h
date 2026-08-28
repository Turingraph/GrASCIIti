#ifndef FDF_H
# define FDF_H

#include"../raster/raster.h"
#include "../../utils/linalg/linalg.h"
#include "../../input/table/table.h"

/**
 * FDF object containing source data (t_table_fdf) and its transformed positions.
 * 
 * The source table stores the original FDF data. The position arrays
 * represent the coordinates used for rendering and may be modified by
 * transformations without changing the source table.
 * 
 * @param src source FDF table
 * @param pos_x transformed x coordinates for each FDF cell
 * @param pos_y transformed y coordinates for each FDF cell
 * @param pos_z transformed z coordinates for each FDF cell
 * @param matrix 3D transformation matrix associated with the object. This matrix is used for undo every linear transformation when user press "Q" button.
 * @param width current width of the transformed FDF object
 */
typedef struct s_fdf
{
	t_table_fdf *src;
	float *pos_x;
	float *pos_y;
	float *pos_z;
	t_matrix matrix;
	float width;
}	t_fdf;

/**
 * Describes the background and initial transformation of a view.
 * 
 * The initial 3D transformation can be used to change the orientation
 * of the first 3D object before it is projected and rasterized.
 * This is useful when a user wants to inspect a static 2D view of an
 * FDF object from a particular orientation without interactively
 * transforming the object during rendering.
 * 
 * @param background_color 32-bit color used for the background
 * @param initial_3d_transform optional transformation applied to the
 * first 3D object before rendering
 */
typedef struct s_view_config
{
	int32_t		background_color;
	t_matrix	*init_3d_transform;
}	t_view_config;

// init_fdf.c

t_fdf	init_fdf(t_table_fdf *src);
void	free_fdf(t_fdf *src);

// public.c

void	view_fdf(t_fdf *still_life, t_ink32 drawing_style, t_view_config view_config);

#endif
