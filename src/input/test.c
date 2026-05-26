#include "input.h"

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
		while (i < src->len)
		{
			ft_putnbr_fd(src->arr[i], 1);
			if (src->rgb != NULL && src->rgb[i] != NULL)
			{
				write(1, " (", 2);
				ft_putnbr_fd((int) src->rgb[i]->r, 1);
				write(1, " | ", 3);
				ft_putnbr_fd((int) src->rgb[i]->g, 1);
				write(1, " | ", 3);
				ft_putnbr_fd((int) src->rgb[i]->b, 1);
				write(1, " | ", 3);
				ft_putnbr_fd((int) src->rgb[i]->a, 1);
				write(1, ") ", 2);
			}
			write(1, ", ", 2);
			i += 1;
		}
		write(1, "\n", 1);
		src = src->next;
	}
	free_llist_fdf(head);
	return (0);
}

/*
valgrind --leak-check=full ./bin/input.out test/fdf/10-2.fdf
*/
