#include"convolve.h"

int	main(int len, char **str)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	t_matrix	kernel;
	size_t		half_dim;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	half_dim = 2;
	table_a = open_table_fdf_file(str[1], NULL, parse_fdf_line_rgba, true);
	table_b = scale_dimension_fdf((const t_table_fdf *)&table_a, 1, 1);
	free_table_fdf(&table_a);
	kernel = gaussian_kernel(half_dim, 0.4, 0.5);
	table_a = convolve_rgba(&table_b, kernel, GREEN);
	write_table_ascii_cheche01(output, &table_a, GREEN);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	free_matrix(&kernel);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/bin/editor/convolve/gauss_rgb.out input_examples/fdf/t1.fdf input_examples/modified/t1_green.txt

*/
