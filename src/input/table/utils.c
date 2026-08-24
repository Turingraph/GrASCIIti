/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:34:48 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 21:28:51 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

// time : O(1)
// space: O(1)
void	set_table_fdf_origin(t_table_fdf *dst,
	size_t direction, size_t ith_position, size_t max_position)
{
	if (direction == 0 && dst != NULL
		&& ith_position <= max_position && max_position <= dst->col)
		dst->origin_x = (dst->col / max_position) * ith_position;
	if (direction == 1 && dst != NULL
		&& ith_position <= max_position && max_position <= dst->col)
		dst->origin_y = (dst->row / max_position) * ith_position;
}

// options for one_line
// 1.	cheche01_ascii_line(char *line) (from txt files)
// 2.	standard_ascii_line(char *line) (from txt files)
// 3.	chungaloider_ascii_line(char *line) (from txt files)
// 4.	bw_fdf_line(char *line) (from fdf files)
// 5.	rgba_fdf_line(char *line)
//		(the only option that load rgb color from fdf files)
// time : O(n)
// space: O(n)
t_table_fdf	open_table_fdf_file(const char *file_name, const char *dir,
	t_load_fdf (*one_line)(char *line), bool is_rgba)
{
	t_table_fdf		dst;
	t_load_fdf_arr	src;

	src = open_fdf_file(file_name, dir, one_line);
	dst = load_table_fdf(&src, is_rgba);
	free_load_fdf_arr(&src);
	return (dst);
}

// time : O(1)
// space: O(1)
t_complex	get_table_fdf_coordinate(const t_table_fdf *dst, size_t index)
{
	t_complex	y;

	y.re = 0;
	y.im = 0;
	if (dst == NULL || index >= dst->row * dst->col)
		return (y);
	y.re = f_floor(f_floor(index % dst->col));
	y.re -= (float)dst->origin_x * dst->zoom;
	y.im = f_floor((float)dst->origin_y);
	y.im -= f_floor(index / dst->col) * dst->zoom;
	return (y);
}

// time : O(1)
// space: O(1)
unsigned char	*get_rgba_of_table_fdf(const t_table_fdf *src,
	t_ergba rgba_type)
{
	if (src == NULL)
		return (NULL);
	if (src->r != NULL && rgba_type == RED)
		return (src->r);
	if (src->g != NULL && rgba_type == GREEN)
		return (src->g);
	if (src->b != NULL && rgba_type == BLUE)
		return (src->b);
	if (src->a != NULL && (rgba_type == ALPHA))
		return (src->a);
	return (NULL);
}
