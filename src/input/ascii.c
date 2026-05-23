#include "input.h"

// https://paulbourke.net/dataformats/asciiart/

// time : O(1)
// space: O(1)
int	f_ctoi(char a)
{
	size_t	i;
	char	*dict;

	dict = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
	i = 0;
	while (dict[i] != '\0' && dict[i] != a)
		i += 1;
	if (69 <= (int) i)
		return (0);
	return (69 - (int) i);
}

// time : O(n)
// space: O(1)
char	f_ctoi_arr(char *src, int *dst, size_t len)
{
	size_t	i;

	if (src == NULL || dst == NULL)
	{
		if (dst != NULL)
			free(dst);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		dst[i] = f_ctoi(src[i]);
		i += 1;
	}
	return (1);
}

// time : O(n)
// space: O(1)
size_t	f_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		str += 1;
		i += 1;
	}
	return (i);
}

// time : O(n)
// space: O(n)
t_llist_int	*create_ascii_line(char *line)
{
	t_llist_int	*ll;

	ll = (t_llist_int *)malloc(sizeof(t_llist_int));
	if (ll == NULL)
		return (NULL);
	ll->next = NULL;
	ll->len = f_strlen(line);
	if (ll->len == 0)
	{
		free(ll);
		return (NULL);
	}
	ll->arr = (int *)malloc(sizeof(int) * ll->len);
	if (0 == f_ctoi_arr(line, ll->arr, ll->len))
	{
		free(ll);
		return (NULL);
	}
	return (ll);
}

// time : O(n)
// space: O(n)
t_llist_int	*create_ascii_file(char *file_name)
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
	header = create_ascii_line(line);
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
			output->next = create_ascii_line(line);
		if (output != NULL)
			output = output->next;
	}
	return (header);
}
