#include "table_private.h"

/**
 * Multiply each selected FDF channel by scale.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param scale multiplication factor
 * @param channels channel to modify
 */
void	scale_multiplication_fdf(t_table_fdf *dst, float scale, e_rgba channels)
{
	size_t	i;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (dst->arr != NULL && channels == HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round((float)dst->arr[i] * scale),
					-2147483648.0, 2147483647.0);
		if (dst->r != NULL && channels == RED)
			dst->r[i] = (unsigned char)f_interval(
					(float)dst->r[i]* scale, 0, 255);
		if (dst->g != NULL && channels == GREEN)
			dst->g[i] = (unsigned char)f_interval(
					(float)dst->g[i]* scale, 0, 255);
		if (dst->b != NULL && channels == BLUE)
			dst->b[i] = (unsigned char)f_interval(
						(float)dst->b[i]* scale, 0, 255);
		if (dst->a != NULL && channels == ALPHA)
			dst->a[i] = (unsigned char)f_interval(
				(float)dst->a[i]* scale, 0, 255);
		i += 1;
	}
}

/**
 * Add input to each value in the selected FDF channel.
 *
 * time/space: O(n) / O(1)
 *
 * status: public api
 * 
 * @param dst FDF table to modify
 * @param input value to add
 * @param channels channel to modify
 */
void	scale_addition_fdf(t_table_fdf *dst, int input, e_rgba channels)
{
	size_t	i;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (dst->arr != NULL && channels == HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] + input), -2147483648.0, 2147483647.0);
		if (dst->r != NULL && channels == RED)
			dst->r[i] = (unsigned char)f_interval(
					(int)dst->r[i] + input, 0, 255);
		if (dst->g != NULL && channels == GREEN)
			dst->g[i] = (unsigned char)f_interval(
					(int)dst->g[i] + input, 0, 255);
		if (dst->b != NULL && channels == BLUE)
			dst->b[i] = (unsigned char)f_interval(
					(int)dst->b[i] + input, 0, 255);
		if (dst->a != NULL && channels == ALPHA)
			dst->a[i] = (unsigned char)f_interval(
					(int)dst->a[i] + input, 0, 255);
		i += 1;
	}
}

/**
 * Add the selected channel of src to dst element by element.
 *
 * time/space: O(n) / O(1)
 * 
 * status: public api
 *
 * @param dst FDF table to modify
 * @param src source FDF table
 * @param channels channel to add
 */
void	table_fdf_addition(t_table_fdf *dst,
	const t_table_fdf *src, e_rgba channels)
{
	size_t	i;

	i = 0;
	while (src != NULL && dst != NULL && i < dst->row * dst->col
		&& dst->row * dst->col == src->row * src->col)
	{
		if (src->arr != NULL && dst->arr != NULL && channels == HEIGHT)
			dst->arr[i] = (int)f_interval(
					f_round(dst->arr[i] + src->arr[i]),
					-2147483648.0, 2147483647.0);
		if (src->r != NULL && dst->r != NULL && channels == RED)
			dst->r[i] = (unsigned char)f_interval(
					dst->r[i] + src->r[i], 0, 255);
		if (src->g != NULL && dst->g != NULL && channels == GREEN)
			dst->g[i] = (unsigned char)f_interval(
					dst->g[i] + src->g[i], 0, 255);
		if (src->b != NULL && dst->b != NULL && channels == BLUE)
			dst->b[i] = (unsigned char)f_interval(
					dst->b[i] + src->b[i], 0, 255);
		if (src->a != NULL && dst->a != NULL && channels == ALPHA)
			dst->a[i] = (unsigned char)f_interval(
					dst->a[i] + src->a[i], 0, 255);
		i += 1;
	}
}
