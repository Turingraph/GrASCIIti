#include"get_next_line.h"

int	main(int len, char **str)
{
	int		fd;
	char	*line;
	int		output;

	if (len < 3)
		return (0);
	output = open_dir_file(str[2], NULL, APPEND);
	fd = open_dir_file(str[1], NULL, READ);
	line = get_next_line(fd, CONTINUE);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		write(output, ">>> ", 5);
		write(output, line, knight_of_coin(line, '\0'));
		free(line);
		line = get_next_line(fd, CONTINUE);
	}
	return (0);
}
