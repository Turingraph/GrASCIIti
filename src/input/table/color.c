/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 18:40:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 18:43:25 by phsottat         ###   ########.fr       */
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
 * Copy the FDF height channel into the selected RGBA channel.
 * 
 * time/space: O(n) / O(1)
 * 
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param channel RGBA channel to overwrite with height values
 */
void	set_table_color_based_on_height(t_table_fdf *dst, t_enum_rgba channel)
{
	size_t	i;

	i = 0;
	while (dst != NULL && dst->arr != NULL && i < dst->row * dst->col)
	{
		if (dst->r != NULL && channel == RED)
			dst->r[i] = (unsigned char)f_interval(dst->arr[i], 0, 255);
		if (dst->g != NULL && channel == GREEN)
			dst->g[i] = (unsigned char)f_interval(dst->arr[i], 0, 255);
		if (dst->b != NULL && channel == BLUE)
			dst->b[i] = (unsigned char)f_interval(dst->arr[i], 0, 255);
		if (dst->a != NULL && channel == ALPHA)
			dst->a[i] = (unsigned char)f_interval(dst->arr[i], 0, 255);
		i += 1;
	}
}
