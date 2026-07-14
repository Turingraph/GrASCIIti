#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_bw, true);
	fill_cells_height(&table, 123, false, is_conjugate_sin);
	write_table_ascii_standard(output, &table, HEIGHT);
	free_table_fdf(&table);
	return (0);
}
