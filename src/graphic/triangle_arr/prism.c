#include"triangle_arr.h"

// time : O(n)
// space: O(n)
t_triangle_arr	*front_table_to_prism(t_table_fdf *src)
{
	t_triangle_arr	*dst;
	t_triangle_arr	*sides;

	if (src->row == 1)
		return (all_sides_triangles_x(src));
	if (src->col == 1)
		return (all_sides_triangles_y(src));
	dst = all_faces_triangles(src, 1);
	if (dst == NULL)
		return (NULL);
	sides = all_sides_triangles_xy(src);
	if (concat_triangle_arr(&dst, sides) == NULL)
		return (NULL);
	sides = all_sides_triangles_x(src);
	if (concat_triangle_arr(&dst, sides) == NULL)
		return (NULL);
	sides = all_sides_triangles_y(src);
	if (concat_triangle_arr(&dst, sides) == NULL)
		return (NULL);
	return (dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	*table_to_prism(t_table_fdf *src, unsigned int width)
{
	t_triangle_arr	*dst;
	t_triangle_arr	*truncate_dst;
	t_triangle_arr	*backroom;

	dst = front_table_to_prism(src);
	if (dst == NULL)
		return (NULL);
	width = (min_and_max_triangle(dst, 2, 1) + (long)width) / 2;
	set_width_triangle_arr(dst, width, 2);
	backroom = clone_triangle_arr(dst, dst->length);
	set_base_triangle_arr(backroom, -1 * ((double) width), 2);
	if (concat_triangle_arr(&dst, backroom) == NULL)
		return (NULL);
	truncate_dst = truncate_triangle_arr(dst, dst->lenght);
	return (truncate_dst);
}

// time : O(n)
// space: O(n)
t_triangle_arr	*table_to_double_faces(t_table_fdf *src, unsigned int width)
{
	t_triangle_arr	*dst;
	t_triangle_arr	*truncate_dst;
	t_triangle_arr	*backroom;

	dst = front_table_to_prism(src);
	if (dst == NULL)
		return (NULL);
	set_width_triangle_arr(dst, width, 2);
	backroom = clone_triangle_arr(dst, dst->length);
	set_width_triangle_arr(backroom, width, 2);
	scale_triangle_arr(backroom, -1.0, 2);
	if (concat_triangle_arr(&dst, backroom) == NULL)
		return (NULL);
	truncate_dst = truncate_triangle_arr(dst, dst->lenght);
	return (truncate_dst);
}
