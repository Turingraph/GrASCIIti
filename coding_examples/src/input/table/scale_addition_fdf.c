#include"table.h"

int	main(int len, char **str)
{
	t_table_fdf	table;
	int			output;
	int			x;
	e_bool		is_int;

	if (len < 4)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	is_int = TRUE;
	x = f_atoi(str[3], &is_int, "0123456789", f_strlen(str[3]));
	if (is_int == FALSE)
		return (0);
	table = open_table_fdf_file(str[1], NULL, cheche01_ascii_line, FALSE);
	scale_addition_fdf(&table, x);
	write_table_ascii_cheche01(output, &table, D5_HEIGHT);
	free_table_fdf(&table);
	return (0);
}
