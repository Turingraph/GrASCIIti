#include"../../../src/graphic/triangle_arr/triangle_arr.h"
#include"../../../src/input/load/load.h"

int	main(int len, char **str)
{
	t_triangle_arr	output;
	t_load_fdf_arr	data;
	t_table_fdf		table;
	int				fd;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	data = load_all_fdf_lines(fd, one_fdf_line);
	if (data.arr == NULL)
		return (0);
	table = load_table_fdf(data, 1);
	free_load_fdf_arr(&data);
	if (table.arr == NULL)
		return (0);
	output = table_to_prism(table, 30, 1);
	update_width_of_triangle_arr(&output, 0);
	update_width_of_triangle_arr(&output, 1);
	update_width_of_triangle_arr(&output, 2);
	center_triangle_arr(&output, 0);
	free_table_fdf(&table);
	write(1, "*** output.arr ***\n", 20);
	write_triangle_arr(1, output);
	write(1, "*** meta data ***\n", 19);
	write_triangle_arr_meta(1, output);
	free_triangle_arr(&output);
	return (0);
}

/*
make test/bin/graphic/triangle_arr.out
valgrind --leak-check=full ./test/bin/graphic/triangle_arr.out
valgrind --leak-check=full ./test/bin/graphic/triangle_arr.out test/input/fdf/julia.fdf

*** meta data ***
src.length = 736
src.capacity = 736
src.width_x = 16
src.width_y = 23
src.width_z = 8

leak
1.	10-2.fdf
2.	convolution_9.fdf
3.	julia.fdf
4.	pentenegpos.fdf
5.	plat.fdf
6.	pnp_flat.fdf
7.	prism_pyramid.fdf
8.	pyra.fdf
9.	pyramid.fdf

*/
