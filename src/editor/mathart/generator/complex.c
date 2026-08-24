/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:37:24 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 20:37:25 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "generator.h"

// time : O(1)
// space: O(1)
int	gen_complex_square(const t_table_fdf *dst, size_t index)
{
	return (gen_complex_func(dst, index, complex_square));
}

// time : O(1)
// space: O(1)
int	gen_complex_cube(const t_table_fdf *dst, size_t index)
{
	return (gen_complex_func(dst, index, complex_cube));
}

// time : O(1)
// space: O(1)
int	gen_complex_sin(const t_table_fdf *dst, size_t index)
{
	return (gen_complex_func(dst, index, complex_sin));
}

// time : O(1)
// space: O(1)
int	gen_complex_reciprocal(const t_table_fdf *dst, size_t index)
{
	return (gen_complex_func(dst, index, complex_reciprocal));
}

// I will implement this function after submit fdf42 coding project.
// time : O(1)
// space: O(1)
int	gen_complex_log(const t_table_fdf *dst, size_t index)
{
	return (gen_complex_func(dst, index, complex_square));
}

