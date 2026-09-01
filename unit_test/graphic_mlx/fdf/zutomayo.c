#include"fdf.h"

// time : O(1)
// space: O(1)
t_gradient	init_blue_period()
{
	t_gradient	dst;

	dst.cell_channel = D7_RED;
	dst.input_start = 66 * 3 / 2;
	dst.input_end = 86 * 3 / 2;
	dst.rgba_start.r = 70;
	dst.rgba_start.g = 75;
	dst.rgba_start.b = 113;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 124;
	dst.rgba_end.g = 213;
	dst.rgba_end.b = 199;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_white_noise()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 0;
	dst.rgba_start.r = 0;
	dst.rgba_start.g = 0;
	dst.rgba_start.b = 0;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 0;
	dst.rgba_end.g = 0;
	dst.rgba_end.b = 0;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_truth_in_a_lie()
{
	t_gradient	dst;

	dst.cell_channel = D7_RED;
	dst.input_start = 66 * 3 / 2;
	dst.input_end = 86 * 3 / 2;
	dst.rgba_start.r = 72;
	dst.rgba_start.g = 33;
	dst.rgba_start.b = 86;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 114;
	dst.rgba_end.g = 40;
	dst.rgba_end.b = 70;
	dst.rgba_end.a = 255;
	return (dst);
}

// time : O(1)
// space: O(1)
t_gradient	init_ztmy_studyme()
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = 0;
	dst.input_end = 200;
	dst.rgba_start.r = 66;
	dst.rgba_start.g = 54;
	dst.rgba_start.b = 118;
	dst.rgba_start.a = 255;
	dst.rgba_end.r = 204;
	dst.rgba_end.g = 131;
	dst.rgba_end.b = 240;
	dst.rgba_end.a = 255;
	return (dst);
}

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_ink32			style;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	style.color = 0;
	style.thickness = 1;
	style.type = E_LINE;
	scale_multiplication_fdf(&table, 10.0, HEIGHT);
	color_cells_gradient(&table, init_ztmy_studyme(), true);
	color_cells_gradient(&table, init_ztmy_truth_in_a_lie(), true);
	scale_multiplication_fdf(&table, 1.0 / 30.0, HEIGHT);
	color_cells_gradient(&table, init_white_noise(), true);
	output = init_fdf(&table);
	view_fdf(&output, style, f_rgba_to_int32(0, 0, 0, 255), true);
	free_fdf(&output);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/graphic_mlx/fdf/zutomayo.out unit_test/editor/convolve/input_ascii/zutomayo_isometric2.txt

*/
