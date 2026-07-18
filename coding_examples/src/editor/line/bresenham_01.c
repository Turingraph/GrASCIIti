#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_line		line;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	line.col = table.col;
	line.row = table.row;
	line.x1 = 2;
	line.x2 = 9;
	line.y1 = 3;
	line.y2 = 4;
	bresenham_line_int(table.arr, line);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/line/bresenham_01.out input_examples/font/isometric2/a.txt input_examples/modified/isometric2_with_line.txt
*/
