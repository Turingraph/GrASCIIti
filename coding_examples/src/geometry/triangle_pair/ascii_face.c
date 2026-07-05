#include"triangle_pair.h"

int	main(int len, char **str)
{
	t_table_fdf		table;
	int				row;
	int				col;
	e_bool			is_int;
	t_triangle_arr	output;

	if (len < 4)
		return (0);
	is_int = TRUE;
	row = f_atoi(str[3], &is_int, "0123456789", f_strlen(str[3]));
	col = f_atoi(str[2], &is_int, "0123456789", f_strlen(str[2]));
	if (is_int == FALSE)
		return (0);
	table = open_table_fdf_file(str[1], NULL, cheche01_ascii_line, FALSE);
	if (table.arr == NULL)
		return (0);
	row = (int)f_interval((float)row, 0.0, (float)(table.row - 1));
	col = (int)f_interval((float)col, 0.0, (float)(table.col - 1));
	write_triangle_pair_geometry(&table, (size_t)row, (size_t)col);
	output = f_fdf_face(table, row, col, PRISM_CROSS);
	free_table_fdf(&table);
	write_triangle_arr(1, output);
	write_triangle_arr_meta(1, output);
	free_triangle_arr(&output);
	return (0);
}
