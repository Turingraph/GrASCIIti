#include"table_private.h"

// options for one_line
// 1.	cheche01_ascii_line(char *line) (from txt files)
// 2.	standard_ascii_line(char *line) (from txt files)
// 3.	chungaloider_ascii_line(char *line) (from txt files)
// 4.	bw_fdf_line(char *line) (from fdf files)
// 5.	rgba_fdf_line(char *line) (the only option that load rgb color from fdf files)
// time : O(n)
// space: O(n)
t_table_fdf	open_table_fdf_file(const char *file_name, const char *dir,
	t_load_fdf (*one_line)(char *line), bool is_rgba)
{
	t_table_fdf		dst;
	t_load_fdf_arr	src;

	src = open_fdf_file(file_name, dir, one_line);
	dst = load_table_fdf(&src, is_rgba);
	free_load_fdf_arr(&src);
	return (dst);
}
