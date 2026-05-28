#include "input.h"
#include "libft.h"
#include "get_next_line.h"

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
	while (llist != NULL)
	{
		i = 0;
		if (llist->int_err == 'E')
			write(1, "Invalid Input\n", 14);
		while (i < llist->len)
		{
			ft_putnbr_fd(llist->arr[i], 1, "0123456789");
			if (llist->rgb != NULL && llist->rgb[i] != NULL)
			{
				write(1, " (", 2);
				ft_putnbr_fd((int) llist->rgb[i]->r, 1, "0123456789abcdef");
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->g, 1, "0123456789abcdef");
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->b, 1, "0123456789abcdef");
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->a, 1, "0123456789abcdef");
				write(1, ") ", 2);
			}
			write(1, ",\t", 2);
			i += 1;
		}
		write(1, "\n", 1);
		llist = llist->next;
	}
	get_next_line(fd, 1);
	free_llist_fdf(head);
	free(line);
	return (0);
}
*/

// int	main(int len, char **str)
// {
// 	if (len < 2)
// 		return (0);
// 	return (0);
// }

/*
int	main(int len, char **str)
{
	t_llist_fdf	*src;
	t_llist_fdf	*head;
	size_t		i;

	if (len < 2)
	{
		write(1, "File name isn't specified.\n", 27);
		return (0);
	}
	head = all_lines(str[1], one_fdf_line);
	if (head == NULL)
		return (0);
	src = head;
	while (src != NULL)
	{
		i = 0;
		while (i < llist->len)
		{
			ft_putnbr_fd(llist->arr[i], 1, "0123456789");
			if (llist->rgb != NULL && llist->rgb[i] != NULL)
			{
				write(1, " (", 2);
				ft_putnbr_fd((int) llist->rgb[i]->r, 1, "0123456789abcdef");
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->g, 1, "0123456789abcdef");
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->b, 1, "0123456789abcdef");
				write(1, " | ", 3);
				ft_putnbr_fd((int) llist->rgb[i]->a, 1, "0123456789abcdef");
				write(1, ") ", 2);
			}
			write(1, ", ", 2);
			i += 1;
		}
		write(1, "\n", 1);
		src = llist->next;
	}
	free_llist_fdf(head);
	return (0);
}
*/

/*
valgrind --leak-check=full ./test/bin/input.out test/input/fdf/10-2.fdf
*/
