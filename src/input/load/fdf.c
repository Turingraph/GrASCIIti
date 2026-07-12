#include"load.h"

// time : O(n)
// space: O(1)
size_t	count_decimal_digits(const char *line, size_t max)
{
	size_t	j;

	if (line == NULL)
		return (0);
	j = 0;
	if (line[j] == '-')
		j += 1;
	while (f_isspace(line[j], "0123456789") == 1 && j < max)
		j += 1;
	return (j);
}

// time : O(n)
// space: O(1)
size_t	count_fdf_columns(const char *line)
{
	size_t	y;

	y = 0;
	while (line != NULL && *line != '\0')
	{
		while (f_isspace(*line, " \n\t\r\f\v") == 1)
			line += 1;
		if (f_isspace(*line, "0123456789") == 1 || *line == '-')
			y += 1;
		while (f_isspace(*line, "-0123456789,xABCDEFabcdef") == 1)
			line += 1;
		while (f_isspace(*line, "-0123456789,xABCDEFabcdef \n\t\r\f\v") == 0 && *line != '\0')
			line += 1;
	}
	return (y);
}

// time : O(n)
// space: O(n)
t_load_fdf	parse_fdf_line(const char *line, e_bool is_rgba)
{
	t_load_fdf	dst;
	size_t		length;
	size_t		i;
	size_t		j;
	e_bool		is_int;

	length = count_fdf_columns(line);
	if (line == NULL || length == 0)
		return (init_load_fdf(0, FALSE));
	dst = init_load_fdf(length, is_rgba);
	if (dst.arr == NULL)
		return (dst);
	is_int = TRUE;
	i = 0;
	while (i < length && *line != '\0')
	{
		while (f_isspace(*line, " \n\t\r\f\v") == 1)
			line += 1;
		j = count_decimal_digits(line, 10);
		dst.arr[i] = f_atoi(line, &is_int, "0123456789", j);
		line += j;
		if (is_rgba == TRUE)
			update_rgba(line, &dst, i);
		j = count_hex_digits(line, 8);
		if (j > 0)
			line += j + 3;
		i += 1;
	}
	if (is_int == FALSE)
		dst.int_warn = NOT_DECIMAL;
	return (dst);
}