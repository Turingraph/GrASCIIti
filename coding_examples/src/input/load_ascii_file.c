#include"../../../src/input/load/load.h"

int	main(int len, char **str)
{
	t_load_fdf_arr	dst;

	if (len < 2)
		return (0);
	dst = open_fdf_file(str[1], NULL, cheche01_ascii_line);
	write_load_fdf_arr(1, dst, 1, HEIGHT_ONLY);
	free_load_fdf_arr(&dst);
	return (0);
}
