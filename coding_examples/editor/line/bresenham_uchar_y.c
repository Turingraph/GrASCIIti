#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_line		line;
	t_boundary	boundary;

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(30, 30, true);
	// table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	boundary.all_area.x = table.col;
	boundary.all_area.y = table.row;
	boundary.sub_area.p1.x = 0;
	boundary.sub_area.p1.y = 0;
	boundary.sub_area.p2.x = table.col;
	boundary.sub_area.p2.y = table.row;
	line.p1.x = 7;
	line.p1.y = 3;
	line.p2.x = 3;
	line.p2.y = 15;
	bresenham_uchar_y(table.r, line, boundary, 42);
	// bresenham_int_x_thick(table.arr, line, boundary, ink);
	write_table_ascii_cheche01(output, &table, RED);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/bresenham_uchar_y.out input_examples/line/line_int_y.txt
*/
