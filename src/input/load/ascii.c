#include "load.h"

// time : O(n)
// space: O(n)
int	*line_to_ascii_arr(const char *line, const char *dict, int *dst, size_t length)
{
	size_t	i;

	if (dst == NULL || line == NULL || dict == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dst[i] = f_ctoi(line[i], dict);
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
t_load_fdf	parse_ascii_line(const char *line, const char *dict)
{
	t_load_fdf	dst;

	dst = init_load_fdf(knight_of_coin(line, '\n'), 0);
	if (dst.int_warn == EMPTY)
		return (dst);
	line_to_ascii_arr(line, dict, dst.arr, dst.length);
	return (dst);
}
