#include"../../../src/editor/convolution/convolution.h"
#include"../../../src/input/input/input.h"
#include"../../../src/input/table/table.h"

/*
//	row_of_src_kernel_int
int	main(int len, char **str)
{
	char	err;
	int		dim;
	int		fd;
	int		i;
	int		j;
	double	**kernel;
	t_llist_fdf	*llist;
	t_table_fdf	*table;

	err = 'K';
	if (len < 5)
		return (0);
	dim = f_atoi(str[2], &err, "0123456789", f_strlen(str[2]));
	i = f_atoi(str[3], &err, "0123456789", f_strlen(str[3]));
	j = f_atoi(str[4], &err, "0123456789", f_strlen(str[4]));
	if (err == 'E' || dim <= 0)
	{
		write(1, "input is invalid.\n", 18);
		return (0);
	}
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	table = llist_to_table_fdf(llist);
	free_llist_fdf(llist);
	if (table == NULL)
		return (0);
	kernel = blur_kernel_2d(2 * dim + 1, (double)dim);
	if (kernel == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	row_of_src_kernel_int(table->arr[i], kernel[0], j, table->col);
	free_table_fdf(table);
	free_nest_arr((void **)kernel, 2 * dim + 1);
	return (0);
}
*/

/*
int	main(int len, char **str)
{
	char	err;
	int		dim;
	int		fd;
	int		i;
	int		j;
	double	**kernel;
	t_llist_fdf	*llist;
	t_table_fdf	*table;

	err = 'K';
	if (len < 5)
		return (0);
	dim = f_atoi(str[2], &err, "0123456789", f_strlen(str[2]));
	i = f_atoi(str[3], &err, "0123456789", f_strlen(str[3]));
	j = f_atoi(str[4], &err, "0123456789", f_strlen(str[4]));
	if (err == 'E' || dim <= 0)
	{
		write(1, "input is invalid.\n", 18);
		return (0);
	}
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	table = llist_to_table_fdf(llist);
	free_llist_fdf(llist);
	if (table == NULL)
		return (0);
	kernel = src_kernel_int(table, i, j, dim);
	free_table_fdf(table);
	if (kernel == NULL)
		return (0);
	free_nest_arr((void **)kernel, (size_t)dim * 2 + 1);
	return (0);
}
*/

/*
int	main(int len, char **str)
{
	char	err;
	int		dim;
	double	**kernel;

	err = 'K';
	if (len < 2)
		return (0);
	dim = f_atoi(str[1], &err, "0123456789", f_strlen(str[1]));
	if (err == 'E' || dim <= 0)
	{
		write(1, "input is invalid.\n", 18);
		return (0);
	}
	kernel = blur_kernel_2d((size_t)dim * 2 + 1, 1.0);
	if (kernel == NULL)
		return (0);
	free_nest_arr((void **)kernel, (size_t)dim * 2 + 1);
	return (0);
}
*/

int	main(int len, char **str)
{
	int			fd;
	t_llist_fdf	*llist;
	t_table_fdf	*table;
	t_table_fdf	*convolute;
	size_t		k_len;
	double		**kernel;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	table = llist_to_table_fdf(llist);
	free_llist_fdf(llist);
	if (table == NULL)
		return (0);
	positive_table_fdf(table);
	write(1, "\n*** Before ***\n", 16);
	write_table_fdf(1, table, 0, 3);
	k_len = 3;
	kernel = blur_kernel_2d(k_len, 1.0/(f_pow((double)k_len, 2)));
	// kernel = blur_kernel_2d(k_len, 0.0);
	if (kernel == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	// kernel[k_len/2][k_len/2] = 1.0;
	convolute = convolution_hight(table, kernel, k_len / 2);
	free_table_fdf(table);
	free_nest_arr((void **)kernel, k_len);
	if (convolute == NULL)
		return (0);
	write(1, "\n*** After ***\n", 15);
	write_table_fdf(1, convolute, 0, 3);
	free_table_fdf(convolute);
	return (0);
}

/*
int	main(int len, char **str)
{
	int			fd;
	t_llist_fdf	*llist;
	t_table_fdf	*table;
	t_table_fdf	*convolute;
	size_t		k_len;
	double		*kernel;
	double		*lernel;
	double		**kernel2;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	table = llist_to_table_fdf(llist);
	free_llist_fdf(llist);
	if (table == NULL)
		return (0);
	// scale_hadamard_fdf(table, 1);
	write(1, "\n*** Before ***\n", 16);
	write_table_fdf(1, table, 0, 1);
	k_len = 5;
	kernel = gaussian_kernel_1d(k_len / 2);
	if (kernel == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	lernel = gaussian_kernel_1d(k_len / 2);
	if (lernel == NULL)
	{
		free_table_fdf(table);
		free(kernel);
		return (0);
	}
	kernel2 = one_dim_to_two_dim(kernel, lernel, k_len / 2);
	free(kernel);
	free(lernel);
	if (kernel2 == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	convolute = convolution_hight(table, kernel2, k_len / 2);
	free_table_fdf(table);
	free_nest_arr((void **)kernel2, k_len);
	if (convolute == NULL)
		return (0);
	write(1, "\n*** After ***\n", 15);
	write_table_fdf(1, convolute, 0, 1);
	free_table_fdf(convolute);
	return (0);
}
*/

/*
int	main(int len, char **str)
{
	int			fd;
	t_llist_fdf	*llist;
	t_table_fdf	*table;
	t_table_fdf	*convolute;
	size_t		k_len;
	double		**kernel;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	table = llist_to_table_fdf(llist);
	free_llist_fdf(llist);
	if (table == NULL)
		return (0);
	write(1, "\n*** Before ***\n", 16);
	write_table_fdf(1, table, 0, 1);
	k_len = 3;
	kernel = blur_kernel_2d(k_len, 1.0/(f_pow((double)k_len, 2)));
	if (kernel == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	convolute = convolution_rgb(table, kernel, k_len / 2, 'b');
	free_table_fdf(table);
	free_nest_arr((void **)kernel, k_len);
	if (convolute == NULL)
		return (0);
	write(1, "\n*** After ***\n", 15);
	write_table_fdf(1, convolute, 1, 1);
	free_table_fdf(convolute);
	return (0);
}
*/

/*
int	main(int len, char **str)
{
	int			fd;
	t_llist_fdf	*llist;
	t_table_fdf	*table;
	t_table_fdf	*convolute;
	size_t		k_len;
	double		*kernel;
	double		*lernel;
	double		**kernel2;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	table = llist_to_table_fdf(llist);
	free_llist_fdf(llist);
	if (table == NULL)
		return (0);
	write(1, "\n*** Before ***\n", 16);
	write_table_fdf(1, table, 0, 1);
	k_len = 3;
	kernel = gaussian_kernel_1d(k_len / 2);
	if (kernel == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	lernel = gaussian_kernel_1d(k_len / 2);
	if (kernel == NULL)
	{
		free_table_fdf(table);
		free(kernel);
		return (0);
	}
	kernel2 = one_dim_to_two_dim(kernel, kernel, k_len / 2);
	free(kernel);
	free(lernel);
	if (kernel2 == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	convolute = convolution_rgb(table, kernel2, k_len / 2, 'g');
	free_table_fdf(table);
	free_nest_arr((void **)kernel2, k_len);
	if (convolute == NULL)
		return (0);
	write(1, "\n*** After ***\n", 15);
	write_table_fdf(1, convolute, 1, 1);
	free_table_fdf(convolute);
	return (0);
}
*/

/*
valgrind --leak-check=full ./test/bin/editor/convolution.out test/input/fdf/20-60.fdf
*/
