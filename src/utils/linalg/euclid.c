/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euclid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 14:31:00 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 14:32:18 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

// time : O(n)
// space: O(1)
float	euclid_distance(const float *vec_v,
	const float *vec_0, size_t dim, char square)
{
	float	y;
	size_t	i;

	if (vec_v == NULL)
		return (0);
	y = 0;
	i = 0;
	while (i < dim)
	{
		if (vec_0 != NULL)
			y += (vec_v[i] - vec_0[i]) * (vec_v[i] - vec_0[i]);
		else
			y += vec_v[i] * vec_v[i];
		i += 1;
	}
	if (square == 1)
		return (y);
	return ((float)f_root_finding(y, 2));
}

// time : O(n)
// space: O(1)
float	cos_between_2_vectors(const float *vec_v,
	const float *vec_u, size_t dim)
{
	float	div;

	div = euclid_distance(vec_v, vec_u, dim, 0);
	if (div == 0)
		return (0);
	return (dot_product(vec_v, vec_u, dim) / div);
}

// time : O(n)
// space: O(n)
void	vector_projection(float *update_v, const float *vec_u, size_t dim)
{
	float	div;
	float	scale;

	if (update_v != NULL && vec_u != NULL)
	{
		div = euclid_distance(update_v, NULL, dim, 1);
		if (div != 0)
		{
			scale = dot_product(update_v, vec_u, dim) / div;
			vector_scale(update_v, scale, dim);
		}
	}
}

// time : O(n)
// space: O(1)
float	scale_projection(const float *vec_v, const float *vec_u, size_t dim)
{
	float	div;
	float	scale;

	if (vec_v == NULL || vec_u == NULL)
		return (0);
	div = euclid_distance(vec_v, NULL, dim, 0);
	if (div == 0)
		return (0);
	scale = dot_product(vec_v, vec_u, dim) / div;
	return (scale);
}
