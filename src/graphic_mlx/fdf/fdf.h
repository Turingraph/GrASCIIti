/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:59:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 17:34:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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

// init_fdf.c

t_fdf		init_fdf(t_table_fdf *src);
void		free_fdf(t_fdf *src);

// projection_01.c

t_2d_int	projection_isometric(float x, float y, float z);
t_2d_int	projection_military(float x, float y, float z);
t_2d_int	projection_cabinet(float x, float y, float z);
t_2d_int	projection_cabinet_flat(float x, float y, float z);

// projection_02.c

t_2d_int	projection_scifi_rotate(float x, float y, float z);
t_2d_int	projection_orthogonal(float x, float y, float z);
t_2d_int	projection_csin(float x, float y, float z);
t_2d_int	projection_cexp(float x, float y, float z);
t_2d_int	projection_cexp_left(float x, float y, float z);

// projection_03.c

t_2d_int	projection_y_times_z(float x, float y, float z);
t_2d_int	projection_scifi_scale(float x, float y, float z);
t_2d_int	projection_scifi_divide(float x, float y, float z);
t_2d_int	projection_zparallel(float x, float y, float z);
t_2d_int	projection_wave(float x, float y, float z);

// public.c

void		view_fdf(t_fdf *fdf, t_ink32 drawing_style, float zoom,
				t_2d_int (*projection)(float x, float y, float z));

#endif
