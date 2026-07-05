#include"paint.h"

// time : O(1)
// space: O(1)
t_gradient	init_gradient(const t_table_fdf *src)
{
	t_gradient	dst;

	dst.cell_channel = D7_HEIGHT;
	dst.start_value = scale_positive_fdf(src, FALSE, TRUE);
	dst.end_value = scale_positive_fdf(src, FALSE, FALSE);
	dst.start_rgb.r = 245;
	dst.start_rgb.g = 51;
	dst.start_rgb.b = 169;
	dst.start_rgb.a = 155;
	dst.end_rgb.r = 187;
	dst.end_rgb.g = 121;
	dst.end_rgb.b = 85;
	dst.end_rgb.a = 131;
	return (dst);
}

int	main(int len, char **str)
{
	t_gradient	gradient;
	t_table_fdf	table;
	double		**kernel;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, cheche01_ascii_line, TRUE);
	gradient = init_gradient(&table);
	color_cells_gradient(&table, gradient, TRUE, is_collatz_coloring);
	write_table_fdf(output, &table, 1, FDF42);
	free_table_fdf(&table);
	return (0);
}
