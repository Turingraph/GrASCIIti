#ifndef TRIANGLE_PAIR_H
# define TRIANGLE_PAIR_H

# include "../../utils/type/type.h"
# include "../../utils/libft/libft.h"
# include "../../utils/math/math.h"

// face.c
t_triangle_arr	f_fdf_face(t_table_fdf src, size_t row, size_t col, char prism);

// init.c
void			free_triangle(t_triangle src);
void			free_triangle_arr(t_triangle_arr src);
t_triangle		init_triangle();
t_triangle_arr	init_triangle_arr(size_t length);
char			fdf_side_detection(t_table_fdf src, size_t row, size_t col, char axis);

// side.c
t_triangle_arr	f_fdf_side(t_table_fdf src, size_t row, size_t col, char axis);

// write_triangle.c
void			write_3d_vector(int fd, double *vec_v);
void			write_triangle(int fd, t_triangle src);
void			write_triangle_arr(int fd, t_triangle_arr src);

#endif
