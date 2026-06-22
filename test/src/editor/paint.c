#include "../../../src/input/load/load.h"
#include "../../../src/input/table/table.h"
#include "../../../src/editor/paint/paint.h"

int	main(int len, char **str)
{
	t_load_fdf_arr	data;
	t_table_fdf		table;
	int				fd;
	int				fd2;

	if (len < 3)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	fd2 = open(str[2], 'a');
	if (fd2 < 0)
		return (0);
	data = load_all_fdf_lines(fd, cheche_one_ascii_line);
	if (data.arr == NULL)
	{
		free_load_fdf_arr(&data);
		return (0);
	}
	table = load_table_fdf(data, 1);
	free_load_fdf_arr(&data);
	if (table.arr == NULL)
		return (0);
	set_color_every_cells(&table, RED, 192, collatz_coloring);
	set_color_every_cells(&table, GREEN, 192, collatz_coloring);
	set_color_every_cells(&table, BLUE, 0, collatz_coloring);
	set_color_every_cells(&table, ALPHA, 225, collatz_coloring);
	write_table_fdf(fd2, table, TRUE, 3);
	free_table_fdf(&table);
	return (0);
}

/*
int	main(int len, char **str)
{
	t_load_fdf_arr	data;
	t_table_fdf		table;
	int				fd;
	t_gradient		rgb;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	data = load_all_fdf_lines(fd, one_fdf_line);
	if (data.arr == NULL)
	{
		free_load_fdf_arr(&data);
		return (0);
	}
	table = load_table_fdf(data, 1);
	free_load_fdf_arr(&data);
	if (table.arr == NULL)
		return (0);
	rgb.r1 = 255;
	rgb.g1 = 0;
	rgb.b1 = 0;
	rgb.a1 = 255;
	rgb.x1 = 2;
	rgb.r2 = 0;
	rgb.g2 = 0;
	rgb.b2 = 255;
	rgb.a2 = 255;
	rgb.x2 = 7;
	paint_gradient_fdf(&table, rgb, 1);
	write_table_fdf(1, table, TRUE, 3);
	free_table_fdf(&table);
	return (0);
}
*/

/*
make test/bin/editor/paint.out
valgrind --leak-check=full ./test/bin/editor/paint.out test/input/fdf/10-2.fdf
*/
