/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:40:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/30 11:56:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

/**
 * Set every RGBA channel as a specific color.
 * 
 * time/space: O(n) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param channel RGBA channel to overwrite with height values
 * @param color the updated color value
 *
 */
void	set_table_color(t_table_fdf *dst, t_enum_rgba channel,
	unsigned char color)
{
	size_t	i;

	i = 0;
	while (dst != NULL && dst->arr != NULL && i < dst->row * dst->col)
	{
		if (dst->r != NULL && channel == RED)
			dst->r[i] = color;
		if (dst->g != NULL && channel == GREEN)
			dst->g[i] = color;
		if (dst->b != NULL && channel == BLUE)
			dst->b[i] = color;
		if (dst->a != NULL && channel == ALPHA)
			dst->a[i] = color;
		i += 1;
	}
}

/**
 * Copy the FDF height channel into the selected RGBA channel of each cell
 * if the height integer value of the cell is in the selected interval.
 * 
 * time/space: O(n) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param channel RGBA channel to overwrite with height values
 * @param min the minimum height range
 * @param max the maximum height range
 */
void	set_table_color_based_on_height(t_table_fdf *dst, t_enum_rgba channel,
	int min, int max)
{
	size_t	i;
	int		x;

	if (min > max)
	{
		x = min;
		min = max;
		max = x;
	}
	i = 0;
	while (dst != NULL && dst->arr != NULL && i < dst->row * dst->col)
	{
		x = dst->arr[i];
		if (dst->r != NULL && channel == RED && min <= x && x <= max)
			dst->r[i] = (unsigned char)f_interval(x, 0, 255);
		if (dst->g != NULL && channel == GREEN && min <= x && x <= max)
			dst->g[i] = (unsigned char)f_interval(x, 0, 255);
		if (dst->b != NULL && channel == BLUE && min <= x && x <= max)
			dst->b[i] = (unsigned char)f_interval(x, 0, 255);
		if (dst->a != NULL && channel == ALPHA && min <= x && x <= max)
			dst->a[i] = (unsigned char)f_interval(x, 0, 255);
		i += 1;
	}
}
