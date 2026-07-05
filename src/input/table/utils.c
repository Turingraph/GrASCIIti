#include"table.h"

// time : O(1)
// space: O(1)
void	set_table_fdf_origin(t_table_fdf *dst, e_axis direction, size_t ith_position, size_t max_position)
{
	if (direction == AXIS_X && dst != NULL && ith_position <= max_position && max_position <= dst->col)
		dst->origin_x = (dst->col / max_position) * ith_position;
	if (direction == AXIS_Y && dst != NULL && ith_position <= max_position && max_position <= dst->col)
		dst->origin_y = (dst->row / max_position) * ith_position;
}

// options for one_line
// 1.	cheche01_ascii_line(const char *line) (from txt files)
// 2.	standard_ascii_line(const char *line) (from txt files)
// 3.	chungaloider_ascii_line(const char *line) (from txt files)
// 4.	bw_fdf_line(const char *line) (from fdf files)
// 5.	rgba_fdf_line(const char *line) (the only option that load rgb color from fdf files)
// time : O(n)
// space: O(n)
t_table_fdf	open_table_fdf_file(const char *file_name, const char *dir,
	t_load_fdf (*one_line)(char *line), e_bool is_rgb)
{
	t_table_fdf		dst;
	t_load_fdf_arr	src;

	src = open_fdf_file(file_name, dir, one_line);
	dst = load_table_fdf(&src, is_rgb);
	free_load_fdf_arr(&src);
	return (dst);
}

