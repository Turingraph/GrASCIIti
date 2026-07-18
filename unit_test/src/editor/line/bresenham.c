#include"line.h"

int	main(void)
{
	size_t		i;
	size_t		length = 8;
	char		*arr[] = {"0", "1", "2", "3", "4", "5", "6", "7"};
	t_table_fdf	table;
	int			output;
	t_line		line[] = {
		{3, 7, 8, 10, .ink=33, .row=20, .col=20},
		{8, 3, 10, 17, .ink=33, .row=20, .col=20},
		{10, 4, 8, 16, .ink=33, .row=20, .col=20},
		{11, 4, 1, 9, .ink=33, .row=20, .col=20},
		{7, 17, 0, 14, .ink=33, .row=20, .col=20},
		{6, 18, 3, 0, .ink=33, .row=20, .col=20},
		{3, 19, 5, 2, .ink=33, .row=20, .col=20},
		{2, 13, 16, 10, .ink=33, .row=20, .col=20}
	};

	i = 0;
	while (i < length)
	{
		output = open_dir_file(arr[i], "input_examples/line/line_", APPEND);
		table = init_table_fdf(20, 20, false);
		bresenham_line_int(table.arr, line[i]);
		write_table_ascii_chungaloider(output, &table, HEIGHT);
		free_table_fdf(&table);
		i += 1;
	}
	return (0);
}

/*
valgrind --leak-check=full --show-leak-kinds=all ./unit_test/out/editor/line/bresenham.out
*/
