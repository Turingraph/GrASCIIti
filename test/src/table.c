#include "../../src/input/input.h"
#include "../../src/table/table.h"

int	main(int len, char **str)
{
	t_llist_fdf	*llist;
	t_table_fdf	*table;
	t_table_fdf	*table2;
	int			fd;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	write(1, "*** LLIST ***\n", 14);
	write_all_lines(1, llist, 0, 3);
	table = llist_to_table_fdf(llist);
	free_llist_fdf(llist);
	if (table == NULL)
		return (0);
	table2 = scale_dimension_fdf(table, 4, 2);
	if (table2 == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	write(1, "*** TABLE ***\n", 14);
	write_table_fdf(1, table2, 0, 3);
	free_table_fdf(table2);
	write(1, "*** TALLY ***\n", 14);
	scale_hadamard_fdf(table, 0.5);
	write_table_fdf(1, table, 0, 3);
	write(1, "*** HAPPY ***\n", 14);
	positive_table_fdf(table);
	write_table_fdf(1, table, 0, 3);
	write(1, "*** ZERO0 ***\n", 14);
	scale_relu_fdf(table, 0, 10, 1);
	write_table_fdf(1, table, 0, 3);
	free_table_fdf(table);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/table.out test/input/fdf/10-70.fdf
*/
