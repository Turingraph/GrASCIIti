#ifndef FDF_H
# define FDF_H

# include "../../utils/linalg/linalg.h"
# include "../../input/table/table.h"

/*
Note that some function are in this module instead of utils/linalg/
because it only works with 3D geometry.
*/

typedef struct t_fdf t_fdf;

struct t_fdf
{
	t_table_fdf	*src;
	float		*pos_x;
	float		*pos_y;
	float		*pos_z;
	t_matrix	matrix;
	float		width;
};

// init.c
t_fdf		init_fdf(t_table_fdf *src);
bool		is_fdf_valid(const t_fdf *src);
void		free_fdf(t_fdf *src);

// linear_map.c
float		linear_map_3d(const t_fdf *src, t_matrix matrix, size_t i, char axis);
void		linear_map_3d_fdf(t_fdf *src, t_matrix matrix);
void		matrix_3d_product(t_matrix src, t_matrix *dst);
float		matrix_det(t_matrix src);

// matrix.c
t_matrix	init_3d_rotate_matrix_x(float delta);
t_matrix	init_3d_rotate_matrix_y(float delta);
t_matrix	init_3d_rotate_matrix_z(float delta);
t_matrix	init_3d_zoom_matrix(float zoom);
t_matrix	init_inverse_3d_matrix(t_matrix src);

#endif
