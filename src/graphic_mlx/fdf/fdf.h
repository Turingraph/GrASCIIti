/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:59:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 16:03:57 by phsottat         ###   ########.fr       */
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

t_fdf	init_fdf(t_table_fdf *src);
void	free_fdf(t_fdf *src);

// public.c

void	view_fdf(t_fdf *fdf, t_ink32 drawing_style,
			int32_t background_color, bool is_isometric);

#endif
