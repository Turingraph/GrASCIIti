#include"fdf.h"

int	main(int len, char **str)
{
	t_table_fdf		table;
	t_fdf			output;
	t_view_config	bc;
	t_ink32			style;

	if (len < 2)
		return (0);
	table = open_table_fdf_file(str[1], NULL, parse_ascii_line_cheche01, true);
	table_fdf_height_to_color(&table, RED);
	table_fdf_height_to_color(&table, GREEN);
	scale_multiplication_fdf(&table, 0.3, GREEN);
	table_fdf_height_to_color(&table, BLUE);
	scale_multiplication_fdf(&table, 1.2, BLUE);
	set_table_color(&table, ALPHA, 255);
	style.color = 0;
	style.thickness = 4;
	style.type = E_LINE;
	bc.init_3d_transform->arr = NULL;
	bc.init_3d_transform->col = 0;
	bc.init_3d_transform->row = 0;
	bc.background_color = 
	output = init_fdf(&table);
	view_fdf(&output, style, bc);
	free_fdf(&output);
	return (0);
}

