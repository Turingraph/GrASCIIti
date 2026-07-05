#include"convolution.h"

int	main(int len, char **str)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	double		**kernel;
	size_t		half_dim;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	half_dim = 3;
	table_a = open_table_fdf_file(str[1], NULL, rgba_fdf_line, TRUE);
	table_b = scale_dimension_fdf(table_a, 3, 3);
	free_table_fdf(&table_a);
	kernel = gaussian_kernel_2d(half_dim);
	table_a = convolution_rgb(&table_b, kernel, half_dim, RED);
	write_table_fdf(output, &table_a, 1, FDF42);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	free_2d_arr((void **)kernel, 2 * half_dim + 1);
	return (0);
}

