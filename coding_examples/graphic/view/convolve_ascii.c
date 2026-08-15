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
	t_rgba		background = {.r = 242, .g = 230, .b = 216, .a = 255};
	t_rgba		target_channels = {.r = 1, .g = 0, .b = 0, .a = 0};
	t_matrix	kernel;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	color_cells_gradient(&table, init_gradient(), true, NULL);
	paint_table_background(&table, background);
	kernel = gaussian_kernel(20, 1, 1);
	view_convolve_table_fdf(&table, target_channels, kernel);
	free_table_fdf(&table);
	free_matrix(&kernel);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/graphic/view/convolve_ascii.out input_examples/view/islamic_gauss.txt

*/

