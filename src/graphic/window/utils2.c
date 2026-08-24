/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:49:07 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 23:03:01 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

// time : O(1)
// space: O(1)
t_line	connecting_2d_point_pair(t_2d_int p1, t_2d_int p2)
{
	t_line	dst;

	dst.p1 = p1;
	dst.p2 = p2;
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_camera	get_static_camera(t_2d_int window_size)
{
	t_2d_camera	dst;

	dst.offset.x = 0;
	dst.offset.y = 0;
	dst.window_size = window_size;
	dst.offset = 1;
	return (dst);
}
