#include "../../../src/input/load/load.h"
#include "../../../src/input/table/table.h"
#include "../../../src/editor/paint/paint.h"

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
	write_table_fdf(1, table, 1, 3);
	free_table_fdf(&table);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/editor/paint.out test/input/fdf/10-2.fdf
*/
