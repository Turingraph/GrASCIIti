#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table_a;
	t_table_fdf	table_b;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table_a = open_table_fdf_file(str[1], NULL, cheche01_ascii_line, FALSE);
	table_b = scale_dimension_fdf(table_a, 3, 3);
	write_table_ascii_cheche01(output, &table_b, D5_HEIGHT);
	free_table_fdf(&table_a);
	free_table_fdf(&table_b);
	return (0);
}
