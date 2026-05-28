#include "input.h"

// time : O(n)
// space: O(1)
char	split_to_int_arr(char **split, int *dst, size_t len)
{
	size_t	i;
	char	err;

	err = 'K';
	i = 0;
	while (i < len)
	{
		dst[i] = f_atoi(split[i], &err, "0123456789", knight_of_coin(split[i], ','));
		i += 1;
	}
	return (err);
}

// time : O(n)
// space: O(n)
int	*line_to_int_arr(char *line, char *err)
{
	int		*dst;
	char	**split;
	size_t	len;

	len = f_split_len(line, " \n\t\r\f\v");
	if (len == 0)
		return (NULL);
	split = f_split(line, " \t\n\r\f\v");
	if (split == NULL)
		return (NULL);
	dst = (int *)malloc_talk(sizeof(int) * len,
		"input/fdf.c/line_to_int_arr\n");
	if (dst == NULL)
	{
		free_nest_arr((void **)split, len);
		return (NULL);
	}
	*err = split_to_int_arr(split, dst, len);
	free_nest_arr((void **)split, len);
	return (dst);
}

/*
Something might be wrong about f_atorgb and/or other rgb related features.
It is a good idea to test with one_ascii_line !
*/

// time : O(n)
// space: O(1)
char	split_to_rgb_arr(char **split, t_rgb **dst, size_t len)
{
	size_t	i;
	char	err;

	err = 'K';
	i = 0;
	while (i < len)
	{
		if (f_strncmp(split[i] + knight_of_coin(split[i], ','), ",0x", 3) == 0
			|| dst[i] != NULL)
			f_atorgb(split[i] + knight_of_coin(split[i], ',') + 3, &err, dst[i]);
		else
			f_atorgb("\0", &err, dst[i]);
		i += 1;
	}
	return (err);
}

// time : O(n)
// space: O(n)
t_rgb	**line_to_rgb_arr(char *line, char *err)
{
	t_rgb	**dst;
	char	**split;
	size_t	len;
	size_t	i;

	len = f_split_len(line, " \n\t\r\f\v");
	if (len == 0)
		return (NULL);
	split = f_split(line, " \t\n\r\f\v");
	if (split == NULL)
		return (NULL);
	dst = (t_rgb **)malloc_talk(sizeof(t_rgb *) * len,
		"input/fdf.c/line_to_rgb_arr\n");
	i = 0;
	while (i < len)
	{
		dst[i] = (t_rgb *)malloc_talk(sizeof(t_rgb),
			"input/fdf.c/line_to_rgb_arr\n");
		i += 1;
	}
	if (dst == NULL)
	{
		free_nest_arr((void **)split, len);
		return (NULL);
	}
	*err = split_to_rgb_arr(split, dst, len);
	free_nest_arr((void **)split, len);
	return (dst);
}

// time : O(n)
// space: O(n)
t_llist_fdf	*one_fdf_line(char *line)
{
	t_llist_fdf	*dst;

	dst = init_llist_fdf(f_split_len(line, " \n\t\r\f\v"));
	if (dst == NULL)
		return (NULL);
	if (dst->int_err == '0')
		return (dst);
	dst->arr = line_to_int_arr(line, &dst->int_err);
	if (dst->arr == NULL)
	{
		free(dst);
		return (NULL);
	}
	dst->rgb = line_to_rgb_arr(line, &dst->rgb_err);
	if (dst->rgb == NULL)
	{
		free(dst->arr);
		free(dst);
		return (NULL);
	}
	return (dst);
}
