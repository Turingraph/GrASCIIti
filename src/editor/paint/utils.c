/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:22:52 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 16:23:12 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paint.h"

// time : O(1)
// space: O(1)
unsigned char	get_rgba_input(t_enum_rgba rgba_type, t_rgba src)
{
	if (rgba_type == RED)
		return (src.r);
	if (rgba_type == GREEN)
		return (src.g);
	if (rgba_type == BLUE)
		return (src.b);
	if (rgba_type == ALPHA)
		return (src.a);
	return (0);
}
