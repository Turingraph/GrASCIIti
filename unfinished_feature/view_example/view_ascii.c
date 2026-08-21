#include"view.h"

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
	int32_t	background = f_rgba_to_int32(123, 155, 244, 255);

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	color_cells_gradient(&table, init_gradient(), true, NULL);
	view_pixel_art(&table, background);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/view/view_ascii.out input_examples/view/zutomayo_isometric2.txt

*/

