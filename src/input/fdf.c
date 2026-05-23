#include "input.h"

// time : O(n)
// space: O(1)
char	f_atoi_arr(char **src, int *dst, size_t len)
{
	size_t	i;
	char	err;

	if (src == NULL || dst == NULL)
	{
		if (dst != NULL)
			free(dst);
		return (0);
	}
	err = 'K';
	i = 0;
	while (i < len && err != 'E')
	{
		dst[i] = f_atoi(src[i], &err);
		i += 1;
	}
	if (err == 'E')
	{
		write(1, "\nInput FdF File contains character, which is invalid.\n", 54);
		free(dst);
		return (0);
	}
	return (1);
}

// time : O(n)
// space: O(n)
t_llist_int	*create_fdf_line(char *line)
{
	t_llist_int	*ll;

	ll = (t_llist_int *)malloc(sizeof(t_llist_int));
	if (ll == NULL)
		return (NULL);
	ll->next = NULL;
	ll->len = f_split_len(line);
	if (ll->len == 0)
	{
		free(ll);
		return (NULL);
	}
	ll->arr = (int *)malloc(sizeof(int) * ll->len);
	if (0 == f_atoi_arr(f_split_space(line), 
		ll->arr, ll->len))
	{
		free(ll);
		return (NULL);
	}
	return (ll);
}

// time : O(n)
// space: O(n)
t_llist_int	*create_fdf_file(char *file_name)
{
	int			fd;
	char		*line;
	t_llist_int	*header;
	t_llist_int	*output;

	fd = open(file_name, 'r');
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	header = create_fdf_line(line);
	if (header == NULL)
	{
		free(line);
		return (NULL);
	}
	output = header;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL && output != NULL)
			output->next = create_fdf_line(line);
		if (output != NULL)
			output = output->next;
	}
	return (header);
}
