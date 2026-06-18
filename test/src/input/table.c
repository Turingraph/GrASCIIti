#include "../../../src/input/load/load.h"
#include "../../../src/input/table/table.h"

int	main(int len, char **str)
{
	t_load_fdf_arr	data;
	t_table_fdf		table;
	t_table_fdf		table2;
	int				fd;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	data = load_all_fdf_lines(fd, cheche_one_ascii_line);
	if (data.arr == NULL)
		return (0);
	write(1, "*** DATA ***\n", 14);
	write_load_fdf_arr(1, data, 3, 0);
	table = load_table_fdf(data, 1);
	free_load_fdf_arr(data);
	if (table.arr == NULL)
		return (0);
	write(1, "*** TABLE ***\n", 15);
	write_table_fdf(1, table, 1, 2);
	write(1, "*** TABLE 1/2 ***\n", 19);
	scale_hadamard_fdf(&table, 0.5);
	write_table_fdf(1, table, 0, 2);
	write(1, "*** TABLE + ***\n", 17);
	scale_positive_fdf(&table, 1);
	write_table_fdf(1, table, 0, 2);
	write(1, "*** RELU 0 ***\n", 16);
	scale_relu_fdf(&table, 1, 10, -55);
	write_table_fdf(1, table, 0, 2);
	table2 = scale_dimension_fdf(table, 3);
	free_table_fdf(&table);
	if (table2.arr == NULL)
		return (0);
	write(1, "*** TABLE 4x4 ***\n", 19);
	write_table_fdf(1, table2, 0, 2);
	free_table_fdf(&table2);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/input/table.out test/input/fdf/10-70.fdf
*/
