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

#ifndef FDF_PRIVATE_H
# define FDF_PRIVATE_H

# include "../display/display.h"

// draw_fdf.c

void		draw_fdf_mlx(t_2d_hook *hook, bool is_draw);

// draw_pixel_art.c

void		draw_fdf_mlx_pixel_art(t_2d_hook *hook, bool is_draw);

// draw_unit.c

t_ink32		get_hook_ink(t_2d_hook *hook, bool is_draw, t_2d_int ixiy);
void		draw_fdf_mlx_unit_circle(t_2d_int point,
				t_ink32 ink, t_2d_camera camera, mlx_image_t *img);
void		draw_fdf_mlx_unit(t_line line, t_ink32 ink, t_2d_camera camera,
				mlx_image_t *img);
void		draw_fdf_mlx_y_unit(t_2d_hook *hook,
				bool is_draw, t_2d_int ixiy);
void		draw_fdf_mlx_x_unit(t_2d_hook *hook,
				bool is_draw, t_2d_int ixiy);

// geometry_2d.c

bool		is_line_in_screen(t_2d_camera camera,
				t_line src);
bool		is_circle_in_screen(t_2d_camera camera,
				t_2d_int src, int radius);
float		get_fdf_point(t_fdf *fdf, t_2d_int ixiy,
				size_t dim, char next);

// geometry_3d.c

float		linear_map_fdf(const t_fdf *src, t_matrix matrix,
				size_t i, char axis);
void		linear_map_fdf_all(t_fdf *src, t_matrix matrix);
t_2d_int	world_3d_to_screen_2d(t_2d_camera camera,
				float x, float y);

// hook.c

void		hook_fdf_controller(mlx_key_data_t keydata, void *param);

// init_2d_hook.c

t_2d_camera	init_2d_camera(size_t window_width, size_t window_height);
t_2d_hook	init_2d_hook(mlx_t *mlx, t_fdf *fdf, t_ink32 drawing_style,
				t_2d_int (*projection)(float x, float y, float z));
void		scale_fdf_as_window_object(t_fdf *src,
				size_t fixed_window_size);

// init_fdf.c

t_fdf		init_fdf(t_table_fdf *src);
void		free_fdf(t_fdf *src);
bool		is_fdf_valid(const t_fdf *src);

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

// verify.c

bool		is_2dhook_valid(const t_2d_hook *src);
bool		is_valid_key(mlx_key_data_t keydata);
bool		is_valid_pan_key(mlx_key_data_t keydata);
bool		is_valid_rotate_key(mlx_key_data_t keydata);
bool		is_valid_zoom_key(mlx_key_data_t keydata, float zoom);

#endif
