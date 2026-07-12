#include "load.h"

// time : O(n)
// space: O(1)
e_load_warning	split_to_int_arr(const char **split, int *dst, size_t len)
{
	size_t	i;
	e_bool	int_warn;

	if (split == NULL)
		return (EMPTY);
	int_warn = TRUE;
	i = 0;
	while (i < len)
	{
		dst[i] = f_atoi((const char *)split[i], &int_warn, "0123456789", knight_of_coin(split[i], ','));
		i += 1;
	}
	if (int_warn == TRUE)
		return (CORRECT);
	return (NOT_DECIMAL);
}

// write(1, ">>> ", 4);
// write(1, split[i], knight_of_coin(split[i], ','));
// write(1, "\t=\t", 3);
// ft_putnbr_fd(knight_of_coin(split[i], ','), 1, "0123456789", 1);
// write(1, "\n", 1);

// time : O(n)
// space: O(n)
int	*line_to_int_arr(const char *line, e_load_warning *int_warn)
{
	int				*dst;
	char			**split;
	size_t			len;
	e_load_warning	log;

	len = f_split_len(line, " \n\t\r\f\v");
	if (len == 0)
	{
		if (int_warn != NULL)
			*int_warn = EMPTY;
		return (NULL);
	}
	split = f_split(line, " \t\n\r\f\v");
	if (split == NULL)
		return (NULL);
	dst = (int *)malloc_talk(sizeof(int) * len,
		"input/fdf.c/line_to_int_arr\n");
	if (dst == NULL)
	{
		free_2d_arr((void **)split, len);
		return (NULL);
	}
	log = split_to_int_arr((const char **)split, dst, len);
	if (int_warn != NULL)
		*int_warn = log;
	free_2d_arr((void **)split, len);
	return (dst);
}

// time : O(1)
// space: O(1)
void	load_fdf_rgba(t_load_fdf *dst, size_t i, const char *src)
{
	size_t	len;
	e_bool	rgb_warn;

	rgb_warn = TRUE;
	len = 1;
	if (f_strlen(src) > 4)
		len = 2;
	if (dst != NULL && dst->r != NULL && i < dst->length && 0 * len < f_strlen(src))
		dst->r[i] = f_rgb(src + 0 * len, len, &rgb_warn);
	if (dst != NULL && dst->g != NULL && i < dst->length && 1 * len < f_strlen(src))
		dst->g[i] = f_rgb(src + 1 * len, len, &rgb_warn);
	if (dst != NULL && dst->b != NULL && i < dst->length && 2 * len < f_strlen(src))
		dst->b[i] = f_rgb(src + 2 * len, len, &rgb_warn);
	if (dst != NULL && dst->a != NULL && i < dst->length && 3 * len < f_strlen(src))
		dst->a[i] = f_rgb(src + 3 * len, len, &rgb_warn);
	else if (dst != NULL && dst->a != NULL && i < dst->length && 0 < f_strlen(src))
		dst->a[i] = (unsigned char)255;
	if (rgb_warn == FALSE)
		dst->rgb_warn = NOT_HEX;
}

// time : O(n)
// space: O(1)
char	line_to_rgb_arr(const char *line, t_load_fdf *dst)
{
	char	**split;
	size_t	i;
	size_t	k;
	size_t	len;

	if (dst == NULL)
		return (0);
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
		free_2d_arr((void **)split, len);
	return (1);
}

// time : O(n)
// space: O(n)
t_load_fdf	one_fdf_line(const char *line, e_bool is_rgb)
{
	t_load_fdf	dst;
	size_t		length;

	length = f_split_len(line, " \n\t\r\f\v");
	dst = init_load_fdf(length, is_rgb);
	if (dst.int_warn == EMPTY)
		return (dst);
	dst.arr = line_to_int_arr(line, &(dst.int_warn));
	if (dst.arr == NULL)
		return (dst);
	if (is_rgb == TRUE)
		line_to_rgb_arr(line, &dst);
	return (dst);
}
