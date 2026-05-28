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

int	main(int len, char **str)
{
	int			fd;
	t_llist_fdf	*head;
	t_llist_fdf	*llist;
	size_t		i;

	if (len < 2)
		return (0);
	fd = open(str[1], 'r');
	if (fd < 0)
		return (0);
	head = all_lines(str[1], one_ascii_line);
	if (head == NULL)
		return (0);
	llist = head;
	while (llist != NULL)
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
		llist = llist->next;
	}
	get_next_line(fd, 1);
	free_llist_fdf(head);
	return (0);
}

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
ISSUES:

// with free_llist_fdf(head);
// with get_next_line(fd, 1);
==8933== LEAK SUMMARY:
==8933==    definitely lost: 60 bytes in 1 blocks
==8933==    indirectly lost: 0 bytes in 0 blocks
==8933==      possibly lost: 0 bytes in 0 blocks
==8933==    still reachable: 0 bytes in 0 blocks
==8933==         suppressed: 0 bytes in 0 blocks

// without free_llist_fdf(head);
// with get_next_line(fd, 1);
==9812== LEAK SUMMARY:
==9812==    definitely lost: 100 bytes in 2 blocks
==9812==    indirectly lost: 232 bytes in 1 blocks
==9812==      possibly lost: 0 bytes in 0 blocks
==9812==    still reachable: 0 bytes in 0 blocks
==9812==         suppressed: 0 bytes in 0 blocks

// with free_llist_fdf(head);
// without get_next_line(fd, 1);
==10858== LEAK SUMMARY:
==10858==    definitely lost: 60 bytes in 1 blocks
==10858==    indirectly lost: 0 bytes in 0 blocks
==10858==      possibly lost: 0 bytes in 0 blocks
==10858==    still reachable: 26 bytes in 1 blocks
==10858==         suppressed: 0 bytes in 0 blocks

// without free_llist_fdf(head);
// without get_next_line(fd, 1);
==11292== LEAK SUMMARY:
==11292==    definitely lost: 100 bytes in 2 blocks
==11292==    indirectly lost: 232 bytes in 1 blocks
==11292==      possibly lost: 0 bytes in 0 blocks
==11292==    still reachable: 26 bytes in 1 blocks
==11292==         suppressed: 0 bytes in 0 blocks
*/

/*
valgrind --leak-check=full ./test/bin/input.out test/input/fdf/10-2.fdf
*/
