#include"line.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	t_table_fdf	table_2;
	int			output;
	t_circle	circle;
	t_boundary	boundary;

	if (len < 2)
		return (0);
	output = open_dir_file(str[1], NULL, APPEND);
	table = init_table_fdf(30, 49, false);
	boundary.all_area.x = table.col;
	boundary.all_area.y = table.row;
	boundary.sub_area.p1.x = 0;
	boundary.sub_area.p1.y = 0;
	boundary.sub_area.p2.x = table.col;
	boundary.sub_area.p2.y = table.row;
	circle.x = 12;
	circle.y = 12;
	circle.radius = 6;
	midpoint_circle_int(table.arr, 10, circle, boundary);
	table_2 = scale_dimension_fdf(&table, 2, 1);
	table_2.row /= 2;
	table_2.col *= 2;
	write_table_ascii_cheche01(output, &table_2, HEIGHT);
	free_table_fdf(&table);
	free_table_fdf(&table_2);
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./coding_examples/out/editor/line/circle.out input_examples/line/circle.txt
*/
