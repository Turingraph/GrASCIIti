/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_type.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 18:45:56 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 18:57:42 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_TYPE_H
# define DISPLAY_TYPE_H

# include "../raster/raster.h"
# include "../../utils/linalg/linalg.h"
# include "../../input/table/table.h"

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
 * @param matrix 3D transformation matrix associated with the object.
 * This matrix is used for undo every linear transformation
 * when user press "Q" button.
 * @param width current width of the transformed FDF object
 */
typedef struct s_fdf
{
	t_table_fdf	*src;
	float		*pos_x;
	float		*pos_y;
	float		*pos_z;
	t_matrix	matrix;
	float		width;
}	t_fdf;

/**
 * 2D camera describing the visible portion of a rendered object.
 * 
 * The camera controls the position and scale used to map object
 * coordinates into the 2D rendering area.
 * 
 * @param offset position of the camera relative to the rendered object
 * @param window_size size of the visible 2D rendering area
 * @param zoom scale applied by the camera
 */
typedef struct s_2d_camera
{
	t_2d_int	offset;
	t_2d_int	window_size;
	float		zoom;
}	t_2d_camera;

/**
 * Describes the object and drawing configuration presented by a view.
 * 
 * A master piece combines the FDF object with the drawing style and
 * background configuration required to display it.
 * 
 * @param drawing_style describes how the FDF object is rasterized
 * @param fdf FDF object to display
 */
typedef struct s_master_piece
{
	t_ink32			drawing_style;
	t_fdf			*fdf;
	t_2d_int		(*projection)(float x, float y, float z);
}	t_master_piece;

/**
 * Runtime state required by the 2D MLX viewer.
 * 
 * The hook owns the MLX image and keeps references to the camera and
 * master piece used while the rendering loop is running.
 * 
 * @param mlx MLX window context
 * @param img image used as the rendering target
 * @param camera camera used to transform the displayed object
 * @param master_piece 3D FDF object and drawing
 * configuration displayed by the viewer
 */
typedef struct s_2d_hook
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_2d_camera		*camera;
	t_master_piece	master_piece;
}	t_2d_hook;

#endif
