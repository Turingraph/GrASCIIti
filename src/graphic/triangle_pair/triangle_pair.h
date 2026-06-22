#ifndef TRIANGLE_PAIR_H
# define TRIANGLE_PAIR_H

# include "../../utils/type/type.h"
# include "../../utils/libft/libft.h"
# include "../../input/table/table.h"
# include "../../utils/linalg/linalg.h"
# include "../../utils/math/math.h"

typedef enum e_side_shape e_side_shape;

enum e_side_shape
{
	SIDE_X,
	SIDE_Y,
	SIDE_LEFT,
	SIDE_RIGHT
};

// face.c
t_triangle_arr	f_fdf_face(t_table_fdf src, size_t row, size_t col, e_bool is_prism);

// init.c
void			*free_triangle(t_triangle *src);
void			*free_triangle_arr(t_triangle_arr *src);
t_triangle		init_triangle();
t_triangle_arr	init_triangle_arr(size_t length);
float			width_of_triangle(t_triangle src, size_t axis, e_bool is_greater);

// side.c
t_triangle_arr	f_fdf_side(t_table_fdf src, size_t row, size_t col, char axis);

// utils.c
char			fdf_side_detection(t_table_fdf src, size_t row, size_t col, char axis);
unsigned char	triangle_side_rgb(unsigned char **src, size_t row, size_t col, char mode);
unsigned char	triangle_face_rgb(t_table_fdf src, size_t row, size_t col, e_rgba rgb_type);

// write.c
void			write_3d_vector(int fd, float *vec_v);
void			write_triangle(int fd, t_triangle src);
void			write_triangle_arr(int fd, t_triangle_arr src);
void			write_triangle_arr_meta(int fd, t_triangle_arr src);

#endif
