#include "input.h"

// time : O(n)
// space: O(1)
void	free_llist_fdf(t_llist_fdf *src)
{
	t_llist_fdf	*temp;
	size_t		i;

	while (src != NULL)
	{
		temp = src->next;
		if (src->arr != NULL)
			free(src->arr);
		if (src->rgb != NULL)
		{
			i = 0;
			while (i < src->len)
			{
				if (src->rgb[i] != NULL)
					free(src->rgb[i]);
				i += 1;
			}
			free(src->rgb);
		}
		free(src);
		src = temp;
	}
}

// time : O(n)
// space: O(1)
char	fdf_line_checker(t_llist_fdf *llist, char *file, size_t *ith_line, int fd)
{
	if (llist != NULL)
	{
		if (llist->int_err == '0')
			non_numerical_file_warning(file, *ith_line, 3);
		if (llist->int_err == 'E')
			non_numerical_file_warning(file, *ith_line, 3);
		if (llist->rgb_err == 'E')
			non_numerical_file_warning(file, *ith_line, 4);
		*ith_line += 1;
		return (1);
	}
	get_next_line(fd, 1);
	return (0);
}

/*
A little bit wrong in all_lines.
*/

// time : O(n)
// space: O(n)
t_llist_fdf	*all_lines(char *file, int fd, t_llist_fdf *(*one_line)(char *))
{
	t_llist_fdf	*head;
	t_llist_fdf	*llist;
	char		*line;
	size_t		i;

	i = 0;
	line = get_next_line(fd, 0);
	head = one_line(line);
	llist = head;
	if (fdf_line_checker(llist, file, &i, fd) == 0)
	{
		free(line);
		return (NULL);
	}
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd, 0);
		if (line != NULL)
			llist->next = one_line(line);
		if (fdf_line_checker(llist->next, file, &i, fd) == 0)
			return (head);
		llist = llist->next;
	}
	return (head);
}

// time : O(n)
// space: O(1)
void	write_all_lines(int fd, t_llist_fdf *llist)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (llist != NULL)
	{
		i = 0;
		while (i < llist->len)
		{
			if (llist->arr != NULL)
				ft_putnbr_fd(llist->arr[i], fd, "0123456789", 1);
			if (llist->rgb != NULL)// && (j == 3 || j == 0))
			{
				write(fd, ",0x", 3);
				if (llist->rgb[i] != NULL)
				{
					ft_putnbr_fd(llist->rgb[i]->r, fd, "0123456789abcdef", 2);
					ft_putnbr_fd(llist->rgb[i]->g, fd, "0123456789abcdef", 2);
					ft_putnbr_fd(llist->rgb[i]->b, fd, "0123456789abcdef", 2);
					ft_putnbr_fd(llist->rgb[i]->a, fd, "0123456789abcdef", 2);
				}
				else
					write(fd, "ffffffff", 8);
			}
			write(fd, " ", 1);
			i += 1;
		}
		j += 1;
		write(1, "\n", 1);
		llist = llist->next;
	}
}
