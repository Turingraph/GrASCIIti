#include"view_table.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient(void)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 1;
	dst.input_end = 100;
	dst.rgba_start.r = 42;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 72;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 255;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_table_fdf	table;
	t_rgba		background = {.r = 242, .g = 230, .b = 216, .a = 255};

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	color_cells_gradient(&table, init_gradient(), true, NULL);
	paint_table_background(&table, background);
	view_table_fdf(&table);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/view/view_fdf.out input_examples/fdf/42.fdf

*/