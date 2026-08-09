#include"line.h"

/*
How to draw islamic art?
*	https://youtu.be/pg1NpMmPv48?si=6bSQGdhU3TX-6IcR
*/

int	main(int len, char **str)
{
	t_table_fdf		table;
	int				output;
	t_line			tiling;
	t_ink			ink;
	t_2d_polygon	polygon;
	t_complex		arr[] = {
		{.re = 0, .im = 0},
		{.re = 1, .im = 0},
		{.re = 1, .im = 3 / 4},
	};

	polygon.is_loop = true;
	polygon.length = 3;
	polygon.arr = arr;
	ink.channel = HEIGHT;
	ink.color = 10;
	ink.thickness = 5;
	tiling.p1.x = 0;
	tiling.p1.y = 0;
	tiling.p1.x = 101;
	tiling.p1.y = 49;
	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	draw_polygon(&table, &polygon, ink, tiling);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/pythagorus.out input_examples/line/pythagorus.txt
*/
