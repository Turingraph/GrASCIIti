#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, cheche01_ascii_line, FALSE);
	scale_positive_fdf(&table, TRUE, TRUE);
	write_table_ascii_cheche01(output, &table, D5_HEIGHT);
	free_table_fdf(&table);
	return (0);
}
