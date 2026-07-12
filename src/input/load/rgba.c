#include"load.h"

// time : O(1)
// space: O(1)
unsigned char	f_rgba(const char *str, size_t len, e_bool *rgb_warn)
{
	int	dst;

	dst = f_atoi(str, rgb_warn, "0123456789abcdef", len);
	if (len == 1)
		dst = 16 * dst + dst;
	if (dst < 0)
		return (0);
	if (dst > 255)
		return (255);
	return ((unsigned char)dst);
}

// time : O(n)
// space: O(1)
size_t	count_hex_digits(const char *line, size_t max)
{
	size_t	i;

	if (line == NULL)
		return (0);
	i = 0;
	if (f_strlen(line) < 4 || *line != ',' || line[1] != '0' || line[2] != 'x')
		return (0);
	while (f_isspace(line[i + 3], "0123456789ABCDEFabcdef") == 1 && i < max)
		i += 1;
	return (i);
}

// time : O(1)
// space: O(1)
void	update_rgba(const char *line, t_load_fdf *dst, size_t index)
{
	size_t	length;
	e_bool	is_rgba;

	is_rgba = TRUE;
	length = count_hex_digits(line, 8);
	if (length > 0 && length < 5 && dst != NULL)
	{
		if (dst->r != NULL)
			dst->r[index] = f_rgba(line + 3, 1, &is_rgba);
		if (length > 1 && dst->g != NULL)
			dst->g[index] = f_rgba(line + 3 + 1, 1, &is_rgba);
		if (length > 2 && dst->b != NULL)
			dst->b[index] = f_rgba(line + 3 + 2, 1, &is_rgba);
		if (length > 3 && dst->a != NULL)
			dst->a[index] = f_rgba(line + 3 + 3, 1, &is_rgba);
	}
	if (length > 0 && length >= 5 && dst != NULL)
	{
		if (dst->r != NULL)
			dst->r[index] = f_rgba(line + 3, 1, &is_rgba);
		if (length > 2 && dst->g != NULL)
			dst->g[index] = f_rgba(line + 3 + 2, 1, &is_rgba);
		if (length > 2 && dst->b != NULL)
			dst->b[index] = f_rgba(line + 3 + 4, 1, &is_rgba);
		if (length > 3 && dst->a != NULL)
			dst->a[index] = f_rgba(line + 3 + 6, 1, &is_rgba);
	}
	if (dst != NULL && is_rgba == FALSE)
		dst->rgb_warn = NOT_HEX;
}