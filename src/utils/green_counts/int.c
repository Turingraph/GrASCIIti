/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 12:36:59 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/06 13:05:37 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "green_counts.h"

// time : O(1)
// space: O(1)
int	f_max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// time : O(1)
// space: O(1)
int	f_min_int(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

// time : O(1)
// space: O(1)
int	f_abs_int(int x)
{
	if (x < 0)
		return (-1 * x);
	return (x);
}

// time : O(1)
// space: O(1)
int	f_interval_int(int num, int min, int max)
{
	if (num > max)
		return (max);
	if (num < min)
		return (min);
	return (num);
}
