#include"line.h"

/*
To Do Now
1.	fix polygon
2.	fix draw_islamic_square_tiling
3.	fix triangle
4.	separate src as src and viewer, and coding_examples as coding_examples and integration_test

How to draw islamic art?
*	https://youtu.be/pg1NpMmPv48?si=6bSQGdhU3TX-6IcR
*/

int	main(int len, char **str)
{
	t_table_fdf		table;
	int				output;
	t_line			boundary;
	t_ink			ink;
	t_complex		arr[] = {
		{.re = 0, .im = 0},
		{.re = 1, .im = 0},
		{.re = 1, .im = 1},
		{.re = 0, .im = 1},
	};
	t_2d_polygon	polygon;

	polygon.length = 4;
	polygon.is_loop = false;
	polygon.arr = arr;
	ink.channel = HEIGHT;
	ink.color = 10;
	ink.thickness = 8;
	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	boundary.p1.x = 0;
	boundary.p1.y = 0;
	boundary.p2.x = table.col;
	boundary.p2.y = table.row;
	draw_polygon(&table, &polygon, ink, boundary);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/rectangle.out input_examples/line/rectangle.txt
*/
