/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 19:33:06 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 19:36:52 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load.h"

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
		while (f_isspace(*line, "-0123456789,xABCDEFabcdef \n\t\r\f\v") == 0
			&& *line != '\0')
			line += 1;
	}
	return (y);
}

// time : O(n)
// space: O(n)
static void	parse_fdf_line_loop(t_load_fdf *dst, char *line,
	bool is_rgba, bool *is_int)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dst->length && *line != '\0')
	{
		while (f_isspace(*line, " \n\t\r\f\v") == 1)
			line += 1;
		j = count_decimal_digits(line, 10);
		dst->arr[i] = f_atoi(line, is_int, "0123456789", j);
		line += j;
		if (is_rgba == true)
			update_rgba(line, dst, i);
		j = count_hex_digits(line, 8);
		if (j > 0)
			line += j + 3;
		i += 1;
	}
}

// time : O(n)
// space: O(n)
t_load_fdf	parse_fdf_line(char *line, bool is_rgba)
{
	t_load_fdf	dst;
	size_t		length;
	bool		is_int;

	length = count_fdf_columns(line);
	if (line == NULL || length == 0)
		return (init_load_fdf(0, false));
	dst = init_load_fdf(length, is_rgba);
	if (dst.arr == NULL)
		return (dst);
	is_int = true;
	parse_fdf_line_loop(&dst, line, is_rgba, &is_int);
	if (is_int == false)
		dst.int_warn = NOT_DECIMAL;
	return (dst);
}
