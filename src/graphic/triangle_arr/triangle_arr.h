#ifndef TRIANGLE_ARR_H
# define TRIANGLE_ARR_H

# include "../triangle_pair/triangle_pair.h"

// all_faces.c
t_triangle_arr	all_triangle_faces(t_table_fdf src, char prism);
t_triangle_arr	all_triangle_side_xy(t_table_fdf src, char axis);
t_triangle_arr	all_triangle_side_lr(t_table_fdf src, char axis);

// center.c
float			update_width_of_triangle_arr(t_triangle_arr *src, size_t axis);
float			center_triangle_arr(t_triangle_arr *src, size_t axis);
float			average_triangle_arr(t_triangle_arr *src, size_t axis, char update);

// concat.c
t_triangle_arr	copy_triangle_arr(t_triangle_arr *src, size_t length);
t_triangle_arr	clone_triangle_arr(t_triangle_arr *src, size_t length);
t_triangle_arr	concat_triangle_arr(t_triangle_arr *dst, t_triangle_arr *src);

// prism.c
t_triangle_arr	table_to_prism(t_table_fdf src, float width, char janus);

// scale.c
void			hadamard_triangle_arr(t_triangle_arr *src, float scale, size_t axis);
void			shift_triangle_arr(t_triangle_arr *src, float shift, size_t axis);
void			setback_triangle_arr(t_triangle_arr *src, float shift, size_t axis);
void			setwidth_triangle_arr(t_triangle_arr *src, float shift, size_t axis);

#endif
