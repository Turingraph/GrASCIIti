#include"table_private.h"

// time : O(1)
// space: O(1)
int	target_minmax(const t_table_fdf *dst, e_rgba channels, size_t index, bool is_bool)
{
	if (dst != NULL && index < dst->col * dst->row)
	{
		if (dst->arr != NULL && channels == HEIGHT && is_bool == true)
			return (1);
		if (dst->arr != NULL && channels == HEIGHT && is_bool == false)
			return (dst->arr[index]);
		if (dst->r != NULL && channels == RED && is_bool == true)
			return (1);
		if (dst->r != NULL && channels == RED && is_bool == false)
			return ((int)dst->r[index]);
		if (dst->g != NULL && channels == GREEN && is_bool == true)
			return (1);
		if (dst->g != NULL && channels == GREEN && is_bool == false)
			return ((int)dst->g[index]);
		if (dst->b != NULL && channels == BLUE && is_bool == true)
			return (1);
		if (dst->b != NULL && channels == BLUE && is_bool == false)
			return ((int)dst->b[index]);
		if (dst->a != NULL && channels == ALPHA && is_bool == true)
			return (1);
		if (dst->a != NULL && channels == ALPHA && is_bool == false)
			return ((int)dst->a[index]);
	}
	return (-1);
}

// time : O(n)
// space: O(1)
int	get_minmax_from_table_fdf(const t_table_fdf *dst, bool is_max, e_rgba channels)
{
	int		sign;
	size_t	i;
	int		y;

	y = 0;
	sign = 1;
	if (is_max == false)
		sign = -1;
	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (target_minmax((const t_table_fdf *)dst, channels, i, true) == 1
			&& y * sign < target_minmax((const t_table_fdf *)dst, channels, 0, false) * sign)
			y = target_minmax((const t_table_fdf *)dst, channels, 0, false);
		i += 1;
	}
	return (y);
}

// time : O(n)
// space: O(1)
void	scale_positive_fdf(t_table_fdf *dst)
{
	int	y;

	y = get_minmax_from_table_fdf((const t_table_fdf *)dst, false, HEIGHT);
	if (y < 0 && y > -2147483648)
		y *= -1;
	else if (y == -2147483648)
		y = 0;
	scale_addition_fdf(dst, y, HEIGHT);
}

// time : O(n)
// space: O(1)
void	scale_relu_fdf(t_table_fdf *dst, int min, int max, int expect)
{
	size_t	i;
	int		temp;

	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	i = 0;
	while (dst != NULL && dst->arr != NULL && i < dst->row * dst->col)
	{
		if (min <= dst->arr[i] && dst->arr[i] <= max)
			dst->arr[i] = expect;
		i += 1;
	}
}
