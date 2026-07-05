#include"paint.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	double		**kernel;
	int			output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	table = open_table_fdf_file(str[1], NULL, bw_fdf_line, TRUE);
	generate_cells_color(&table, D5_BLUE, is_in_prism_border, gen_conformal_reciprocal);
	write_table_ascii_standard(output, &table, D5_BLUE);
	free_table_fdf(&table);
	return (0);
}
