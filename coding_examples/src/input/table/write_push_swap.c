#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_bw, false);
	write_push_swap_fdf(output, &table, 1);
	free_table_fdf(&table);
	return (0);
}

/*
./coding_examples/out/input/table/write_push_swap.out input_examples/fdf/pushswap_tester.fdf push_swap_file

*/
