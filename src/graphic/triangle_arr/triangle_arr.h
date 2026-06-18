#ifndef TRIANGLE_ARR_H
# define TRIANGLE_ARR_H

# include "../triangle_pair/triangle_pair.h"

// all_faces.c
t_triangle_arr	*all_faces_triangles(t_table_fdf *src, char prism);
t_triangle_arr	*all_sides_triangles_non_xy(t_table_fdf *src);
t_triangle_arr	*all_sides_triangles_x(t_table_fdf *src);
t_triangle_arr	*all_sides_triangles_y(t_table_fdf *src);

// concet_tri.c
t_triangle_arr	*truncate_triangle_arr(t_triangle_arr *src, size_t len);
t_triangle_arr	*concat_triangle_arr(t_triangle_arr **update_arr, t_triangle_arr *arr);
t_triangle_arr	*clone_triangle_arr(t_triangle_arr *src, size_t len);

// prism.c
t_triangle_arr	*table_to_prism(t_table_fdf *src, unsigned int width);
t_triangle_arr	*table_to_double_faces(t_table_fdf *src, unsigned int width);

// scale.c
void			scale_triangle_arr(t_triangle_arr *src, double scale, size_t axis);
void			shift_triangle_arr(t_triangle_arr *src, double shift, size_t axis);
void			set_base_triangle_arr(t_triangle_arr *src, double base, size_t axis);
void			set_width_triangle_arr(t_triangle_arr *src, double width, size_t axis);
void			min_and_max_triangle(t_triangle_arr *src, size_t axis, char mode);

#endif
