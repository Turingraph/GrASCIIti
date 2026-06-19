#include"../../../src/input/load/load.h"

/*
int	main(int len, char **str)
{
	t_load_fdf	dst;
	int			fd;
	char		*line;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	line = get_next_line(fd, 0);
	get_next_line(fd, 1);
	if (line == NULL)
		return (0);
	// dst = one_fdf_line(line);
	dst = my_one_ascii_line(line);
	write_load_fdf(1, dst, 1, 0);
	warning_load_fdf(dst, 0);
	free_load_fdf(dst);
	free(line);
	return (0);
}
*/

//	load_all_fdf_lines
int	main(int len, char **str)
{
	int				fd;
	int				fd2;
	t_load_fdf_arr	dst;

	if (len < 3)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	fd2 = open(str[2], 'a');
	if (fd2 < 0)
		return (0);
	dst = load_all_fdf_lines(fd, one_fdf_line);
	write_load_fdf_arr(fd2, dst, 1, 1);
	free_load_fdf_arr(&dst);
	return (0);
}

/*
make test/bin/input/load.out
valgrind --leak-check=full ./test/bin/input/load.out test/input/fdf/20-60.fdf output.txt
*/
