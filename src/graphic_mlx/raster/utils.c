/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 13:40:39 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 16:27:23 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"

// time : O(1)
// space: O(1)
bool	is_in_boundary(int x, int y, t_line boundary)
{
	if (x >= boundary.p1.x
		&& x < boundary.p2.x
		&& y >= boundary.p1.y
		&& y < boundary.p2.y)
		return (true);
	return (false);
}
