#ifndef FDF_H
# define FDF_H

# include "../../utils/linalg/linalg.h"
# include "../../input/table/table.h"

typedef struct t_fdf t_fdf;

struct t_fdf
{
	t_table_fdf	*src;
	float		*pos_x;
	float		*pos_y;
	float		*pos_z;
	float		width;
};

// init.c
t_fdf		init_fdf(t_table_fdf *src);
bool		is_fdf_valid(const t_fdf *src);
void	free_fdf(t_fdf *src);

// matrix.c
float	linear_map_3d(const t_fdf *src, t_matrix matrix, size_t i, char axis);
void		linear_map_3d_all(t_fdf *src, t_matrix matrix);
t_matrix	init_3d_rotate_matrix(float delta, char axis);

#endif
