#ifndef VIEW_H
# define VIEW_H

#include "../../utils/type/type.h"
#include "../../input/table/table.h"
#include "MLX42.h"

// color.c
void		paint_table_on_image(const t_table_fdf *src,
				mlx_image_t *img);
t_table_fdf	scale_window_dimension_fdf(const t_table_fdf *src);

// init.c
int			view_table_fdf(const t_table_fdf *src);

#endif
