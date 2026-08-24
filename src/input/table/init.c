/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 11:19:52 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 11:20:31 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "table.h"

// time : O(1)
// space: O(1)
void	*free_table_fdf(t_table_fdf *src)
{
	if (src == NULL)
		return (NULL);
	free(src->arr);
	free(src->r);
	free(src->g);
	free(src->b);
	free(src->a);
	src->arr = NULL;
	src->r = NULL;
	src->g = NULL;
	src->b = NULL;
	src->a = NULL;
	src->row = 0;
	src->col = 0;
	src->origin_x = 0;
	src->origin_y = 0;
	src->color_sampling = SAMPLE_TOP_LEFT;
	src->zoom = 1;
	return (NULL);
}

// time : O(n)
// space: O(n)
t_table_fdf	init_table_fdf(size_t row, size_t col, bool is_rgba)
{
	t_table_fdf	dst;

	dst.arr = malloc_talk(sizeof(int) * row * col,
			"table/init.c/init_table_fdf");
	dst.row = row;
	dst.col = col;
	dst.origin_x = col / 2;
	dst.origin_y = row / 2;
	dst.zoom = 1;
	dst.color_sampling = SAMPLE_TOP_LEFT;
	if (is_rgba == false)
		row = 0;
	dst.r = malloc_talk(sizeof(unsigned char) * row * col,
			"table/init.c/init_table_fdf");
	dst.g = malloc_talk(sizeof(unsigned char) * row * col,
			"table/init.c/init_table_fdf");
	dst.b = malloc_talk(sizeof(unsigned char) * row * col,
			"table/init.c/init_table_fdf");
	dst.a = malloc_talk(sizeof(unsigned char) * row * col,
			"table/init.c/init_table_fdf");
	if (dst.arr == NULL || dst.col < 1 || dst.row < 1)
		free_table_fdf(&dst);
	return (dst);
}

// time : O(n)
// space: O(1)
size_t	load_fdf_col(const t_load_fdf_arr *src)
{
	size_t	i;
	size_t	col;

	col = 0;
	i = 0;
	while (i < src->length && src->arr != NULL)
	{
		if (col < src->arr[i].length)
			col = src->arr[i].length;
		i += 1;
	}
	return (col);
}

// time : O(1)
// space: O(1)
void	load_rgba_for_table_fdf(const t_load_fdf *src,
	t_table_fdf *dst, size_t row, size_t col)
{
	if (src != NULL && dst != NULL
		&& row < dst->row && col < dst->col && col < src->length)
	{
		if (src->r != NULL && dst->r != NULL)
			dst->r[dst->col * row + col] = src->r[col];
		if (src->g != NULL && dst->g != NULL)
			dst->g[dst->col * row + col] = src->g[col];
		if (src->b != NULL && dst->b != NULL)
			dst->b[dst->col * row + col] = src->b[col];
		if (src->a != NULL && dst->a != NULL)
			dst->a[dst->col * row + col] = src->a[col];
	}
}

// time : O(n)
// space: O(1)
t_table_fdf	load_table_fdf(const t_load_fdf_arr *src, bool is_rgba)
{
	t_table_fdf	dst;
	size_t		i;
	size_t		j;

	if (src == NULL || src->arr == NULL
		|| src->length == 0 || src->capacity == 0)
		return (init_table_fdf(0, 0, false));
	dst = init_table_fdf(src->length, load_fdf_col(src), is_rgba);
	if (dst.arr == NULL)
		return (dst);
	i = 0;
	while (i < src->length)
	{
		j = 0;
		while (j < src->arr[i].length && src->arr[i].arr != NULL)
		{
			dst.arr[dst.col * i + j] = src->arr[i].arr[j];
			if (is_rgba == true)
				load_rgba_for_table_fdf(&(src->arr[i]), &dst, i, j);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}
