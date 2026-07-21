#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_circle	circle;
	t_2d_int	tiling;
	t_ink		ink;

	ink.channel = HEIGHT;
	ink.thickness = 0;
	ink.color = 30;
	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, true);
	tiling.x = 10;
	tiling.y = 10;
	circle.x = 0;
	circle.y = 5;
	circle.radius = 2;
	draw_kusama_circle(&table, circle, ink, tiling);
	ink.channel = BLUE;
	tiling.x = 10;
	tiling.y = 10;
	circle.x = 6;
	circle.y = 7;
	ink.color = 50;
	circle.radius = 1;
	draw_kusama_circle(&table, circle, ink, tiling);
	write_table_fdf(output, &table, 2, HEIGHT_RGB);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/kusama_uchar.out input_examples/line/kusama_art_uchar.fdf

*/