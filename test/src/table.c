#include "../../src/input/input.h"
#include "../../src/table/table.h"

// int	main(int len, char **str)
// {
// 	char			err;
// 	int				row;
// 	int				col;
// 	// unsigned char	**intp;
// 	t_table_fdf		*intp;

// 	if (len < 3)
// 		return (0);
// 	err = 'K';
// 	row = f_atoi(str[1], &err, "0123456789", 1);
// 	col = f_atoi(str[2], &err, "0123456789", 1);
// 	// intp = init_null_char_arr((size_t)row, (size_t)col);
// 	intp = init_table_fdf((size_t)row, (size_t)col);
// 	if (intp == NULL)
// 		return (0);
// 	free_nest_arr((void **)intp, row);
// 	return (0);
// }

/*
// int	main(int len, char **str)
// {
// 	// t_table_fdf	*table;
// 	char			err;
// 	int				row;
// 	int				col;
// 	// t_table_fdf		*intp;
// 	unsigned char	**intp;

// 	// table = init_table(10, 12);
// 	// free_table_fdf(table);
// 	if (len < 3)
// 		return (0);
// 	err = 'K';
// 	row = f_atoi(str[1], &err, "0123456789", 1);
// 	col = f_atoi(str[2], &err, "0123456789", 1);
// 	// arr = init_null_char_arr((size_t)row, (size_t)col);
// 	// intp = init_table_fdf((size_t)row, (size_t)col);
// 	intp = init_null_char_arr((size_t)row, (size_t)col);
// 	if (intp == NULL)
// 		return (0);
// 	free_nest_arr((void **)intp, row);
// 	// free_table_fdf(intp);
// 	return (0);
// }
*/

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
	table2 = scale_table_fdf(table, 4);
	if (table2 == NULL)
	{
		free_table_fdf(table);
		return (0);
	}
	write(1, "*** TABLE ***\n", 14);
	write_table_fdf(1, table2, 0, 3);
	free_table_fdf(table2);
	write(1, "*** TALLY ***\n", 14);
	higher_table_fdf(table, 3);
	write_table_fdf(1, table, 0, 3);
	free_table_fdf(table);
	return (0);
}

/*
// ISSUE

// valgrind --leak-check=full ./test/bin/table.out test/input/fdf/10-70.fdf
// with every lines
==111861== LEAK SUMMARY:
==111861==    definitely lost: 240 bytes in 3 blocks
==111861==    indirectly lost: 2,400 bytes in 30 blocks
==111861==      possibly lost: 0 bytes in 0 blocks
==111861==    still reachable: 0 bytes in 0 blocks
==111861==         suppressed: 0 bytes in 0 blocks

// valgrind --leak-check=full ./test/bin/table.out test/input/fdf/10-70.fdf
// with 1 line
==114365== LEAK SUMMARY:
==114365==    definitely lost: 24 bytes in 3 blocks
==114365==    indirectly lost: 240 bytes in 3 blocks
==114365==      possibly lost: 0 bytes in 0 blocks
==114365==    still reachable: 0 bytes in 0 blocks
==114365==         suppressed: 0 bytes in 0 blocks
*/

/*
valgrind --leak-check=full ./test/bin/table.out test/input/fdf/10-70.fdf
*/
