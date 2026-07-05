#include"triangle_arr.h"

int	main(int len, char **str)
{
	t_triangle_arr	output;
	t_table_fdf		table;
	int				fd;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, cheche01_ascii_line, FALSE);
	output = all_triangle_faces(&table, ISOMETRIC);
	update_width_of_triangle_arr(&output, 0);
	update_width_of_triangle_arr(&output, 1);
	update_width_of_triangle_arr(&output, 2);
	center_triangle_arr(&output, 0);
	free_table_fdf(&table);
	write(1, "*** output.arr ***\n", 20);
	write_triangle_arr(1, output);
	write(1, "*** meta data ***\n", 19);
	write_triangle_arr_meta(1, output);
	free_triangle_arr(&output);
	return (0);
}
