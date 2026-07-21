#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_line		line;
	t_boundary	boundary;
	t_ink		ink;

	ink.channel = HEIGHT;
	ink.color = 10;
	ink.thickness = 4;
	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(40, 30, false);
	// table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	boundary.all_area.x = table.col;
	boundary.all_area.y = table.row;
	boundary.sub_area.p1.x = 0;
	boundary.sub_area.p1.y = 0;
	boundary.sub_area.p2.x = table.col;
	boundary.sub_area.p2.y = table.row;
	line.p1.x = 2;
	line.p1.y = 13;
	line.p2.x = 28;
	line.p2.y = 20;
	bresenham_int_x_thick(table.arr, line, boundary, ink);
	ink.color = 50;
	ink.thickness = 1;
	bresenham_int_x_thick(table.arr, line, boundary, ink);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/bresenham_int_x_thick.out input_examples/line/bresenham_int_x_thick.txt
*/
