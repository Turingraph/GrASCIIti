#include"triangle_arr.h"

int	main(int len, char **str)
{
	t_triangle_arr	output;
	t_table_fdf		table;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	output = table_to_prism((const t_table_fdf *)&table, 30, true, PRISM_CROSS);
	update_width_of_triangle_arr(&output, 0);
	update_width_of_triangle_arr(&output, 1);
	update_width_of_triangle_arr(&output, 2);
	center_triangle_arr(&output, 0);
	free_table_fdf(&table);
	write(1, "*** output.arr ***\n", 20);
	write_triangle_arr(1, (const t_triangle_arr *)&output);
	write(1, "*** meta data ***\n", 19);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&output);
	free_triangle_arr(&output);
	return (0);
}
