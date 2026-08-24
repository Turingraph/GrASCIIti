/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 21:58:34 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 22:01:51 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"

// time : O(1)
// space: O(1)
t_circle	return_2d_point(t_boundary boundary, t_circle circle)
{
	t_circle	point;
	int			offset;

	point.radius = circle.radius;
	offset = boundary.sub_area.p1.x;
	point.x = (int)f_interval(circle.x, 0,
			boundary.sub_area.p2.x - boundary.sub_area.p1.x) + offset;
	offset = boundary.sub_area.p1.y;
	point.y = (int)f_interval(circle.y, 0,
			boundary.sub_area.p2.y - boundary.sub_area.p1.y) + offset;
	return (point);
}
