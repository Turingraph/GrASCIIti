#include"triangle_pair.h"

int	main(int len, char **str)
{
	t_table_fdf		table;
	int				row;
	int				col;
	bool			is_int;
	t_triangle_arr	output;

	if (len < 4)
		return (0);
	is_int = true;
	row = f_atoi(str[3], &is_int, "0123456789", f_strlen(str[3]));
	col = f_atoi(str[2], &is_int, "0123456789", f_strlen(str[2]));
	if (is_int == false)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	if (table.arr == NULL)
		return (0);
	row = (int)f_interval((float)row, 0.0, (float)(table.row - 1));
	col = (int)f_interval((float)col, 0.0, (float)(table.col - 1));
	write_triangle_pair_geometry(&table, (size_t)row);
	output = f_fdf_edge((const t_table_fdf *)&table, row, EDGE_DIAGONAL_LEFT);
	free_table_fdf(&table);
	write_triangle_arr(1, (const t_triangle_arr *)&output);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&output);
	free_triangle_arr(&output);
	return (0);
}
