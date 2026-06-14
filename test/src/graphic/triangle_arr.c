#include"../../src/graphic/triangle_arr/triangle_arr.h"
#include"../../src/input/input/input.h"
#include"../../src/input/table/table.h"

int	main(int len, char **str)
{
	t_triangle_arr	*output;
	t_llist_fdf		*llist;
	t_table_fdf		*table;
	int				fd;

	if (len < 1)
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
	output = all_faces_triangles(table, 0);
	free_table_fdf(table);
	write_triangle_arr(1, output);
	free_triangle_arr(output);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/graphic/triangle_arr.out test/input/fdf/20-60.fdf
*/
