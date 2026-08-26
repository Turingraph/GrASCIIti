#include "table_private.h"

// time : O(n)
// space: O(1)
void	scale_multiplication_fdf(t_table_fdf *dst, float scale, e_rgba channels)
{
	size_t	i;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (dst->arr != NULL && channels == HEIGHT)
			dst->arr[i] = (int)f_interval(f_round((float)dst->arr[i] * scale), -2147483648.0, 2147483647.0);
		if (dst->r != NULL && channels == RED)
			dst->r[i] = (unsigned char)f_interval((float)dst->r[i]* scale, 0, 255);
		if (dst->g != NULL && channels == GREEN)
			dst->g[i] = (unsigned char)f_interval((float)dst->g[i]* scale, 0, 255);
		if (dst->b != NULL && channels == BLUE)
			dst->b[i] = (unsigned char)f_interval((float)dst->b[i]* scale, 0, 255);
		if (dst->a != NULL && channels == ALPHA)
			dst->a[i] = (unsigned char)f_interval((float)dst->a[i]* scale, 0, 255);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	scale_addition_fdf(t_table_fdf *dst, int input, e_rgba channels)
{
	size_t	i;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (dst->arr != NULL && channels == HEIGHT)
			dst->arr[i] = (int)f_interval(f_round(dst->arr[i] + input), -2147483648.0, 2147483647.0);
		if (dst->r != NULL && channels == RED)
			dst->r[i] = (unsigned char)f_interval((int)dst->r[i] + input, 0, 255);
		if (dst->g != NULL && channels == GREEN)
			dst->g[i] = (unsigned char)f_interval((int)dst->g[i] + input, 0, 255);
		if (dst->b != NULL && channels == BLUE)
			dst->b[i] = (unsigned char)f_interval((int)dst->b[i] + input, 0, 255);
		if (dst->a != NULL && channels == ALPHA)
			dst->a[i] = (unsigned char)f_interval((int)dst->a[i] + input, 0, 255);
		i += 1;
	}
}
