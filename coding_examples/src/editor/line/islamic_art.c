#include"line.h"

/*
How to draw islamic art?
*	https://youtu.be/pg1NpMmPv48?si=6bSQGdhU3TX-6IcR
*/

int	main(int len, char **str)
{
	float			cx = 0.5;
	float			cy = 0.5;
	t_table_fdf		table;
	int				output;
	t_2d_int		tiling;
	t_ink			ink;
	t_2d_polygon	polygon;
	t_2d_polygon	polygon_1;
	t_2d_polygon	polygon_2;
	t_complex		arr[] = {
		{.re = f_cos((1 / 4) * 3.1415) / 2 + cx, .im = f_sin(3.1415 / 4 * 1.) / 2 + cy},
		{.re = f_cos((1 / 4) * 3.1415) / 2 + cx, .im = f_sin(3.1415 / 4 * -1) / 2 + cy},
		{.re = f_cos((3 / 4) * 3.1415) / 2 + cx, .im = f_sin(3.1415 / 4 * 1.) / 2 + cy},
		{.re = f_cos((3 / 4) * 3.1415) / 2 + cx, .im = f_sin(3.1415 / 4 * -1) / 2 + cy},
	};
	t_complex		arr_1[] = {
		{.re = f_cos((1 / 4) * 3.1415) / 2 + cx, .im = f_sin(3.1415 / 4 * -1) / 2 + cy},
		{.re = cx, .im = cy + 1},
		{.re = f_cos((3 / 4) * 3.1415) / 2 + cx, .im = f_sin(3.1415 / 4 * -1) / 2 + cy},
	};
	t_complex		arr_2[] = {
		{.re = f_cos((1 / 4) * 3.1415) / 2 + cx, .im = f_sin(3.1415 / 4 * 1.) / 2 + cy},
		{.re = cx, .im = cy - 1},
		{.re = f_cos((3 / 4) * 3.1415) / 2 + cx, .im = f_sin(3.1415 / 4 * 1.) / 2 + cy},
	};

	polygon.is_loop = true;
	polygon.length = 4;
	polygon.arr = arr;
	polygon_1.is_loop = true;
	polygon_1.length = 3;
	polygon_1.arr = arr_1;
	polygon_2.is_loop = true;
	polygon_2.length = 3;
	polygon_2.arr = arr_2;
	ink.channel = HEIGHT;
	ink.color = 10;
	ink.thickness = 5;
	ink.thickness = 0;
	tiling.x = 10;
	tiling.y = 10;
	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, false);
	draw_square_tiling(&table, &polygon, ink, tiling);
	ink.thickness = 3;
	ink.color = 50;
	draw_square_tiling(&table, &polygon_1, ink, tiling);
	draw_square_tiling(&table, &polygon_2, ink, tiling);
	write_table_ascii_cheche01(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/islamic_art.out input_examples/line/islamic_art.txt
*/
