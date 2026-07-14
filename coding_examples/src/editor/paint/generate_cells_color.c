#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, parse_fdf_line_bw, true);
	generate_cells_color(&table, BLUE, is_in_prism_border, gen_complex_reciprocal);
	write_table_ascii_standard(output, &table, BLUE);
	free_table_fdf(&table);
	return (0);
}
