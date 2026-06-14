#include"../../../src/graphic/triangle_pair/triangle_pair.h"
#include"../../../src/input/input/input.h"
#include"../../../src/input/table/table.h"

/*
//	init_triangle_arr
int	main(int len, char **str)
{
	t_triangle_arr	*dst;
	char			err;
	int				length;

	err = 'K';
	if (len < 2)
		return (0);
	length = f_atoi(str[1], &err, "0123456789", 0);
	if (length < 0)
		length *= -1;
	if (err == 'E')
		return (0);
	dst = init_triangle_arr((size_t)length);
	free_triangle_arr(dst);
	return (0);
}
*/

/*
//	f_fdf_face
int	main(int len, char **str)
{
	t_triangle_arr	*output;
	t_llist_fdf		*llist;
	t_table_fdf		*table;
	int				fd;
	int				row;
	int				col;
	char			err;

	if (len < 4)
		return (0);
	err = 'K';
	row = f_atoi(str[2], &err, "0123456789", 0);
	col = f_atoi(str[3], &err, "0123456789", 0);
	if (err == 'E')
		return (0);
	if (row < 0)
		row *= -1;
	if (col < 0)
		col *= -1;
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
	output = f_fdf_face(table, (size_t)(row % (table->row - 1)),
		(size_t)(col % (table->col - 1)), 1);
	free_table_fdf(table);
	write_triangle_arr(1, output);
	free_triangle_arr(output);
	return (0);
}
*/

// f_fdf_side
int	main(int len, char **str)
{
	t_triangle_arr	*output;
	t_llist_fdf		*llist;
	t_table_fdf		*table;
	int				fd;
	int				row;
	int				col;
	char			err;

	if (len < 4)
		return (0);
	err = 'K';
	row = f_atoi(str[2], &err, "0123456789", 0);
	col = f_atoi(str[3], &err, "0123456789", 0);
	if (err == 'E')
		return (0);
	if (row < 0)
		row *= -1;
	if (col < 0)
		col *= -1;
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
	// output = f_fdf_side(table, (size_t)(row % (table->row - 1)),
	// 	(size_t)(col % (table->col - 1)), 'x');
	output = f_fdf_side(table, row, col, 'y');
	free_table_fdf(table);
	write_triangle_arr(1, output);
	free_triangle_arr(output);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/graphic/triangle_pair.out test/input/fdf/20-60.fdf 0 0

(0, 0, 36),	(0, 1, 43),	(1, 1, 16),	0xffffff00
(0, 0, 36),	(1, 0, -40),	(1, 1, 16),	0xffffff00
*/
