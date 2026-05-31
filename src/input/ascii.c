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
	if (i >= 41)
		i -= 1;
	if (68 <= (int) i)
		return (0);
	return (68 - (int) i);
}

// time : O(n)
// space: O(n)
int	*line_to_ascii_arr(char *line)
{
	int		*dst;
	size_t	len;
	size_t	i;

	len = knight_of_coin(line, '\n');
	if (len == 0)
		return (NULL);
	dst = (int *)malloc_talk(sizeof(int) * len,
		"input/ascii.c/line_to_ascii_arr\n");
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = f_ctoi(line[i]);
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_llist_fdf	*init_llist_fdf(size_t line_len)
{
	t_llist_fdf	*dst;

	dst = (t_llist_fdf *)malloc_talk(sizeof(t_llist_fdf),
		"input/ascii.c/init_llist_fdf\n");
	if (dst == NULL)
		return (NULL);
	dst->next = NULL;
	dst->rgb = NULL;
	dst->int_err = 'K';
	dst->rgb_err = 'K';
	dst->len = line_len;
	if (dst->len == 0)
	{
		dst->arr = (int *)malloc_talk(sizeof(int),
			"input/ascii.c/one_ascii_line\n");
		if (dst->arr == NULL)
		{
			free(dst);
			return (NULL);
		}
		dst->int_err = '0';
		dst->len = 1;
		dst->arr[0] = 0;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_llist_fdf	*one_ascii_line(char *line)
{
	t_llist_fdf	*dst;

	dst = init_llist_fdf(knight_of_coin(line, '\n'));
	if (dst == NULL)
		return (NULL);
	if (dst->int_err == '0')
		return (dst);
	dst->arr = line_to_ascii_arr(line);
	if (dst->arr == NULL)
	{
		free(dst);
		return (NULL);
	}
	return (dst);
}
