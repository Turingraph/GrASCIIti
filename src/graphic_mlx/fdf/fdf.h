/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:59:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 19:03:09 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../display/display.h"

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
