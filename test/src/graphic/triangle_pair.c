#include"../../../src/graphic/triangle_pair/triangle_pair.h"
#include"../../../src/input/load/load.h"
#include"../../../src/input/table/table.h"

//	f_fdf_face
int	main(int len, char **str)
{
	t_triangle_arr	output;
	t_load_fdf_arr	data;
	t_table_fdf		table;
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
	data = load_all_fdf_lines(fd, cheche_one_ascii_line);
	if (data.arr == NULL)
		return (0);
	table = load_table_fdf(data, 1);
	free_load_fdf_arr(data);
	if (table.arr == NULL)
		return (0);
	if ((size_t)(row + 1) < table.row && (size_t)(col + 1) < table.col)
	{
		ft_putnbr_fd(table.arr[row][col], 1, "0123456789", 1);
		write(1, "\t", 1);
		ft_putnbr_fd(table.arr[row][col + 1], 1, "0123456789", 1);
		write(1, "\n", 1);
		ft_putnbr_fd(table.arr[row + 1][col], 1, "0123456789", 1);
		write(1, "\t", 1);
		ft_putnbr_fd(table.arr[row + 1][col + 1], 1, "0123456789", 1);
		write(1, "\n", 1);
	}
	output = f_fdf_side(table, row, col, 'y');
	free_table_fdf(&table);
	write_triangle_arr(1, output);
	free_triangle_arr(&output);
	return (0);
}

/*
make test/bin/graphic/triangle_pair.out
valgrind --leak-check=full ./test/bin/graphic/triangle_pair.out font/rozzo/0.txt 3 4
*/
