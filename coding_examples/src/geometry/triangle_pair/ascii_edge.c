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
	row = f_atoi(str[2], &is_int, "0123456789", f_strlen(str[2]));
	col = f_atoi(str[3], &is_int, "0123456789", f_strlen(str[3]));
	if (is_int == false)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	if (table.arr == NULL)
		return (0);
	row = (int)f_interval((float)row, 0.0, (float)(table.row - 1));
	col = (int)f_interval((float)col, 0.0, (float)(table.col - 1));
	write_2d_index(table.col, row, col);
	row = row * table.col + col;
	write_triangle_pair_geometry(&table, (size_t)row);
	output = f_fdf_edge((const t_table_fdf *)&table, row, EDGE_X);
	free_table_fdf(&table);
	write_triangle_arr(1, (const t_triangle_arr *)&output);
	write_triangle_arr_meta(1, (const t_triangle_arr *)&output);
	free_triangle_arr(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/geometry/triangle_pair/ascii_edge.out input_examples/mathart_gen/cube_x

valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/geometry/triangle_pair/ascii_edge.out input_examples/mathart_gradient/rozzo_a_404.txt 11 0
*/