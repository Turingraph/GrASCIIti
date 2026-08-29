/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raster.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:33:51 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 17:22:23 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RASTER_H
# define RASTER_H

# include "../../utils/green_counts/green_counts.h"
# include "../../utils/libft/libft.h"
# include "MLX42.h"
# include "raster_type.h"

// color.c

int32_t		f_rgba_to_int32(unsigned char r,
				unsigned char g, unsigned char b, unsigned char a);
void		color_background_mlx(mlx_image_t *dst, int32_t color);
int32_t		get_table_rgba_int32(const t_table_fdf *src, size_t index);

// init.c

int			float_to_2d_int(float src, t_line boundary, char mode);

// line.c

void		draw_mlx_straight_line(mlx_image_t *dst, t_line line,
				t_line rectangle_boundary, t_ink32 ink);

// shape.c

t_line		init_rectangle(t_line src, t_boundary boundary);
void		draw_rectangle_mlx(mlx_image_t *dst, t_line rectangle,
				t_line boundary, int32_t ink);
void		midpoint_circle_mlx(mlx_image_t *dst,
				int32_t color, t_circle point, t_boundary boundary);

// utils.c

bool		is_in_boundary(int x, int y, t_line boundary);
t_line		reverse_line(t_line line);
t_line		get_tiling(t_2d_int tiling_area, size_t i, size_t j);
t_boundary	get_all_area(size_t row, size_t col);

#endif
