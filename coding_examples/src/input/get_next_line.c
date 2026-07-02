#include"../../../src/input/get_next_line/get_next_line.h"

int	main(int len, char **str)
{
	int		fd;
	char	*line;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	line = get_next_line(fd, CONTINUE);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		write(1, ">>> ", 5);
		write(1, line, knight_of_coin(line, '\0'));
		free(line);
		line = get_next_line(fd, CONTINUE);
	}
	return (0);
}
