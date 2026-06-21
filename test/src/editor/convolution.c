#include"../../../src/editor/convolution/convolution.h"
#include"../../../src/input/load/load.h"

int	main(int len, char **str)
{
	t_load_fdf_arr	data;
	t_table_fdf		table;
	t_table_fdf		blur;
	int				fd;
	double			*vec;
	double			**ker;
	size_t			half_dim;

	half_dim = 2;
	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	vec = gaussian_kernel_1d(half_dim);
	if (vec == NULL)
		return (0);
	ker = outer_product_kernel(vec, vec, 2 * half_dim + 1);
	free(vec);
	if (ker == NULL)
		return (0);
	data = load_all_fdf_lines(fd, one_fdf_line);
	if (data.arr == NULL)
	{
		free_2d_arr((void **)ker, 2 * half_dim + 1);
		free_load_fdf_arr(&data);
		return (0);
	}
	table = load_table_fdf(data, 1);
	free_load_fdf_arr(&data);
	scale_positive_fdf(&table, 1);
	blur = convolution_hight(table, ker, half_dim);
	free_2d_arr((void **)ker, 2 * half_dim + 1);
	free_table_fdf(&table);
	if (blur.arr == NULL)
		return (0);
	write_table_fdf(1, blur, 0, 1);
	free_table_fdf(&blur);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/editor/convolution.out test/input/fdf/julia.fdf
time: 33 seconds
*/
