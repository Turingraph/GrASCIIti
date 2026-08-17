#ifndef VIEW_TABLE_H
# define VIEW_TABLE_H

#include "../../utils/type/type.h"
#include "../../input/table/table.h"
#include "MLX42.h"

typedef struct s_view
{
    mlx_t       *mlx;
    mlx_image_t *img;
	// float		zoom;
}   t_view;

// color.c
void		paint_table_on_image(const t_table_fdf *src,
				mlx_image_t *img);
t_table_fdf	scale_window_dimension_fdf(const t_table_fdf *src);

// hook.c
void 		hook_pan(mlx_key_data_t keydata, void *param);

// init.c
int			view_table_fdf(const t_table_fdf *src);

#endif
