#include "input.h"

// time : O(n)
// space: O(n)
int	init_all_lines(char *file, char **line, t_llist_fdf **header,
		t_llist_fdf *(*one_line)(char *))
{
	int	fd;

	fd = open(file, 'r');
	if (fd < 0)
	{
		write(1, file, f_strlen(file));
		write(1, " Don't Exists\n", 14);
		return (fd);
	}
	*line = get_next_line(fd, 0);
	if (*line == NULL)
		return (-1);
	*header = one_line(*line);
	if (*header == NULL)
	{
		get_next_line(fd, 1);
		free(*line);
		return (-1);
	}
	return (fd);
}

// time : O(n)
// space: O(n)
t_llist_fdf	*all_lines(char *file, t_llist_fdf *(*one_line)(char *))
{
	t_llist_fdf	*header;
	t_llist_fdf	*output;
	char		*line;
	int			fd;
	size_t		i;

	fd = init_all_lines(file, &line, &header, one_line);
	if (fd < 0)
		return (NULL);
	output = header;
	i = 0;
	while (output != NULL)
	{
		if (output->int_err == '0')
			non_numerical_file_warning(file, i, 3);
		if (output->int_err == 'E')
			non_numerical_file_warning(file, i, 3);
		if (output->rgb_err == 'E')
			non_numerical_file_warning(file, i, 4);
		output = output->next;
		free(line);
		line = get_next_line(fd, 0);
		if (line != NULL)
			output = one_line(line);
		i += 1;
	}
	return (header);
}

// time : O(n)
// space: O(1)
void	free_llist_fdf(t_llist_fdf *src)
{
	t_llist_fdf	*temp;

	temp = src;
	while (temp != NULL)
	{
		if (temp->arr != NULL)
			free(temp->arr);
		if (temp->rgb != NULL)
			free(temp->rgb);
		free(temp);
		temp = src->next;
	}
}
