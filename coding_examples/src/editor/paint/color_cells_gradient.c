#include"paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient(t_table_fdf *src)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.input_start = get_minmax_from_table_fdf(src, false, HEIGHT);
	dst.input_end = get_minmax_from_table_fdf(src, true, HEIGHT);
	dst.rgba_start.r = 245;
	dst.rgba_start.g = 51;
	dst.rgba_start.b = 169;
	dst.rgba_start.a = 155;
	dst.rgba_end.r = 187;
	dst.rgba_end.g = 121;
	dst.rgba_end.b = 85;
	dst.rgba_end.a = 131;
	return (dst);
}

int	main(int len, char **str)
{
	t_gradient	gradient;
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	gradient = init_gradient(&table);
	color_cells_gradient(&table, gradient, true, is_collatz_coloring);
	write_table_fdf(output, &table, 1, HEIGHT_ONLY);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all
./coding_examples/bin/editor/paint/color_cells_gradient.out
input_examples/font/rozzo/ampersand.txt
output_examples/paint/rozzo_ampersand.txt
*/
