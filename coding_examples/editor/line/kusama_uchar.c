#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	t_circle	circle = {.x = 0, .y = 7, .radius = 2};
	t_2d_int	tiling = {.x = 10, .y = 10};
	t_ink		ink = {.channel = HEIGHT, .thickness = 0, .color = 30};

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(49, 101, true);
	draw_kusama_circle(&table, circle, ink, tiling);
	ink.channel = BLUE;
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