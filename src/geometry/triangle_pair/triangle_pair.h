#ifndef TRIANGLE_PAIR_H
# define TRIANGLE_PAIR_H

# include "../../utils/libft/libft.h"
# include "../../utils/linalg/linalg.h"

typedef enum e_edge e_edge;

enum e_edge
{
	EDGE_X,
	EDGE_Y,
	EDGE_DIAGONAL_LEFT,
	EDGE_DIAGONAL_RIGHT,
	EDGE_INVALID
};

typedef enum e_3d_shape e_3d_shape;

enum e_3d_shape
{
	ISOMETRIC,
	PRISM_MODE2,
	PRISM_CROSS
};

// color.c
void			average_tri_coloring(const t_table_fdf *src, size_t row, size_t col, t_triangle *dst);
void			topleft_tri_coloring(const t_table_fdf *src, size_t row, size_t col, t_triangle *dst);
void			edge_average_tri_coloring(const unsigned char **src, t_triangle_arr *dst, e_rgba rgb_type);

// edge.c
t_triangle_arr	f_fdf_edge(const t_table_fdf *src, size_t row, size_t col, e_edge mode);

// face.c
t_triangle_arr	f_fdf_face(const t_table_fdf *src, size_t row, size_t col, e_3d_shape shape);

// init.c
void			*free_triangle(t_triangle *src);
void			*free_triangle_arr(t_triangle_arr *src);
t_triangle		init_triangle(void);
t_triangle_arr	init_triangle_arr(size_t length, size_t row, size_t col);
float			width_of_triangle(const t_triangle *src, size_t axis, e_bool is_greater);

// write.c
void			write_3d_vector(int fd, const float *vec_v);
void			write_triangle(int fd, const t_triangle *src);
void			write_triangle_arr(int fd, const t_triangle_arr *src);
void			write_triangle_arr_meta(int fd, const t_triangle_arr *src);

#endif
