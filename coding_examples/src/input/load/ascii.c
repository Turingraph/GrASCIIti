#include"load.h"

int	main(int len, char **str)
{
	t_load_fdf_arr	dst;
	int				output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	dst = open_fdf_file(str[1], NULL, cheche01_ascii_line);
	write_load_fdf_arr(output, dst, 1, HEIGHT_ONLY);
	free_load_fdf_arr(&dst);
	return (0);
}
