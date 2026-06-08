#include"../../../src/input/input/input.h"

/*
int	main(int len, char **str)
{
	int			fd;
	char		*line;
	t_llist_fdf	*head;
	size_t		i;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	line = get_next_line(fd, 0);
	if (line == NULL)
		return (0);
	head = one_ascii_line(line);
	if (head == NULL)
	{
		free(line);
		return (0);
	}
	i = 0;
	while (i < head->len)
	{
		ft_putnbr_fd(head->arr[i], 1, "0123456789");
		if (head->rgb != NULL && head->rgb[i] != NULL)
		{
			write(1, " (", 2);
			ft_putnbr_fd((int) head->rgb[i]->r, 1, "0123456789abcdef");
			write(1, " | ", 3);
			ft_putnbr_fd((int) head->rgb[i]->g, 1, "0123456789abcdef");
			write(1, " | ", 3);
			ft_putnbr_fd((int) head->rgb[i]->b, 1, "0123456789abcdef");
			write(1, " | ", 3);
			ft_putnbr_fd((int) head->rgb[i]->a, 1, "0123456789abcdef");
			write(1, ") ", 2);
		}
		write(1, ", ", 2);
		i += 1;
	}
	get_next_line(fd, 1);
	free_llist_fdf(head);
	free(line);
	return (0);
}
*/

/*
int	main(int len, char **str)
{
	int			fd;
	char		*line;
	t_llist_fdf	*head;
	t_llist_fdf	*llist;
	size_t		i;
	size_t		j;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	line = get_next_line(fd, 0);
	if (line == NULL)
		return (0);
	head = one_fdf_line(line);
	if (head == NULL)
	{
		get_next_line(fd, 1);
		free(line);
		return (0);
	}
	llist = head;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, 0);
		if (line != NULL)
			llist->next = one_fdf_line(line);
		llist = llist->next;
	}
	llist = head;
	j = 0;
	while (llist != NULL)
	{
		i = 0;
		write(1, "::: ", 4);
		if (llist->int_err == 'E')
			write(1, "Invalid Input\n", 14);
		while (i < llist->len)
		{
			ft_putnbr_fd(llist->arr[i], 1, "0123456789", 3);
			if (llist->rgb != NULL && llist->rgb[i] != NULL && (j == 0 || j == 3))
			{
				write(1, " (", 2);
				ft_putnbr_fd((int) llist->rgb[i]->r, 1, "0123456789abcdef", 2);
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->g, 1, "0123456789abcdef", 2);
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->b, 1, "0123456789abcdef", 2);
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->a, 1, "0123456789abcdef", 2);
				write(1, ") ", 2);
				if (llist->rgb[i]->r == (unsigned char) 0)
					write(1, "Suisei", 6);
			}
			write(1, ",\t", 2);
			i += 1;
		}
		write(1, "\n", 1);
		llist = llist->next;
		j += 1;
	}
	get_next_line(fd, 1);
	if (head->rgb_err == 'E')
		write(1, "I'm queer!\n", 11);
	else
		write(1, "I'm straight!\n", 14);
	free_llist_fdf(head);
	free(line);
	return (0);
}
*/

// Graffiti
// GrASCIIti
int	main(int len, char **str)
{
	int			fd;
	t_llist_fdf	*llist;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	llist = all_lines(str[1], fd, one_fdf_line);
	if (llist == NULL)
		return (0);
	write_all_lines(1, llist, 0, 3);
	free_llist_fdf(llist);
	return (0);
}

/*
valgrind --leak-check=full ./test/bin/input/input.out test/input/fdf/10-2.fdf
*/
