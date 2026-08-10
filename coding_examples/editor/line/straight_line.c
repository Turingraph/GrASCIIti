#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_line		line;
	t_line		boundary;
	t_ink		ink;

	ink.channel = HEIGHT;
	ink.color = 10;
	ink.thickness = 8;
	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	// table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, false);
	boundary.p1.x = 3;
	boundary.p1.y = 3;
	boundary.p2.x = 49;
	boundary.p2.y = 49;
	line.p1.x = 10;
	line.p1.y = 10;
	line.p2.x = 25;
	line.p2.y = 25;
	draw_straight_line(&table, line, boundary, ink);
	ink.thickness = 3;
	ink.color = 42;
	draw_straight_line(&table, line, boundary, ink);
	ink.thickness = 1;
	ink.color = 100;
	draw_straight_line(&table, line, boundary, ink);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/straight_line.out input_examples/line/straight_line.txt
*/
