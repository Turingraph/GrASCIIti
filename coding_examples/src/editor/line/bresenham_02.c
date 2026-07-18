#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_line		line;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	line.col = table.col;
	line.row = table.row;
	line.x1 = 2;
	line.x2 = 9;
	line.y1 = 3;
	line.y2 = 4;
	bresenham_line_uchar(table.r, line);
	bresenham_line_int(table.arr, line);
	write_table_fdf(output, &table, 2, HEIGHT_RGB);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/line/bresenham_02.out input_examples/fdf/t1.txt input_examples/modified/t1_with_line.fdf
*/
