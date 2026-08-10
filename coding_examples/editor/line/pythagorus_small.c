#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf		table;
	int				output;
	t_line			rectangle_boundary;
	t_ink			ink;
	t_2d_polygon	polygon;
	t_complex		arr[] = {
		{.re = 0, .im = 0},
		{.re = 1, .im = 0},
		{.re = 1, .im = 3.0f / 4.0f},
	};

	polygon.is_loop = true;
	polygon.length = 3;
	polygon.arr = arr;
	ink.channel = HEIGHT;
	ink.color = 10;
	ink.thickness = 6;
	rectangle_boundary.p1.x = 3;
	rectangle_boundary.p1.y = 3;
	rectangle_boundary.p2.x = 30;
	rectangle_boundary.p2.y = 30;
	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	draw_polygon(&table, &polygon, ink, rectangle_boundary);
	ink.color = 100;
	ink.thickness = 1;
	draw_polygon(&table, &polygon, ink, rectangle_boundary);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/pythagorus_small.out input_examples/line/pythagorus_small.txt
*/
