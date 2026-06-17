#include "load.h"

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

// time : O(1)
// space: O(1)
void	load_fdf_rgba(t_load_fdf *dst, size_t i, char *src)
{
	size_t			len;
	char			err;

	err = 'K';
	len = 1;
	if (f_strlen(src) > 4)
		len = 2;
	if (dst != NULL && dst->r != NULL && i < dst->length && 0 * len < f_strlen(src))
		dst->r[i] = f_rgb(src + 0 * len, len, &err);
	if (dst != NULL && dst->g != NULL && i < dst->length && 1 * len < f_strlen(src))
		dst->g[i] = f_rgb(src + 1 * len, len, &err);
	if (dst != NULL && dst->b != NULL && i < dst->length && 2 * len < f_strlen(src))
		dst->b[i] = f_rgb(src + 2 * len, len, &err);
	if (dst != NULL && dst->a != NULL && i < dst->length && 3 * len < f_strlen(src))
		dst->a[i] = f_rgb(src + 3 * len, len, &err);
	else if (dst != NULL && dst->a != NULL && i < dst->length && 0 < f_strlen(src))
		dst->a[i] = (unsigned char)255;
	if (err == 'E')
		dst->rgb_err = 'E';
}

// time : O(n)
// space: O(1)
void	line_to_rgb_arr(char *line, t_load_fdf *dst)
{
	char	**split;
	size_t	i;
	size_t	k;
	size_t	len;

	len = f_split_len(line, " \n\t\r\f\v");
	split = NULL;
	if (len > 0)
		split = f_split(line, " \t\n\r\f\v");
	i = 0;
	while (i < len && split != NULL)
	{
		k = knight_of_coin(split[i], ',');
		if (split[i][k] != '\0' && f_strlen(split[i] + k) > 3)
			load_fdf_rgba(dst, i, split[i] + k + 3);
		i += 1;
	}
	if (split != NULL)
		free_nest_arr((void **)split, len);
}

// time : O(n)
// space: O(n)
t_load_fdf	one_fdf_line(char *line)
{
	t_load_fdf	dst;
	size_t		length;

	length = f_split_len(line, " \n\t\r\f\v");
	dst = init_load_fdf(length, 1);
	if (dst.int_err == '0')
		return (dst);
	dst.arr = line_to_int_arr(line, &(dst.int_err));
	if (dst.arr == NULL)
		return (dst);
	line_to_rgb_arr(line, &dst);
	return (dst);
}
