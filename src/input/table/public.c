#include"table_private.h"

/**
 * Load target file as t_table_fdf 5 rgba and height integer array data.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 * 
 * @param file_name the input file
 * @param dir the directory of the input file
 * @param one_line loading style, including parse_ascii_line_standard for
 * loading file as ASCII art, parse_fdf_line_rgba as colorful Fdf file etc.
 * @param is_rgba if is_rgba == true, then the program using malloc 
 * for initializing rgba color.
 * @see src/input/load/parse.c
 */
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
