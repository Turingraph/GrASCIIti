/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:43:32 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 19:03:16 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_PRIVATE_H
# define WINDOW_PRIVATE_H

# include "../display/display.h"

// hook.c

void		hook_fdf_controller(mlx_key_data_t keydata, void *param);

// init_2d_hook.c

t_2d_camera	init_2d_camera(size_t window_width, size_t window_height);
t_2d_hook	init_2d_hook(mlx_t *mlx, t_fdf *fdf, t_artstyle32 artstyle);
void		scale_fdf_as_window_object(t_fdf *src,
				size_t fixed_window_size);

// linalg.c

float		linear_map_fdf(const t_fdf *src, t_matrix matrix, size_t i, char axis);
void		linear_map_fdf_all(t_fdf *src, t_matrix matrix);

// public.c

void		view_fdf(t_fdf *fdf, t_artstyle32 artstyle);

// verify.c

bool		is_valid_key(mlx_key_data_t keydata);
bool		is_valid_pan_key(mlx_key_data_t keydata);
bool		is_valid_rotate_key(mlx_key_data_t keydata);
bool		is_valid_zoom_key(mlx_key_data_t keydata, float zoom);

#endif
