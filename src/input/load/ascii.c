#include "load.h"

// https://paulbourke.net/dataformats/asciiart/

// time : O(n)
// space: O(1)
char	mirror_tune(char ithchar, char *dict, size_t dict_len)
{
	size_t	i;

	i = 0;
	while (i < dict_len && dict[i] != ithchar)
		i += 1;
	if (dict[i] == ithchar)
		return (dict[i + dict_len]);
	while (i < dict_len * 2 && dict[i] != ithchar)
		i += 1;
	if (dict[i] == ithchar)
		return (dict[i - dict_len]);
	return (0);
}

// time : O(n)
// space: O(1)
int	f_ctoi(char a, char *dict)
{
	size_t	i;

	if (a == '\0')
		return (0);
	i = 0;
	while (dict[i] != '\0' && dict[i] != a && dict[i] != mirror_tune(a,
		"ASLbpsuaf[({</6VZJdqznej])}>\\9", 15))
		i += 1;
	if (dict[i] == '\0')
		return (0);
	return (i);
}

// time : O(n)
// space: O(n)
int	*line_to_ascii_arr(char *line, char *dict)
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
t_load_fdf	one_ascii_line(char *line, char *dict)
{
	t_load_fdf	dst;

	dst = init_load_fdf(knight_of_coin(line, '\n'), 0);
	if (dst.int_warn == EMPTY)
		return (dst);
	dst.arr = line_to_ascii_arr(line, dict);
	return (dst);
}
