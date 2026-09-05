/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_private.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 19:02:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 19:05:47 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_PRIVATE_H
# define DISPLAY_PRIVATE_H

# include "display_type.h"

// init_line.c

t_line		init_draw_line_y(t_2d_camera camera, t_fdf *fdf, t_2d_int ixiy);
t_line		init_draw_line_x(t_2d_camera camera, t_fdf *fdf, t_2d_int ixiy);
t_line		init_proj_line_y(t_2d_camera camera, t_fdf *fdf, t_2d_int ixiy,
				t_2d_int (*projection)(float x, float y, float z));
t_line		init_proj_line_x(t_2d_camera camera, t_fdf *fdf, t_2d_int ixiy,
				t_2d_int (*projection)(float x, float y, float z));

// proj_*/draw_*.c

void		proj_kusama_fdf(t_2d_hook *hook, bool is_draw, size_t thickness);
void		draw_kusama_fdf(t_2d_hook *hook, bool is_draw, size_t thickness);
void		proj_picasso_fdf(t_2d_hook *hook, bool is_draw, size_t thickness);
void		draw_picasso_fdf(t_2d_hook *hook, bool is_draw, size_t thickness);
void		draw_toby_fox_fdf(t_2d_hook *hook, bool is_draw);

// draw_etc.c

void		draw_euler_fdf(t_2d_hook *hook, bool is_draw);
void		draw_poincare_fdf(t_2d_hook *hook, bool is_draw);
void		draw_dijkstra_fdf(t_2d_hook *hook, bool is_draw);
void		draw_warhol_fdf(t_2d_hook *hook, bool is_draw);
void		draw_araki_fdf(t_2d_hook *hook, bool is_draw);

// proj_etc.c

void		proj_euler_fdf(t_2d_hook *hook, bool is_draw);
void		proj_poincare_fdf(t_2d_hook *hook, bool is_draw);
void		proj_dijkstra_fdf(t_2d_hook *hook, bool is_draw);
void		proj_warhol_fdf(t_2d_hook *hook, bool is_draw);
void		proj_araki_fdf(t_2d_hook *hook, bool is_draw);

// public.c

void		draw_fdf_mlx(t_2d_hook *hook, bool is_draw);

// unit.c

t_ink32		get_hook_ink32(t_2d_hook *hook, bool is_draw, t_2d_int ixiy, size_t thickness);
void		draw_circle_fdf(t_2d_int point,
				t_ink32 ink, t_2d_camera camera, mlx_image_t *img);
void		draw_rectangle_fdf(t_line line, int32_t ink,
				t_2d_camera camera, mlx_image_t *img);
void		draw_line_fdf(t_line line, t_ink32 ink,
				t_2d_camera camera, mlx_image_t *img);

// utils.c

bool		is_2dhook_valid(const t_2d_hook *src);
bool		is_line_in_screen(t_2d_camera camera,
				t_line src);
bool		is_circle_in_screen(t_2d_camera camera,
				t_2d_int src, int radius);
float		get_fdf_point(t_fdf *fdf, t_2d_int ixiy, size_t dim, char next);
t_2d_int	world_3d_to_screen_2d(t_2d_camera camera, float x, float y);

#endif
