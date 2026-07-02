#include "load.h"

// time : O(n)
// space: O(n)
int	*line_to_ascii_arr(const char *line, const char *dict)
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
		dst[i] = f_ctoi(line[i], dict);
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_load_fdf	one_ascii_line(const char *line, const char *dict)
{
	t_load_fdf	dst;

	dst = init_load_fdf(knight_of_coin(line, '\n'), 0);
	if (dst.int_warn == EMPTY)
		return (dst);
	dst.arr = line_to_ascii_arr(line, dict);
	return (dst);
}
