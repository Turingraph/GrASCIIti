#ifndef VIEW_H
# define VIEW_H

#include "../../utils/type/type.h"
#include "../../editor/convolve/convolve.h"
#include "MLX42.h"

// color.c
void		paint_table_on_image(const t_table_fdf *src,
				mlx_image_t *img);
t_table_fdf	scale_window_dimension_fdf(const t_table_fdf *src);

// init.c
void		view_table_fdf(const t_table_fdf *src);
int			view_convolve_table_fdf(const t_table_fdf *src, t_rgba target_channels, t_matrix kernel);

#endif
