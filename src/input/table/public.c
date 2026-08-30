/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:46:26 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 19:14:31 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table_private.h"

/**
 * Load target file as t_table_fdf 5 rgba and height integer array data.
 *
 * time/space: O(n) / O(n)
 *
 * status: public api
 * 
 * @param file_name the input file
 * @param dir the directory of the input file
 * @param one_line loading style, including parse_ascii_line_standard for
 * loading file as ASCII art, parse_fdf_line_rgba as colorful Fdf file etc.
 * @param is_rgba if is_rgba == true, then the program using malloc 
 * for initializing rgba color.
 * @see src/input/load/parse.c
 */
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

// t_table_fdf	open_table_fdf_file(const char *file_name, const char *dir,
// 	t_load_fdf (*one_line)(char *line), bool is_rgba)
// {
// 	t_table_fdf		dst;
// 	t_load_fdf_arr	src;

// 	src = open_fdf_file(file_name, dir, one_line);
// 	if (src.length == 0)
// 	{
// 		dst = init_table_fdf(0, 0, false);
// 		dst.is_valid_map = false;
// 		return (dst);
// 	}
// 	dst = load_table_fdf(&src, is_rgba);
// 	if (src.arr[src.length - 1].int_warn != CORRECT
// 		|| src.arr[src.length - 1].rgb_warn != CORRECT)
// 	{
// 		dst.is_valid_map = false;
// 		return (dst);
// 	}
// 	free_load_fdf_arr(&src);
// 	return (dst);
// }
